/*
	TITLE			Class Int				Chapter19Exercise5.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Define a class Int having a single member 
					of type int. Define constructors, assignment, 
					operators +, -, /, *, I/O opeators <<, >>.

					Test and improve desing as needed.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 24.1.2016
*/
#include <iostream>
#include <algorithm>
#include "Chapter19Exercise5.h"

int main ()
{
	try
	{
		// Test class Int members

		// default constructor
		Int a;

		// consrtuctor
		Int b(5);

		// copy constuctor
		Int c = 5;
	
		// copy assingment
		Int d(c);

		// operator+
		Int add = a + b;

		// operator-
		Int sub = a - b;

		// operator/
		Int div = b / c;

		// operator*
		Int mul = b * c;

		// I/O operators
		std::cout <<"default: "<< a <<'\n';
		std::cout <<"constructor: "<< b <<'\n';
		std::cout <<"copy constructor: "<< c <<'\n';
		std::cout <<"copy assignment: "<< d <<'\n';
		std::cout <<"addition: "<< add <<'\n';
		std::cout <<"subtraction: "<< sub <<'\n';
		std::cout <<"division: "<< div <<'\n';
		std::cout <<"multiplication: "<< mul <<'\n';
	
		Int input;
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