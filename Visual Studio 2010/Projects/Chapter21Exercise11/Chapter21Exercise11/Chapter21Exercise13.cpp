/*
	TITLE		    Clean up text file		 Chapter21Exercise13.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: "clean up" a text file for use in a word query program; 
					that is, replace punctuation with whitespace,
					put words into lower case, 
					replace "don't" with "do not" (etc.), 
					and remove plurals (e.g., ships becomes ship).
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 04. 03. 2017
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Chapter21Exercise13.h"

int main()
{
	try
	{
		std::vector<std::string> modified_text;
		std::string input_file_name("Chapter21Exercise13.txt");
		std::string output_file_name("Chapter21Exercise13.txt");

		cleaup_text_file(input_file_name,  modified_text, output_file_name);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}
