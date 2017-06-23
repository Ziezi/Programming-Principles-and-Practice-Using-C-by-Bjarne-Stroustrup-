/*
	TITLE			   Combination/ Permutaion Calculator	Chapter6Exercise10.cpp
    Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Implement a permutation/calculation calculator.
				Input: Type two numbers (Total elements, asked elements),
				       select operation.
			   Output: Returns the result of the selected operation.
			   Author: Chris B. Kirov
			     Data: 16.02.2015
*/
#include "stdafx.h"

void calculate();
double factorial(int);
double permutation(int, int);
double combination(int,int);

//===========================================================================================
int main()
{
	try
	{
		calculate();
	}
	catch(runtime_error& e)
	{
		std::cerr << "runtime error: "<< e.what() << endl;
		getchar();
		return 1;
	}
	catch(...)
	{
		std::cerr << "unknown exception!" << endl;
		getchar();
		return 1;
	}
}
//===========================================================================================

/*
	Function: calculate();

	It runs the input loop,
	calls the needed functions.
*/
void calculate()
{
	std::cout << "\t\tWelcome to our Permutation & Combination calculator\n";
	std::cout << "\t\tChoose k Permutations/Combinations out of n elements.\n";

	std::string prompt = "\nType integers k and n separated white space; 'x' to exit: \n>>";
	std::string sentinel = "x";
	std::string input;

	while(true)
	{
		std::cout << prompt;
		getline(std::cin, input);

		if (input == sentinel)
		{
			break;
		}

		int k = 0; // combinations
		int n = 0; // total elements
		std::stringstream ss(input);
		ss >> k >> n;

		int Permutation = 1;
		int Combination = 2;
		std::cout << "Type number to select operation:\n";
		std::cout << "1.Calculate permutations.\n";
		std::cout << "2.Calculate combinations.\n>>";

		int selectOperation = 0;
		getline(std::cin, input);
		
		std::stringstream ss1(input);
		ss1 >> selectOperation;

		if (selectOperation == Permutation)
		{
			std::cout << "There are: " << permutation(k,n) << " permuations of " << k <<" elements in: " << n << " elements."<< std::endl;  
					 
		}
		else if (selectOperation == Combination)
		{
			std::cout << "There are: " << combination(k,n) << " combinations of " << k << " elements in: " << n << " elements." << std::endl;  
		}
		else
		{
			std::cerr <<"Operation not supported !\n";
		}
	}
}

/*
	Function: factorial(int num)
	Use: int fact = factorial(int num)

	Recursively calculates the factorial of
	the input argument.  
*/  
double factorial(int num)
{   
	if (num < 0)
	{
			std::cerr << "factorial input must be positive!\n";
	}

	if (num < 1)
	{
		return 1;
	}
	else
	{
		return num * factorial(num - 1);
	}
}

//-------------------------------------------------------------------------------------------
/*
	Function: permutation(int k,int n)
	Use: double perm = permutation(int k, int n)

	Calculates the permutation of k out of n elements, 
	by calling factorial function twice.
*/
double permutation(int k, int n)
{
	if (k < 0 || n < 0)
	{
		std::cerr << "permutation: k and n must be positive!\n";
	}

	if (k > n)
	{
		std::cerr << "permutation: k must be subset of n!\n";
	}

	double enumerator = factorial(n);
	double denomenator = factorial(n - k);
	return enumerator / denomenator;
}

//-------------------------------------------------------------------------------------------
/*
	Function: combination(int k,int n)
	Use: double comb = combination(int k, int n)

	Calculates the combination of k out of n elements, 
	by calling permutation and factorial function.
*/
double combination(int k, int n)
{
	if (k < 0 || n < 0)
	{
		std::cerr << "combination: k and n must be positive!\n";
	}

	if (k > n)
	{	
		std::cerr << "combination: k must be subset of n!\n";
	}

	double enumerator = permutation(k, n);
	double denomenator = factorial(k);
	return enumerator / denomenator;
}