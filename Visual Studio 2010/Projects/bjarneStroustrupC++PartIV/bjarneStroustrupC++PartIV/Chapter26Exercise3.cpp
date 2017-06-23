/* 
	TITLE		   Generalise binary_search and add custom Comparator	Chapter26Exercise3.cpp
	COMMENT
		Objective: Repeat the exercise in §26.2.1 with the version of binary_search that
				   takes a comparison criterion. 
				   Make a list of new opportunities for errors introduced by that extra argument.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 31.05.2017
*/
#include <iostream>
#include <string>
#include <vector>

//--------------------------------------------------------------------------------------------
/*
	Possible Errors introduced through LessCmp:
	- no comparison operator< for type T.
	- template type mismatch?
	- comparison not defined properly?
*/
template <typename T>
struct LessCmp
{
	bool operator()(const T& lhs, const T& rhs)
	{
		return lhs < rhs;
	}
};

//--------------------------------------------------------------------------------------------

template <typename It, typename T, typename Compare>
bool binary_search(It begin, It end, const T& target, Compare comp)
{
	while (begin != end)
	{
		auto offset  = std::distance(begin, end);
		It middle = begin;
		std::advance(middle, offset / 2);

		if (comp(target, *middle))		  // target < middle
		{
			end = middle;
		}
		else if (comp(*middle, target))   // target > middle
		{
			begin = middle;
			std::advance(begin, 1);
		}
		else							  // target == middle
		{
			return true;
		}
	}

	return false;
}

//--------------------------------------------------------------------------------------------

int main()
{
	try
	{
		const int size = 6;
		int arr[size] = { 1, 2, 3, 4, 5, 6 };
		int* begin = arr;
		int* end = arr + size;

		int target = 1;

		bool found = binary_search(begin, end, target, LessCmp<int>());

		if (!found)
		{
			std::cout <<"Element: " << target <<" not found in the array!\n";
		}
		else
		{
			std::cout <<"Element: " << target <<" found in the array.\n";
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}