/*
	TITLE	       Rounding Error						 Chapter24TryThis1.cpp
	COMMENT
		Objective: Replace 333 in the example with 10 and run the example again. 
				   What result would you expect? What result did you get? 
				   You have been warned! 
				   
				   float is only an approximation of a real number, R. 
				   They tend to lose precision (i.e. lose LSBs).
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 01.05.2017
*/
#include <iostream>
#include <iomanip>

void Rounding_Error(float n, float d, int p)
{
	float term = n / d;
	float sum = 0;

	for (int i = 0; i < d; ++i)
	{
		sum += term;
	}

	std::cout <<"Sum = "<< std::setprecision(p) << std::fixed << sum 
		      <<", Expected = "<< std::setprecision(p) << std::fixed << n;
}

//------------------------------------------------------------------------------

int main ()
{
	try
	{
		float numerator = 1;
		float denominator = 333; // test for multiple values
		int precision = 15;

		Rounding_Error(numerator, denominator, precision);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}