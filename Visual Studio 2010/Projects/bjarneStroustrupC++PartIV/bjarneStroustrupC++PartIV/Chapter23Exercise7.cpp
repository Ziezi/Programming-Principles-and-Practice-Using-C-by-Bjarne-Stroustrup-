/*
	TITLE		   Find credit card numbers in file				Chapter23Exercise7.cpp
	COMMENT
		Objective: Write a program that finds redit card numbers in a file and displays
				   the line containing the date and its number.
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

#include "Chapter23Exercise7.h" // check card number validity

void find_pattern(const std::string& n, const std::string& p)
{
	std::ifstream ifs(n.c_str());
	if (!ifs)
	{
		std::cerr <<"Can't open input file!\n";
	}

	std::regex pattern;
	std::smatch match;

	try
	{
		pattern = p;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		throw std::runtime_error("\nfind_dates()::Wrong regex format!\n");
	}

	long int line_number = 1;
	std::string line;

	while (getline(ifs, line))
	{
		if (std::regex_search(line, match, pattern))
		{
			std::cout <<"Line-"<< line_number <<": "<< line <<'\n';
		}
		++line_number;
	}
}

//--------------------------------------------------------------------

int main ()
{
	std::string card_type1("\\d{12,19}");
	 
	std::string s("5892420084436054");
	std::cout <<"Is valid: "<< std::boolalpha <<is_valid_number(s);
	getchar();

	std::string pattern(card_type1);
	std::string file("Chapter23Exercise7.txt");

	try
	{
		find_pattern(file, pattern);
	}
	catch (std::runtime_error& e)
	{
		std::cerr << e.what();
	}
	getchar();
}