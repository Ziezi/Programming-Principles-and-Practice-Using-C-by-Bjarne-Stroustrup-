/*
	TITLE		   String separation	          Chapter11Exercise10.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Create a function that returns 
				   vector of whitespace separated substrings
				   of a string passed as argument.
				   Add second argument that defines additional
				   charactes interpreted as whitespace.  
		    Input: -
		   Output: -
		     Date: 24.08.2015
		   Author: Chris B. Kirov
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void split(const std::string& source, const std::string& whitespace, std::vector<std::string>& substrings);
void print(std::vector<std::string>&);

//-----------------------------------------------------------------------------------------------------
int main()
{
	try
	{
		std::cout << "This program separates a string into a vector of its substrings.\n";

		std::string sentinel = "quit";
		std::string input;
		std::string whitespace = ".;,";
		std::vector<std::string> substrings;

		std::string prompt("Please type a string:\n>> ");
		while (true)
		{
			std::cout << prompt;
			getline(std::cin, input);

			if (input == sentinel )
			{
				break;
			}

		    split(input, whitespace, substrings);
			print(substrings);
		}	 
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

//-----------------------------------------------------------------------------------------------------

/*
	Function: isDefinedWhiteSpace()
	 
	This function returns true if the first parameter is
	among the elements defined as whitespace, provided
	by the second parameter. Otherwise returns false.
*/
bool is_whitespace(const char& test_char, const std::string& whitespace)
{
	for(size_t i = 0; i < whitespace.size(); ++i)
	{
		if(test_char == whitespace[i] || isspace(test_char))
		{
			return true;
		}
	}
	return false;
}

/*
	Function: split()
	 
	This function separates the string, s, in substrings,
	defined by the characters in string, w, and stores
	them in a vector, v.
*/
void split(const std::string& source, const std::string& whitespace, std::vector<std::string>& substrings)
{
	std::string word;
	for(size_t i = 0; i < source.size(); ++i)
	{
		 if (is_whitespace(source[i], whitespace))
		 {
			substrings.push_back(word);
			word.clear();
		 }
		 else
		 {
			word += source[i];
		 }
	}
}

//-----------------------------------------------------------------------------------------------------

/*
	Function: print()

*/
void print(std::vector<std::string>& v)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] <<"\n";
	}
}