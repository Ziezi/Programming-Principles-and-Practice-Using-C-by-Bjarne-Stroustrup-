/*
	TITLE		    Compare strings		     Chapter18Exercise6.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Modify cat_dot() function to concatenate two strings
					adding a separator in between, as third argument.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 25.12.2015
*/
#include <iostream>
#include <string>

std::string cat_dot (const std::string& s1, const std::string& s2, const std::string& sep)
{
	return s1 + sep + s2;
}

int main ()
{
	try
	{
		std::string s1 = "Hristo";
		std::string s2 = "Botev";

		std::cout << cat_dot(s1, s2, " ");
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	catch (...) {
		std::cerr << "Unhandled exception\n";
	}
	getchar();
}
 

 