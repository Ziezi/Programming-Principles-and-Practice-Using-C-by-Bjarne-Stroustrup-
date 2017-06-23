/*
	TITLE			   Manipulate and image  	Chapter12Exercise9.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Insert an image and
					   label it with a title on the window and
					   a caption in the window.
			    Input: -
			   Output: Graph on screen.
			   Author: Chris B. Kirov
			     Date: 31. 08. 2015
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
		 Simple_window sw(centerScreen, windowWidth, windowHeight, "Chapter 12 Exercise 9: Image of a Bulgarian medieval Fortress.");

		 // insert an image
		 const int frameSizeX = 1;
		 const int frameSizeY = 35;
		 Image im(Point(frameSizeX, frameSizeY), "prof_pic.jpg"); 
		 sw.attach(im);

		 // create a caption for the image
		 // text
		 const int textWidth = 200;
		 const int textHeight = 10;
		 Text imageCaption(Point(sw.x_max() - textWidth, sw.y_max() - textHeight), "Veliko Tarnovska Krepost");
		 sw.attach(imageCaption);

		 // box to encircle the text
		 const int boxWidth = 20;
		 const int boxHeight = 20;
		 Graph_lib::Rectangle box(Point(sw.x_max() - textWidth - frameSizeX,
			                            sw.y_max() - textHeight - frameSizeX - boxHeight),
			                            textWidth - boxWidth,
										textHeight + boxHeight);
		 box.set_fill_color(Color::invisible);

		 sw.attach(box);
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
