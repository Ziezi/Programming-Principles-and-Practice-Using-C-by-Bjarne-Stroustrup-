/*
	TITLE		   Cirlce drawing		        Chapter13Exercise12.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Draw a circle
		           move a Mark around on the circle
				   on every "Next" button click.
			Input: -
		   Output: !!!window description not printed after the first click!!!
		   Author: 20.09.2015
		     Date: Chris B. Kirov
*/
#include "GUI.h"
#include "Simple_window.h"
#include <iostream>

#define PI 3.14159

int main()
{
	 // window parameters
	 int winWidth = 800;
	 int winHeight = 600;
	 Point centerPoint((x_max() - winWidth) / 2, (y_max() - winHeight) / 2);

	 Simple_window* siw = new Simple_window(centerPoint, winWidth, winHeight, "Chapter 13 Exercise 12");

	 try
	 {
         // cirle parameters
		 int radius = 100;
		 int x = (siw->x_max() - radius)/2;
		 int y = (siw->y_max() - radius)/2;
	     
		 // mark parameters
		 double step = 0;
		 int clicks = 10;

		 for (size_t i = 0; i < clicks; ++i)
		 {
            step += 5 * clicks;

			// perform a rotation of the coordinates of the Mark
			double angle = step * PI / 180.;
		    int xMark = radius * cos(angle) + x;
		    int yMark = radius * sin(angle) + y;

			Simple_window* siw = new Simple_window(centerPoint, winWidth, winHeight, "Chapter 13 Exercise 12");

			Graph_lib::Circle circle(Point(x, y), radius);
			siw->attach(circle);

			Graph_lib::Mark m(Point(xMark, yMark), 'x');

			m.set_color(Color::red);
			siw->attach(m);

			siw->wait_for_button();
		 }

		 siw->wait_for_button();
	 }
	 catch(std::exception& e)
	 {
		std::cerr << e.what() << std::endl;
	 }
	 catch(...)
	 {
		std::cerr <<"Defaul exception!"<< std::endl;
	 }
}