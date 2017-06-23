/*
	TITLE		   Binary tree	                 Chapter14Exercise14.cpp
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
#include "algorithm"
#include "Graph.h"
#include "Simple_window.h"

#define PI 3.14159265359

#include "Chapter14Exercise14.h"

int main()
{
	Point tl(x_max() / 2, 0);
	int width = 700;
	int height = 700;
	string label("Chapter 14 Exercise 14");

	Simple_window w(tl, width, height, label);

	try
	{ 
		Point root(w.x_max() / 2, 30);
		int depth = 4;
		ConnectionType ct = ConnectionType::up_red_arrow;

		Binary_tree bt(root, depth, ct);

		std::string node_location = "l";
		std::string node_label = "root";
		bt.set_node_label(node_location, node_label);

		node_location = "rr";
		node_label = "Lv:1";
		bt.set_node_label(node_location, node_label);

		node_location = "rrr";
		node_label = "Lv:2";
		bt.set_node_label(node_location, node_label);

		node_location = "rrrr";
		node_label = "Lv:3";
		bt.set_node_label(node_location, node_label);

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