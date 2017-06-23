/*
	TITLE		   Function GUI			          Chapter16Exercise10.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Provide a program where one can choose among
				   a set of functions (e.g. sin(x), log(x)), 
				   provide parameters for those functions,
				   and then graph them. 
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"

#include "Chapter16Exercise10.h"

int main()
{
	try
	{
		Function_GUI fg;

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