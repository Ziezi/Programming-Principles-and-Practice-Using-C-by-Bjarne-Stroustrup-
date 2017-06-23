/*
	TITLE		  String separation  			  Chapter11Exercise9.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Create a function that returns 
				   vector of whitespace separated substrings
				   of a string passed as argument.
		    Input:  
		   Output:  
		     Date: 24.08.2015
		   Author: Chris B. Kirov
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void split(std::string&, std::vector<std::string>&);
void print(std::vector<std::string>&);

//-----------------------------------------------------------------------------------------------------
int main()
{
	try
	{
		std::cout << "This program separates a string into a vector of its substrings.\n";

		std::string sentinel = "quit";
		std::string input;
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

		    split(input, substrings);

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
	Function: split()

*/
void split(std::string& input, std::vector<std::string>& v)
{
	std::stringstream ss(input);

	std::string word; 
	while(ss >> word)
	{
		v.push_back(word);
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