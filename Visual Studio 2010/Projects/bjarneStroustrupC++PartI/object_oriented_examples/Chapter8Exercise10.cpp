/*
	TITLE	           Weigthed sum     		  Chapter8Exercise10.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++
	COMMENT
			Objective: Write a function that sums the product of two vectors.
			           One of whom may be of smaller size.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 10.03.2015
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

double calculate_index(const std::vector<double>&, const std::vector<double>&);
void populate_vectors(std::vector<double>&, std::vector<double>&);

//============================================================================

int main()
{
	std::vector<double> price;
	std::vector<double> weight;

	std::cout <<"Calculates sum of products of two vectors\n";
	populate_vectors(price, weight);

	std::cout <<"Index: "<< calculate_index(price, weight) <<"\n";
}

//============================================================================

/*
	Function: populate_vectors(weight, price);

	It runs an input loop populating the 
	two vectors.
*/
void populate_vectors(std::vector<double>& price, std::vector<double>& weight)
{
	std::string prompt1("Type price; 'q' to end.\n>>");
	std::string prompt2("Type weight; 'q' to end.\n>>");
	std::string sentinel("q");

	// read prices
	while(true)
	{
		std::cout << prompt1;
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
			price.push_back(price_value);
		}
		else
		{
			std::cout <<"Wrong input format!\n";
		}
	}

	// read weights
	while(true)
	{
		std::cout << prompt2;
		std::string input;
		getline(std::cin, input);

		if (input == sentinel)
		{
			break;
		}

		std::stringstream ss(input);

		double weight_value;
		if (ss >> weight_value)
		{
			weight.push_back(weight_value);
		}
		else
		{
			std::cout <<"Wrong input format!\n";
		}
	}
}

/*
	Function: int index = calculate_index(weight, price);

	It returns the sum of the products of the elements
	of the two vectors.
*/
double calculate_index(const std::vector<double>& price, const std::vector<double>& weight)
{
	double sum = 0;
	for (size_t i = 0; i < price.size(); ++i)
	{
		double w = 1;
		// if weight < price
		if (i < weight.size())
		{
			w = weight[i];
		}
		sum += w * price[i];
	}
	return sum;
}