/*
	TITLE		   Implement code from 16.5§		  Chapter16Drill.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Write line - drawing program with GUI.
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/

#ifndef _Chapter16Drill_h_
#define _Chapter16Drill_h_

struct Lines_window: Window
{
	Lines_window(Point o, int w, int h, const std::string& t);

private:
	Graph_lib::Open_polyline lines;
	
	// widget
	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;
	Out_box xy_out;

	Menu color_menu;
	Button menu_button;

	Menu style_menu;
	Button style_button;

	// callback
	static void cb_next(Address, Address);
	static void cb_quit(Address, Address);

	static void cb_red(Address, Address);
	static void cb_blue(Address, Address);
	static void cb_black(Address, Address);
	static void cb_menu(Address, Address);

	static void cb_solid(Address, Address);
	static void cb_dash(Address, Address);
	static void cb_dot(Address, Address);
	static void cb_style(Address, Address);

	// action
	void next();
	void quit();

	void red_pressed() { change(Color::red); hide_menu(); }
	void blue_pressed() { change(Color::blue); hide_menu(); }
	void black_pressed() { change(Color::black); hide_menu(); }
	void menu_pressed() { menu_button.hide(); color_menu.show(); }

	void solid_pressed() { change_style(Line_style::Line_style_type::solid); hide_style(); };
	void dash_pressed() { change_style(Line_style::Line_style_type::dash); hide_style();};
	void dot_pressed() { change_style(Line_style::Line_style_type::dot); hide_style();};
	void style_pressed() { style_button.hide(); style_menu.show(); }

	// helper
	void change (Color c) { lines.set_color(c); }
	void change_style(Line_style::Line_style_type s) { lines.set_style(s); }
	void hide_menu() { color_menu.hide(); menu_button.show(); }
	void hide_style() { style_menu.hide(); style_button.show(); }
};

#include "Chapter16DrillDef.cpp"

#endif