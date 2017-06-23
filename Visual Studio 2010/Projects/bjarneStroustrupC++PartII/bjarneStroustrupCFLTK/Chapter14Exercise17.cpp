/*
	TITLE		   std::exception class hierarchy Chapter14Exercise17.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Draw a class hierarchy for the std::exception C++ standard library.
		           It's consisted of a set of labeled boxes located on different lines.

				   Note: Drawing hardcoded, a lot of literals for coorinate adjustment.
		    Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>
#include "Graph.h"
#include "Point.h"
#include "Simple_window.h"
#include "Chapter14Exercise17.h"

using namespace Graph_lib;

 int main()
 {
	Simple_window sw(Point(50, 50), 700, 700, "Chapter 14 Exercise 17");

	// coordinates and names of the labeled boxes of the diagram
	Point center(sw.x_max() /2 - 100 , 20);
	
	try
	{
		Hierchy_Diagram hd(center);

		sw.attach(hd);

		sw.wait_for_button();
	}
	catch(...)
	{
		std::cerr << "Exception!\n";
	}
 }