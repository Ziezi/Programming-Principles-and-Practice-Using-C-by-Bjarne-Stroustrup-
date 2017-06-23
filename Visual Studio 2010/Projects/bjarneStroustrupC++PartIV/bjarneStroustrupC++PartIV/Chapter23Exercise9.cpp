/*
	TITLE		   Table checking using eof()					     Chapter23Exercise9.cpp
	COMMENT
		Objective: Using eof() (§B.7.2), it is possible to detcnninc which line of a table
				   is the last. Use that to (try to) simplify the table-checking program from §23.9.
				   Be sure to test your program with files that end with empty 
				   lines after the table and with files that don't end with a newline at all.  

				   Chapter23Exercise9a.txt   - ends with \n on the last line
				   Chapter23Exercise9b.txt   - empty lines after the table
				   Chapter23Exercise9c.txt   - empty line in the middle
				   Chapter23Exercise9c.txt  - without \n on the last line
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 27.04.2017
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

#include "Chapter23Exercise9.h"

int main()
{
	std::string header("^[\\w\\s]+(\\t[\\w\\s]+)*$");
	std::string row("^[\\w ]+(\\t\\d+)(\\t\\d+)(\\t\\d+)$");

	// test for all a, b, c ,d .txt files
	std::string file_name("Chapter23Exercise9a.txt");

	try
	{
		std::cout <<"The data file is ";
		if (!is_valid_table(header, row, file_name))
		{
			std::cout <<"not ";
		}
		std::cout <<"valid.";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}

	getchar();
}