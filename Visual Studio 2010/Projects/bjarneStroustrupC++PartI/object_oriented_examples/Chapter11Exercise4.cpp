/*
	TITLE		   Character Classification		Chapter11Exercise4.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Accepts string input and classifies each of its characters.
				   Prints the number of occurences of each character.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
		     Date: 2.07.2015
*/
#include <iostream>
#include <iomanip>
#include <string>

void classify_characters(const std::string& s);

//=======================================================================================
int main()
{
	try
	{
		std::cout <<"Character classification.\n";

		std::string sentinel = "quit";
		std::string input;
		while(true)
		{
			std::cout << "Type a string; 'quit' to exit\n>>";
			std::cin >> input;

			if (input == sentinel)
			{
				break;
			}

			classify_characters(input);
		}
		 
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
//=======================================================================================

/*
	Function: void print_table();
 
*/
void print_table(std::string identifiers[], int freuquency[], const size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << std::setw(7) << identifiers[i] <<" "<< std::setw(5) << freuquency[i] <<'\n';
	}
}

//---------------------------------------------------------------------------------------

/*
	Function: void charClassify()
	 
*/
void classify_characters(const std::string& s)
{
	const size_t size = 11;
	std::string identifiers[size] = { "space", "alpha", "digit", "xdigit", "upper", "lower", "alnum", "cntrl", "punct", "print", "graph" };
	int frequency[size] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (size_t i=0; i < s.length(); i++)
	{
		if (isspace(s[i])) frequency[0] += 1; 
		if (isalpha(s[i])) frequency[1] += 1;
		if (isdigit(s[i])) frequency[2] += 1;
		if (isxdigit(s[i])) frequency[3] += 1;
		if (isupper(s[i])) frequency[4] += 1;
		if (islower(s[i])) frequency[5] += 1;
		if (isalnum(s[i])) frequency[6] += 1;
		if (iscntrl(s[i])) frequency[7] += 1;
		if (ispunct(s[i])) frequency[8] += 1;
		if (isprint(s[i])) frequency[9] += 1;
		if (isgraph(s[i])) frequency[10] += 1;
	}

	print_table(identifiers, frequency, size);
}

