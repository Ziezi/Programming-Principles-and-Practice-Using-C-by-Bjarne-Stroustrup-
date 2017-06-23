/*
	TITLE		   Hexagon						 Chapter13Exercise8.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Create a class Hexagon that draws a hexagon using as
		           parameters the center and the distance to the corner
				   (radius).
		   Output: 
		   Author: 20.09.2015
		     Date: Chris B. Kirov
*/
#include "GUI.h"
#include "Simple_window.h"
#include <iostream>
#include <iomanip>

#define PI 3.14159265359

namespace Graph_lib
{

class Hexagon: public Closed_polyline
{
public:
	Hexagon(Point c, int r);
	double getSide() { return  2 * radius * sin(PI * 1 / 6.); }

private:
	Point center;
	int radius;

	void generateHex();
	void rotateCoordinate(Point& axisOfRotation, Point& initial, double angRads, int numberOfRotations);
};

Hexagon::Hexagon(Point c, int r)
	: center(c), radius(r)
{ 
	generateHex();
}

void Hexagon::generateHex()
{
	 int numberOfRotations = 6;
	 double angRads = PI / 180. * (360. / numberOfRotations);

	 // first point of the Hexagon in above the center at distance: radius
	 Point initial(center.x, center.y - radius);

	 // initialize the first point of the hexagon
	 Closed_polyline::add(initial);
	 rotateCoordinate(center, initial, angRads, numberOfRotations);
}

void Hexagon::rotateCoordinate(Point& axisOfRotation, Point& initial, double angRads, int numberOfRotations)
{
	// base case: when all rotations performed return vector holding the rotated points
	if(numberOfRotations <= 0)
	{
		return;
	}
	else
	{
		// apply transformation on the initial point
		double x = cos(angRads) * (initial.x - axisOfRotation.x) - sin(angRads) * (initial.y - axisOfRotation.y) + axisOfRotation.x;
		double y = sin(angRads) * (initial.x - axisOfRotation.x) + cos(angRads) * (initial.y - axisOfRotation.y) + axisOfRotation.y;

		// save the rest of the five points of the hexagon
		Closed_polyline::add(Point(x, y));

		// call the same function this time on the rotated point and decremented number of rotations
		rotateCoordinate(axisOfRotation, Point(x,y), angRads, --numberOfRotations);
	}
}

} // end of namespace Graph_lib

//----------------------------------------------------------------------------------------------------------------------------------------
int main()
{
	 // window parameters
	 int winWidth = 800;
	 int winHeight = 600;

	 Point centerPoint((x_max() - winWidth) / 2, (y_max() - winHeight) / 2);
	 Simple_window* siw = new Simple_window(centerPoint, winWidth, winHeight, "Chapter 13 Exercise 8");

	 try
	 {
		 Graph_lib::Hexagon hexagon(Point(200,200), 100);
		 hexagon.set_fill_color(Color::green);
		 hexagon.set_color(Color::invisible);

		 siw->attach(hexagon);
		 siw->wait_for_button();
	 }
	 catch(std::exception& e)
	 {
		std::cerr << e.what() << std::endl;
	 }
	 catch(...)
	 {
		std::cerr <<"Defaul exception!"<< std::endl;
	 }
}