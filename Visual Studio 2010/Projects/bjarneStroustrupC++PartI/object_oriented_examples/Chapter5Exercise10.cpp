/*
	TITLE  			   Adjacent differences	     Chapter5Exercise10.cpp
	 Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Input a set of numbers into a vector
			           and find the differences of
					   the adjacent numbers.
					   Error handling performed implicitly by the member
					   functions of the std::vector. 
					   (subscript operator[] has range check)
			  	Input: Type a set of doubles. 
			   Output: The set of differences.
       		     Date: 23.02.2016	   
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void populate_vector(std::vector<double>&);
void print_vector(const std::vector<double>&, unsigned int);
void find_adjacent_differences(const std::vector<double>&, std::vector<double>&);

//=================================================================================================
int main()
{
	std::vector<double> numbers;
	std::vector<double> adjacent_differences;

	populate_vector(numbers);

	std::cout << "\nYou have entered the following numbers: ";
	int elements_per_line = 5;
	print_vector(numbers, elements_per_line);

	find_adjacent_differences(numbers, adjacent_differences);

	std::cout <<"The list of the adjacent differences is:\n";
	print_vector(adjacent_differences, adjacent_differences.size());
}
//=================================================================================================

/*
	Function: populate_vector()
	Use: populate_vector(vect_int);
	It runs an input loop reading
	a line of integers separated by 
	white space, used to populate 
	the vector passed by reference.
*/
void populate_vector(std::vector<double>& v)
{
	std::string prompt = "\nPlease enter a set of numbers; type ""|"" to exit.\n>>";
	std::string input;	
		
	while (true)
	{
		std::cout << prompt;
		getline(std::cin, input);

		if (input == "|")
		{ 
			return;
		}

		std::stringstream ss(input);
		
		int nums = 0;
		while (ss >> nums)
		{
			v.push_back(nums);
		}
	}
}

//-------------------------------------------------------------------------------------------------
/*
	Function: print_vector()
	Use: print_vector(vect_int, per_line);
*/
void print_vector(const std::vector<double>& v, unsigned int per_line)
{
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] <<", ";
		if (i % per_line == 0 && i != 0)
		{
			std::cout <<"\n";
		}
	}
}

//-------------------------------------------------------------------------------------------------
/*
	Function: find_adjacent_differences()
	Use: find_adjacent_differences(src, dest);

	It calculates the differences between 
	adjacent elements of the vector: src and 
	stores them into vector: dest.
*/
void find_adjacent_differences(const std::vector<double>& src, std::vector<double>& dest)
{
	for (unsigned int i = 0; i < src.size() - 1; ++i)
	{
		dest.push_back(src[i+1] - src[i]);
	}
}
