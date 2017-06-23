/*
	TITLE		    GUI Order & files		Chapter21Exercise11.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Provide a GUI interface for entering Orders into files.  
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 01. 03. 2017
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include "D:\C++ Projects\Visual Studio 2010\Projects\bjarneStroustrupC++PartIII\bjarneStroustrupC++PartIII\Chapter21Exercise9.h"

#include "Simple_Window.h"
#include <time.h>	// time(); localtime()
#include <iomanip>	// put_time()
#include "Order_GUI.h"

int main()
{
	try
	{
		Order_GUI order_menu;

		return gui_main();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}

