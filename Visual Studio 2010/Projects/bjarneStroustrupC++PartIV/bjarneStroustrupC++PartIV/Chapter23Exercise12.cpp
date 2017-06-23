/*
	TITLE		   Find & replace dates in file				       Chapter23Exercise12.cpp
	COMMENT
		Objective: Write a program, based on the program thai finds lines containing dates,
				   that finds all dates and reformats them to the ISO yyyy/mm/dd format.
				   The program should take an input file and produce an output file that is 
				   identical to the input file except for the changed date fommatting.
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

int month_to_digit (const std::string& n)
{
	if (n == "Jan" || n == "January") return 1;
	else if (n == "Feb" || n == "February") return 2;
	else if (n == "Mar" || n == "March") return 3;
	else if (n == "Apr" || n == "Aprill") return 4;
	else if (n == "May" || n == "May") return 5;
	else if (n == "Jun" || n == "June") return 6;
	else if (n == "Jul" || n == "Jully") return 7;
	else if (n == "Aug" || n == "August") return 8;
	else if (n == "Sep" || n == "September") return 9;
	else if (n == "Oct" || n == "October") return 10;
	else if (n == "Nov" || n == "November") return 11;
	else if (n == "Dec" || n == "December") return 12;
	else throw std::runtime_error("month_to_digit::Invalid input value!\n");
}

//---------------------------------------------------------------------------------------------------------------

/*
	Function: convert_date()

	Converts to ISO yyyy/mm/dd date format, from two possible
	input formats: dd*MonthName*yyyy and MonthName*dd*yyyy.
*/
std::string convert_date(const std::string& src, std::smatch& m)
{
	std::stringstream ss;
	
	ss << m[1] << m[4] <<"/";	             //  year

	if (isalpha(m[3].str()[0]))		 // dd*MonthName*yyyy
	{
		ss << month_to_digit(m[3]) <<"/"<< m[2];
	}
	else if (isalpha(m[2].str()[0])) // MonthName*dd*yyyy.
	{
		ss << month_to_digit(m[2]) <<"/"<< m[3]; 
	}
	else 
	{
		throw std::runtime_error("convert_date::input format not supported!\n");
	}

	ss << m[5];						 // text after date

	return ss.str();
}

//---------------------------------------------------------------------------------------------------------------

void standardize_date(const std::string& src, const std::string& dest)
{
	std::ifstream ifs(src.c_str());
	if (!ifs)
	{
		throw std::runtime_error("standardize_date::Can't open input file!\n");
	}

	std::ofstream ofs(dest.c_str());
	if (!ofs)
	{
		throw std::runtime_error("standardize_date::Can't open output file!\n");
	}

	// dd*mm*yyyy  , where * is -, ,\ 
	std::string date1("([1-31]{1,2})[\\s/.\\\\-]([1-12]{1,2})[\\s/.\\\\-](\\d{2,4})");
	std::string fmt1("$3/$2/$1");

	// dd*MonthName*yyyy , where MonthName - upper case followed by one or more lower case letters
	std::string date2("^(.*?)([1-31]{1,2})\\s*[\\s/.\\\\-]\\s*([A-Z][a-z]+)\\s*[\\s/.\\\\-]\\s*(\\d{2,4})(.*)$");

	// MonthName*dd*yyyy
	std::string date3("^(.*?)([A-Z][a-z]+)\\s*[\\s/.\\\\-]\\s*([1-31]{1,2})\\s*[\\s/.\\\\-]\\s*(\\d{2,4})(.*)$");

	std::regex pattern1, pattern2, pattern3;
	std::smatch match;

	try
	{
		pattern1 = date1;
		pattern2 = date2;
		pattern3 = date3;
	}
	catch(std::exception& e)
	{
		throw std::runtime_error("standardize_date::Wrong std::regex format!\n");
	}

	std::string line;
	while (getline(ifs, line))
	{
		if (std::regex_match(line, match, pattern3))
		{
			ofs << convert_date(line, match) <<'\n';
		}
		else if (std::regex_match(line, match, pattern2))
		{
			ofs << convert_date(line, match) <<'\n';
		}
		else if (std::regex_search(line, match, pattern1))
		{
			ofs << std::regex_replace(line, pattern1, fmt1) <<'\n';
		}
		else												// no need of conversion
		{
			ofs << line <<"\n";
		}
	}
}

//---------------------------------------------------------------------------------------------------------------

int main ()
{
	std::string src_file("Chapter23Exercise12in.txt");
	std::string dest_file("Chapter23Exercise12out.txt");

	try
	{
		 standardize_date(src_file, dest_file);
	}
	catch (std::runtime_error& e)
	{
		std::cerr << e.what();
	}
	getchar();
}