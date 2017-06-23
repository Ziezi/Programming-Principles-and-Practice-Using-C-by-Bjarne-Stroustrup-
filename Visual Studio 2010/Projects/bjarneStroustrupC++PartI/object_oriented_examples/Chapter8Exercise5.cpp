/*
	TITLE			   Reverse order of vector of int		Chapter8Exercise5.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Write two functions that reverse the order of elements
					   in a vector of integeres: 
					   - return the same vector with reversed elements.
					   - return new vector with the reversed elements of the first.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 03.03.2015
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

void reverseElements(std::vector<int>&);
void reverseElements(const std::vector<int>&, std::vector<int>&);
void print_vector(const std::string&, std::vector<int>&);

//================================================================================================
int main()
{
	// define and initialize vector
	std::vector<int> numbers;
	size_t size = 10;
	for (size_t i = 0; i < size; ++i) 
	{
		numbers.push_back(i);
	}

	// print elements
	std::string label("Elements:");
	print_vector(label, numbers);
	
	// reverse and print elements
	reverseElements(numbers);
	label = "Reversed Elements:";
	print_vector(label, numbers);

	// define a vector to hold reversed elements
	std::vector<int> reversed_numbers;
	reverseElements(numbers, reversed_numbers);

	// print elemenets
	label = "Elements:";
	print_vector(label, reversed_numbers);
}
//================================================================================================
 
/*
	Function: reverseElements(container);

	It reverses the elements of the vector
	passed by reference.
*/
void reverseElements(std::vector<int>& v)
{
	 for (size_t i = 0, j = v.size() -1; i < j; i++, j--)
	 {
		std::swap(v[i], v[j]); 
	 }
}

/*
	Function: reverseElements(in_container, out_container);

	It reverses the elements of the in_container and stores
	them in the out_container.
*/
void reverseElements(const std::vector<int>& in, std::vector<int>& out)
{
	  for (int i = in.size() - 1; i >= 0; i--)
	  {
		 out.push_back(in[i]);
	  }
}

/*
	Function: print_vector(label, container);


*/
void print_vector(const std::string& label, std::vector<int>& v)
{
	std::cout << label << "\n";
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		// each element is alligned to the rigth on 10 space field
		std::cout << std::setw(2) << std::right << v[i];		

		// separate each element by comma
		if (i != v.size() - 1)
		{	
			std::cout <<",";
		}

		// five elements per line
		if (i % 10 == 0 && i != 0)
		{
			std::cout <<'\n';
		}
	}
	std::cout << "\n";
}