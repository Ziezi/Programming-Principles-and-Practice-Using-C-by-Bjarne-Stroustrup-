/*
	TITLE		   Regular expressions      		Chapter23TryThis3.cpp
	COMMENT 
		Objective: Get the program from §23.8.7 to run and use it to try
				   out some patterns, such as:
				   abc
				   x.*x
				   (.*)
				   \([^)]*\)
				   \w+ \w+( Jr\.)
			Input: - 
		   Output: - 
		   Author: Chris B. Kirov   
		    Date: 24.04.2017
*/ 
#include <regex>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main()
{
	std::regex pattern;

	std::string get_pattern;
	std::cout <<"Type pattern: ";
	getline(std::cin, get_pattern);

	try
	{
		pattern = get_pattern;
		std::cout <<"Pattern: " << get_pattern <<'\n';
	}
	catch (std::exception& e)
	{
		std::cerr <<"Exception: " << e.what() <<"\n";
	}

	std::cout <<"Type string lines:\n";
	std::string line;
	int line_number = 0;

	while (getline(std::cin, line) && line != "exit")
	{
		line_number++;

		std::smatch matches; // store matched strings

		// if line fits pattern, store in matches
		if (std::regex_search(line, matches, pattern))
		{
			std::cout <<"Line: "<< line_number <<": "<< line <<'\n';

			for (size_t i = 0; i < matches.size(); ++i)
			{
				std::cout <<"\tmatches[" << i <<"]: " << matches[i] <<'\n';
			}
		}
		else
		{
			std::cout <<"Didn't match!\n";
		}
	}
}
