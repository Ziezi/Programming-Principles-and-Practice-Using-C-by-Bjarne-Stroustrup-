/* 
	TITLE			   Print vector content	     Chapter8Exercise2.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Create a print function that prints the content of
					   vector of ints to cout.
				Input: -
			   Output: Contents of the vector.
			   Author: Chris B. Kirov
			     Data: 03.03.2015
*/
#include <iostream>
#include <string>
#include <vector>

void print_vector(std::string&, std::vector<int>&);

//=========================================================================
int main()
{
	std::string vector_label("Vector of integers:");
	std::vector<int> numbers(10, 5);
	
	print_vector(vector_label, numbers);
}

//=========================================================================
void print_vector(std::string& label, std::vector<int>& v)
{
	std::cout << label << "\n";
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i];		 
		if (i != v.size() - 1) std::cout <<", ";
	}
	std::cout << "\n";
}