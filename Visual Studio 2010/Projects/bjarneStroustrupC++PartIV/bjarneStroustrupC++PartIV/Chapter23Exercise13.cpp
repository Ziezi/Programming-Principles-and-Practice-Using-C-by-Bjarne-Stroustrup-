/*
	TITLE	       Regex dot special character	 Chapter23Exercise13.cpp
	COMMENT
		Objective: Does dot (.) match '\n'? Write a program to find out.
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 30.04.2017
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

int main()
{
	std::string src("\n");
	std::regex pattern("."); // pattern2(".*"); multiple dots include newline 
	std::smatch match;

	if (std::regex_search(src, match, pattern))
	{
		std::cout <<"Regex dot special character includes newline.\n";
	}
	else
	{
		std::cout <<"Regex dot special character doesn't include newline.\n";
	}

	getchar();
}