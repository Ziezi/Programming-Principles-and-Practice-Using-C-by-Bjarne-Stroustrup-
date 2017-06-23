/*
	TITLE		    Implement count_if() 	 Chapter21Exercise4.cpp
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

template <class Iterator, class Predicate>
size_t count_if (Iterator first, Iterator last , Predicate p)
{
	size_t occurences = 0;
	while (first != last)
	{
		if (p(*first))
		{
			++occurences;
		}
		++first;
	}
	return occurences;
}

//------------------------------------------------------------------

struct Less
{
	Less (int b) : bound(b) { }
	bool operator() (int src) { return src < bound;}

	int bound;
};

//------------------------------------------------------------------

int main()
{
	try
	{
		std::vector<int> v(10, 2);

		std::cout <<"Count: " << count_if(v.begin(), v.end() , Less(3));
		std::cout <<"\nCount: " << count_if(v.begin(), v.end() , Less(1));
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}