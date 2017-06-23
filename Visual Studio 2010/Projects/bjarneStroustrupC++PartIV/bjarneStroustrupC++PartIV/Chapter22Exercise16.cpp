/*
	TITLE		   Programming Languages Connection			Chapter22Exercise16.cpp
	COMMENT
		Objective: Modify the program from the previous exercise so that it reads a file of
				   (name,year,(ancestors)) tuples, such as (Fortran,19S6,()), (Algol,1960,(Fortran))
				   , and (C++,198S,(C,Simula)), and graphs them on a timeline with arrows from 
				   ancestors to descendants. Use this program to draw improved versions of the
				   diagrams in §22.2.2 and §22.2.7.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 10.04.2017
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // find
#include <cctype>    // isdigit isalpha isalnum
#include <time.h>    // time()

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"

#include "Chapter22Exercise16.h"
#include "Chapter22Exercise16Graphical.h"

int main()
{
	try
	{
		std::string file_name1("Chapter22Exercise16First.txt");
		std::string file_name2("Chapter22Exercise16Second.txt");
		
		PlotGraph pg(file_name2); 
		
		return gui_main();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}