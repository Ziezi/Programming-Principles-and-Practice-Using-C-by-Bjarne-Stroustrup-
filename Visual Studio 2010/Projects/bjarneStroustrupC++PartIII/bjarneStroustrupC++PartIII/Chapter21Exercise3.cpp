/*
	TITLE		    Implement count() 		 Chapter21Exercise3.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: 
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 27. 02. 2017
*/
#include <iostream>
#include <vector>

template <class Iterator, class T>
size_t count (Iterator first, Iterator last, const T& target)
{
	size_t occurences = 0;
	while (first != last)
	{
		if (*first == target)
		{
			++occurences;
		}
		++first;
	}
	return occurences;
}

//------------------------------------------------------------------

int main()
{
	try
	{
		std::vector<int> v(10, 2);
		std::vector<int> v2;

		std::cout <<"Count: "<< count(v.begin(), v.end(), 2);
		std::cout <<"\nCount: "<< count(v.begin(), v.end(), 3);
		std::cout <<"\nCount: "<< count(v2.begin(), v2.end(), 1);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}