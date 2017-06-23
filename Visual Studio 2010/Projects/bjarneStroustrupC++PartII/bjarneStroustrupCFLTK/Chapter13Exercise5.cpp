/*
	TITLE		Connection points with Circle and Ellipse  Chapter13Exercise5.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: (virtual funtions?) Define functions:
		           n(),	s(), e(), w(), center(), 
				   ne(), se(), sw() and nw().
				   Each takes argument a Rectangle
				   and returns a Point.
				   These functions define "connection points"
				   on and in the rectangle, e.g.: nw(r) is
				   the North-West corner of a Rectangle r.

				   Define the same functions for Circle and Ellipse.
				   Place the connectio points on or outside the shape,
				   but no outside the bounding rectangle.
		   Output: 
		   Author: 17.09.2015
		     Date: Chris B. Kirov
*/
#include "GUI.h"
#include "Simple_window.h"
#include <iostream>

class ConnectionPoints
{
public:
	// constructors
	ConnectionPoints(const Graph_lib::Rectangle& r);
	ConnectionPoints(const Graph_lib::Circle& c);
	ConnectionPoints(const Graph_lib::Ellipse& e);

	// non-modyfing member function
	Point n();
	Point s();
	Point e();
	Point w();
	Point center();
	Point ne();
	Point se();
	Point sw();
	Point nw();

private:
	Point topLeft;
	int width;
	int height;
	
};

// Class Connectionpoints member implementation
// constructors
ConnectionPoints::ConnectionPoints(const Graph_lib::Rectangle& r)
	: topLeft(r.point(0)), width(r.width()), height(r.height())
{ }
ConnectionPoints::ConnectionPoints(const Graph_lib::Circle& c)
	: topLeft(c.center().x - c.radius(), c.center().y - c.radius()), width(2 * c.radius()), height(2 * c.radius())
{ }

ConnectionPoints::ConnectionPoints(const Graph_lib::Ellipse& e)
	: topLeft(e.center().x - e.major(), e.center().y - e.minor() ), width(2 * e.major()), height(2 * e.minor())
{ }

// // non-modyfing member function

/*
	Function: n()
	Use: Point p = n(Rect_obj);
	It returns the middle point
	of the top side of the passed rectangle.
	Internally, it retrieves the zero-th
	point from the base class Shape,i.e.
	the upper left point and increases
	the x-coordinate by half the width.
*/
Point ConnectionPoints::n()
{
	return Point(topLeft.x + width / 2., topLeft.y);
}

/*
	Function: s()
	Use: Point p = s(Rect_obj);
	It returns the middle point
	of the bottom side of the passed rectangle.
	Internally, it retrieves the zero-th
	point from the base class Shape,i.e.
	the upper left point and increases
	the x-coordinate by half the width and
	the y-coordiante by the full height.
*/
Point ConnectionPoints::s()
{
	return Point(topLeft.x + width / 2., topLeft.y + height);
}

/*
	Function: e()
	Use: Point p = e(Rect_obj);
	It returns the middle point
	of the right side (on the screen) 
	of the passed rectangle.
	Internally, it retrieves the zero-th
	point from the base class Shape,i.e.
	the upper left point and increases
	the x-coordinate by the full width and
	the y-coordiante by half the height.
*/
Point ConnectionPoints::e( )
{
	return Point(topLeft.x + width, topLeft.y + height / 2.);
}

/*
	Function: w()
	Use: Point p = w(Rect_obj);
	It returns the middle point
	of the left side (on the screen) 
	of the passed rectangle.
	Internally, it retrieves the zero-th
	point from the base class Shape,i.e.
	the upper left point and increases
	the y-coordiante by half the height.
*/
Point ConnectionPoints::w( )
{
	return Point(topLeft.x, topLeft.y + height / 2.);
}

/*
	Function: center()
	Use: Point p = center(Rect_obj);
	It returns the middle point
	of the passed rectangle.
	Internally, it retrieves the zero-th
	point from the base class Shape,i.e.
	the upper left point and increases
	the x-coordinate by half the width and
	the y-coordiante by half the height.
*/
Point ConnectionPoints::center( )
{
	return Point(topLeft.x + width / 2., topLeft.y + height / 2.);
}

/*
	Function: ne()
	Use: Point p = ne(Rect_obj);
	It returns the top right vertex
	of the passed rectangle.
	Internally, it retrieves the zero-th
	point from the base class Shape,i.e.
	the upper left point and increases
	the x-coordinate by the full width.
*/
Point ConnectionPoints::ne( )
{
	return Point(topLeft.x + width, topLeft.y);
}

/*
	Function: se()
	Use: Point p = se(Rect_obj);
	It returns the bottom right vertex
	of the passed rectangle.
	Internally, it retrieves the zero-th
	point from the base class Shape,i.e.
	the upper left point and increases
	the x-coordinate by the full width
	and the y-coordinate by the full height.
*/
Point ConnectionPoints::se( )
{
	return Point(topLeft.x + width, topLeft.y + height);
}

/*
	Function: sw()
	Use: Point p = se(Rect_obj);
	It returns the top left vertex
	of the passed rectangle.
	Internally, it retrieves the zero-th
	point from the base class Shape,i.e.
	the upper left point.
*/
Point ConnectionPoints::sw( )
{
	return Point(topLeft.x, topLeft.y  + height);
}

/*
	Function: nw()
	Use: Point p = ne(Rect_obj);
	It returns the top left vertex
	of the passed rectangle.
	Internally, it retrieves the zero-th
	point from the base class Shape,i.e.
	the upper left point and increases
	the y-coordinate by the full height.
*/
Point ConnectionPoints::nw( )
{
	return Point(topLeft.x, topLeft.y);
}
//--------------------------------------------------------------------------------------------------

int main()
{
	 // window parameters
	 int winWidth = 800;
	 int winHeight = 600;
	 Point centerPoint((x_max() - winWidth) / 2., (y_max() - winHeight) / 2.);
	 Simple_window* siw = new Simple_window(centerPoint, winWidth, winHeight, "Chapter 13 Exercise 5");

	 try
	 {
		 // test the rectangle
		 Graph_lib::Rectangle rect(Point(50,50), 400, 200);
		 siw->attach(rect);
		 
		 Point north = ConnectionPoints(rect).n();
		 Graph_lib::Mark nM(north, 'N');
		 nM.set_color(Color::red);
		 siw->attach(nM);

		 Point south = ConnectionPoints(rect).s();
		 Graph_lib::Mark sM(south, 'S');
		 sM.set_color(Color::blue);
		 siw->attach(sM);
		
		 Point east = ConnectionPoints(rect).e();
		 Graph_lib::Mark eM(east, 'E');
		 eM.set_color(Color::green);
		 siw->attach(eM);

		 Point west = ConnectionPoints(rect).w();
		 Graph_lib::Mark wM(west, 'W');
		 wM.set_color(Color::dark_yellow);
		 siw->attach(wM);

		 Point northEast = ConnectionPoints(rect).ne( );
		 Graph_lib::Mark neM(northEast, 'x');
		 neM.set_color(Color::dark_magenta);
		 siw->attach(neM);

		 Point northWest = ConnectionPoints(rect).nw( );
		 Graph_lib::Mark nwM(northWest, 'x');
		 nwM.set_color(Color::blue);
		 siw->attach(nwM);

		 Point southWest = ConnectionPoints(rect).sw( );
		 Graph_lib::Mark swM(southWest, 'x');
		 swM.set_color(Color::blue);
		 siw->attach(swM);

		 Point southEast = ConnectionPoints(rect).se( );
		 Graph_lib::Mark seM(southEast, 'x');
		 seM.set_color(Color::blue);
		 siw->attach(seM);

		 Point cent = ConnectionPoints(rect).center( );
		 Graph_lib::Mark c(cent, 'o');
		 c.set_color(Color::red);
		 siw->attach(c);

		 // test the circle
		 Graph_lib::Circle circ(Point(500, 500), 50);
		 siw->attach(circ);

		 Point north1 = ConnectionPoints(circ).n();
		 Graph_lib::Mark nM1(north1, 'N');
		 nM1.set_color(Color::red);
		 siw->attach(nM1);

		 Point south1 = ConnectionPoints(circ).s();
		 Graph_lib::Mark sM1(south1, 'S');
		 sM1.set_color(Color::blue);
		 siw->attach(sM1);
		
		 Point east1 = ConnectionPoints(circ).e();
		 Graph_lib::Mark eM1(east1, 'E');
		 eM1.set_color(Color::green);
		 siw->attach(eM1);

		 Point west1 = ConnectionPoints(circ).w();
		 Graph_lib::Mark wM1(west1, 'W');
		 wM1.set_color(Color::dark_yellow);
		 siw->attach(wM1);

		 Point northEast1 = ConnectionPoints(circ).ne( );
		 Graph_lib::Mark neM1(northEast1, 'x');
		 neM1.set_color(Color::dark_magenta);
		 siw->attach(neM1);

		 Point northWest1 = ConnectionPoints(circ).nw( );
		 Graph_lib::Mark nwM1(northWest1, 'x');
		 nwM1.set_color(Color::blue);
		 siw->attach(nwM1);

		 Point southWest1 = ConnectionPoints(circ).sw( );
		 Graph_lib::Mark swM1(southWest1, 'x');
		 swM1.set_color(Color::blue);
		 siw->attach(swM1);

		 Point southEast1 = ConnectionPoints(circ).se( );
		 Graph_lib::Mark seM1(southEast1, 'x');
		 seM1.set_color(Color::blue);
		 siw->attach(seM1);

		 Point cent1 = ConnectionPoints(circ).center( );
		 Graph_lib::Mark c1(cent1, 'o');
		 c1.set_color(Color::red);
		 siw->attach(c1);

		 // test ellipse
		 Graph_lib::Ellipse elps(Point(150, 500), 100, 50);
		 siw->attach(elps);

		 Point north2 = ConnectionPoints(elps).n();
		 Graph_lib::Mark nM2(north2, 'N');
		 nM2.set_color(Color::red);
		 siw->attach(nM2);

		 Point south2 = ConnectionPoints(elps).s();
		 Graph_lib::Mark sM2(south2, 'S');
		 sM2.set_color(Color::blue);
		 siw->attach(sM2);
		
		 Point east2 = ConnectionPoints(elps).e();
		 Graph_lib::Mark eM2(east2, 'E');
		 eM2.set_color(Color::green);
		 siw->attach(eM2);

		 Point west2 = ConnectionPoints(elps).w();
		 Graph_lib::Mark wM2(west2, 'W');
		 wM2.set_color(Color::dark_yellow);
		 siw->attach(wM2);

		 Point northEast2 = ConnectionPoints(elps).ne( );
		 Graph_lib::Mark neM2(northEast2, 'x');
		 neM2.set_color(Color::dark_magenta);
		 siw->attach(neM2);

		 Point northWest2 = ConnectionPoints(elps).nw( );
		 Graph_lib::Mark nwM2(northWest2, 'x');
		 nwM2.set_color(Color::blue);
		 siw->attach(nwM2);

		 Point southWest2 = ConnectionPoints(elps).sw( );
		 Graph_lib::Mark swM2(southWest2, 'x');
		 swM2.set_color(Color::blue);
		 siw->attach(swM2);

		 Point southEast2 = ConnectionPoints(elps).se( );
		 Graph_lib::Mark seM2(southEast2, 'x');
		 seM2.set_color(Color::blue);
		 siw->attach(seM2);

		 Point cent2 = ConnectionPoints(elps).center( );
		 Graph_lib::Mark c2(cent2, 'o');
		 c2.set_color(Color::red);
		 siw->attach(c2);

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
//--------------------------------------------------------------------------------------------------