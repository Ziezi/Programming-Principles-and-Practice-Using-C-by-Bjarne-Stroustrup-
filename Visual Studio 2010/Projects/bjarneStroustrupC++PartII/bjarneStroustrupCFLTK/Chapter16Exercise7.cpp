/*
	TITLE		   Airplane animation			  Chapter16Exercise7.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Make an image of an airplane "fly around" in a window.
				   Have a "start" and "stop" button.   
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"

#include "Chapter16Exercise7.h"

int main()
{
	try
	{
		Airplane super;

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