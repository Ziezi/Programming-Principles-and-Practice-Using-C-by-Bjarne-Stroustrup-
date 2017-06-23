/*
	TITLE		   Immobile Circle      Chapter14Exercise4.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a circle that can not be moved.
		    Input: - 
		   Output: -
		   Author: 27.09.2015
		     Date: Chris B. Kirov
*/
#include "Graph.h"
#include "Simple_window.h"
#include <iostream> 

class ImmobileCircle: protected Circle
{
public:
	ImmobileCircle(Point c, int r): Circle(c, r) { }
};

int main()
{
	Point tl(x_max()/2,0);
	int width = 700;
	int height = 700;
	string label = "Chapter 14 Exercise 1";

	Simple_window sw(tl, width, height, label);

	try
	{
        ImmobileCircle ic(Point(100,100), 50);
		// inheritance access specifier selected to be: protected
		// such that the member functions of Circle are not accessible
		ic.move(5,5); // error: innaccessible

		sw.wait_for_button();
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
