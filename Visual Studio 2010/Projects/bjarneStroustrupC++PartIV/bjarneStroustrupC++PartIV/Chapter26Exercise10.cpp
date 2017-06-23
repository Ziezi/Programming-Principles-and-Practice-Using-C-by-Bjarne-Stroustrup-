/* 
	TITLE		   Test Graph_lib from Text I/O  Chapter26Exercise10.cpp
	COMMENT
		Objective: Use the text-based interface from Exercise 9 to write 
				   a better test for the graphical interface library. 
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
#include <iterator>		// std::istream_iterator
#include <algorithm>    // std::equal

#include "Simple_window.h"
#include "Graph.h"
#include "Chapter26Exercise8.h"

int main()
{
	try
	{
		std::string input("Chapter26Exercise8Input.txt");
		std::ifstream ifs(input.c_str());

		std::string output("Chapter26Exercise9Output.txt");
		std::ofstream ofs(output.c_str());

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

			// shape saved in container => safe to print it
			ofs << s;
		}
		 
		// TESTING 
		/*
			Success:
			Input text file containing commands for object creation
			identical to output text file containing created objects.
		*/
		std::ifstream ifs2(output.c_str());

		std::vector<std::string> expected_output;
		std::vector<std::string> actual_output;

		std::copy(std::istream_iterator<std::string>(ifs),
			      std::istream_iterator<std::string>(),
				  std::back_inserter(expected_output));

		std::copy(std::istream_iterator<std::string>(ifs2),
				  std::istream_iterator<std::string>(),
				  std::back_inserter(actual_output));

		if (std::equal(expected_output.begin(), expected_output.end(), actual_output.begin()))
		{
			std::cout <<"Tests passed.\n";
		}
		else
		{
			std::cout <<"Tests NOT passed!\n";
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}