/*
	TITLE		   Text edit and character replacement	Chapter11Exercise6.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Accepts text and replaces punctuation with whitespce,
				   keeping hyphens within words untouched,
				   replaces apostrophes in words: 
				   can't and don't with: cannot and: do not,
				   converting all charactes to lowercase.
			Input: -
		   Output: -
		     Date: 02.07.2015
		   Author: Chris B. Kirov
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string modify_string(std::string&);

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
			std::cout << modify_string(text);
		}
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		 
	}
}
//=======================================================================================

/*
	Function: modify_string()

*/
std::string modify_string(std::string& t)
{
	// string to hold the modified result
	std::string no_punctuation;

	for(size_t i = 0; i < t.size(); i++)
	{
		// convert to lower case
		t[i] = tolower(t[i]);

		// remove punctuation
		if (ispunct(t[i]) && t[i] != '\'')
		{
			if (t[i] = '-')
			{
				if (i != 0 && i < t.size() - 1)
				{
					if (isalpha(t[i - 1]) && isalpha(t[i + 1]))
					{
						// do nothing
					}
					else
					{
						// replace with whitespace
						t[i] = ' ';
					}
				}
				else
				{
					// replace with whitespace
					t[i] = ' ';
				}
			}
			else 
			{
				// replace with whitespace
				t[i] = ' ';
			}
		}
	}

	// replace don't and can't
	std::stringstream ss(t);
	std::string word;

	// extract whitespace separated strings
	while (ss >> word)
	{
		if (word == "don't")
		{
			no_punctuation += "do not ";
		}
		else if (word == "can't")
		{
			no_punctuation = "cannot ";
		}
		else
		{
			no_punctuation += word + " ";
		}
	}

	return no_punctuation;
}

 