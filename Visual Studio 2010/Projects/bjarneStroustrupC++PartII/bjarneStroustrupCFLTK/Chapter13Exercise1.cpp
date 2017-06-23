/*
	TITLE		   Define class Arc    Chapter13Exercise1.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a class Arc which draws a part of an ellipse.
		           Use fltk library member: fl_arc().
		    Input: -
		   Output: 
		   Author: 10.09.2015
		     Date: Chris B. Kirov
*/

#include "GUI.h"
#include "Simple_window.h"
#include <iostream>

namespace Graph_lib
{
bool validInput(int, int);

class Arc: public Ellipse
{
public:
	Arc(Point center, int w, int h, double s, double e)
		: Ellipse(Point(center.x, center.y), w, h), start(s), end(e), height(h), width(w) 
	{ 
		if (!validInput(w,h))
		{
			std:cerr <<"Invalid input";
		}	
	}

	void draw_lines() const;
	
private:
  // starting at endging angle of the arc: start from 3'oclock counterclockwise
  double start;
  double end;
  int height;
  int width;
};

//---------------------------------------------------------------------------------------
// NOT PART OF THE EXERCISE
// function that draws 4 Arcs
// Helper function
void draw4Arcs(Simple_window* w, Point center, int width, int height)
{
	vector<Arc*> arcs;
	for(size_t i = 0; i < 4; ++i)
	{
		int start = 90 * i;
		int end = 90 * (i+1);
		arcs.emplace_back(new Arc(center, width, height, start, end));
		w->attach(*arcs[i]);
	}
	// MEMORY LEAK!
	//for(size_t i = 0; i < arcs.size(); ++i) delete arcs[i];
}

vector<Arc*> draw4Arcs1(Point center, int width, int height)
{
	vector<Arc*> arcs;
	for(size_t i = 0; i < 4; ++i)
	{
		int start = 90 * i;
		int end = 90 * (i+1);
		arcs.emplace_back(new Arc(center, width, height, start, end));
	}
	return arcs;
}
//------------------------------------------------------------------------------------------
} // end of namespace Graph_lib 

//-----------------------------------------------------------------------------------------------------------------------

int main()
{
	 // window parameters
	 int winWidth = 800;
	 int winHeight = 700;
	 Point center((x_max() - winWidth) / 2., (y_max() - winHeight) / 2.);
	 Simple_window* sw = new Simple_window(center, winWidth, winHeight, "Chapter 13 Exercise 1");

	 // ellipse segment parameters
	 int xCoord = sw->x_max() / 2.;
	 int yCoord = sw->y_max() / 2.;
	 int width = 200;
	 int height = 100;
	 double startAngle = 0;
	 double endAngle = 90;

	try{
		// test center point of Arc. i.e. ellipse by encircling it in a rectangle
		Graph_lib::Rectangle rect(Point(xCoord - width, yCoord- height ), width, height);
		sw->attach(rect);

		// test Arc
		int x = 400;
		int y = 200;
		Graph_lib::Arc arc1(Point(x, y), width, height, startAngle, endAngle);
		arc1.set_color(Color::red);
		sw->attach(arc1);

		Graph_lib::Arc arc2(Point(x, y), width, height, 90, 180);
		arc2.set_color(Color::blue);
		sw->attach(arc2);

		Graph_lib::Arc arc3(Point(x, y), width, height, 180, 270);
		arc3.set_color(Color::green);
		sw->attach(arc3);

		Graph_lib::Arc arc4(Point(x, y), width, height, 270, 360);
		arc4.set_color(Color::magenta);
		sw->attach(arc4);

		// test function draw4Arcs; MEMORY LEAK!
		Graph_lib::Arc arc11(Point(xCoord, yCoord), width, height, startAngle, endAngle);
		draw4Arcs(sw, Point(xCoord, yCoord), width, height);

		// test function draw4Arcs1
		vector<Graph_lib::Arc*> ar = draw4Arcs1(Point(xCoord, yCoord+ 200), width, height);
		for(size_t i = 0; i < ar.size(); i++) sw->attach(*ar[i]);
		 
		sw->wait_for_button();
		for(size_t i = 0; i < ar.size(); i++) delete ar[i]; 

	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	catch(...)
	{
		std::cerr <<"Default exception!"<< std::endl;
		getchar();
	}
	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------

namespace Graph_lib
{

// Helper function
bool validInput(int w, int h)
{
	if (w < 0 || h < 0)
	{
		return false;
	}
	else 
	{
		return true;
	}
}

// Member function
void Arc::draw_lines() const
{
	if(color().visibility())
	{
		fl_arc (point(0).x, point(0).y, major(), minor(), start, end);
	}
}

} // end of namespace Graph_lib 

