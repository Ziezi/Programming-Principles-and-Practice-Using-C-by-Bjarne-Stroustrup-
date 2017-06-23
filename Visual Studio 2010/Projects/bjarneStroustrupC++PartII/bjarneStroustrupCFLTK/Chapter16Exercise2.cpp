/*
	TITLE		   Checkerboard window			  Chapter16Exercise2.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define class based on Window 4 x 4 checkerboard of 
				   square buttons. When pressed a button persorms a simple
				   action: prints own coordinates, changes color, etc.
				   until other button is pushed.
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
		rect_00(Point(2, 2), (x_max() / 2) - 2, (y_max() / 2) - 2),
		text_01(Point(x_max() /  2 + 25, 25), "Upper Right Button is Pushed"),
		button_00(Point(0, 0), x_max() / 2, y_max() / 2, "00" , cb_00),
		button_01(Point(x_max() / 2, 0), x_max() / 2, y_max() / 2, "01" , cb_01),
		button_10(Point(0, y_max() /2), x_max() / 2, y_max() / 2, "10" , cb_10),
		button_11(Point(x_max() / 2, y_max() / 2), x_max() / 2, y_max() / 2, "11" , cb_11)
		 
	{
		rect_00.set_color(Color::red);
		rect_00.set_fill_color(Color::red);
		attach(rect_00);

		attach(button_00);
		attach(button_10);
		attach(button_01);
		attach(button_11);
	}

private:
	Graph_lib::Rectangle rect_00;
	Graph_lib::Text text_01;

	// widget
	Graph_lib::Button button_00;
	Graph_lib::Button button_01;
	Graph_lib::Button button_10;
	Graph_lib::Button button_11;

	// callback
	static void cb_00(Address, Address pw) { reference_to<My_window>(pw).pressed_00(); }
	static void cb_01(Address, Address pw) { reference_to<My_window>(pw).pressed_01(); }
	static void cb_10(Address, Address pw) { reference_to<My_window>(pw).pressed_10(); }
	static void cb_11(Address, Address pw) { reference_to<My_window>(pw).pressed_11(); }

	// action
	void pressed_00() { reset(); rect_00.set_color(Color::blue); rect_00.set_fill_color(Color::blue);}
	void pressed_01() { reset(); attach(text_01); }
	void pressed_10() { reset(); bethoven(); }
	void pressed_11() { reset(); }

	// helper
	void reset() 
	{
		rect_00.set_color(Color::red);
		rect_00.set_fill_color(Color::red);
		detach(text_01); 
		redraw(); 
	}

	void bethoven()
	{
		Beep(1568, 200);
		Beep(1568, 200);
		Beep(1568, 200);
		Beep(1245, 1000);
		Beep(1397, 200);
		Beep(1397, 200);
		Beep(1397, 200);
		Beep(1175, 1000);
	}
};

//-------------------------------------------------------------------------------------------------------
int main()
{
	try
	{
		const int width = 600;
		const int height = width;
		std::string title = "Chapter 16 Exercise 2";

		My_window sw(Point(500, 0), width, height, title);

		return gui_main();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() <<'\n';
		getchar();
	}
}