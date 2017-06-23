/*
	TITLE		    GUI to "Hunt the wumpus" Chapter19Exercise14.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Provide a simple GUI interface output to the 
					"Hunt the Wumpus" from Chapter 18.
					Take the input from an input box and display a
					map of of the part of the cave currently known 
					to the player in a window.
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
#include "Chapter19Exercise14.h"

int main()
{
	try 
	{
		Hunt_the_Wumpus hw;

		return gui_main();
	} 
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}