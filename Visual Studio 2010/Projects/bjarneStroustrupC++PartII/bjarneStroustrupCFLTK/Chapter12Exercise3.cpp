/*
	TITLE			   Text				        Chapter12Exercise3.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Draw text and manipulate its properties.
				Input: -
			   Output: C.B.K (in different color)
			   Author: Chris B. Kirov
			     Date: 30. 08. 2015
*/
#include <iostream>
#include "Simple_window.h"

int main()
{
	try
	{
		// create a window in the center of the screen wiht size: 600x600
		const int wWidth = 600;
		const int wHeight = 600;
		Point centerScreen(x_max() / 2 - wWidth / 2, y_max() / 2 - wHeight / 2);
		Simple_window sw(centerScreen, wWidth, wHeight, "Chapter 12 Exercise 3");

		// create a text 
		int textFontSize = 150;

		int t1Translation = 200;
		Text tex1(Point(sw.x_max() / 2 - t1Translation, sw.y_max() / 2), "C.");
		tex1.set_font_size(textFontSize);
		tex1.set_color(Color::blue);
		sw.attach(tex1);

		// create a text 
		int t2Translation = 50;
		Text tex2(Point(sw.x_max() / 2 - t2Translation, sw.y_max() / 2), "B.");
		tex2.set_font_size(textFontSize);
		tex2.set_color(Color::dark_blue);
		sw.attach(tex2);

		// create a text 
		int t3Translation = 100;
		Text tex3(Point(sw.x_max() / 2 + t3Translation, sw.y_max() / 2), "K.");
		tex3.set_font_size(textFontSize);
		tex3.set_color(Color::dark_cyan);
		sw.attach(tex3);

		sw.wait_for_button();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(...)
	{
		std::cerr <<"Default exception!"<< std::endl;
	}
}
