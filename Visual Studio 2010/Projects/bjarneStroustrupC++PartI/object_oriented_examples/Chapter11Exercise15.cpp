/*
	TITLE		   Read and count numbers  Chapter11Exercise15.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Create a function that reads a file with
				   whitespace-separated numbers and sorts them
				   in ascending order into two columns, 
				   where the first is the number
				   and the second its frequency of occurence.
		    Input: -
		   Output: -
		     Date: 25.08.2015
		   Author: Chris B. Kirov
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

//--------------------------------------------------------------------------------------------------------------------------------
int main()
{
	try
	{
		std::cout <<"This program reads a file filled with numbers, sorts, counts and displays them in ascending order.\n";

		std::string source("Chapter11Exercise14Source.txt");
		std::string destination("Chapter11Exercise15Destination.txt");
		int precision = 2;
		sort_count(source, destination, precision);

		std::cout << "\nSorting and counting done!\n";
		std::cin.get();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
//--------------------------------------------------------------------------------------------------------------------------------

/*
	Function: sort_count ()

	It reads a file with whitespace-separated 
	numbers and sorts them in ascending order 
	into two columns, where the first is the number
	and the second its frequency of occurence.
*/
void sort_count (std::string& src, std::string& dest, int setPrecision = 2)
{
	std::ifstream ifs(src.c_str());
	if(!ifs) 
	{
		std::cerr <<"Can't open input file!\n";
	}
	 
	std::string line;
	std::vector<float> numbers;
	// read line
	while(ifs >> line)
	{
		std::stringstream is(line);
		float number;
		// read individual numbers, convert them in scientific notation 
		// with 8 digits of precision and store them in a vector
		is.precision(setPrecision);
		while(is >> number) 
		{
			numbers.push_back(number);
		}
	} 
	ifs.close();
	
	// sort the numbers
	sort(numbers.begin(), numbers.end());

	std::ofstream ofs(dest.c_str());
	if(!ofs)
	{
		std::cerr <<"Can't open output file!\n";
	}

	ofs << std::setw(10) << std::left <<"Number: "<<"Frequency: \n";

	// count frequency
	for(size_t i = 0; i < numbers.size(); ++i)
	{
		// counts occurences: incremented if next element equals current
		size_t count = 1;

		// prevents out of range error
		size_t limit = numbers.size() - 1;
		while(i < limit && numbers[i] == numbers[i+1])
		{ 
			++count;

			// if next equals current, advance to it
			++i; 
		} 

		ofs << std::setw(10) << numbers[i] << std::setw(10) << count <<'\n';
	}
}