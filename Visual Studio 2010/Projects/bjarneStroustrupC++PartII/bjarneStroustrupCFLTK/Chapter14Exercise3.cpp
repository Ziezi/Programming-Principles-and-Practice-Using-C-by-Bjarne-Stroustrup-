/*
	TITLE		   Abstract class instantiation	 Chapter14Exercise3.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define an abstract class and try to instantiate it.
		    Input: - 
		   Output: -
		   Author: 27.09.2015
		     Date: Chris B. Kirov
*/
#include "Graph.h"
#include "Simple_window.h"
#include <iostream>

class A
{
	virtual void f() = 0;
};

//-----------------------------------------------------------------------
int main()
{
	Point tl(x_max()/2,0);
	int width = 700;
	int height = 700;
	string label = "Chapter 14 Exercise 1";

	Simple_window sw(tl, width, height, label);

	try
	{
		A a; // object is not allowed

		sw.wait_for_button();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(...)
	{
		std::cerr <<"Default exception!"<< endl;
	}
}