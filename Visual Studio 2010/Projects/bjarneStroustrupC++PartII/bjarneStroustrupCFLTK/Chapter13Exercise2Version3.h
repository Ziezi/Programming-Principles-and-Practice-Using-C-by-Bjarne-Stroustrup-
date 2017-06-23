/*
	TITLE		   Rounded box			    Chapter13Exercise2Version3.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a class Box which draws four lines and four arcs.
		           Draw a rounded box.
				   Superellipse could be used as well!
		    Input: -
		   Output: 
		   Author: 18.09.2015
		     Date: Chris B. Kirov
*/
#include "GUI.h"
#include "Simple_window.h"
#include <iostream>

namespace Graph_lib{
// class Arc
bool validInput(int w, int h);
class Arc: public Ellipse{
public:
	Arc(Point p, int w, int h, double s, double e) : Ellipse(Point(p.x, p.y), w, h), start(s), end(e) 
	{ if (!validInput(w,h)) error("Invalid input Arc"); }
	
	void draw_lines() const;
protected:
	Arc();
private:
  // starting and ending angle of the arc: start from 3'oclock counterclockwise
  double start;
  double end;
};

// Member function
void Arc::draw_lines() const{
	if(color().visibility()) fl_arc(point(0).x, point(0).y, major() , minor() , start, end);
}

// Class RoundedBox
class RoundedBox: public Closed_polyline{
public:
	RoundedBox(Point ul, Point dr);
	RoundedBox(Point ul, int w, int h);

	void draw_lines() const;

private:
	Point upperLeft;
	int width;
	int height;
	// roundedness of the box 
	// should be changed together with Arc center, major and minor axes
	int roundWidth;
	int roundHeight;
};

// Class member implementations
RoundedBox::RoundedBox(Point ul, Point dr)
	: upperLeft(ul), width(abs(ul.x - dr.x)), height(abs(ul.y - dr.y)), 
	  roundWidth(abs(ul.x - dr.x) / 4), roundHeight(abs(ul.y - dr.y) / 4)  
{
	Closed_polyline::add(ul);
}

RoundedBox::RoundedBox(Point ul, int w, int h)
	: upperLeft(ul), width(w), height(h), roundWidth(w / 4), roundHeight(h / 4) 
{
	Closed_polyline::add(ul);
}

void RoundedBox::draw_lines() const{
	
	if(Closed_polyline::color().visibility()){ 
		// Arcs
		// upper left arc
		fl_arc(Closed_polyline::point(0).x , Closed_polyline::point(0).y, width/2, height/2, 90, 180);
		// upper right arc
		fl_arc(Closed_polyline::point(0).x + width/2, Closed_polyline::point(0).y, width/2, height/2, 0, 90);
		// down right arc
		fl_arc(Closed_polyline::point(0).x + width/2, Closed_polyline::point(0).y + height/2, width/2, height/2, 270, 0); 
		// down left arc
		fl_arc(Closed_polyline::point(0).x, Closed_polyline::point(0).y + height/2, width/2, height/2, 180, 270); 

		// Lines
		// top horizontal
		fl_xyline(Closed_polyline::point(0).x + roundWidth, Closed_polyline::point(0).y, Closed_polyline::point(0).x + width - roundWidth);
		// right vertical
		fl_yxline(Closed_polyline::point(0).x + width, Closed_polyline::point(0).y + roundHeight, Closed_polyline::point(0).y + height - roundHeight);
		// bottom horizontal
		fl_xyline(Closed_polyline::point(0).x + roundWidth, Closed_polyline::point(0).y + height, Closed_polyline::point(0).x + width - roundWidth);
		// left vertical
		fl_yxline(Closed_polyline::point(0).x, Closed_polyline::point(0).y + roundHeight, Closed_polyline::point(0).y + height - roundHeight);
	}
}

} // end of namespace Graph_lib


// TRY GENERATING ALL THE NECCESSARY POINTS FOR 4 LINES AND 4 ARCS AND PUTTING THEM INTO A POLYLINE!!!!