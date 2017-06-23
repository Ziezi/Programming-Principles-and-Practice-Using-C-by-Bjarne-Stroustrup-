/*
	TITLE			   Word in a file          Chapter10Exercise12.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: It prints the line containing a specific word in a file.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 07.05.2015
*/ 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Chapter10Exercise12.h"

void test_function();

// page 375

//===================================================================================================
int main()
{
	try
	{
		test_function();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() <<'\n';
	}
}
//===================================================================================================

/*
	Function: test_function();

*/
void test_function()
{
	std::string info("Find a word in a file and print the line that contains it and its number.\n");
	std::cout << info;
	std::string word("to");

	std::string file_name("Chapter10Exercise12.txt");
		 
	find_word_in_file(file_name, word);
}


