/*
	TITLE		    Count char in Document   Chapter20Exercise8.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define a function that counts the characters in
					Document.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 19. 02. 2017
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include "Chapter20Exercise6.h"

int main()
{
	try 
	{ 
		Document text;

		std::string s("Lorem Ipsum is simply dummy text\n of the printing and typesetting industry.");
		std::stringstream ss(s);
		ss >> std::noskipws >> text;

		std::cout << text <<'\n';
		std::cout <<"Number of characters: "<< text.get_char_number() <<'\n';
		std::cout <<"String size: "<< s.size();
	}
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}