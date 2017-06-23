/* 
	TITLE		   Text Input to Graph_lib								Chapter26Exercise8.cpp
	COMMENT
		Objective: Add a text-based interface to the graphics interface library from Chapters
				   12 - 15. For example, the string: Cirle(Point(O, 1), 15) should generate a
				   call Circle(Poinl(O, 1), 15). 
				   Use this text interface to make a "kid 's drawing" of a two-dimensional
				   house with a roof, two windows, and a door.  
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 04.06.2017
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <regex>

#include "Simple_window.h"
#include "Graph.h"
#include "Chapter26Exercise8.h"

int main()
{
	try
	{
		Simple_window sw(Point(10,10), 500, 500, "Chapter 26 Exercise 8");

		std::string input("Chapter26Exercise8.txt");
		std::ifstream ifs(input.c_str());

		if (!ifs)
		{
			throw std::runtime_error("Can't open file!\n");
		}

		Command_Parser cp(ifs);
		std::vector<Command> commands = cp.get_commands();

		Graph_lib_Factory glf;
		std::vector<Graph_lib::Shape*> shapes;

		for (auto i = 0; i < commands.size(); ++i)
		{
			Graph_lib::Shape* s = glf.create(commands[i]);
			shapes.push_back(s);
		}
		 
		for (auto i = 0; i < shapes.size(); ++i)
		{
			sw.attach(*shapes[i]);
		}

		sw.wait_for_button();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}
