/*
	TITLE			Templatized Class Number    Chapter19Exercise6.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Define a class Number<T>
					having a single member of numeric type.
					Define constructors, assignment, operators +,-,/,*,
					I/O opeators <<, >>.

					Test and improve desing as needed.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 24.1.2016
*/
#include <iostream>
#include <algorithm>
#include <limits>
#include "Chapter19Exercise6.h"

int main () 
{
	try
	{
		// Test class Number<T> members
		// Tested for: int, double, float, unsigned int, long unsigned int

		Number<double> a;
		Number<double> b(5);
		Number<double> c = 5;
		Number<double> d(c);
		Number<double> add = a + b;
		Number<double> sub = a - b;
		Number<double> div = b / c;
		Number<double> mul = b * c;

		// operator%
		// doesn't work  for double
		// Number<double> mod = b % c;

		Number<int> int_a(16), int_b(15);

		std::cout <<"int a, b; a / b = " << int_a / int_b <<'\n';
		getchar();

		// operator<
		Number<double> smaller = 1.0;
		Number<double> larger = 1.00000000000001; // for type double fulfils inequality 10e-15
		//                      1.000000000000001 // fulfils equality 10e-16
	
		std::cout <<"epsilon: "<< std::numeric_limits<double>::epsilon() <<'\n';
		std::cout <<"double min: "<< std::numeric_limits<double>::min() <<'\n';

		std::cout <<"difference: "<< smaller - larger <<'\n';

		if (smaller < larger)
		{
			std::cout << smaller <<" < "<< larger <<'\n';
		}
		else 
		{
			std::cout << "truncation\n";
		}

		// operator== 
		if (smaller == larger) 
		{
			std::cout << smaller <<" == "<< larger <<'\n';
		}
		else 
		{
			std::cout << "smaller - larger > epsilon\n";
		}

		// I/O operators
		std::cout <<"default: "<< a <<'\n';
		std::cout <<"constructor: "<< b <<'\n';
		std::cout <<"copy constructor: "<< c <<'\n';
		std::cout <<"copy assignment: "<< d <<'\n';
		std::cout <<"addition: "<< add <<'\n';
		std::cout <<"subtraction: "<< sub <<'\n';
		std::cout <<"division: "<< div <<'\n';
		std::cout <<"multiplication: "<< mul <<'\n';
		// std::cout <<"modulus: "<< mod <<'\n';
	
		Number<double> input;
		std::cout <<"Type an Int:\n>>";
		std::cin >> input;
		std::cout <<"You typed: "<< input;
		std::cin.ignore();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	catch (...)
	{
		std::cerr <<"Unhandled Exception!\n";
	}
	getchar();
}