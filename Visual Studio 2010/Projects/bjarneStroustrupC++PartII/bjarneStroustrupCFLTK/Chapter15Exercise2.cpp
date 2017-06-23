/*
	TITLE		   Reset Class Data Members		  Chapter15Exercise2.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a class just like `Function`, 
				   but one that stores its constructor
				   arguments and allows reset of their value.  
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
	void reset_sample_size (int n) { sample = n; redraw_f(); }
	void reset_xscale (double xs) { xscale = xs; redraw_f(); }
	void reset_yscale (double ys ) { yscale = ys; redraw_f(); }

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
		 const int width = 600;
		 const int height = width;
		 Simple_window sw(Point(500, 0), width, height, "Chapter 15 Exercise 2");

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
		 int sample_points = 200;
		 int fxscale = 20;
		 int fyscale = 20;

		 Reset_function rf(&cos, start, end, origin, sample_points, fxscale, fyscale);
		 sw.attach(rf);
		 sw.wait_for_button();

		 rf.reset_function(square);
		 sw.wait_for_button();

		 rf.reset_xscale(fxscale * 2.);
		 sw.wait_for_button();

		 rf.reset_yscale(fxscale / 2.);
		 sw.wait_for_button();

		 rf.reset_origin(Point(origin.x + 20, origin.y + 20));
		 sw.wait_for_button();

		 rf.reset_interval(start + 40, end - 40); // no visible change !
		 sw.wait_for_button();

		 rf.reset_sample_size(sample_points/10.);
		 sw.wait_for_button();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() <<'\n';
		getchar();
	}
}