/*
	TITLE		   My window					  Chapter16Exercise1.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define class based on Window with two buttons: quit, next.
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
		quit_button(Point(x_max() - 80, 0), 70, 20, "Quit" , cb_quit),
		next_button(Point(x_max() - 80, 30), 70, 20, "Next" , cb_next)
	{
		attach(quit_button);
		attach(next_button);
	}

private:
	// widget
	Graph_lib::Button quit_button;
	Graph_lib::Button next_button;

	// callback
	static void cb_quit(Address, Address pw) { reference_to<My_window>(pw).quit_pressed(); }
	static void cb_next(Address, Address pw) { reference_to<My_window>(pw).next_pressed(); }

	// action
	void quit_pressed() { hide(); }
	void next_pressed() { redraw(); }
};

//-------------------------------------------------------------------------------------------------------
int main()
{
	try
	{
		const int width = 600;
		const int height = width;
		std::string title = "Chapter 16 Exercise 1";

		My_window sw(Point(500, 0), width, height, title);

		return gui_main();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() <<'\n';
		getchar();
	}
}