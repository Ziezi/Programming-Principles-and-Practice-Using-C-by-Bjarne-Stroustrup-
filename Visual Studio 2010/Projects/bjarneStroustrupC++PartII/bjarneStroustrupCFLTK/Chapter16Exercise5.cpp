/*
	TITLE		   Drawing GUI					  Chapter16Exercise5.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Make a program that draws a shape of you choice and moves
				   it to a new point each time you click "Next". The new point
				   should be determined by a coordinate pair read from an input
				   stream.

				   Menu should act like (mutually exclusive) switches and "next" should only move existing
				   shape if switch is same; or create new shape at given coordinates
				   is switch changed to different shape.
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"

#include "Chapter16Exercise5.h"

int main()
{
	try
	{
		std::string title = "Chapter 16 Exercise 5";
		Shape_window sw(Point(300, 300), 600, 600, title);

		return gui_main();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() <<'\n';
	}
	catch(...)
	{
		std::cerr << "Exception!\n";
	}
}