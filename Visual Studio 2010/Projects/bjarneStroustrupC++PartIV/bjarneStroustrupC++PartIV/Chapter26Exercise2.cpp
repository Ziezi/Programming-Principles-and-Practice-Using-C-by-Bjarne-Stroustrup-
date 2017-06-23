/* 
	TITLE		   Generalise binary_search and its tests			 Chapter26Exercise2.cpp
	COMMENT
		Objective: Modify the testing of binary_search to deal with arbitrary element types.
				   Then, test it with string sequences and floating-point sequences. 
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
		// std::string ifile("Chapter26Exercise2String.txt");
		std::string ifile("Chapter26Exercise2Float.txt");
		std::ifstream ifs(ifile.c_str());
		if (!ifs)
		{
			throw std::runtime_error("Can't open file!\n");
		}
	
		if (test_all<float>(ifs, std::cout))
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

