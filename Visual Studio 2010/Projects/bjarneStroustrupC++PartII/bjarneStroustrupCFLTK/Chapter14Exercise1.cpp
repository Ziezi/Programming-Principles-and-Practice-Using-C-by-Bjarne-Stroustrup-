/*
	TITLE		   Class Smiley and Frowny        Chapter14Exercise1.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Derive class Smiley and Frowny from class Circle.
		           Derive classes from Smiley and Frowny, adding 
				   appropriate hat to each.
		    Input:  
		   Output:  
		   Author: 27.09.2015
		     Date: Chris B. Kirov
*/
#include "Graph.h"
#include "Simple_window.h"
#include <iostream> 

using namespace Graph_lib;

// class Smiley
class Smiley: public Circle
{
public:
	Smiley(Point c, int rr)  : Circle(c, rr), r(rr) { }

	void draw_lines() const;

private:
	int r;
};

void Smiley::draw_lines() const
{
	if (color().visibility())
	{
		// add the mouth
        fl_arc(point(0).x + r/2, point(0).y + r/2, r, r, 180, 360);

		// add the eyes
        fl_arc(point(0).x + r/2, point(0).y + r/4, r/2, r/2, 0, 360);
        fl_arc(point(0).x + 3/2 * r, point(0).y + r/4, r/2, r/2, 0, 360);

        fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
	}
}
//---------------------------------------------------------------------------------

// class Frowney
class Frowny: public Circle
{
public:
	Frowny(Point c, int rr)  : Circle(c, rr), r(rr) { }

	void draw_lines() const;

private:
	int r;
};

void Frowny::draw_lines() const
{
	if (color().visibility())
	{
		// add the mouth
        fl_arc(point(0).x + r/2, point(0).y + r, r, r, 0, 180);

		// add the eyes
	    fl_line(point(0).x + r/2 - 5, point(0).y + r/2, point(0).x + r,  point(0).y + r/4);
        fl_line(point(0).x + r + 5, point(0).y + r/4, point(0).x + 1.5*r, point(0).y + r/2);

        fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
	}
}
//---------------------------------------------------------------------------------

// class SmileHat
class SmileyHat: public Smiley
{
public:
	SmileyHat(Point c, int rr)  : Smiley(c,rr), r(rr) { }

	void draw_lines() const;

private:
	int r;
};

void SmileyHat::draw_lines() const
{
	if (color().visibility())
	{
		// add the mouth
        fl_arc(point(0).x + r/2, point(0).y + r/2, r, r, 180, 360);

		// add the eyes
        fl_arc(point(0).x + r/2, point(0).y + r/4, r/2, r/2, 0, 360);
        fl_arc(point(0).x + 3/2 * r, point(0).y + r/4, r/2, r/2, 0, 360);

		// add triangle hat
		fl_line(point(0).x, point(0).y + r / 2,       point(0).x + r, point(0).y - r);
		fl_line(point(0).x + 2*r, point(0).y + r / 2, point(0).x + r, point(0).y - r);

        fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
	}
}
//---------------------------------------------------------------------------------

// class FrowneyHat
class FrownyHat: public Circle
{
public:
	FrownyHat(Point c, int rr)  : Circle(c, rr), r(rr) { }

	void draw_lines() const;

private:
	int r;
};

void FrownyHat::draw_lines() const
{
	if (color().visibility())
	{
		// add the mouth
        fl_arc(point(0).x + r/2, point(0).y + r, r, r, 0, 180);

		// add the eyes
	    fl_line(point(0).x + r/2 - 5, point(0).y + r/2, point(0).x + r,  point(0).y + r/4);
        fl_line(point(0).x + r + 5, point(0).y + r/4, point(0).x + 1.5*r, point(0).y + r/2);

		// add rectangle hat
		fl_line(point(0).x, point(0).y + r / 2,       point(0).x, point(0).y - r);
		fl_line(point(0).x + 2*r, point(0).y + r / 2, point(0).x + 2*r, point(0).y - r);
		fl_line(point(0).x, point(0).y - r, point(0).x + 2*r, point(0).y - r);

        fl_arc(point(0).x,point(0).y,r+r,r+r,0,360);
	}
}

void printHat(Circle& c, Simple_window* sw)
{
	sw->attach(c);
}

//---------------------------------------------------------------------------------------

int main()
{
	Point tl(x_max() / 2, 0);
	int width = 700;
	int height = 700;
	string label = "Chapter 14 Exercise 1";

	Simple_window* sw= new Simple_window(tl, width, height, label);

	try
	{
		 
		Smiley smile(Point(200, 150), 100); 
		sw->attach(smile);
		 
		Frowny frown(Point(450, 150), 100);
		sw->attach(frown);
		 
		SmileyHat SH(Point(200, 550), 100);		 
		FrownyHat FH(Point(450, 550), 100);

		std::cout << "Interface Inheritance test\n";
		printHat(SH, sw);
		printHat(FH, sw);

		sw->wait_for_button();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(...)
	{
		std::cerr <<"Default exception!"<< std::endl;
	}
}
