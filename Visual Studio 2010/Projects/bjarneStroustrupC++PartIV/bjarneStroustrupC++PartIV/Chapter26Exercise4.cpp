/* 
	TITLE		   Test data format  			  Chapter26Exercise4.cpp
	COMMENT
		Objective: Devise a format for test data so that you can 
				   define a sequence once and run several tests against.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 31.05.2017
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>		// std::istream_iterator<>()
#include <string>
#include <vector>
#include <algorithm>	// std:replace()

#include "Chapter26Exercise4.h"

int main()
{
	try
	{
		std::string mfile("Chapter26Exercise4Conditions.txt");
		std::string sfile("Chapter26Exercise4Sequences.txt");

		std::ifstream mifs(mfile.c_str());
		std::ifstream sifs(sfile.c_str());

		if (!mifs || !sifs)
		{
			throw std::runtime_error("Can't open file!\n");
		}

		std::vector<Measurement_Conditions<int>> conditions;
		std::vector< std::vector<int> > sequences;

		get_Measurement_Conditions(mifs, conditions);
		get_Input_Sequences(sifs, sequences);

		if (test_all(conditions, sequences))  
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