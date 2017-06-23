/*
	TITLE		   Bar Graph  					  Chapter15Exercise6.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Design and implement a bar graph with basic data `std::vector<double>`. 
				   Each value is represented by a "bar"'s height.
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>
#include <random>

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"

class Bar_Graph: public Shape
{
public:
	Bar_Graph(Point& o, double xs, double ys, std::vector<double>& v)
		: data(v), origin(o), x_scale(xs), y_scale(ys)
	{
	
	}

	void draw_lines() const;

private:
	std::vector<double> data;

	Point origin;
	double x_scale;
	double y_scale;
};

void Bar_Graph::draw_lines() const
{
	const int xoffset = 1;
	const int xspace = 1;

	const int yoffset = 1;

	for (int i = 0; i < data.size(); ++i)
	{
		if (color().visibility()) 
		{
			double width = x_scale - xspace;
			double height = data[i] * y_scale;

			fl_rect(origin.x + i * x_scale + xoffset,
				    origin.y - height + yoffset,
					width, height);
		}
	}
}

//------------------------------------------------------------------------------------------------

void generate_data(std::vector<double>& v, size_t size, double min, double max)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<> distr(min, max);

	for (size_t i = 0; i < size; ++i)
	{
		v.push_back(distr(eng));
		std::cout <<"value: "<< v[v.size() - 1] <<'\n';
	}
}
 
int main()
{
	try
	{
		 const int width = 600;
		 const int height = width;
		 Simple_window sw(Point(500, 0), width, height, "Chapter 15 Exercise 6");

		 Point origin (width / 2., height / 2.);

		 const int xoffset = 100;	
		 const int yoffset = 100;

		 const int xspace = 100;
		 const int yspace = 100;

		 const int xlength = width - xoffset - xspace;
		 const int ylength = height - yoffset - yspace;

		 std::vector<double> data_sample;

		 const int xscale = 10;
		 const int yscale = 40;

		 const int xnotches = xlength / xscale;
		 const int ynotches = ylength / yscale;

		 generate_data(data_sample, xnotches / 2, 0., ynotches / 2);

		 Axis x (Axis::x, Point(origin.x - xlength / 2., origin.y) , xlength, xnotches, "1 notch == i-th variable");
		 Axis y (Axis::y, Point(origin.x, origin.y + ylength / 2.), ylength, ynotches, "1 notch == 1 frequency number");

		 sw.attach(x);
		 sw.attach(y);

		 Bar_Graph bg(origin, xscale, yscale, data_sample);
		 sw.attach(bg);

		 sw.wait_for_button();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() <<'\n';
		getchar();
	}
}