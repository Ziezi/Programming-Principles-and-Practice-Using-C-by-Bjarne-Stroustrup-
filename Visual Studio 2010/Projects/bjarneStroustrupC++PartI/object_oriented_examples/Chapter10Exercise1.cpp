/*
	TITLE			 Read numbers from file and sum         	Chapter10Exercise1.cpp
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Write a function that reads a file (filled with whitespace-separated numbers)
			           and sum them.
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 05.04.2015
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include"Chapter10Exercise1.h"

//==================================================================================================
int main()
{
	try
	{
		std::string name("Chapter10Exercise1.txt");
		populate_file(name);
		 
		std::vector<int> numbers;

		std::ifstream ifs(name.c_str());
		if (!ifs)
		{
			std::cerr <<"Can't open input file!\n";
		}

		fill_vector(ifs, numbers);

		std::cout <<"Sum: "<< sum_vector(numbers) <<"\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}