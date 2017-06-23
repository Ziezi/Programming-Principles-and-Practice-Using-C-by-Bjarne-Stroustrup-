/*
	TITLE		    Text statistics GUI		 Chapter21Exercise15.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Provide GUI for exercise 14
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 06. 03. 2017
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <iterator>

#include "Chapter21Exercise13.h"
#include "Chapter21Exercise14.h"

#include "Simple_Window.h"
#include "Chapter21Exercise15.h"

int main()
{
	try
	{
		Text_Statistics_GUI ts;

		return gui_main();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}