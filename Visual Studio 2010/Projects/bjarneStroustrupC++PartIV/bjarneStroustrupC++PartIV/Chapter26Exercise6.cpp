/* 
	TITLE		   Test Calculator & I/O redirection			    	Chapter26Exercise6.cpp
	COMMENT
		Objective: Modify the calculator from Chapter 7 minimally to let it take input from a
				   file and produce output to a file (or use your operating system's facilities
				   for redirecting I/O ). Then devise a reasonably comprehensive test for it.  
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 01.06.2017
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>  
#include <forward_list>
#include <map>

#include "D:\C++ Projects\Visual Studio 2010\Projects\bjarneStroustrupC++PartII\bjarneStroustrupCFLTK\Chapter16Exercise9Calc.h"
#include "Chapter26Exercise6.h"


int main()
{
	try
	{
		std::string test("Chapter26Exercise6Tests.txt");
		std::string input("Chapter26Exercise6Input.txt");

		std::ifstream test_ifs(test.c_str());
		std::ifstream input_ifs(input.c_str());

		if(!test_ifs || !input_ifs)
		{
			throw std::runtime_error("Can't open file!\n");
		}

		std::vector<Measurement_Conditions<double>> conditions;
		std::vector<std::string> expressions;

		get_Measurement_Conditions(test_ifs, conditions);
		get_Input_Sequences(input_ifs, expressions);

		if (test_all<double>(conditions, expressions))
		{
			std::cout <<"Tests passed.\n";
		}
		else
		{
			std::cout <<"Tests NOT passed!\n";
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}