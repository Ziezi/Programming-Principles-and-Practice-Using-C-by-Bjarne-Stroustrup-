/*
	TITLE			   Rectangle and Polygone   Chapter12Exercise1.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Draw a rectangle using class Rectangle (red lines) 
					   and class Polygon (blue lines). 
				Input: -
			   Output: Graph on screen.
			   Author: Chris B. Kirov
			     Date: 17. 08. 2015
*/
#include <iostream>
#include "Simple_window.h"

int main()
{
	try
	{
		// create a window in the center of the screen
		int windowHeigth = 600;
		int windowWidth = 600;
		Point centerOfScreen(x_max()/2 - windowHeigth / 2, y_max()/2 - windowWidth / 2);

		Simple_window sw(centerOfScreen, windowWidth, windowHeigth, "Chapter12 Exercise 1");

		// draw a rectangle
		Point windowLeftCenter(sw.x_max()/2 - 150, sw.y_max() - 250);
		Graph_lib::Rectangle rect(windowLeftCenter, 300, 200);
		rect.set_color(Color::dark_blue);
		sw.attach(rect);

		// draw a polygon: points added clockwise
		Graph_lib::Polygon poly;
		// upper left
		poly.add(Point(sw.x_max()/2 - 150, sw.y_max()/2 - 250));
		// upper right 
		poly.add(Point(sw.x_max()/2 + 150, sw.y_max()/2 - 250));
		// lower right
		poly.add(Point(sw.x_max()/2 + 150, sw.y_max()/2 - 50));
		// lower left
		poly.add(Point(sw.x_max()/2 - 150, sw.y_max()/2 - 50));
		poly.set_color(Color::dark_red);
		sw.attach(poly);

		sw.wait_for_button();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(...)
	{
		std::cerr << "Default exception!" << std::endl;
	}
}