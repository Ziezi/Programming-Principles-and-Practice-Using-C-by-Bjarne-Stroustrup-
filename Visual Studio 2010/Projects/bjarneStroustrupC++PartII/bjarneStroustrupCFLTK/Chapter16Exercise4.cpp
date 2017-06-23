/*
	TITLE		   Drawing GUI					  Chapter16Exercise4.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Make a menu with items that make a circle, a square,
				   an equilateral triangle, and a hexagon respectively.
				   Make an input box for giving coordinate pair, and
				   place the shape made by pressing a menu item at 
				   that coordinate.
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"

#include "Chapter16Exercise4.h"

int main()
{
	try
	{
		std::string title = "Chapter 16 Exercise 4";
		Shapes_window sw(Point(300, 300), 600, 600, title);

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