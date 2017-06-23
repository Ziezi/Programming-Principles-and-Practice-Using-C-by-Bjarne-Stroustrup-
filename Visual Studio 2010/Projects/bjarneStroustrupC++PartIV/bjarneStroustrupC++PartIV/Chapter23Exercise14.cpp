/*
	TITLE	       Test regular expression 			     Chapter23Exercise14.cpp
	COMMENT
		Objective: Write a program similar to the one in §23.8.7, 
				   have it read a file into memory 
				   (representing a line break with the newline character, '\n'),
			       so that you can experiment with patterns spanning line breaks.
				   Test it and document a dozen test patterns.  
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 30.04.2017
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

void test_patterns(const std::string& f, const std::string& p)
{
	std::ifstream ifs(f.c_str());
	if (!ifs)
	{
		throw std::runtime_error("test_patterns::Can't open input file!\n");
	}

	std::regex pattern;

	try
	{
		pattern = p;
	}
	catch (std::exception& e)
	{
		throw std::runtime_error("test_patterns::invalud regex expression!\n");
	}

	long int line_number = 1;
	std::string line;

	while (getline(ifs, line))
	{
		std::smatch match;

		if (std::regex_match(line, match, pattern))
		{
			std::cout <<"Line: "<< line_number <<" : " << line <<'\n';

			for (int i = 0; i < match.size(); ++i)
			{
				std::cout <<"match[" << i <<"] : " << match[i] <<'\n';
			}
		}

		++line_number;
	}
}

//-----------------------------------------------------------------------------------------------

int main()
{
	std::string file("Chapter23Exercise14.txt");
	std::string pattern(" ");

	try
	{
		test_patterns(file, pattern);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}