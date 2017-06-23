/*
	TITLE		   Floating number manipultors   Chapter11TryThis3.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: I / O data in:
				   fixed , scientific and general notation. 
			Input: 1234567.89
		    Ouput: 1.23457e+006    1234567.890000  1.234568e+006 
		   Author: Chris B. Kirov
		     Data: 19.05.2015
*/
#include <iostream>
#include <iomanip>

/* 
	Function: general()
	
	Manipulator setting default 
	format settings for floating point 
	numbers.
*/ 
std::ios_base& general(std::ios_base& b)
{
	// clear all floating-point format flags
	b.setf(std::ios_base::fmtflags(0), std::ios_base::floatfield);
	return b;
}

//=================================================================================================
int main()
{
	float number = 1234567.89;

	// default setting shows up to 6 digits rounded up using 4/5 rounding
	std::cout << number 
			  << std::fixed <<'\t'<< number 
		      << std::scientific <<'\t'<< number <<'\n';

	// show that sceintific is persistent
	std::cout << number <<'\n';

	// show functionality of manipulaor: general
	std::cout << general << number <<'\t' // it still prints in scientific to present the most accurate representation
		      << std::fixed << number <<'\t'
		      << std::scientific << number <<'\n';
}

