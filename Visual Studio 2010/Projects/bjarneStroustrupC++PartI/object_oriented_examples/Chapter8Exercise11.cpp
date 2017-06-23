 /*
	TITLE	           Max element     		     Chapter8Exercise11.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++
	COMMENT
			Objective: Write a function that finds the largest element
			           of a vector.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 10.03.2015
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>

double maxv(const std::vector<double>&);
void populate_vector(std::vector<double>&);

//============================================================================

int main()
{
	std::vector<double> numbers;
	 
	std::cout <<"Find max element of a vectors\n";
	populate_vector(numbers);

	std::cout <<"Max element: "<< maxv(numbers) <<"\n";
}

//============================================================================

/*
	Function: populate_vectors(numbers);

	It runs an input loop populating the 
	vector.
*/
void populate_vector(std::vector<double>& v)
{
	std::string prompt("Type value; 'q' to end.\n>>");
	std::string sentinel("q");

	// read values
	while(true)
	{
		std::cout << prompt;
		std::string input;
		getline(std::cin, input);

		if (input == sentinel)
		{
			break;
		}

		std::stringstream ss(input);

		double price_value;
		if (ss >> price_value)
		{
			v.push_back(price_value);
		}
		else
		{
			std::cout <<"Wrong input format!\n";
		}
	}
}

/*
	Function: int max_element = maxv(numbers);

	It returns the maximum element of the vector.
*/
double maxv(const std::vector<double>& v)
{
	double max = std::numeric_limits<int>::min();
	for (size_t i = 0; i < v.size(); ++i)
	{
		 max = (v[i] > max) ? v[i] : max;
	}
	return max;
}