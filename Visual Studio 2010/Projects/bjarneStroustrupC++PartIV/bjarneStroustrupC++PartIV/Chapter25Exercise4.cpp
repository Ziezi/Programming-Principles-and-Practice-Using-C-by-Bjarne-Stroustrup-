/*
	TITLE		   Bitwise logical operators    Chapter25Exercise4.cpp
	COMMENT
		Objective: Add the bitwise logical operators &, |, ^ , and ~ 
				   to the calculator from Chapter 7. 
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 13.05.2017
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>  
#include <string>
#include <vector>
#include <forward_list>
#include <map>

#include "Chapter25Exercise4.h"
 
//-----------------------------------------------------------------------------------------------------------
 
int main()
{
	try
	{ 
		 Token_stream ts(std::cin);
		 calculate(ts, std::cout, std::cerr);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}