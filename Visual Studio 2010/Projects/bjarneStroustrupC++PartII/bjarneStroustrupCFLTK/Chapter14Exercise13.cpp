/*
	TITLE		   Binary tree                   Chapter14Exercise13.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define Binary_Tree class derived from Shape.
		           Modify it to include a parameter indicating 
				   whether the connection between two nodes is:
				   - arrow pointing down
				   - red arrow pointing up.
		    Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream> 
#include <vector>
#include "Graph.h"
#include "Simple_window.h"

#define PI 3.14159265359

#include "Chapter14Exercise13.h"


int main()
{
	Point tl(x_max() / 2, 0);
	int width = 700;
	int height = 700;
	string label("Chapter 14 Exercise 13");
	 
	Simple_window w(tl, width, height, label);

	try
	{
		int depth = 4;
		Point root(w.x_max() / 2, 30);
		
		Binary_tree bt(root, depth, ConnectionType::line);
		//w.attach(bt);

		
		Binary_tree bt1(root, depth, ConnectionType::down_arrow);
		//w.attach(bt1);
		
		Binary_tree bt2(root, depth, ConnectionType::up_red_arrow);
		w.attach(bt2);

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