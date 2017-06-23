/*
	TITLE		   Drawing GUI					    Chapter16Exercise4.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Make a menu with items that make a circle, a square,
				   an equilateral triangle, and a hexagon respectively.
				   Make an input box for giving coordinate pair, and
				   place the shape made by pressing a menu item at 
				   that coordinate.
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/

#ifndef _Chapter16Exercise4_h_
#define _Chapter16Exercise4_h_

class Shapes_window: Window
{
public:
	Shapes_window(Point o, int w, int h, std::string& t);

private:
	std::vector<Graph_lib::Shape*> drawings;

	// widgets
	In_box x_coordinate;
	In_box y_coordinate;

	Out_box xy_current;

	Button menu_button;
	Menu shape_menu;

	// callback
	static void cb_menu_button(Address, Address pw) { reference_to<Shapes_window>(pw).menu_button_pressed(); }
	static void cb_circle(Address, Address pw) { reference_to<Shapes_window>(pw).circle_pressed(); }
	static void cb_square(Address, Address pw) { reference_to<Shapes_window>(pw).square_pressed(); }
	static void cb_triangle(Address, Address pw) { reference_to<Shapes_window>(pw).triangle_pressed(); }
	static void cb_hexagon(Address, Address pw) { reference_to<Shapes_window>(pw).hexagon_pressed(); }

	// action
	void menu_button_pressed() { menu_button.hide(); shape_menu.show(); }
	void circle_pressed();
	void square_pressed();
	void triangle_pressed();
	void hexagon_pressed();

	// helper
	void add_drawing(Graph_lib::Shape* s) { drawings.emplace_back(s); }
	void plot_drawings() { for (size_t i = 0; i < drawings.size(); ++i) attach(*drawings[i]); redraw(); }
	void hide_menu() { shape_menu.hide(); menu_button.show(); }
};


#include "Chapter16Exercise4Def.cpp"

#endif