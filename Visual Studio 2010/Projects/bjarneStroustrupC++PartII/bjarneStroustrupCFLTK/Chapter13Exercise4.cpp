/*
	TITLE		Connection points in rectangle    Chapter13Exercise4.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define functions:
		           n(),	s(), e(), w(), center(), 
				   ne(), se(), sw() and nw().
				   Each takes argument a Rectangle
				   and returns a Point.
				   These functions define "connection points"
				   on and in the rectangle, e.g.: nw(r) is
				   the North-West corner of a Rectangle r.
		   Output: 
		   Author: 17.09.2015
		     Date: Chris B. Kirov
*/

#include "GUI.h"
#include "Simple_window.h"
#include <iostream>

Point n(const Graph_lib::Rectangle& r);
Point s(const Graph_lib::Rectangle& r);
Point e(const Graph_lib::Rectangle& r);
Point w(const Graph_lib::Rectangle& r);
Point center(const Graph_lib::Rectangle& r);
Point ne(const Graph_lib::Rectangle& r);
Point se(const Graph_lib::Rectangle& r);
Point sw(const Graph_lib::Rectangle& r);
Point nw(const Graph_lib::Rectangle& r);
//--------------------------------------------------------------------------------------------------

int main()
{
	 // window parameters
	 int winWidth = 800;
	 int winHeight = 600;
	 Point centerPoint((x_max() - winWidth) / 2., (y_max() - winHeight) / 2.);
	 Simple_window* siw = new Simple_window(centerPoint, winWidth, winHeight, "Chapter 13 Exercise 4");

	 try
	 {
		 Graph_lib::Rectangle rect(Point(50,50), 400, 200);
		 siw->attach(rect);

		 Point north = n(rect);
		 Graph_lib::Mark nM(north, 'N');
		 nM.set_color(Color::red);
		 siw->attach(nM);

		 Point south = s(rect);
		 Graph_lib::Mark sM(south, 'S');
		 sM.set_color(Color::blue);
		 siw->attach(sM);
		
		 Point east = e(rect);
		 Graph_lib::Mark eM(east, 'E');
		 eM.set_color(Color::green);
		 siw->attach(eM);

		 Point west = w(rect);
		 Graph_lib::Mark wM(west, 'W');
		 wM.set_color(Color::dark_yellow);
		 siw->attach(wM);

		 Point northEast = ne(rect);
		 Graph_lib::Mark neM(northEast, 'x');
		 neM.set_color(Color::dark_magenta);
		 siw->attach(neM);

		 Point northWest = nw(rect);
		 Graph_lib::Mark nwM(northWest, 'x');
		 nwM.set_color(Color::blue);
		 siw->attach(nwM);

		 Point southWest = sw(rect);
		 Graph_lib::Mark swM(southWest, 'x');
		 swM.set_color(Color::blue);
		 siw->attach(swM);

		 Point southEast = se(rect);
		 Graph_lib::Mark seM(southEast, 'x');
		 seM.set_color(Color::blue);
		 siw->attach(seM);

		 Point cent = center(rect);
		 Graph_lib::Mark c(cent, 'o');
		 c.set_color(Color::red);
		 siw->attach(c);

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
Point n(const Graph_lib::Rectangle& r)
{
	return Point(r.point(0).x + r.width() / 2., r.point(0).y);
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
Point s(const Graph_lib::Rectangle& r)
{
	return Point(r.point(0).x + r.width() / 2., r.point(0).y + r.height());
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
Point e(const Graph_lib::Rectangle& r)
{
	return Point(r.point(0).x + r.width(), r.point(0).y + r.height()/2.);
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
Point w(const Graph_lib::Rectangle& r)
{
	return Point(r.point(0).x, r.point(0).y + r.height()/2.);
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
Point center(const Graph_lib::Rectangle& r)
{
	return Point(r.point(0).x + r.width()/2., r.point(0).y + r.height()/2.);
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
Point ne(const Graph_lib::Rectangle& r)
{
	return Point(r.point(0).x + r.width(), r.point(0).y);
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
Point se(const Graph_lib::Rectangle& r)
{
	return Point(r.point(0).x + r.width(), r.point(0).y + r.height());
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
Point sw(const Graph_lib::Rectangle& r)
{
	return Point(r.point(0).x, r.point(0).y  + r.height());
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
Point nw(const Graph_lib::Rectangle& r)
{
	return Point(r.point(0).x, r.point(0).y);
}