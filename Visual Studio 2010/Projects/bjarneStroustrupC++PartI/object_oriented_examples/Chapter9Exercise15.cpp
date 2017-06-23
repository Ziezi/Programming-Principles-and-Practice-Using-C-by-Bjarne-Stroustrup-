 /*
	TITLE			   Class Money					 	Chapter9Exercise15.cpp
		   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Add data member currency and supporting functions.

					Data members:	Member functions:	Overloaded operators:	Helper functions:
									get_dollars()		copy assignment			round_and_convert()
								    set_dollars()		operator=				 
																				 
					cents			get_all_in_cents()	relational:				 
									set_all_in_cents()	operator<				convert_to_dollars_and_cents()
														operator>				convert_to_cents()
					Invalid			Money()  			operator==
									Money(all_cents)	operator!=
								 	Money(dollars)		
														algebracaic:
					currency		get_currency()		operator+				valid_currency()
									set_currency()		operator-				initialize_currency_table()
														
														insertion/extraction:   initialize_conversion_table()
														operator<<				currency_convertor()
														operator>>
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 30.03.2015
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "Chapter9Exercise15.h"

void test_function();

//===============================================================================================================================
int main()
{
	try
	{
		test_function();		  
	}
	catch(Mycurrency::Money::Invalid)
	{
		std::cerr <<"Exception from Class Money caught!"<< std::endl;
	}
}
//===============================================================================================================================

/*
	Function: test_function();

	Test (not fully) all the
	functions related to class
	Money.
*/
void test_function()
{
	using namespace Mycurrency;
	 
	double dollars = 12.50;
	std::string USD = "USD"; 
	Money amount(dollars, USD);
	std::cout<<"1. Amount in cents: "<< amount.get_all_in_cents() <<", in dollars: "<< amount <<'\n';


	std::cout <<"\n2. Default constructor value: "<< Mycurrency::Money() <<'\n';

	long long cents = 100005;
	std::string BGR = "BGN"; 
	Money m(cents, BGR);
	std::cout <<"\n3. Amount in dollars: "<< m <<" equivalent to: "<< m.get_all_in_cents() <<" cents\n";
			

	// relational operators ==, !=
	if (amount == m)
	{
		std::cout <<"\nObjects equal.\n";
	}
	else
	{
		std::cout <<"\nObjects NOT unequal.\n";
		
	}

	// relational operators <, >
	if (amount < m) 
	{
		std::cout << amount <<" < "<< m <<'\n';
	}
	else
	{
		std::cout << amount <<" > "<< m <<'\n';
	}

	// algebraic operations: +, - 
	std::cout << amount << " + " << m << " = " << amount + m <<'\n';
	std::cout << amount << " - " << m << " = " << amount - m <<'\n';
}
