/* 
	TITLE			   Fibonacci vector				Chapter8Exercise3.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Read a number n; 
			           Create and print vector containing
					   the first n Fibonacci numbers.
				Input: -
			   Output: Contents of the vector.
			   Author: Chris B. Kirov
			     Data: 03.03.2015
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

void print_vector(std::string&, std::vector<long>&);
void fibonacci(std::vector<long>&,  int);
 
//===========================================================================
int main()
{
	std::string label("The fibonacci numbers:");
	std::vector<long> fibonacciNubmbers;

	std::cout <<"How many Fibonacci numbers do you want to calculate:\n>>";
	int upper_bound = 0;
	std::cin >> upper_bound;

	fibonacci(fibonacciNubmbers, upper_bound);
	print_vector(label, fibonacciNubmbers);
}

//============================================================================

/*
	Function: fibonacci(container, number);

	It calculates a "number" of fibonacci and 
	stores them in the vector passed as first 
	parameter.
*/
void fibonacci(std::vector<long>& v, int upper_bound)
{
	int first = 0, second = 1;
	v.push_back(first);
	v.push_back(second);
	
	for (int i = 0; i < upper_bound - 2; ++i)
	{
		v.push_back(v[v.size() - 1] + v[v.size() - 2]);

		// prevent overflow
		if (v[v.size() - 1] < 0 || v[v.size() - 1] < v[v.size() - 2])
		{
			std::cerr <<"Overflow at the: "<< v.size() <<" element.\n";
			v.pop_back();
			return;
		}
	}
}

/*
	Function: print_vector(label, container);

*/
void print_vector(std::string& label, std::vector<long>& v)
{
	std::cout << label << "\n";
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		// each element is alligned to the rigth on 10 space field
		std::cout << std::setw(10) << std::right << v[i];		

		// separate each element by comma
		if (i != v.size() - 1)
		{	
			std::cout <<",";
		}

		// five elements per line
		if (i % 5 == 0 && i != 0)
		{
			std::cout <<'\n';
		}
	}
	std::cout << "\n";
}