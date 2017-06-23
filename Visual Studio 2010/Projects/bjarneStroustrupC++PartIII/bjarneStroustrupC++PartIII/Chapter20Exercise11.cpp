/*
	TITLE		    List<int> to vector<double>  Chapter20Exercise11.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Give a list `std::list<int>` as a 
					(by - reference) parameter, make a 
					`std::vector<double>` and copy the 
					elements of the list into it. 
					Verify the copy was correct and complete. 
					Print the elements sorted in increasing value.  
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 21. 02. 2017
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

template<class T>
void print (T begin, T end)
{
	for (auto i = begin; i != end; ++i)
	{
		std::cout << *i <<" "; 
	}
	std::cout <<'\n';
}

//---------------------------------------------------------------

void f (std::list<int>& l)
{
	std::vector<double> v(l.begin(), l.end());

	std::sort(v.begin(), v.end());

	print(v.begin(), v.end());
}

//---------------------------------------------------------------

void initialize(std::list<int>& l, size_t n)
{
	srand((unsigned int)time(NULL));
	for (size_t i = 0; i < n; ++i)
	{
		l.push_back(rand());
	}
}

//---------------------------------------------------------------

int main()
{
	try 
	{ 
		 std::list<int> l;
		 
		 size_t elements = 10;
		 initialize(l, elements);

		 print(l.begin(), l.end());

		 f(l);
	}
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}