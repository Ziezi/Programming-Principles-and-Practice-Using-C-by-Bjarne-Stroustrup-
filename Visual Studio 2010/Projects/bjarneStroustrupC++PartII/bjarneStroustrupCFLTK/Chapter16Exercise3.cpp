/*
	TITLE		   Moving image					  Chapter16Exercise3.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define class with a button that moves to a random position
				   when pressed, together with an image placed on it.
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"

struct My_window: Window
{
	My_window(Point o, int w, int h, std::string& t)
		: Window(o, w, h, t), 
		next_button(Point(x_max() / 2 - 125, y_max() / 2 - 125), 250, 250, "" , cb_next),
		picture(Point(x_max() / 2 - 125, y_max() / 2 - 125), "Chapter16Exercise3.jpg", Suffix::jpg) 
	{
		attach(next_button);
		attach(picture);
	}

private:
	// widget
	Graph_lib::Button next_button;
	Graph_lib::Image picture;

	// callback
	static void cb_next(Address, Address pw) { reference_to<My_window>(pw).next_pressed(); }

	// action
	void next_pressed()
	{ 
		int x = rint(-25, 25);  
		int y = rint(-25, 25);  

		next_button.move(x, y);
		picture.move(x, y);

		redraw();
	}

	// helper
	int rint(int low, int high) { return low + rand() % (high - low); } 
};

//-------------------------------------------------------------------------------------------------------
int main()
{
	try
	{
		const int width = 600;
		const int height = width;
		std::string title = "Chapter 16 Exercise 3";

		My_window sw(Point(500, 0), width, height, title);

		return gui_main();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() <<'\n';
		getchar();
	}
}