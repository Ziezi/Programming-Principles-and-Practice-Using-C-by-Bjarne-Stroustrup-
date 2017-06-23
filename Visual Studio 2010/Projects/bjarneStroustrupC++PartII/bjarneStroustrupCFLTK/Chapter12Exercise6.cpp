/*
	TITLE			   Non-matching dimensions	 Chapter12Exercise6.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: 1. Demonstrate an object not matching the size of the window.
					   2. Demonstrate a window not matching the size of the screen.
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
		// create a window
		// when the window is larger than the screen size, the edges of the window are not displayed

        //int sizeOfScreen = 2000;
		int sizeOfScreen = 400;

		Point tp(x_max() / 2. - sizeOfScreen / 2., y_max() / 2. - sizeOfScreen / 2.);
		Simple_window sw(tp, sizeOfScreen, sizeOfScreen, "Chapter 12 Exercise 6");

		// this rectangle goes out in y direction, as it is 50 pixels larger than the heigth of the window
		Graph_lib::Rectangle rect(Point(sw.x_max() / 2. , sw.y_max() / 2.), 199, 250);
		rect.set_fill_color(Color::red);
		sw.attach(rect);
		 
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
