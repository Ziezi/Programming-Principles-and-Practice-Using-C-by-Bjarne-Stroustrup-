/*
	TITLE	       Truncation, over- & under- flow	  Chapter24TryThis2.cpp
	COMMENT
		Objective: Run the examples from §24.2 showing truncation, overflow
				   and underflow examples due to intertype assignments, 
				   implicit conversion and algebraic calculations.
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 01.05.2017
*/
#include <iostream>
#include <iomanip>
#include <limits>

void Overlow_Truncation_Assignment(int ii, double fpd)
{
	int i = ii;
	std::cout <<"i = " << i <<", fpd =" << fpd <<'\n';
	getchar();

	char c = i;		// possible overflow: sizeof(int) > sizeof(char)
	std::cout <<"i = " << i <<", c =" << c <<'\n';
	getchar();

	short s = i;	// possible overflow: sizeof(int) > sizeof(short)
	std::cout <<"i = " << i <<", s =" << s <<'\n';
	getchar();

	std::cout <<"i = " << ii;
	i += 1;			// possible overflow: i value == numerical_limits<int>()
	std::cout <<", i + 1 =" << i <<'\n';
	getchar();

	std::cout <<"i = " << ii;
	i = ii;
	long lg = i*i;	// possible overlow: sizeof(int) == sizeof(long) && i value == numerical_limits<int>()
	std::cout <<", lg = i*i = " << lg <<'\n';
	getchar();

	float fps = fpd;// possible overlow: sizeof(float) < sizeof(double)
	std::cout <<"fps = " << fps <<", fpd = "<< fpd <<'\n';
	getchar();

	std::cout <<"i = " << ii;
	i = fpd;		// truncation: any digits after decimap point discarded
	std::cout <<", i = fpd = " << i;
	getchar();

	fps = i;		// possible truncation: sizeof(int) == sizeof(float)
					// size of mantissa (meaningful digits) smaller, part of size for float exponent
	std::cout <<"i = " << ii <<", fps = i = "<< fps <<'\n';
	getchar();
}

//------------------------------------------------------------------------------

void Overflow_Calculations()
{	
	char ch = 0; // overlfow to negative values 
	for (int i = 0; i < 500; ++i)
	{
		std::cout <<"int(char++)"<< int(ch++) <<"\n";
	}
	getchar();

	unsigned char ch2 = 0; // overflow to 0 
	for (int i = 0; i < 500; ++i)
	{
		std::cout <<"int(unsigned char++)"<< int(ch2++) <<"\n";
	}
}

//------------------------------------------------------------------------------

int main ()
{
	try
	{
		 int i = std::numeric_limits<int>::max();
		 double d = std::numeric_limits<double>::max();

		 Overlow_Truncation_Assignment(i, d);
		 Overflow_Calculations();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}
