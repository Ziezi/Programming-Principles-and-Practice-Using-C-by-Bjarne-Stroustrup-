/*
	TITLE		    "Hunt the Lumpus"       Chapter18Exercise12.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Implement the game: "Hunt the Lumpus".
					Command format: 
					move:        s 
					shoot arrow: -
					Both followed by room number, no whitespaces.

		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 12.1.2016
*/
#include <iostream>
#include <time.h>
#include <string>
#include <set>
#include <vector>
#include <sstream>
 
#include "Chapter18Exercise12.h"

int main() 
{
	try 
	{
		run_game();
	} 
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}

 