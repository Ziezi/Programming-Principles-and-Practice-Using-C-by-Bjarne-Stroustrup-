/*
	TITLE		   Drawing GUI					  Chapter16Exercise5.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Make a program that draws a shape of you choice and moves
				   it to a new point each time you click "Next". The new point
				   should be determined by a coordinate pair read from an input
				   stream.
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/

#ifndef _Chapter16Exercise5_h_
#define _Chapter16Exercise5_h_

class Shape_window: Window
{
public:
	Shape_window(Point o, int w, int h, std::string& t);

private:
	// data members
	Graph_lib::Shape* shape;
	Point center;
	bool circle;
	bool square;
	bool ellipse;

	// control
	Button next_button;
	Button menu_button;
	Menu shape_menu;
	Out_box xy_current;

	// callback
	static void cb_next(Address, Address pw) { reference_to<Shape_window>(pw).next_pressed(); }
	static void cb_menu_button(Address, Address pw) { reference_to<Shape_window>(pw).menu_button_pressed(); }
	static void cb_circle(Address, Address pw) { reference_to<Shape_window>(pw).circle_pressed(); }
	static void cb_square(Address, Address pw) { reference_to<Shape_window>(pw).square_pressed(); }
	static void cb_ellipse(Address, Address pw) { reference_to<Shape_window>(pw).ellipse_pressed(); }

	// action
	void next_pressed();
	void menu_button_pressed() { menu_button.hide(); shape_menu.show(); } 
	void circle_pressed() { circle = true; square = false; ellipse = false; }
	void square_pressed() { circle = false; square = true; ellipse = false; }
	void ellipse_pressed() { circle = false; square = false; ellipse = true; }
	
	// helper
	void read_console_input();
	void hide_menu() { shape_menu.hide(); menu_button.show(); }

	void circle_make();
	void square_make();
	void ellipse_make();
};

#include "Chapter16Exercise5Def.cpp"

#endif