/*
	TITLE		   Drill 1						    Chapter15Drill1.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: 1. Create an empty 600 x 600 Window object, 
					  labeled "Function Graphs". 
				   2. Check FLTK installation details.
				   3. Include Graph.cpp and Window.cpp in the project.
				   4. Add x and y axis crossing at (300, 300), 
				      with length 400 and labeled  "1  == 20 pixels", 
					  with notch every 20 pixels.
				   5. Make both axes red.

				   // function plot
				   1. Plot the function double one(double x) { return 1; } 
				      in [-10:11] starting at (300, 300) using 400 points and no scaling.
				   2. Change it to use scaling: 20 for x and 20 for y.
				   3. Use same range, scale etc for rest of graphs.
				   4. Draw double slope (double x) { return x / 2; }
				   5. Add label above lower end of the slope function;
				   6. Draw double square (double x) { return x * x; }
				   7. Draw cosine.
				   8. Set cosine color to blue.
				   9. Write a function sloping_cos() and draw it.
		    Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>
#include "Simple_window.h"
#include "Graph.h"
#include "Point.h"

using namespace Graph_lib;

double one (double x) { return 1; }
double slope (double x) { return x / 2; }
double square (double x) { return x * x; }
double sloping_cos (double x) { return slope(x) + cos(x); }

int main()
{
	// Drill 1
	Point ul(50, 400);
	int width = 600;
	int height = 600;

	try
	{
		Simple_window w(ul, width, height, "Function Graphs");

		const int xoffset = 100;
		const int yoffset = 100;

		const int xspace = 100;
		const int yspace = 100;

		const int xlength = width - xspace - xoffset;
		const int ylength = height - yspace - yoffset;

		const int xnotches = 20;
		const int ynotches = 20;

		Point origin(width / 2., height / 2.);

		// Drill 2
		Axis x(Axis::x, Point(origin.x - xlength / 2, origin.y), xlength, xnotches, "1 == 20 pixels");
		Axis y(Axis::y, Point(origin.x, origin.y + ylength / 2.), ylength, ynotches, "1 == 20 pixels");

		// Drill 5
		x.set_color(Color::red);
		y.set_color(Color::red);

		w.attach(x);
		w.attach(y);

		// function plot
		// 1.
		const int lRange = -10;
		const int uRange = 11;
		Point start = origin;

		// 2. 
		const int xscale = 20;
		const int yscale = xscale;

		Function graph_one(one, lRange, uRange, start, 400, xscale, yscale);
		w.attach(graph_one);

		// 4.
		Function graph_slope(slope, lRange, uRange, start, 400, xscale, yscale);
		w.attach(graph_slope);

		// 5.
		const int label_vert_offset = 20;
		Text slope_label(Point(origin.x + (lRange * xscale),
			                   origin.y - (slope(lRange) * yscale) - label_vert_offset),
							   "x / 2");
		w.attach(slope_label);

		// 6. 
		Function graph_square(square, lRange, uRange, start, 400, xscale, yscale);
		w.attach(graph_square);

		// 7. 
		Function graph_cos(cos, lRange, uRange, start, 400, xscale, yscale);

		// 8.
		graph_cos.set_color(Color::blue);

		w.attach(graph_cos);

		// 9.
		Function graph_sloping_cos(sloping_cos, lRange, uRange, start, 400, xscale, yscale);
		w.attach(graph_sloping_cos);

		w.wait_for_button();
	}
	catch(...)
	{
		std::cerr <<"Exception!\n";
	}
}




