/*
	TITLE		   Read a data file, scale and plot  Chapter15Exercise9.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Read a data file containig heights in inches, scale it
		           and represent it graphically.
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>    

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"

class Bar_Graph: public Shape
{
public:
	Bar_Graph(Point& o, double xs, double ys, std::vector<double>& v, std::vector<std::string>& l, Graph_lib::Color c)
		: data(v), origin(o), x_scale(xs), y_scale(ys), bar_color(c.as_int())
	{
		if (v.size() != l.size() - 1) // labels contain: graph headline at index 0 and all individual bar labels
		{
			throw std::invalid_argument("Bar_Graph::constructor: labels - data size mismatch!\n");
		}

		// store headline
		const int ylenght = y_scale * (*std::max_element(data.begin(), data.end())) * 3/2;

		labels.emplace_back(new Text(Point(origin.x, origin.y - ylenght), l[0]));

		// store individual labeles
		const int xoffset = 1;
		const int yoffset = 15;
		
		for (int i = 1; i < l.size(); ++i)
		{
			labels.emplace_back(new Text(Point(origin.x + (i - 1) * x_scale, origin.y + i * yoffset), l[i]));
		}
	}

	void draw_lines() const;

private:
	std::vector<double> data;
	std::vector<Text*> labels;
	Fl_Color bar_color;

	Point origin;
	double x_scale;
	double y_scale;
};

void Bar_Graph::draw_lines() const
{
	// draw bar graph headline
	labels[0]->draw();

	const int xoffset = 1;
	const int xspace = 1;

	const int yoffset = 1;

	for (int i = 0; i < data.size(); ++i)
	{
		if (color().visibility()) 
		{
			double width = x_scale - xspace;
			double height = data[i] * y_scale;
			 
			// draw colored rectangles
			fl_rectf(origin.x + i * x_scale + xoffset,
				     origin.y - height + yoffset,
					 width, height, bar_color);

			// reset color to black 
			fl_color(fill_color().as_int()); 

			// draw rectangle outline
			fl_rect(origin.x + i * x_scale + xoffset,
				    origin.y - height + yoffset,
					width, height);

			// draw individual labels
			labels[i + 1]->draw();
		}
	}
}

//------------------------------------------------------------------------------------------------
struct Data
{
	Data (double h, int f)
		: height(h), frequency(f)
	{
	
	}

	double height;
	int frequency;
};

class Convert
{
public:
	 Convert(double r)
		 : rate(r)
	 {
	 
	 }

	 double operator() (double input) { return rate * input;}
private:
	 
	double rate;
};

void read_file(std::string& file_name, std::vector<Data>& v)
{
	std::ifstream ifs(file_name.c_str());

	if (!ifs)
	{
		throw std::runtime_error("Read_file: can't open file: " + file_name);
	}

	std::string line;

	while (getline(ifs, line))
	{
		std::stringstream ss(line);

		char p1, c, p2;
		double h;
		int f;

		if (ss >> p1 >> h >> c >> f >> p2)
		{
			if (p1 != '(' || c != ',' || p2 != ')')
			{
				throw std::runtime_error("Read_file: wrong input format!");
			}
			else
			{
				v.emplace_back(Data(h, f));
			}
		}
		else	
		{
			throw std::runtime_error("Read_file: input file stream error!");
		}
	}
}
 
void get_labels(std::vector<std::string>& l, std::vector<Data>& data)
{
	l.emplace_back("Height bar graph");

	for (size_t i = 0; i < data.size(); ++i)
	{
		std::stringstream ss;

		double inch_to_cm = 2.54;
		Convert cv(inch_to_cm); // convert input data from inch to cm
		double in_cm = ceil(cv(data[i].height));

		ss << in_cm;

		l.emplace_back(ss.str());
	}
}

void get_frequencies(std::vector<double>& v, std::vector<Data>& data)
{
	for (size_t i = 0; i < data.size(); ++i)
	{
		v.emplace_back(data[i].frequency);
	}
}
//------------------------------------------------------------------------------------------------

int main()
{
	try
	{
		 // read file and extract data
		 std::vector<Data> data;
		 std::string file_name("Chapter15Exercise9.txt");

		 read_file(file_name, data);

		 std::vector<double> data_sample;
		 std::vector<std::string> labels;

		 get_frequencies(data_sample, data);
		 get_labels(labels, data);

		 // graphical part
		 const int width = 600;
		 const int height = width;
		 Simple_window sw(Point(500, 0), width, height, "Chapter 15 Exercise 9");

		 Point origin (width / 2., height / 2.);

		 const int xoffset = 100;	
		 const int yoffset = 100;

		 const int xspace = 100;
		 const int yspace = 100;

		 const int xlength = width - xoffset - xspace;
		 const int ylength = height - yoffset - yspace;

		 // the factor 2 is due to the negative parts of the axis
		 const int xscale = xlength / (data_sample.size() * 2);
		 const int yscale = ylength / (*std::max_element(data_sample.begin(), data_sample.end()) * 2);

		 const int xnotches = data_sample.size() * 2;
		 const int ynotches = (*std::max_element(data_sample.begin(), data_sample.end())  + 2) * 2; // 25 notches in the positive direction

		 Axis x (Axis::x, Point(origin.x - xlength / 2., origin.y) , xlength, xnotches, "Height [cm]");
		 Axis y (Axis::y, Point(origin.x, origin.y + ylength / 2.), ylength, ynotches, "Amount [people]");

		 Bar_Graph bg(origin, xscale, yscale, data_sample, labels, Color::blue);
		 sw.attach(bg);

		 sw.attach(x);
		 sw.attach(y);

		 sw.wait_for_button();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() <<'\n';
		getchar();
	}
}