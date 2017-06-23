/* 
	TITLE		   Test Binary_search	Chapter26Exercise1.cpp
	COMMENT
		Objective: Run your binary search algorithm from §26.1 
				   wilh the tests presented in §26.3.2.1.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 31.05.2017
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Chapter26Exercise1.h"

int main()
{
	try
	{
		std::string ifile("Chapter26Exercise1Tests.txt");
		std::ifstream ifs(ifile.c_str());
		if (!ifs)
		{
			throw std::runtime_error("Can't open file!\n");
		}
	
		if (test_all<int>(ifs, std::cout))
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

