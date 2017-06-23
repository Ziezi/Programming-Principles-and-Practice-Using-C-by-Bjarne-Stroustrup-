/* 
	TITLE		   Test Binary_search with strings	     Chapter26Drill4.cpp
	COMMENT
		Objective: Repeat the tests with sequence of strings
				   such as: { Bohr , Darwin , Einstein , Lavoisier , Newton , Turing }
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 31.05.2017
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Chapter26Drill4TestedCode.h"

int main()
{
	try
	{
		std::string ifile("Chapter26Drill4Tests.txt");
		std::ifstream ifs(ifile.c_str());
		if (!ifs)
		{
			throw std::runtime_error("Can't open file!\n");
		}
	
		if (test_all<std::string>(ifs, std::cout))
		{
			std::cout <<"All tests passed successfully.\n";
		}
		else
		{
			std::cout <<"Tests NOT passed !\n";
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}

