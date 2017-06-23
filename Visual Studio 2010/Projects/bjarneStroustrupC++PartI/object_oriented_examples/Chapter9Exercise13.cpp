/*
	TITLE			   Class Rational 				   Chapter9Exercise13.cpp
		   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Implement a class Rational representing a rational number.

					   Data members:	Member functions:	Overloaded operators:	Helper Function:
					   
					   numerator		get_numerator()		algebraic operations:	valid_rational()
					   denomenator		get_denominator() 	operator+				rational_simplification()
					   Invalid			to_fraction()		operator-				least_common_denominator()
															operator* 
															operator/
					   										operator= 
					   
															relational operators:
															operator==
															operator!= 
															operator<
															operator>
											 
															extraction / insertion
															operator<<
															operator>>

					   Why would someone want to use class Rational? 
					   To avoid rounding error (from algebraic operations) from floating point representation.
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 30.03.2015
*/
#include <iostream>
#include "Chapter9Exercise13.h"

void test_function();
//=====================================================================================================================
int main()
{
	try
	{
		test_function();
	}
	catch(Myrational::Rational::Invalid)
	{
		std::cerr <<"Exception caught!"<< std::endl;
	}
}
//=====================================================================================================================

/*
	Function: test_function();

	Tests (not fully) the functions
	related to class Rational.
*/
void test_function()
{
		std::cout <<"Default constructor value: "<< Myrational::Rational() <<'\n';
		std::cout <<"\nType a rational number in the form (numerator, denominator).\n>>";
		Myrational::Rational r1;
		std::cin >> r1;
		std::cout <<"Object initialized to: "<< r1 <<'\n';

		// toDouble()
		Myrational::Rational r2(1,2);
		double decimalrepresentation = r2.to_fraction();
		std::cout <<"\nThe rational number: "<< r2 << " in floating point representation: " << decimalrepresentation <<'\n';

		// assignment =
		Myrational::Rational r3 = r2;
		std::cout <<"\nInitialize new object using assignment: "<< r3 <<'\n';

		// relational operators ==, !=
		if (r3 == r2)
		{
			std::cout << "\nObjects equal.\n";
		}

		if (r3 != r2); 
		else 
		{
			std::cout << "\nObjects NOT unequal.\n";
		}

		// relational operators <, >
		if (r1 > r2)
		{
			std::cout << r1 << " > " << r2 <<'\n';
		}

		if (r1 < r3);
		else
		{
			std::cout << r1 << " greater than " << r2 <<'\n';
		}

		// algebraic operations: +, -, *, /;  rationalSimplification(), (indirectly)leastCommonDenominator()
		Myrational::Rational r4(3, 4), r5(5, 6);
		std::cout << r4 << " + " << r5 << " = " << r4 + r5 <<'\n';
		std::cout << r4 << " - " << r5 << " = " << r4 - r5 <<'\n';
		std::cout << r4 << " * " << r5 << " = " << r4 * r5 <<'\n';
		std::cout << r4 << " / " << r5 << " = " << r4 / r5 <<'\n';
}
