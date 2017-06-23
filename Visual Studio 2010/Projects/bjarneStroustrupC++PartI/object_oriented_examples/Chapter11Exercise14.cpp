/*
	TITLE		   Read, format and print numbers  	 Chapter11Exercise14.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Create a function that reads a file with
				   whitespace-separated numbers and prints them
				   in format: precision: 8, in four fields of 20 
				   characters/ line.
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

void read_format_write (std::string&, std::string&, int, int);

//-----------------------------------------------------------------------------------------------------------------------
int main()
{
	try
	{
		std::cout <<"This program reads a file, filled with numbers and writes them to another in specific format.\n";

		std::string source ("Chapter11Exercise14Source.txt");
		std::string destination ("Chapter11Exercise14Destination.txt");
		int precision = 8;
		int per_line = 4;
		read_format_write (source, destination, precision, per_line);

		std::cout <<"\nFormating done!\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
//-----------------------------------------------------------------------------------------------------------------------

/*
	Function: readAndPrintToFile()
	 
	It opens and reads the text file with name
	provided from the first parameter (assumes it contains
	whitespace-separated numbers).

	It formats the numbers to be displayed in scientific notation
	with 8 digits of precision set by default by the third parameter
	and 4 numbers per line, default by the forth parameter.
*/
void read_format_write (std::string& src, std::string& dest, int precision = 8, int per_line = 4)
{
	std::ifstream ifs(src.c_str());
	if(!ifs) 
	{
		std::cerr <<"Can't open input file!\n";
	}

	std::string line;
	// holds individual, formated numbers
	std::vector<float> numbers;

	// read line
	while(ifs >> line)
	{
		std::stringstream is(line);
		float number;
		// read individual numbers, convert them in scientific notation 
		// with 8 digits of precision and store them in a vector
		is.precision(precision);
		while(is >> std::scientific >> number)
		{
			numbers.push_back(number);
		}
	} 
	ifs.close();

	std::ofstream ofs(dest.c_str());
	if(!ofs)
	{
		std::cerr <<"Can't open output file!\n";
	}

    // write to output file, 4 numbers per line 
	for(size_t i = 0; i < numbers.size(); ++i)
	{ 
		ofs.precision(precision); 
		ofs << std::scientific << numbers[i] <<" ";

		if(i % per_line == 0)
		{
			ofs <<'\n';
		}
	}
}