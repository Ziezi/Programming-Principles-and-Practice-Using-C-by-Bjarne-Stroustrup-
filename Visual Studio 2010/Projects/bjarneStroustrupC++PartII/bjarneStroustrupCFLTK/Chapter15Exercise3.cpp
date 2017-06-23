/*
	TITLE		   Reset Class Data Members		  Chapter15Exercise3.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Add new constructor argument that controls precision.
		    Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>
#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"

class Reset_function: public Graph_lib::Function
{
public:
	Reset_function(Graph_lib::Fct f, double s, double e, Point o, int samp, double xs, double ys)
		: function(f), start(s), end(e), origin(o), sample(samp), xscale(xs), yscale(ys),
		Graph_lib::Function(f, s, e, o, samp, xs, ys)
	{

	}

	void reset_function(Graph_lib::Fct* f) { function = f; redraw_f(); }
	void reset_interval (double s, double e) { start = s; end = e; redraw_f(); }
	void reset_origin (Point o) { origin = o; redraw_f(); }
	void reset_sample_size (unsigned int n) { sample = n; redraw_f(); }
	void reset_xscale (double xs) { xscale = xs; redraw_f(); }
	void reset_yscale (double ys ) { yscale = ys; redraw_f(); }

	void reset_precision (unsigned int n) { sample = n; redraw_f(); } 

private:

	Graph_lib::Fct* function;
	double start;
	double end;
	Point origin;
	int sample;
	double xscale;
	double yscale;

	void draw_f();
	void redraw_f();
};

void Reset_function::draw_f()
{
	if (end - start <= 0)
	{
		throw std::invalid_argument("Reset_function::draw_f(): bad graphing range!\n");
	}
		
    if (sample <= 0) 
	{
		throw std::invalid_argument("Reset_function::draw_f(): sample doesn't contain any points!\n");
	}	
		 
    double dist = (end - start) / sample;

    double r = start;

    for (int i = 0; i < sample; ++i)
	{
        add(Point(origin.x + int(r * xscale), origin.y - int(function(r) * yscale)));
        r += dist;
	}
}

void Reset_function::redraw_f()
{
	// erase current drawing
	Graph_lib::Shape::clear_points();

	// create new coordinates and draw a function out of them
	draw_f();
}
//------------------------------------------------------------------------------------------------------------------

double square (double x) { return x * x; }

int main()
{
	try
	{
		 // 10 - 20 points shows edges, > 200 shows relatively smooth graph
		 const int PRECISION = 100; // number of sample points

		 const int width = 600;
		 const int height = width;
		 Simple_window sw(Point(500, 0), width, height, "Chapter 15 Exercise 3");

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

		 // class test
	     int start = - 50;
		 int end = 50;
		 int sample_points = PRECISION; // <------------------------------------------------------------
		 int fxscale = 20;
		 int fyscale = 20;

		 Reset_function rf(&cos, start, end, origin, sample_points, fxscale, fyscale);
		 sw.attach(rf);
		 sw.wait_for_button();

		 rf.reset_precision(sample_points / 10.);
		 sw.wait_for_button();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() <<'\n';
		getchar();
	}
}