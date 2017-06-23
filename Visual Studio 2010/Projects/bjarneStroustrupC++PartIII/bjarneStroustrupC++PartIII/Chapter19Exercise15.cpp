/*
	TITLE		    GUI to "Hunt the wumpus" Chapter19Exercise15.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Modify the previous exercise to allow the user
					to mark rooms on the map based on knowledge
					and guesses, such as "maybe bats" and "botomless pit".
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 06. 2. 2016
*/
#include <iostream>
#include <time.h>
#include <string>
#include <set>
#include <vector>
#include <sstream>

#include "GUI.h"
#include "Window.h"
#include "Graph.h"
#include "Simple_window.h"

#include "D:\C++ Projects\Visual Studio 2010\Projects\bjarneStroustrupC++PartIII\bjarneStroustrupC++PartIII\Chapter18Exercise12.h"
#include "Chapter19Exercise15.h"

int main()
{
	try 
	{
		Hunt_the_Wumpus1_1 hw;

		return gui_main();
	} 
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}