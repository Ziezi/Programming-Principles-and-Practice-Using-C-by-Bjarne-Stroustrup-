/*
	TITLE			   File I/O & Statistics    Chapter10Exercise4.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: 1. Populate a file with temperature readings in
					      the format (hour, temperature, unit), where
						  hour: [0, 23], temperature: [min, max],
						  unit: C - Celcius,    min = -273.15, max = 1.4e32,
						        F - Fahrenheit, min = −459.67, max = 2.5e32.
					   2. Read the file containing the temperatures, convert
					      them all into Fahrenheit and calcualte their mean
						  and median.
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
#include <time.h> // time
#include "Chapter10Exercise4.h"

//===========================================================================================================

int main()
{
	std::string file_name("Chapter10Exercise4raw_temps.txt");

	populate_file(file_name);

	std::ifstream ifs(file_name.c_str());

	if (!ifs)
	{
		std::cerr <<"Can't open input file: "<< file_name <<"\n";
	}
	
	std::vector<Reading> file_data;
	fill_vector(ifs, file_data);

	std::cout <<"Temperature Mean: "<< vector_mean(file_data) <<" [F]\n";
	std::cout <<"Temperature Median: "<< vector_median(file_data) <<" [F]\n";
}

