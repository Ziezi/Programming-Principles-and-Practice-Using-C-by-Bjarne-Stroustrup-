/*
	TITLE		   Read a data file, scale and plot  Chapter15Exercise9.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Read a data file containig mean maximum temperatures
		           for each month of the year, for two locations and
				   plot them together.
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

//------------------------------------------------------------------------------------------------
struct Data
{
	Data (std::string& m, double t1, double t2)
		: month(m), temp1(t1), temp2(t2)
	{
	
	}

	std::string month;
	double temp1;
	double temp2;
};

class Scale
{
public:
	Scale(double ob, double db, double sc)
		: origin_base(ob), data_base(db), scale(sc)
	{
	
	}

	// convert raw to scaled data
	double operator() (double input) { return origin_base + (input - data_base) * scale; }

private:
	double origin_base; // coordinate system origin 
	double data_base;   // min value of sample
	double scale;       // axis scale factor
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

		char p1, c1, c2, p2;
		std::string m;
		double t1, t2;

		if (ss >> p1 >> m >> c1 >> t1 >> c2 >> t2 >> p2)
		{
			if (p1 != '(' || c1 != ',' || c2 != ',' || p2 != ')')
			{
				throw std::runtime_error("Read_file: wrong input format!");
			}
			else
			{
				v.emplace_back(Data(m, t1, t2));
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
	for (size_t i = 0; i < data.size(); ++i)
	{
		std::stringstream ss;
		ss <<  data[i].month;

		l.emplace_back(ss.str());
	}
}

void get_temperature(std::vector<double>& t1, std::vector<double>& t2, std::vector<Data>& data)
{
	for (size_t i = 0; i < data.size(); ++i)
	{
		t1.emplace_back(data[i].temp1);
		t2.emplace_back(data[i].temp2);
	}
}
//------------------------------------------------------------------------------------------------

int main()
{
	try
	{
		 // read file and extract data
		 std::vector<Data> data;
		 std::string file_name("Chapter15Exercise11.txt");

		 read_file(file_name, data);

		 std::vector<double> temp1;
		 std::vector<double> temp2;
		 std::vector<std::string> labels;

		 get_temperature(temp1, temp2, data);
		 get_labels(labels, data);

		 // graphical part
		 const int width = 600;
		 const int height = width;
		 Simple_window sw(Point(500, 0), width, height, "Chapter 15 Exercise 11");

		 
		 // coordinate system
		 const int xoffset = 100;	
		 const int yoffset = 100;

		 const int xspace = 100;
		 const int yspace = 100;

		 const int xlength = width - xoffset - xspace;
		 const int ylength = height - yoffset - yspace;

		 Point origin (width / 2. - xlength / 2., height / 2. + ylength / 2.7);

		 const int xscale = xlength / (temp1.size());
		 const int yscale = ylength / (*std::max_element(temp2.begin(), temp2.end()));

		 const int xnotches = temp1.size();
		 const int ynotches = *std::max_element(temp2.begin(), temp2.end()); 

		 Axis x (Axis::x, Point(origin.x, origin.y), xlength, xnotches, "                                                                                               Months");
		 Axis y (Axis::y, Point(origin.x, origin.y), ylength, ynotches, "Temperature [Celsius]");

		 sw.attach(x);
		 sw.attach(y);

		 Graph_lib::Open_polyline sliven, serres;
		 std::vector<Text*> xlabels;

		 Scale sx(origin.x, 0, xscale);
		 Scale sy(origin.y, 0, yscale);
		 
		 for (size_t i = 0; i < temp1.size(); ++i)
		 {
			    double slx = sx(i);
				double sly = sy(-temp1[i]); 
				sliven.add(Point(slx, sly));

				double sey = sy(-temp2[i]);
				serres.add(Point(slx, sey));

				xlabels.emplace_back(new Text(Point(slx, sy(0) + (i + 1) * 12), labels[i]));
				sw.attach(*xlabels[i]);
		 }

		 sliven.set_color(Color::blue);
		 sw.attach(sliven);

		 serres.set_color(Color::red);
		 sw.attach(serres);

		 sw.wait_for_button();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() <<'\n';
		getchar();
	}
}