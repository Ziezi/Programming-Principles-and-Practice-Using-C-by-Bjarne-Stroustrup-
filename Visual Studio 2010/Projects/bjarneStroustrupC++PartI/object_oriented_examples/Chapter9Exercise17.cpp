/*
	TITLE			   Compare Rational	and double        Chapter9Exercise17.h
		   "Software - Principles and Practice using C++" by Bjarne Stroustrup"
	COMMENT
			Objective: Demonstrate a calculation where class Rational gives
					   better result than double.
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 1.04.2015
*/
#include <iostream>
#include "Chapter9Exercise13.h" // class Rational

int main()
{
	try
	{
		/*
			Floating point numbers are not precise and
			do not retain sufficient information to 
			fully reconstruct a fraction.
		*/
		double a1 = 1. / 1234567.;
		std::cout << std::fixed << a1 <<'\n';

		Myrational::Rational r1(1, 123456789);
		std::cout << r1 <<'\n';
	}
	catch(Myrational::Rational::Invalid)
	{
		std::cerr << "Class Rational Exception caugth!" << std::endl;
	}
}