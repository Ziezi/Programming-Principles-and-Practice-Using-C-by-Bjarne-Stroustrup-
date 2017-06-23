/*
	TITLE			   Draw the Olympic Circles  	 Chapter12Exercise8.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Draw the Olympi Circles. // Should be semi - circles to overlap properly
				Input: -
			   Output: Graph on screen.
			   Author: Chris B. Kirov
			     Date: 17. 08. 2015
*/
#include <iostream>
#include "Simple_window.h"

int main()
{
	try
	{
		 // create a centered window
		 const int windowWidth = 800;
		 const int windowHeight = 600;
		 Point centerScreen(x_max() / 2.- windowWidth / 2., y_max() / 2. - windowHeight / 2.);
		 Simple_window sw(centerScreen, windowWidth, windowHeight, "Chapter 12 Exercise 8");

		 // create Olympic circles
		 const int frameSize = 20;
		 const int circleRadius = 100;
		 const int circleWidth = 10;

		 // black in the top middle
		 Graph_lib::Circle cBlack(Point(sw.x_max() / 2., 
			                            sw.y_max() / 2. - circleRadius), 
								  circleRadius);
		 cBlack.set_style(Line_style(Line_style::solid, circleWidth));
		 cBlack.set_color(Color::black);

		 // blue in the top left
		 Graph_lib::Circle cBlue(Point(sw.x_max() / 2. - 2 * circleRadius - frameSize, 
			                           sw.y_max() / 2. - circleRadius), 
								  circleRadius);
		 cBlue.set_style(Line_style(Line_style::solid, circleWidth));
		 cBlue.set_color(Color::blue);

		 // red in the top right
		 Graph_lib::Circle cRed(Point(sw.x_max() / 2. + 2 * circleRadius + frameSize, 
			                          sw.y_max() / 2. - circleRadius), 
								  circleRadius);
		 cRed.set_style(Line_style(Line_style::solid, circleWidth));
		 cRed.set_color(Color::red);

		 // yellow in the bottom left
		 Graph_lib::Circle cYellor(Point(sw.x_max() / 2. - circleRadius - frameSize / 2., 
			                             sw.y_max() / 2.), 
								  circleRadius);
		 cYellor.set_style(Line_style(Line_style::solid, circleWidth));
		 cYellor.set_color(Color::yellow);

		 // greem in the bottom right
		 Graph_lib::Circle cGreen(Point(sw.x_max() / 2. + circleRadius + frameSize / 2., 
			                             sw.y_max() / 2.), 
								  circleRadius);
		 cGreen.set_style(Line_style(Line_style::solid, circleWidth));
		 cGreen.set_color(Color::green);
		
		 // right overlapping
		 sw.attach(cBlack);
		 sw.attach(cBlue);
		 sw.attach(cRed);
		 sw.attach(cYellor);
		 sw.attach(cGreen);

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
