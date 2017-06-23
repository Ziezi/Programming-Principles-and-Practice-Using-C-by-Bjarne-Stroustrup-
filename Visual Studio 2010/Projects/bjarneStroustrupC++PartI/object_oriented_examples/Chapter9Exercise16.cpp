/*
	TITLE			   Compare Rational and Money	 Chapter9Exercise16.cpp
		   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Demonstrate a calculation where class Rational gives
					   better result than class Money.
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 30.03.2015
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

#include "Chapter9Exercise13.h" // class Rational
#include "Chapter9Exercise15.h" // class Money

//===========================================================
int main()
{
	try
	{
		// class Money provides precision only to the second digit 
		// class Rational data members provide much more significant digits
		int numerator = 12345;
		int denominator = 1000000000;
		Myrational::Rational r(numerator, denominator);

		std::string BGN("BGN");
		Mycurrency::Money m(1.23456, BGN);

		std::cout <<"Precision\nMoney: "<< m <<" Rational: "<< r <<'\n'; 
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}