/*
	TITLE		  Stripped_Closed_Polyline	      Chapter14Exercise7.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a class where the closed polyline is
		           "filled" by drawing varying-pixel-wide-spaced
				   horizontal lines across the inside 
				   area. (Consider line width and spacing.)
		    Input: - 
		   Output: -
		   Author: 13.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream> 
#include <vector>
#include <algorithm>
#include "Graph.h"
#include "Simple_window.h"
#include "Chapter14Exercise7Version2.h"

int main()
{
	Point tl(x_max()/2,0);
	int width = 700;
	int height = 700;
	string label = "Chapter 14 Exercise 7";

	Simple_window sw(tl, width, height, label);

	try
	{ 
		// create a poly-line
		Striped_closed_polyline scp;

		// use pointer to pass the object to a function 
		Striped_closed_polyline* pscp = &scp; 

		// generate points for the poly-line
		generatePoints(pscp);

		// set spacing 
		pscp->set_spacing(2);

		sw.attach(*pscp);

		sw.wait_for_button();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	catch(...)
	{
		std::cerr <<"Default exception!"<< std::endl;
		getchar();
	}
}