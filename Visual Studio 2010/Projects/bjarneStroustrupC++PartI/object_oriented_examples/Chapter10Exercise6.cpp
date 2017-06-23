/*
	TITLE			   Class Roman_int			   Chapter10Exercise6.cpp
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Implement a class that represents a number as Roman.
			class Roman_int					Helper Functions:					Overloaded operators:

			Roman_int()			            to_arab(std::string& n)				operator>>
			Roman_int(int n)			    to_roman(int n)				        operator<<
			Roman_int(std::string& n)		is_roman_number(std::string& n)
									        is_roman_digit(char& c)
			as_int()
			as_roman()

			value
				Input: - 
			   Output: -
			   Author: Chris B. Kirov
			     Date: 24.04.2015
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <forward_list>
#include"Chapter10Exercise6.h"

void test_function();

//==========================================================================
int main()
{
	try
	{
		test_function();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
 
}
//==========================================================================

/*
	Function: test_function()

	It tests basic functionality
	of the newly defined functions:
	to_arab(), to_int(), is_roman_number(), is_roman_digit(), 
	as_int(), as_roman(), and objects 
	of class Roman_int.
*/
void test_function()
{
	// default construct & operator<<; (implicitly: as_roman())
	Roman_int rn;
	std::cout <<"0. Roman: "<< rn << '\n';
		 
	// construct from Arab & as_int() 
	int value1 = 222;
	Roman_int r2(value1);
	std::cout <<"1. Roman numeral: "<< r2 <<" Arabic numeral: "<< r2.as_int() <<'\n' ;

	// contruct from Roman (implicitly: to_roman())
	std::string value2 = "MMXVI";
	Roman_int r3(value2);
	std::cout <<"2. Roman numeral: "<< r3 <<" Arabic numeral: "<< r3.as_int() <<'\n';
		
	// operator>>
	std::string roman = "X";
	std::stringstream ss(roman);

	Roman_int r4;
	ss >> r4;

	std::cout <<"3. Roman numeral: "<< r4 <<" Arabic numeral: "<< r4.as_int() <<'\n';

	// input validity
	std::string value3 = "VX";
	Roman_int r5(value3);
}
