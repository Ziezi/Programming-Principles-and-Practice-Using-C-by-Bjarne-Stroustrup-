/*
	TITLE  			   Sum of integers					Chapter5Exercise8.cpp
	 Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Input a set of numbers and sum the first n of them.
					   Error handling performed implicitly by the member
					   functions of the std::vector. (subscript operator[] has range check)
				Input: Type a set of integers. Type the number n.
			   Output: The wanted sum.
			   Author: Chris B. Kirov
				 Date: 5. 1 . 2015	   
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void populate_vector(std::vector<int>&);
void print_vector(const std::vector<int>&, unsigned int);
void sum_vector_elements(const std::vector<int>&, unsigned int);

//=================================================================================================
int main()
{
	std::vector<int> numbers;

	populate_vector(numbers);

	std::cout << "\nYou have entered the following numbers: ";
	int elements_per_line = 5;
	print_vector(numbers, elements_per_line);

	std::cout << "\nPlease enter how many of the numbers you wish to sum:\n>>";
	int number_of_summed_elements = 0;
	std::cin >> number_of_summed_elements;
	 
	sum_vector_elements(numbers, number_of_summed_elements);
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
void populate_vector(std::vector<int>& v)
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
void print_vector(const std::vector<int>& v, unsigned int per_line)
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
	Function: sum_vector_elements()
	Use: sum_vector_elements(vect_int, first_n);

	It sums and prints the first_n elemenents
	of the vector passed by reference.
*/
void sum_vector_elements(const std::vector<int>& v, unsigned int number_of_summed_elements)
{
	int sum = 0;
	for (unsigned int i = 0; i < number_of_summed_elements; ++i)
	{
		sum += v[i];
	}

	std::cout << "The sum of the first: " << number_of_summed_elements << " numbers: ";

	print_vector(v, v.size());

	std::cout << "is: "<< sum << std::endl;
}

