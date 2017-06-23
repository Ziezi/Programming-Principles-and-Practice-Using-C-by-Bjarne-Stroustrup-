/*
	TITLE		   Fibonacci numbers	        Chapter5Exercise11.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
    COMMENT
		Objective: Compute the first N Fibonacci numbers.
			Input: N (the number of Fibonacci numbers to be diaplayed).
		   Output: The largest Fibonacci that fits in an int is the:
				   46 th and its value is: 1836311903.
		   Author: Chris B. Kirov
		     Date: 5. 1 . 2015
*/
#include <iostream>
#include <vector>

void find_fibonacci(std::vector<int>&, unsigned int);
void print_vector(const std::vector<int>&, unsigned int);
bool isMaxIntFibonacci(int);

//=================================================================================================

int main()
{
	int first_fibonacci = 0;
	int second_fibonacci = 1;

	std::vector<int> fibonacci_numbers;
	fibonacci_numbers.push_back(first_fibonacci);				
	fibonacci_numbers.push_back(second_fibonacci);				 

	std::cout <<"How many Fibonacci numbers do you want to find:\n>>";
	int number = 0;
	std::cin >> number;

	find_fibonacci(fibonacci_numbers, number);

	int per_line = 5;
	print_vector(fibonacci_numbers, per_line);

	std::cout <<"The largest Fibonacci that fits in an int is the: "
			  << fibonacci_numbers.size() - 1 <<" th "
			  <<"with value: "<< fibonacci_numbers[fibonacci_numbers.size() - 1] <<'\n';
}
//=================================================================================================

/*
	Function: find_fibonacci()
	Use: find_fibonacci(vect, num);

	It calculates the first num 
	Fibonacci numbers and stores
	them in vect.
	Assumes vect contains the first
	two Fibonacci numbers.
*/
void find_fibonacci(std::vector<int>& v, unsigned int index)
{
	for (unsigned int i = 0; i < index; ++i)
	{
		if (isMaxIntFibonacci(v[v.size() - 1]))
		{
			v.pop_back();
			break;
		}
		v.push_back(v[v.size() - 1] + v[v.size() - 2]);
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
	std::cout <<'\n';
}

//-------------------------------------------------------------------------------------------------
/*
	Function: isMaxIntFibonacci()
	Use: isMaxIntFibonacci(fib_num);

	Check if the parameter is the
	largest Fibonacci that fits 
	in int.

	It checks for overflow, signified
	by sign shift.
*/
bool isMaxIntFibonacci(int n)
{
	if (n < 0)
	{
		return true;
	}
	return false;
}