/*
	TITLE          Game: "Bulls & Cows"		    Chapter5Exercise13.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
    COMMENT
		Objective: Guess the value and position of a set of 4  
		           randomly generated numbers.
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
#include <time.h>  

bool doYouWin(const std::vector<int>&, const std::vector<int>&);
void runGame();
int random(unsigned int, unsigned int);

//===================================================================
int main()
{
	runGame();
}
//===================================================================

void runGame()
{
	// input loop
	std::string prompt = "Type four numbers separated by white space; 'q' to exit.\n>>";
	std::string sentinel = "q";
	std::string input;
	while (true)
	{
		// generate random values
		std::vector<int> password(4);
		password[0] = random(0,9);
		password[1] = random(0,9); 
		password[2] = random(0,9);
		password[3] = random(0,9);

		// std::cout <<"password: "<< password[0] << password[1] << password[2] << password[3]<<'\n';

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

/*
	Function: random()
	Use: int num = random(min, max)

	It generates a pseudo-random
	number in the interval [min, max].
*/
int random(unsigned int min ,unsigned int max)
{
	static bool initialized = false;
	if (!initialized)
	{
		srand(time(NULL));
		initialized = true;
	}
	return rand() % max + min;
}

