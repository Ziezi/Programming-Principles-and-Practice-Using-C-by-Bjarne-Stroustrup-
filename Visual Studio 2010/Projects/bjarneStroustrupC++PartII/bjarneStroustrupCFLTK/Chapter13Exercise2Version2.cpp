/*
	TITLE		   Rounded box		      Chapter13Exercise2Version2.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a class Box which draws four lines and four arcs.
		           Draw a rounded box.
				   Superellipse could be used as well!
		    Input: -
		   Output: 
		   Author: 17.09.2015
		     Date: Chris B. Kirov
*/

#include "GUI.h"
#include "Simple_window.h"
#include <iostream>
#include "Chapter13Exercise2Version2.h"
//-----------------------------------------------------------------------------------------------------------------------

int main()
{
	// window parameters
	int winWidth = 800;
	int winHeight = 600;
	Point center((x_max() - winWidth) / 2., (y_max() - winHeight) / 2.);
	Simple_window* sw = new Simple_window(center, winWidth, winHeight, "Chapter 13 Exercise 2");

	// rounded box parameters
	int width = 400;
	int height = 200;
	int xCoord = (sw->x_max() - width) / 2;
	int yCoord = (sw->y_max() - height) / 2;

	try
	{
		Graph_lib::RoundedBox rb(Point(xCoord, yCoord), width, height);
		sw->attach(rb);
		 
		sw->wait_for_button();
		delete sw;
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