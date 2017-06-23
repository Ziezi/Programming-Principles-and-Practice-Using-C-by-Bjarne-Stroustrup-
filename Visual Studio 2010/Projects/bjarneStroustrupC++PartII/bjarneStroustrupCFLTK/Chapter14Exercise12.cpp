/*
	TITLE		   Group container                Chapter14Exercise12.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define Binary_Tree class derived from Shape.
		           Modify the draw function to be virtual and
				   derive a new class that overrides it and
				   lets each node be triangle.
		    Input: - 
		   Output: -
		   Author: 17.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream> 
#include <vector>
#include "Graph.h"
#include "Simple_window.h"

#define PI 3.14159265359

#include "Chapter14Exercise12.h"

int main()
{
	Point tl(x_max() / 2, 0);
	int width = 900;
	int height = 700;
	string label("Chapter 14 Exercise 12");

	Simple_window w(tl, width, height, label);

	try
	{ 
		int depth = 5;
		Point root(w.x_max() / 2, 30);

		Binary_tree bt(root, 1);
		//w.attach(bt);
		//w.wait_for_button();

		Binary_tree_triangle btt (root, depth);
		w.attach(btt);
		w.wait_for_button();
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