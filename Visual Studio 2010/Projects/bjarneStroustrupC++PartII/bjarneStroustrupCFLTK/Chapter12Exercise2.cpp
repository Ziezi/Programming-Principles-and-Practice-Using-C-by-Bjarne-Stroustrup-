/*
	TITLE			   Rectangle and Text       Chapter12Exercise2.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Draw a rectangle using and place text within it.
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
		// create a window in the center of the screen wiht size: 600x600
		int wWidth = 600;
		int wHeigth = 600;
		Point centerScreen(x_max() / 2 - wWidth / 2, y_max() / 2 - wHeigth / 2);
		Simple_window sw(centerScreen, wWidth, wHeigth, "Chapter 12 Exercise 2");

		// create a rectangle in the center of the window with size: 300x200
		int rWidth = 300;
		int rHeight = 200;
		Point upperLeft (sw.x_max() / 2 - rWidth / 2, sw.y_max() / 2 - rHeight / 2);
		Graph_lib::Rectangle rect(upperLeft, rWidth, rHeight);
		sw.attach(rect);

		// create a text inside the rectangle (center of the window / screen), shifted by the width of the text
		int tWidth = 25;
		Text tex(Point(sw.x_max() / 2 - tWidth, sw.y_max() / 2), "Howdy!");
		sw.attach(tex);

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
