/*
	TITLE		   Copy Shape				 Chapter14Exercise2and3.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Try to copy Shape.
		    Input: - 
		   Output: -
		   Author: 27.09.2015
		     Date: Chris B. Kirov
*/
#include "Graph.h"
#include "Simple_window.h"
#include <iostream> 

int main()
{
	Point tl(x_max()/2,0);
	int width = 700;
	int height = 700;
	string label = "Chapter 14 Exercise 1";

	Simple_window sw(tl, width, height, label);

	try
	{
		Graph_lib::Circle c = Graph_lib::Shape();

		sw.wait_for_button();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(...)
	{
		cerr <<"Default exception!"<< endl;
	}
}
