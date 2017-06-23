/*
	TITLE			   Function print_year          Chapter10Exercise5.cpp
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Implement function print_year() from §1O.11.2. 
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
#include"Chapter10Exercise5.h"

//====================================================================================================
int main()
{
	try
	{
		// initialize Month representations
		init_input_tbl(month_input_tb);	
		init_print_tbl(month_print_table);

		// create a file
		std::string file_name = "Chapter10Exercise5.txt";
		std::ofstream ofs(file_name.c_str());

		if(!ofs)
		{
			std::cerr <<"Output file can't be opened: "<< file_name <<"\n";
		}
		ofs.exceptions(ofs.exceptions() | std::ios_base::badbit);

		// input values
		std::string year_marker = "year";
		int year = 1990;

		std::string month_marker = "month";
		std::string month = "jan";

		int day = 1;
		int hour = 1;
		double temp = 60.0;

		// write to file
		ofs <<"{ "<< year_marker <<" "<< year <<" { "<< month_marker <<" "<< month <<" ( "<< day <<" "<< hour <<" "<< temp <<" )"<<" }"<<" }";
		ofs.close();

		// read from file and store in vector
		std::ifstream ifs(file_name.c_str());

		if(!ifs)
		{
			std::cerr <<"Input file can't be opened: "<< file_name <<"\n";
		}
		ifs.exceptions(ifs.exceptions()| std::ios_base::badbit);

		std::vector<Year> years;
		std::string input;
		while(getline(ifs, input))
		{
			std::stringstream ss(input);

			Year y;
			if(ss >> y)
			{
				years.emplace_back(y);
			}
			else
			{
				std::cout <<"Wrong input format!\n";
			}
		}
		ifs.close(); 

		// print result
		print_year(std::cout, years);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() <<'\n';
	}
}