/*
	TITLE	       Math functions error checking 	 Chapter24Drill4.cpp
	COMMENT
		Objective: Write a program that takes ints from d n and outputs the
				   sqrt() of each int, or "no square root" if sqrt(x) is 
				   illegal for some x (i.e., check your sqrt() return values).  
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 03.05.2017
*/
#include <iostream>
#include <cerrno>

int main()
{
	try
	{
		double result;
		int input = 0;

		while(true)
		{
			errno = 0;

			result = sqrt((double)input);

			if (errno == ERANGE)
			{
				std::cout << "test_sqrt::no square root:: range error!\n";
			}
			else if (errno == EDOM)
			{
				std::cout << "test_sqrt::no square root:: domain error!\n";
			}
			else if (errno)
			{
				std::cout << "test_sqrt::no square root:: something wrong!\n";
			}
			++input;
		}
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}