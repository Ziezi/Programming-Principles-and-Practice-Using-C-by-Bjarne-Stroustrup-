/*
	TITLE			   Class Book			          Chapter9Exercise8.cpp
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: 
			Data members:		Function members:	    Overloaded operators:    Helper Functions:
			userName			get_user_name();		operator<<			     valid_input();
			libraryCardNumber   get_library_number();
			libraryFees		    get_library_fees();
								fee_exists();
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 16.03.2015
*/
#include <iostream>
#include <string>
#include <vector>
#include "Chapter9Exercise8.h"

void test_function();

//==============================================================================
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
//==============================================================================

void test_function()
{
	 Patron p;
	 Patron p2("Chris Kirov", "20092058", 0);

	 std::cout <<"Welcome to this simple library account system.\n";
	 std::cout << p2;

	 std::cout <<"Outstanding Fees:\n";
	 if (p2.fee_exists())
	 {
		 std::cout << p2.get_library_fee() <<'\n';
	 }
	 else
	 {
		 std::cout <<"no fees\n";
	 }
}