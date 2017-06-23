/*
	TITLE			   Create a simple window       Chapter12Drill.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: 1. Make a simple window.
					   2. Add all the examples from Chapter 12.7, one by one.
					   3. Make a minor change on each of the examples.
			    Input: - 
			   Output: Labeled window.
			   Author: Chris B. Kirov
			     Date: 17. 08. 2015
*/
#include "fltk.h"
#include "Graph.h"
#include "Window.h"
#include "Simple_window.h"
#include "GUI.h"
#include <iostream>
  
int main()
{
	try
	{
		// reference point for the window
		Point topLeft(50,50);

		// initializing a Simple_window object to size: 600x400 pixels, labeled: My window
		Simple_window myWindow(topLeft, 1000, 750, "My window");
		
		// add a coordinate sytem
		Point coordSysOrigin(50, 350);

	    // horizontal axis
		Axis xa(Axis::x, coordSysOrigin, 300, 10, "x: abscissa");
		xa.set_color(Color::dark_blue);
		xa.set_style(Line_style(Line_style::solid, 2));
		myWindow.attach(xa);

		// vertical axis
		Axis ya(Axis::y, coordSysOrigin, 300, 10, "y: ordinate");
		ya.set_color(Color::dark_blue);
		ya.set_style(Line_style(Line_style::solid, 2));
		myWindow.attach(ya);
		
		// graph a function
		int startInterval = 0;
		int endInterval = 9;
		Point initialPoint(50, 300);
		int numberOfPoints = 4000;
		float scaleXBy = 25;
		float scaleYBy = 100;

		// plot a mathematical function (cosinus)
		Function func1(cos, startInterval, endInterval, initialPoint, numberOfPoints, scaleXBy, scaleYBy);
		func1.set_color(Color::dark_green);
		func1.set_style(Line_style(Line_style::dashdotdot, 2));
		myWindow.attach(func1);

		// graph a geometric figure
		Graph_lib::Polygon poly1;
		poly1.add(Point(myWindow.x_max() / 6, myWindow.y_max() / 4));
		poly1.add(Point(myWindow.x_max() - 100, myWindow.y_max() / 4));
		poly1.add(Point(myWindow.x_max() / 6, myWindow.y_max() - 100));
		poly1.add(Point(myWindow.x_max() - 100, myWindow.y_max() - 100));
		poly1.set_fill_color(Color::dark_magenta);
		poly1.set_style(Line_style(Line_style::dash, 2));
		poly1.set_color(Color::dark_red);
		myWindow.attach(poly1);

		// graph a geometric figure
		Graph_lib::Rectangle rect1(Point(myWindow.x_max()-60, myWindow.y_max() - 60), 50, 50);
		rect1.set_fill_color(Color::dark_cyan);
		rect1.set_style(Line_style(Line_style::dash, 3));
		rect1.set_color(Color::white);
		myWindow.attach(rect1);

		// graph a geometric figure
		Circle c1(Point(myWindow.x_max()/2- 50, myWindow.y_max()/2), 50);
		myWindow.attach(c1);

		// graph a geometric figure
		Graph_lib::Ellipse e1(Point(myWindow.x_max()/2 - 50, myWindow.y_max()/2), 100, 20);
		myWindow.attach(e1);

		// print a mark
		Mark m1(Point(myWindow.x_max()/2 - 50, myWindow.y_max()/2), 'X');
		myWindow.attach(m1);

		// display a text
		Text te1(Point(150, 50),"This is my first graph!");
		te1.set_font(Font::times_bold_italic);
		te1.set_font_size(30);
		myWindow.attach(te1);

		// dislpay an image
		Image im1(Point(myWindow.x_max() - 300, 100), "prof_pic.jpg");
		im1.move(-100, 50);
		myWindow.attach(im1);

		// Get info about the window and insert it in the stringstream object
		std::ostringstream oss;
		oss <<"Screen size: "<< x_max() <<" * "<< y_max()
			<<"\n Window size: "<< myWindow.x_max() <<" * "<< myWindow.y_max();

		// display the window info as text
		Text windowSize(Point(500, 50), oss.str());
		myWindow.attach(windowSize);

		// pass control to GUI 
		myWindow.wait_for_button();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	catch(...)
	{
		std::cerr << "Default exception!" << std::endl;
		getchar();
	}
}