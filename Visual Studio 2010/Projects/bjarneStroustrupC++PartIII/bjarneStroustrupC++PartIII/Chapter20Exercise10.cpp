/*
	TITLE		    Count words in Document  Chapter20Exercise10.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define a function that counts the words in
					Document, where a word is defined via the
					string argument.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 21. 02. 2017
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
		std::cout <<"Number of characters: "<< text.get_word_number("1. ") <<'\n';
	}
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}