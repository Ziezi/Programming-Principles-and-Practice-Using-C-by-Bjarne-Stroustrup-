/*
  TITLE          Game: "Bulls & Cows"	       Chapter6Exercise8.cpp
  Bjarne Stroustrup "Programming: Principles and Practice Using C++"
  COMMENT
      Objective: Redo Exercise 12 from Chapter 12 to use for letters
				 (characters) rather than four digits.
  	      Input: Guessed quadruplet of letters.
         Output: Bull(for every guessed value & place); 
                 Cow (for every guessed value)
           Date: 23.04.2015
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

bool doYouWin(const std::vector<char>&, const std::vector<char>&);
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
	const char first = 'a';
	const char second = 'b';
	const char third = 'c';
	const char forth = '1';

	std::vector<char> password(4);
	password[0] = first;
	password[1] = second; 
	password[2] = third;
	password[3] = forth;

	// input loop
	std::string prompt = "Type four characters separated by white space; 'q' to exit.\n>>";
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
		std::vector<char> guess;
		std::stringstream ss(input);
		char letter = 0;
		while (ss >> letter )
		{
			guess.push_back(letter);
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
bool doYouWin(const std::vector<char>& a, const std::vector<char>& b)
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