/*
	TITLE		   Regular Polygon		        Chapter13Exercise10.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Create a class RegularPolygon that
				   instantiates an objects using three
				   paremeters:
				   center, radius and number of sides.
		   Output: 
		   Author: 20.09.2015
		     Date: Chris B. Kirov
*/
#include "GUI.h"
#include "Simple_window.h"
#include <iostream>

#define PI 3.14159265359

namespace Graph_lib
{
class RegularPolygon: public Closed_polyline
{
public:
	RegularPolygon(Point c, int r, int n);
	double getSide() { return  2 * radius * sin(PI * 1 / 6.); }

private:
	Point center;
	int radius;
	int sidesNumber;

	void generateHex();
	void rotateCoordinate(Point& axisOfRotation, Point& initial, double angRads, int numberOfRotations);
};

RegularPolygon::RegularPolygon(Point c, int r, int n)
	: center(c), radius(r), sidesNumber(n) 
{
	generateHex();
}

void RegularPolygon::generateHex()
{	  
	 double angRads = PI / 180. * (360. / sidesNumber);

	 // first point of the Hexagon in above the center at distance: radius
	 Point initial(center.x, center.y - radius);

	 // initialize the first point of the hexagon
	 Closed_polyline::add(initial);
	 rotateCoordinate(center, initial, angRads, sidesNumber);
}

void RegularPolygon::rotateCoordinate(Point& axisOfRotation, Point& initial, double angRads, int numberOfRotations)
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

// Helper function
double hexagonApothem(double side)
{
	return side / (2 * tan(PI * 1 / 6.));
}

Point rotatePoint(Point axisOfRotation, Point initial, double angle)
{
	double angRads = angle * PI / 180.;
	return Point(cos(angRads) * (initial.x - axisOfRotation.x) - sin(angRads) * (initial.y - axisOfRotation.y) + axisOfRotation.x,
		         sin(angRads) * (initial.x - axisOfRotation.x) + cos(angRads) * (initial.y - axisOfRotation.y) + axisOfRotation.y);
}
//------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	 // window parameters
	 int winWidth = 800;
	 int winHeight = 600;
	 Point centerPoint((x_max() - winWidth) / 2, (y_max() - winHeight) / 2);

	 Simple_window* siw = new Simple_window(centerPoint, winWidth, winHeight, "Chapter 13 Exercise 10");

	 try
	 {
		 // garbage collector
		 vector<RegularPolygon*> hexagons;

		 // hexagon parameters
		 int x = 0;
		 int y = 100;
		 int radius = 50;
		 int numberOfSides = 6;
		 size_t numOfHex = 10;
		 int apothem = hexagonApothem(radius);
		  
		 for (size_t k = 0; k < 3; ++k)
		 {
			y = 100 + 150 * k;
			for(size_t i = 0; i < numOfHex; ++i)
			{
				Graph_lib::RegularPolygon* h = new RegularPolygon(Point(x + 2 * apothem*(i % 9), y), radius, numberOfSides);

				h->set_fill_color(rand() % 100 + 50);
				hexagons.push_back(h);

				siw->attach(*h);
			}
		 
			Point center2 = rotatePoint(Point(x,y), Point(x + 2 * apothem, y), 60);

			for(size_t i = 0; i < numOfHex; ++i)
			{
				Graph_lib::RegularPolygon* h = new RegularPolygon(Point(center2.x + 2 * apothem*i, center2.y), radius, numberOfSides);

				h->set_fill_color(rand() % 100 + 50);
				hexagons.push_back(h);

				siw->attach(*h);
			}		
		 }

		 siw->wait_for_button();

		 // free heap memory
		 for(auto it = hexagons.begin() ; it != hexagons.end(); ++it) delete *it;
	 }
	 catch(std::exception& e)
	 {
		std::cerr << e.what() << std::endl;
	 }catch(...)
	 {
		std::cerr <<"Defaul exception!"<< std::endl;
	 }
}