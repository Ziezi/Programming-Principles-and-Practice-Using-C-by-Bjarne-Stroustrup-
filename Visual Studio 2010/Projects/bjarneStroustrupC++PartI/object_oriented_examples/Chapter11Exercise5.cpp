/*
	TITLE		   Replace puntucation with whitespace  Chapter11Exercise5.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Accepts text and replaces punctuation with whitespce.
			Input: -
		   Output: -
		     Date: 02.07.2015
		   Author: Chris B. Kirov
*/
#include <iostream>
#include <string>

std::string replace_punctuation_with_whitespace(std::string&);

//=======================================================================================
int main()
{
	try
	{
		std::cout << "This program replaces punctuation with whitespace.\n";

		std::string sentinel = "quit";
		while (true)
		{
			std::cout <<"\nPlease type a text, including punctuation; 'quit' to exit.\n>>";
			std::string text;
			getline(std::cin, text);

			if (text == sentinel)
			{
				break;
			}

			std::cout << "Edited text:\n>>"; 
			std::cout << replace_punctuation_with_whitespace(text);
		}
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		 
	}
}
//=======================================================================================

/*
	Function: replace_punctuation_with_whitespace()

*/
std::string replace_punctuation_with_whitespace(std::string& t)
{
	std::string no_punctuation;

	for(size_t i = 0; i < t.size(); i++)
	{
		no_punctuation += ispunct(t[i]) ? ' ' : t[i];
	}

	return no_punctuation;
}

 
