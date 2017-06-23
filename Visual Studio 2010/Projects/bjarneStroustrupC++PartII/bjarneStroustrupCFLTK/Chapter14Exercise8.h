/*
	TITLE		   Regular Octagon                Chapter14Exercise8.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a class Regular Octagon
		           and write a test function that 
				   exercises all of its functions.
		    Input: - 
		   Output: -
		   Author: 13.10.2015
		     Date: Chris B. Kirov
*/

#ifndef _Chapter14Exercise8_h
#define _Chapter14Exercise8_h

#define PI 3.14159265359

namespace Graph_lib
{
// Class RegularPolygon 
class RegularPolygon: public Closed_polyline
{
public:

	RegularPolygon(Point c, int r, int n);

	// non-modifying members
	Point get_center() const { return center; }
	int get_radius() const { return radius; }
	int get_sideNumber() const { return sidesNumber; }
	double get_sideLenght() const { return  2 * radius * sin(PI * 1 / 6.); }

private:

	// data members
	Point center;
	int radius;
	int sidesNumber;

	// private member function
	void generatePoly();
	void rotateCoordinate(Point& axisOfRotation, Point& initial, double angRads, int numberOfRotations);
};

// constructor
RegularPolygon::RegularPolygon(Point c, int r, int n)
	: center(c), radius(r), sidesNumber(n) 
{
	generatePoly(); 
}

// function wrapper 
void RegularPolygon::generatePoly()
{
	 double angRads = PI / 180. * (360. / sidesNumber);

	 // first point of the Hexagon in above the center at distance: radius
	 Point initial(center.x, center.y - radius);

	 // initialize the first point of the hexagon
	 rotateCoordinate(center, initial, angRads, sidesNumber);
}

// recursive function applying consequtive coordinate rotations to an initial point
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

//---------------------------------------------------------------------------------------------------------------------------------------
// Class Octagon
class Octagon: public RegularPolygon
{
public:
	Octagon(Point c, int r)
		: RegularPolygon(c, r, 8) 
	{
	
	}

};

// helper function
void classOctagonFunctionTest(Graph_lib::Octagon* oct)
{
	// add a point (it should be forbidden)
	// oct->add(Point(50, 50));

	// get color
	Color c = oct->color();
	cout <<"Color as int: "<< c.as_int() <<'\n';
	// 
	oct->draw();
	// 
	oct->draw_lines();

	// get filling color
	Color fc = oct->fill_color();
	cout <<"Fill color as int: "<< fc.as_int() <<'\n';

	// move (all points)
	oct->move(-50, -50);

	// get center
	Point cent = oct->get_center();
	cout <<"Center: ("<< cent.x <<", "<< cent.y <<")\n";

	// get radius
	cout <<"Radius: "<< oct->get_radius() <<'\n';

	// get side lenght
	cout <<"Get side lenght: "<< oct->get_sideLenght() <<'\n';

	// get side number
	cout <<"Get side number: "<< oct->get_sideNumber() <<'\n';

	// get number of points in shape
	cout <<"Number of points in shape: "<< oct->number_of_points() <<'\n';

	// get Shape::point[0]
	cout <<"Shape::Point[0]: ("<< oct->point(0).x <<", "<< oct->point(0).y <<')'<< '\n'; 

	//
	oct->set_color(Color::blue);
	//
	oct->set_fill_color(Color::dark_green);
	//
	oct->set_style(Line_style::dashdotdot);

	//
	Line_style ls = oct->style();
	cout <<"Line style as int: "<< ls.style() <<'\n';
	cout <<"Line width: "<< ls.width() <<'\n';  
}

} // end of namespace Graph_lib

#endif