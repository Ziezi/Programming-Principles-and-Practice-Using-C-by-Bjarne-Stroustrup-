/*
	TITLE		    Concatenate strings		  Chapter18Exercise5.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Write a function, cat_dot(), that concatenated two strings
					with a dot in between.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 25.12.2015
*/
#include <iostream>
#include <string>

std::string cat_dot (const std::string& s1, const std::string& s2, const std::string middle_char = ".")
{
	return s1 + middle_char + s2;
}

int main ()
{
	try
	{
		std::string s1 = "Hristo";
		std::string s2 = "Botev";

		std::cout << cat_dot(s1, s2);
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


 