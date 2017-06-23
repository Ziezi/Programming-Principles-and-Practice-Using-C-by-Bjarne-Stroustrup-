/*
	TITLE			   Read file & calculate statistics     Chapter10Exercise3.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Write a function that reads a file containing
					   data in the format (hour, temp) and calculates
					   mean and median temperatures.
				Input: - 
			   Output: -
			   Author: Chris B. Kirov
			     Date: 08.04.2015
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // sort
#include "Chapter10Exercise3.h"
 
//===========================================================================================================

int main()
{
	std::string file_name("Chapter10Exercise2raw_temps.txt");
	std::ifstream ifs(file_name.c_str());

	if (!ifs)
	{
		std::cerr <<"Can't open input file: "<< file_name <<"\n";
	}
	
	std::vector<Reading> file_data;
	fill_vector(ifs, file_data);

	std::cout <<"Temperature Mean: "<< vector_mean(file_data) <<"\n";
	std::cout <<"Temperature Median: "<< vector_median(file_data) <<"\n";
}

 
