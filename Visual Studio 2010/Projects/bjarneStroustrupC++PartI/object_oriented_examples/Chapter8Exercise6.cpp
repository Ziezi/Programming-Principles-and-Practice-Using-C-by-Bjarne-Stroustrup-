/*
	TITLE			   Reverse order of vector of string   Chapter8Exercise6.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Write two functions that reverse the order of elements
					   in a vector of strings: 
					   - return the same vector with reversed elements.
					   - return new vector with reversed elements.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 04.03.2015
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

void reverseElements(std::vector<std::string>&);
void reverseElements(const std::vector<std::string>&, std::vector<std::string>&);
void print_vector(const std::string&, std::vector<std::string>&);

//================================================================================================
int main()
{
	// define and initialize vector
	std::vector<std::string> words;
	size_t size = 10;
	for (size_t i = 0; i < size; ++i) 
	{
		char c = 'a' + i;
		std::string element(1, c);
		words.push_back(element);
	}

	// print elements
	std::string label("Elements:");
	print_vector(label, words);
	
	// reverse and print elements
	reverseElements(words);
	label = "Reversed Elements:";
	print_vector(label, words);

	// define a vector to hold reversed elements
	std::vector<std::string> reversed_words;
	reverseElements(words, reversed_words);

	// print elemenets
	label = "Elements:";
	print_vector(label, reversed_words);
}
//================================================================================================
 
/*
	Function: reverseElements(container);

	It reverses the elements of the vector
	passed by reference.
*/
void reverseElements(std::vector<std::string>& v)
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
void reverseElements(const std::vector<std::string>& in, std::vector<std::string>& out)
{
	  for (int i = in.size() - 1; i >= 0; i--)
	  {
		 out.push_back(in[i]);
	  }
}

/*
	Function: print_vector(label, container);


*/
void print_vector(const std::string& label, std::vector<std::string>& v)
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