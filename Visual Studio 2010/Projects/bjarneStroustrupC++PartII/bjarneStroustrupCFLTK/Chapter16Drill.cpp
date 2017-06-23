/*
	TITLE		   Implement code from 16.5§		  Chapter16Drill.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Write line - drawing program with GUI.
		           Add color pop - up menu.
				   Add style pop - up menu.
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>
#include <string>
#include <sstream>

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"
#include "Chapter16Drill.h"

int main()
{
	try
	{
		const int width = 600;
		const int height = width;
		Lines_window sl(Point(500, 0), width, height, "Chapter 16 Drill");

		return gui_main();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() <<'\n';
		getchar();
		return 1;
	}
	catch (...)
	{
		std::cerr << "Exception!\n";
		getchar();
		return 2;
	}
}