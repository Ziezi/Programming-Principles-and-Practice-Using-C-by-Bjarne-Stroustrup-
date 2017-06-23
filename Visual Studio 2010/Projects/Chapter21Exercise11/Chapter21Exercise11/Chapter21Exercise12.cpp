/*
	TITLE		    Query GUI		  		Chapter21Exercise12.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Provide a GUI interface for querying a file of Orders; 
					e.g., "Find all orders from Joe,"
					"Find the tolal value of orders in file Hardware," and
					"List all orders in file Clothing." 

					Test commands:

					find all orders from Chapter21Exercise12.txt
					find the tolal value of orders in file Chapter21Exercise12.txt
					list all orders in file Chapter21Exercise12.txt

					Note: inherited problem with Out_box: appends ^J at output string; no new lines

		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 03. 03. 2017
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
#include <numeric>  // inner_product()
#include "Query_GUI.h"

int main()
{
	try
	{
		Query_GUI query_menu;

		return gui_main();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}

