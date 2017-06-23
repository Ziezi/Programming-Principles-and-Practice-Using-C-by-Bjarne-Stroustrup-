/*
	TITLE		   Currency Converter			   Chapter16Exercis8.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Provide a currency converter.
				   Read the conversion rates from file on startup.
				   Enter amount in an input window and provide a way of
				   selecting currencies to convert to and from (e.g. a pair of menus).    
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>
#include <iomanip> // precision
#include <string>
#include <map>

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"

#include "Chapter16Exercise8.h"

int main()
{
	try
	{
		Currency_converter cc;

		return gui_main();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() <<'\n';
		getchar();
	}
	catch(...)
	{
		std::cerr << "Exception!\n";
		getchar();
	}
}