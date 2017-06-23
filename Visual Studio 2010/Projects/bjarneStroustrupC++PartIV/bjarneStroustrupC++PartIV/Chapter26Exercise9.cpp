/* 
	TITLE		   Text Output to Graph_lib					   Chapter26Exercise9.cpp
	COMMENT
		Objective: Add a text-based output format for the graphics interface library.
				   For example, when a call Circle(Point(0,1),15) is executed, a string 
				   like: Circle(Point(0,1),15) should be produced on an output stream.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 07.06.2017
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <regex>
#include <typeinfo>

#include "Simple_window.h"
#include "Graph.h"
#include "Chapter26Exercise8.h"

int main()
{
	try
	{
		Simple_window sw(Point(10,10), 500, 500, "Chapter 26 Exercise 9");

		std::string input("Chapter26Exercise8.txt");
		std::ifstream ifs(input.c_str());

		std::string output("Chapter26Exercise9Output.txt");
		std::ofstream ofs(output.c_str(), std::ios_base::app);

		if (!ifs || !ofs)
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

			// shape saved in container => safe to print the command
			ofs << s; 
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
