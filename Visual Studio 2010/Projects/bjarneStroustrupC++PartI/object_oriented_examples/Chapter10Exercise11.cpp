/*
	TITLE			   Sum integers from file   Chapter10Exercise11.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: This program reads file containing text and numbers
					   and sum only the numbers.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 07.05.2015
*/ 
// Declaration segment
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Chapter10Exercise11.h"

void test_function();

//=====================================================================================
int main()
{
	try
	{
		test_function();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
//=====================================================================================

/*
	Function: test_function();


*/
void test_function()
{
	std::string intro("Sum digits within a file.\n");
	std::cout << intro;

	std::string file_name("Chapter10Exercise11.txt");

	std::vector<int> numbers;
	read_numbers(file_name, numbers);

	std::cout <<"Sum: "<< sum_vector(numbers) <<"\n";
}