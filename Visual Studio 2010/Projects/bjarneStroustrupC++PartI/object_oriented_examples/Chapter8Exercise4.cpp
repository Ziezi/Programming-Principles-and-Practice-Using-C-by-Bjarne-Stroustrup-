 /* 
	TITLE			   Max Fibonacci number	     Chapter8Exercise4.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Find the maximum Fibonacci number held in int.
				Input: -
			   Output: Contents of the vector.
			   Author: Chris B. Kirov
			     Data: 03.03.2015
*/
#include <iostream>
#include <vector>

void fibonacci(std::vector<int>&);
 
//===========================================================================
int main()
{
	std::vector<int> fibonacciNubmbers;
	fibonacci(fibonacciNubmbers);
}

//============================================================================

/*
	Function: fibonacci(container);

	It calculates the largest of the fibonacci
	that could be stored withing an int type.
*/
void fibonacci(std::vector<int>& v)
{
	int first = 0, second = 1;
	v.push_back(first);
	v.push_back(second);
	
	while (true)
	{
		v.push_back(v[v.size() - 1] + v[v.size() - 2]);

		// prevent overflow
		if (v[v.size() - 1] < 0 || v[v.size() - 1] < v[v.size() - 2])
		{
			std::cerr <<"Overflow at the: "<< v.size() - 1 <<" element.\n";
			v.pop_back();
			std::cout <<"The largest Fibonacci held in int is: "<< v[v.size() - 1] <<".\n";

			return;
		}
	}
}

