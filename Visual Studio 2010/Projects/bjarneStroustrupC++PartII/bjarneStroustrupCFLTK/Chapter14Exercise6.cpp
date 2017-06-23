/*
	TITLE		  Stripped_Circle			     Chapter14Exercise6.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a class where the circle is
		           "filled" by drawing varying-pixel-wide-spaced
				   horizontal lines across the inside 
				   area. (Consider line width and spacing.)
		    Input: - 
		   Output: -
		   Author: 28.09.2015
		     Date: Chris B. Kirov
*/
#include "Graph.h"
#include "Simple_window.h"
#include <iostream> 

#define PI 3.14159265358979323846

class Stripped_Circle: public Circle
{
public:
	Stripped_Circle(Point ul, int r, int s)
		: Circle(ul, r), radius(r), spacing(s) 
	{
		if(s <=0 || s >= 2 * ( r - 1))
		{
			throw std::invalid_argument("Spacing out of range!"); 
		}
	}
	 
	void draw_lines() const;

private:

	int radius;
	int spacing;
};

void Stripped_Circle::draw_lines() const
{	 
	if (color().visibility()) 
	{
		// draw circle
        fl_arc(point(0).x,point(0).y,radius + radius, radius + radius, 0, 360);
	}

    if (fill_color().visibility())
	{ 
		// fill
		fl_color(fill_color().as_int());

	    int offsetX = point(0).x + radius;
		int offsetY = point(0).y + radius;

	    // corrections by: +/-1 are made to not overlap the filling with the contour lines
		for(int i = -radius; i < radius; i += spacing)
		{
			int ry = i;
			int rx = sqrt(double((radius - 1) * (radius - 1) - ry * ry));

			fl_line(offsetX - rx, offsetY + i, offsetX + rx - 1, offsetY + i);
		}
	} 
}
//------------------------------------------------------------------------------------------------

int main()
{
	Point tl(x_max()/2,0);
	int width = 700;
	int height = 700;
	string label = "Chapter 14 Exercise 6";

	try
	{
		for	(size_t i = 1; i < 200; i++)
		{
			Simple_window sw(tl, width, height, label);

			Point ul(300, 300);
			int radius = 100;
			int lineSpacing = i;

			Stripped_Circle sc(ul, radius, lineSpacing);

			sc.set_fill_color(Color::red);

			sw.attach(sc);
			
			sw.wait_for_button();
		}
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	catch(...)
	{
		std::cerr <<"Default exception!"<< std::endl;
		getchar();
	}
}

// using the circle parametric equations
/*
void calcLineCoordOnCircle()
{
	 fl_color (fill_color().as_int());
	 {
		for (size_t i =  0; i < 360 ; i += spacing)
		{
			// use circle parametric equations for x and y 
			int startCoordX = radius * cos(270 * PI / 180. - i * PI / 180.);
			int startCoordY = radius * sin(270 * PI / 180. - i * PI / 180.);

			int endCoordX = radius * cos(270 * PI / 180. + i * PI / 180.);
			int endCoordY = radius * sin(270 * PI / 180. + i * PI / 180.);

			fl_line (point(0).x + radius + startCoordX, point(0).y + radius + startCoordY, 
				    point(0).x + radius +  endCoordX, point(0).y + radius  + endCoordY);
		}
	}
}
*/

// using the radius vector
/*
void calcLineCoordOnCircle
{ 
	for (int i = -radius; i < radius; i += spacing)
	{
		int ry = i;
		int rx = sqrt (double(radius * radius - ry * ry));

		fl_line(point(0).x + radius - rx, point(0).y + i, 
				point(0).x + radius + rx, point(0).y + i);
	}
}
*/