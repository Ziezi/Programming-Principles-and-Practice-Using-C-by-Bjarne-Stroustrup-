/*
	TITLE		   Liebniz Series		          Chapter15Exercise5.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Animate the Liebniz series: 1 - 1/3 + 1/5 - 1/7 + 1/9 -> pi /4 
		    Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"
 


double i_th_term(int i)
{
	double value  = 1. / (1. + 2. * i);

	return (i % 2 != 0) ? -value : value;
}

double Liebniz_series(int terms)
{
	double sum = 0;
	for (int i  = 0; i < terms; ++i)
	{
		sum += i_th_term(i);
	}
	return sum;
}

double pi_4 (double x) { return M_PI / 4.; } 
//------------------------------------------------------------------------------------------

int main()
{
	try
	{
		 const int width = 600;
		 const int height = width;
		 Simple_window sw(Point(500, 0), width, height, "Chapter 15 Exercise 5");

		 // coordinate system
		 Point origin (width / 2., height / 2.);

		 const int xoffset = 100;	
		 const int yoffset = 100;

		 const int xspace = 100;
		 const int yspace = 100;

		 const int xlength = width - xoffset - xspace;
		 const int ylength = height - yoffset - yspace;

		 const int xscale = 10;
		 const int yscale = 50;

		 const int xnotches = xlength / xscale;
		 const int ynotches = ylength / yscale;

		 Axis x (Axis::x, Point(origin.x - xlength / 2., origin.y) , xlength, xnotches, "1 notch == i-th term");
		 Axis y (Axis::y, Point(origin.x, origin.y + ylength / 2.), ylength, ynotches, "1 notch == 1");

		 sw.attach(x);
		 sw.attach(y);

		 Graph_lib::Function pi_over_4(pi_4, -20, 20, origin, 100, xscale, yscale);
		 pi_over_4.set_color(Color::red);
		 sw.attach(pi_over_4);

		 Text l(Point(5, width / 2. - (yscale * M_PI / 4.)), "pi / 4 = 0.78");
		 l.set_color(Color::red);
		 sw.attach(l);

		 std::vector<Graph_lib::Mark*> approximation;

		 int precision = 20;
		 int number_of_terms = precision;

		 for (int i = 0; i < number_of_terms; ++i)
		 {
			double x = origin.x + i * xscale;
			double y = origin.y - Liebniz_series(i) * yscale;
			Point p(x, y);

			std::cout <<"pi/4 -> "<< M_PI / 4. <<" Approximate Value of pi/4: "<< Liebniz_series(i) <<'\n';

			approximation.emplace_back(new Mark(p, 'x'));
			approximation[approximation.size() - 1]->set_color(Color::blue);
		 }

		 for (int i = 0; i < number_of_terms; ++i)
		 {
			 sw.attach(*approximation[i]);
		 }

		 sw.wait_for_button();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() <<'\n';
		getchar();
	}
}