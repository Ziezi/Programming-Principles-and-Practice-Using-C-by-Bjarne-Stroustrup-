/*
	TITLE		   Programming Language Chronology		Chapter22Exercise15.cpp
	COMMENT
		Objective: Write a program that given a file with (name, year) pairs, such
				   as (Algol, 1960) and (C, 1974), graphs the names on a timeline.

				   Note: include .cpp files together with the source file of the included .h files below: 
				   Graph.cpp, GUI.cpp
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 06.04.2017

*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"

#include "Chapter22Exercise15.h"

int main()
{
	 try
	 {
		ProgrammingTimeline pt;

		return gui_main();
	 }
	 catch (std::exception& e)
	 {
		std::cerr << e.what();
	 }
}