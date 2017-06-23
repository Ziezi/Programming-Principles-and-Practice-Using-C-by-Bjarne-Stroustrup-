/*
	TITLE		   Calculator GUI			       Chapter16Exercise9.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Modify the calculator from Chapter 7
				   to get its input from input box and
				   to return its results to output box.  
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>  
#include <string>
#include <vector>
#include <forward_list>
#include <map>

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"

#include "Chapter16Exercise9Calc.h"
#include "Chapter16Exercise9.h"

int main()
{
	try
	{
		Calculator_GUI cg;

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