/*
	TITLE		   Stripped_Rectangle			  Chapter14Exercise5.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a class where the rectangle is
		           "filled" by drawing one-pixel-wide 
				   horizontal lines across the inside 
				   area. (Consider line width and spacing.)
		    Input: - 
		   Output: -
		   Author: 27.09.2015
		     Date: Chris B. Kirov
*/
#include "Graph.h"
#include "Simple_window.h"
#include <iostream> 

class Stripped_Rectangle: public Rectangle
{
public:
	Stripped_Rectangle(Point ul, int w, int h, int s)
		: Rectangle(ul, w, h), width(w), height(h), spacing(s) 
	{
		if(s <=0 || s >= h - 1)
		{
			throw std::invalid_argument("Spacing out of range!");  
		}
	}

	Stripped_Rectangle(Point ul, Point dr, int s) 
		: Rectangle(ul, dr), width(abs(dr.x- ul.x)), height(abs(dr.y - ul.y)), spacing(s)
	{ 
		if(s <=0 || s >= abs(dr.y - ul.y) - 1) 
		{
			throw std::invalid_argument("Spacing out of range!");
		}
	}

	void draw_lines() const;

private:

	int width;
	int height; 
	int spacing;
};

void Stripped_Rectangle::draw_lines() const
{	
    if (fill_color().visibility()) 
	{    
		// fill
        fl_color(fill_color().as_int());
		for(size_t i =  0; i < height; i += spacing)
		{
			fl_line(point(0).x, point(0).y + i, point(0).x + width - 1, point(0).y + i);
		}
    }

    if (color().visibility())
	{    
		// lines on top of fill
        fl_color(color().as_int());
        fl_rect(point(0).x,point(0).y, width, height);
    }
}

//----------------------------------------------------------------------------------------------
int main()
{
	Point tl(x_max()/2,0);
	int width = 700;
	int height = 700;
	string label = "Chapter 14 Exercise 5";

	Simple_window sw(tl, width, height, label);

	try
	{
		Point ul(100, 100);
		int width = 300;
		int height = 100;
		int lineSpacing = 3; // in pixels

        Stripped_Rectangle sr(ul, width, height, lineSpacing);

		sr.set_fill_color(Color::red);

		sw.attach(sr);

		sw.wait_for_button();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(...)
	{
		std::cerr <<"Default exception!"<< std::endl;
	}
}
