/*
	TITLE		   Regular expressions      			         Chapter23Drill.cpp
	COMMENT 
		Objective: 1. Find out if regex is shipped as part of your standard library.
					  Try: std::regex and tr1::regex.
				   2. Get the program from §23.7.7 to run. Install boost library; 
					  set project options; and include needed headers.
				   3. Use the program from 2 to test the pattern from §23.7.
			Input: - 
		   Output: - 
		   Author: Chris B. Kirov   
		     Date: 25.04.2017
*/ 
#include <regex>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main ()
{
	try
	{
		std::string file("Chapter23Drill.txt");
		std::ifstream ifs(file.c_str());
		if (!ifs) 
		{
			throw std::runtime_error("Can't open input file: " + file);
		}

		std::regex pattern("\\w{2}\\s*\\d{5}(-\\d{4})?");	// ZIP code pattern
		 
		int line_number = 0;
		std::string line;
		while (getline(ifs, line))
		{
			++line_number;

			std::smatch matches;

			if (std::regex_search(line, matches, pattern))
			{
				std::cout << line_number <<": "<< matches[0] <<'\n';
			}
			else
			{
				std::cout <<"No match!\n";
			}
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}