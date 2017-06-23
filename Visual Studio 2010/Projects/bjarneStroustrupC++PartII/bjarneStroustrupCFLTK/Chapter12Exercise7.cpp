/*
	TITLE			   Draw a house  	        Chapter12Exercise7.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Draw a 2D house from the front:
					   door, windows, roof, chimney, etc. 
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
		 // create a centred window
		 const int windowWidth = 800;
		 const int windowHeight = 600;
		 Point centerScreen(x_max() / 2.- windowWidth / 2., y_max() / 2. - windowHeight / 2.);
		 Simple_window sw(centerScreen, windowWidth, windowHeight, "Chapter 12 Exercise 7");

		 // create green grass in the bottom
		 const int frameSize = 1;
		 const int grassWidth = windowWidth - frameSize;
		 const int grassHeight = 200;
		 Graph_lib::Rectangle grass(Point(frameSize, sw.y_max() - grassHeight + frameSize), grassWidth, grassHeight);
		 grass.set_fill_color(Color::green);
		 grass.set_style(Line_style::dot);
		 sw.attach(grass);

		 // create a sun in the top right 
		 const int radius = 50;
		 Graph_lib::Circle sun(Point(50 + frameSize, 50 + frameSize), radius);

		 // it doesn't honour the fill colour statement???
		 sun.set_fill_color(Color::yellow);
		 sun.set_style(Line_style::dashdotdot);
		 sw.attach(sun);

		 // create a house
		 const int houseWidth = 300;
		 const int houseHeight = 250;
		 Graph_lib::Rectangle house(Point(sw.x_max() / 2. - houseWidth / 2. ,
			                              sw.y_max() - (grassHeight + houseHeight)),
									houseWidth,
									houseHeight);
		 house.set_style(Line_style(Line_style::solid, 2));
		 sw.attach(house);

		 // create roof
		 const int roofHeight = 100;
		 const int roofWidth = 100;
		 Graph_lib::Polygon roof;
		 roof.add(Point(sw.x_max() / 2.,
			            sw.y_max() - (grassHeight + houseHeight + roofHeight)));
		 roof.add(Point((sw.x_max()/ 2.) + ((houseWidth + roofWidth) / 2.),
			             sw.y_max() - (grassHeight + houseHeight)));
		 roof.add(Point((sw.x_max()/ 2.) - ((houseWidth + roofWidth) / 2.),
			             sw.y_max() - (grassHeight + houseHeight)));
		 roof.set_fill_color(Color::red);
		 sw.attach(roof);

		 // create chimney
		 const int chWidth = 30;
		 const int chHeight = 50;
		 Graph_lib::Open_polyline chimney;
		 chimney.add(Point(sw.x_max() / 2. - chWidth,
			               sw.y_max() - (grassHeight + houseHeight + (roofHeight / 2.))));
		 chimney.add(Point(sw.x_max() / 2. - chWidth,
			               sw.y_max() - (grassHeight + houseHeight + (roofHeight / 2.)) - chHeight));
		 chimney.add(Point(sw.x_max() / 2.,
			               sw.y_max() - (grassHeight + houseHeight + (roofHeight / 2.)) - chHeight));
		 chimney.add(Point(sw.x_max() / 2.,
			               sw.y_max() - (grassHeight + houseHeight + (roofHeight / 2.))));
		 chimney.move(-50,0);
		 chimney.set_style(Line_style(Line_style::solid, 2));
		 chimney.set_fill_color(Color::dark_red);
		 sw.attach(chimney);

		 // create door
		 const int doorWidth = 100;
		 const int doorHeight = 200;
		 Graph_lib::Rectangle door(Point(sw.x_max() / 2. ,
			                             sw.y_max() - (grassHeight + doorHeight)),
								   doorWidth, 
								   doorHeight);
		 door.set_style(Line_style(Line_style::solid, 4));
		 door.set_fill_color(Color::invisible);
		 sw.attach(door);

		 // door handle
		 const int doorHandleRadius = 5;
		 Graph_lib::Circle doorHandle(Point(sw.x_max() / 2. + 5*frameSize,
			                                sw.y_max() - (grassHeight + (doorHeight / 2.))),
									  doorHandleRadius);

		 // it doesn't honour the fill colour statement???
		 sun.set_fill_color(Color::black);
		 sw.attach(doorHandle);

		 // create a window 
		 const int hwinWidth = 100;
		 const int hwinHeight = 100;
		 Graph_lib::Rectangle hwin(Point(sw.x_max() / 2. - hwinWidth * 1.25,
			                             sw.y_max() - (grassHeight + ((houseHeight + hwinHeight) / 2.))),
								   hwinWidth,
								   hwinHeight);
		 hwin.set_style(Line_style(Line_style::solid, 4));
		 hwin.set_fill_color(Color::invisible);
		 sw.attach(hwin);

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
