/*
	TITLE			   Frame around rectangle	 Chapter12Exercise5.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Draw a 1/4-inch frame around a rectangle
					   with size 3/4 the height of the screen
					   and 2/3 the width.
				Input: -
			   Output: Graph on screen.
			   Author: Chris B. Kirov
			     Date: 17. 08. 2015
*/
#include "std_lib_facilities.h"
#include <iostream>
#include "Simple_window.h"
#include "Chapter12Exercise5.h"

int main()
{
	try
	{
		// use the object to obtain x_max() and y_max()
		Simple_window sw(Point(0,0), 100, 100, "test");

		// instantiate an object via default constructor
		framedBox defaultfb;

		// box parameters
		Point ul(x_max()/2., y_max()/2.);

		// use GUI member functions to find screen width and height
		int width = (2 / 3.) * sw.x_max();
		int height = (3 / 4.) * sw.y_max();

		// figure out the width of a pixel in inches from: http://auctionrepair.com/pixels.html
		// My current laptop has a resolution of: 92 DPI (Dots per inch)

		// Inches = Pixels / DPI => Pixels = 1/4 * DPI => 1/4 * 92 = 23 Pixels
		// i.e. 1/4 inches is 23 pixels
		int frame = 23;

		framedBox fb(ul, width, height, frame, Color::green, Color::dark_yellow);
		fb.drawFramedBox();
	}
	catch(exception& e)
	{
		cerr << e.what() << endl;
	}
	catch(...)
	{
		cerr <<"Default exception!"<< endl;
	}
}
