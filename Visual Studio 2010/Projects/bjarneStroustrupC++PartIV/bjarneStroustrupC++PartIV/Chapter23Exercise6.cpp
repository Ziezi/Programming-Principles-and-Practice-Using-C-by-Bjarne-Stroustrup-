/*
	TITLE		   Find dates in file			    Chapter23Exercise6.cpp
	COMMENT
		Objective: Write a program that finds dates in a file and displays
				   the line containing the date and its number.
				   Start with regular expression for simple formats like:
				   12/24/2017. Add more formats later.
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 27.04.2017
*/
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

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
	// dd*dd*dddd  , where * -, , /, \ 
	std::string date1("\\d{1,2}\\s*[/\\.-]\\s*\\d{1,2}\\s*[/\\.-]\\s*\\d{2,4}");
	// dd*MonthName*dddd , where MonthName - uppercase followed by one or more lowercase letters
	std::string date2("\\d{1,2}\\s*[/\\.-]\\s*[A-Z][a-z]+\\s*[/\\.-]\\s*\\d{2,4}");
	// MonthName*dd*dddd
	std::string date3("[A-Z][a-z]+\\s*[/\\.-]\\s*\\d{1,2}\\s*[/\\.-]\\s*\\d{2,4}");

	std::string pattern(date1 +"|"+ date2 +"|"+ date3);
	std::string file("Chapter23Exercise6.txt");

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