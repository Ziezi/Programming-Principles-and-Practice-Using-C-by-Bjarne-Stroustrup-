/*
	TITLE		   Pseudo window                Chapter14Exercise10.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a Pseudo_window with:
				   rounded corners, label,
				   control icons and fake
				   contents (image, etc.).
		    Input: - 
		   Output: -
		   Author: 14.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream> 
#include <vector>
#include "Graph.h"
#include "Simple_window.h"
#include "Chapter14Exercise10.h"

int main()
{
	Simple_window sw(Point(100, 100), 600, 600, "Chapter 14 Exercise 10");

	try
	{ 
		Point tl(500, 500);
		int width = 400;
		int height = 400;
		string label2("Elon Musk");

		Pseudo_window ps(tl, width, height, label2);

		sw.attach(ps);

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