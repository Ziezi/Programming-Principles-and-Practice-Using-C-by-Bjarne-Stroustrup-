/*
	TITLE		   Analog clock     			  Chapter16Exercise6.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Make an "Analog Clock", that is, a clock with hands that move;
				   get the time from OS library; find functions that wait for short
				   period of time.   
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>
#include <ctime> // get current time

#define _USE_MATH_DEFINES
#include <math.h> // M_PI


#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"

#include "Chapter16Exercise6.h"

int main()
{
	try
	{
		std::string title = "Chapter 16 Exercise 6";
		Analog_clock ac(Point(300, 300), title);

		return gui_main();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() <<'\n';
	}
	catch(...)
	{
		std::cerr << "Exception!\n";
	}
}