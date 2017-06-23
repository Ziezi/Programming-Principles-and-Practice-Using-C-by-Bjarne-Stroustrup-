/*
	TITLE		   Group container                Chapter14Exercise11.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define Binary_Tree class derived from Shape.
		           Give Number of levels as parameter:
				   0 - no nodes;
				   1 - one done;
				   2 - top node with two subnodes, etc.
				   Let a node be a circle; connect nodes
				   by lines 
		    Input: - 
		   Output: -
		   Author: 16.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream> 
#include <vector>
#include "Graph.h"
#include "Simple_window.h"
#include "Chapter14Exercise11.h"

int main()
{
	Point tl(x_max() / 2., 0);
	int width = x_max();
	int height = 700;
	string label("Chapter 14 Exercise 11");

	Simple_window w(tl, width, height, label);

	try
	{ 
		int levels = 6;
		Point root(x_max() / 2.,30);

		Binary_tree bt(root, levels);

		w.attach(bt);
		 
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