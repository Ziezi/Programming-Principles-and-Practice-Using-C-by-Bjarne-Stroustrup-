/*
	TITLE		   Regular Octagon                Chapter14Exercise8.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a class Regular Octagon
		           and write a test function that 
				   exercises all of its functions.
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
#include "Chapter14Exercise8.h"

int main()
{
	Point tl(x_max()/2,0);
	int width = 700;
	int height = 700;
	string label = "Chapter 14 Exercise 8";

	Simple_window sw(tl, width, height, label);

	try
	{ 
		Point octCenter(350,350);
		int octRadius = 300;

		Graph_lib::Octagon* oct = new Octagon(octCenter, octRadius);

		classOctagonFunctionTest(oct);

		sw.attach(*oct);

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