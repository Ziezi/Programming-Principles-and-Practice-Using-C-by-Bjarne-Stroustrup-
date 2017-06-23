/*
	TITLE          Game: "Bulls & Cows"		    Chapter5Exercise12.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
    COMMENT
		Objective: Guess the value and position of a set of 4 numbers.
			Input: Guessed quadruplet of numbers.
		   Output: Bull(for every guessed value & place); 
		           Cow (for every guessed value)
		   Author: Chris B. Kirov
		     Date: 5. 1 . 2015
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

bool doYouWin(const std::vector<int>&, const std::vector<int>&);
void runGame();

//===================================================================
int main()
{
	runGame();
}
//===================================================================

void runGame()
{
	// password digits
	const int first = 2;
	const int second = 4;
	const int third = 1;
	const int forth = 5;

	std::vector<int> password(4);
	password[0] = first;
	password[1] = second; 
	password[2] = third;
	password[3] = forth;

	// input loop
	std::string prompt = "Type four numbers separated by white space; 'q' to exit.\n>>";
	std::string sentinel = "q";
	std::string input;
	while (true)
	{

		// read input
		std::cout << prompt;
		getline(std::cin, input);

		// quit ?
		if (input == sentinel)
		{
			return;
		}

		// extract input
		std::vector<int> guess;
		std::stringstream ss(input);
		int digit = 0;
		while (ss >> digit)
		{
			guess.push_back(digit);
		}
		 
		// check input validity
		if (guess.size() != password.size())
		{
			std::cerr <<"Wrong input!\n";
		}
		else 
		{
			// check game result
			if (doYouWin(password, guess))
			{
				std::cout <<"You win!\n";
				return;
			}
		}
	}			
}


/*
	Function: doYouWin()
	Use: bool allSame = doYouWin(vect_a, vect_b);

	Compares wether all elements with the same index
	of the two vectors passed by reference are equal
	and if so returns true.

	Prints equal elements with equal indexes as 
	bulls number and those with different indexes
	as cow number.
*/
bool doYouWin(const std::vector<int>& a, const std::vector<int>& b)
{
	// cow: value match
	int cow = 0;
	// bull: value and index match
	int bull = 0;

	for (size_t i = 0; i < a.size(); ++i)
	{
		for (size_t j = 0; j < b.size(); ++j)
		{
			if (a[i] == b[j] && i == j)
			{
				++bull;
			}
			else if (a[i] == b[j] && i != j)
			{
				++cow;
			} 
		}
	}

	std::cout <<"Cows: "<< cow <<" Bulls: "<< bull <<'\n';

	if (bull == a.size())
	{
		return true;
	}
	return false;
}