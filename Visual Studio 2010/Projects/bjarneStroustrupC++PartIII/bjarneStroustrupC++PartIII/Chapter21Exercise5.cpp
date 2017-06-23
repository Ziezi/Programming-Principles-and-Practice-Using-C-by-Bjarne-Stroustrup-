/*
	TITLE		    No end() 				 Chapter21Exercise5.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Reimplement count() and count_if() without
					end() iterator.

					Side effects: 
					- missing last element
					- difficulties in defining closed intervals [b, e - 1]
					  in for, while loops.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 27. 02. 2017
*/
#include <iostream>
#include <vector>

//------------------------------------------------------------------

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

		std::cout <<"Count: " << count(v.begin(), v.end() - 1, 2);
		std::cout <<"\nCount: " << count_if(v.begin(), v.end() - 1, Less(3));
		std::cout <<"\nCount: " << count_if(v.begin(), v.end() - 1, Less(1));
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}