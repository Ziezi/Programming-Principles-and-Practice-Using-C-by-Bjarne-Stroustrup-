/*
	TITLE		   BinarySearch        	Chapter26BinarySearch.cpp
	COMMENT
		Objective: Write a binary search.
				   How do you know it is correct?
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 30.05.2017
*/
#include <iostream>
#include <vector>

/*
	Asssumes sorted containers.

	Parameters: 
		target - wanted value.
		begin - pointer/iterator to begining of container.
		end- pointer/iterator to end of container.
	Returns:
		- pointer/iterator to found element 
		- parameter: end, if element not found.
	Complexity: 
		O(logN)
	Exception Safety:
		- Basic exception safety.
	Tested:
		- for elements at all positions: [0, size - 1].
		- for targets larger and smaller than the elemens in the container.  
		- with pointers and iterators.
		- with array and std::vector of type int; with empty containers.
*/
template<typename T, typename it>
it binary_search(const T& target, it begin, it end)
{
	 it not_found = end;

	 while (begin != end)
	 {
		auto offset = std::distance(begin, end);
		it middle = begin;
		std::advance(middle, offset / 2);

		if (target == *middle)
		{
			return middle;
		}
		else if (target < *middle)
		{
			end = middle;
			// std::advance(end, -1); // forward iterators
		}
		else 
		{
			begin = middle;
			std::advance(begin, 1);
		}
	 }

	 return not_found;
}

//------------------------------------------------------------------------------------------------

void test()
{
	// single element
	// odd/even number of elements
	// all elements equal
	// different elements at the end of container
}

//------------------------------------------------------------------------------------------------

int main()
{
	const int size = 6;
	int arr[size] = { 1, 2, 3, 4, 5, 6 };
	int* begin = arr;
	int* end = arr + size;

	int target = 3;

	int* ptr = binary_search(target, begin, end);

	if (ptr == end)
	{
		std::cout <<"Element: " << target <<" not found in the array!\n";
	}
	else
	{
		std::cout <<"Element: " << *ptr <<" found in the array.\n";
	}
	getchar();

	std::vector<int> vec(begin, end);
	std::vector<int>::iterator it = binary_search(target, vec.begin(), vec.end());
	
	if (it == vec.end())
	{
		std::cout <<"Element: " << target <<" not found in the vector!\n";
	}
	else
	{
		std::cout <<"Element: "<< *it  <<" found in the vector.\n";
	}
	
	getchar();
}
