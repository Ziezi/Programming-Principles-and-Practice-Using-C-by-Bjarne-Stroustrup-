/*
	TITLE		    Compare strings			 Chapter18Exercise4.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Test the functions for non-zero terminated strings. 
					Modify the functions to handle non-zero terminated strings.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 25.12.2015
*/
#include <iostream>
#include <sstream>
#include "Chapter18Exercise4.h"

int main ()
{
	try
	{
		test1();

		test2();

		test3();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	catch (...)
	{
		std::cerr << "Unhandled exception!\n";
	}
	getchar();
}

