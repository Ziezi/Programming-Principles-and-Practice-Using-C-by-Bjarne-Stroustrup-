/*
	TITLE		   Graph functions		          Chapter15Exercise4.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Plot sin(x), cos(x), their sum and the sum of their squares
				   on a single graph. Provide labels.
		    Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>
#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"

double sin_cos (double x) { return sin(x) + cos(x); }
double sin_cos_squared (double x) { return sin(x) * sin(x)  + cos(x) * cos(x); }

int main()
{
	try
	{
		 const int width = 600;
		 const int height = width;
		 Simple_window sw(Point(500, 0), width, height, "Chapter 15 Exercise 4");

		 // coordinate system
		 Point origin (width / 2., height / 2.);

		 const int xoffset = 100;	
		 const int yoffset = 100;

		 const int xspace = 100;
		 const int yspace = 100;

		 const int xlength = width - xoffset - xspace;
		 const int ylength = height - yoffset - yspace;

		 const int xnotches = 40;
		 const int ynotches = 40;

		 Axis x (Axis::x, Point(origin.x - xlength / 2., origin.y) , xlength, xnotches, "horizontal axis");
		 Axis y (Axis::y, Point(origin.x, origin.y + ylength / 2.), ylength, ynotches, "vertical axis");

		 sw.attach(x);
		 sw.attach(y);

		 //  graph
	     int start = - 50;
		 int end = 50;
		 int sample_points = 200;  
		 int fxscale = 20;
		 int fyscale = 20;

		 Function rf1(sin, start, end, origin, sample_points, fxscale, fyscale);
		 rf1.set_color(Color::red);
		 sw.attach(rf1);

		 Function rf2(cos, start, end, origin, sample_points, fxscale, fyscale);
		 rf2.set_color(Color::blue);
		 sw.attach(rf2);

		 Function rf3(sin_cos, start, end, origin, sample_points, fxscale, fyscale);
		 rf3.set_color(Color::green);
		 sw.attach(rf3);

		 Function rf4(sin_cos_squared, start, end, origin, sample_points, fxscale, fyscale);
		 rf4.set_color(Color::yellow);
		 sw.attach(rf4);

		 Text t1(Point(5, 15), "sin(x)");
		 t1.set_color(Color::red);
		 sw.attach(t1);

		 Text t2(Point(5, 35), "cos(x)");
		 t2.set_color(Color::blue);
		 sw.attach(t2);

		 Text t3(Point(5, 55), "sin(x) + cos(x)");
		 t3.set_color(Color::green);
		 sw.attach(t3);

		 Text t4(Point(5, 75), "sin(x)^2 + cos(x)^2");
		 t4.set_color(Color::yellow);
		 sw.attach(t4);

		 sw.wait_for_button();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() <<'\n';
		getchar();
	}
}