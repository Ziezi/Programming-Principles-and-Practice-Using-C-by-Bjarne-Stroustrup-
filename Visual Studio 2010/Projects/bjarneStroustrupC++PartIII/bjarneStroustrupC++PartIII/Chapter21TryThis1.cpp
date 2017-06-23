/*
	TITLE			find() implementations	   Chapter21TryThis1.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Write, test the functions find() and construct an argument for their
					being equivalent.

					Both functions have complexity linear on
					the size of the input data, i.e. : O(n).
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 25. 02. 2017
*/
#include <iostream>

template <class Iter, class T>
Iter find(Iter first, Iter last, const T& val)
{
	while (first != last && *first != val)
	{
		++first;
	}
	return first;
}

//-------------------------------------------------------------------

template <class Iter, class T>
Iter find2(Iter first, Iter last, const T& val)
{
	for (Iter p = first; p != last; ++p)
	{
		if (*p == val)
		{
			return p;
		}
	}
	return last;
}

//-------------------------------------------------------------------

int main()
{
	const size_t size = 10;
	int arr[size] = { 0, 1, 2, 3, 4, 5, 6, 7 ,8, 9 };

	int target = 9;


	int* found = find(arr, arr + size, target);
	int* found2 = find2(arr, arr + size, target);

	if (found != arr + size)
	{
		std::cout <<"Target: "<< *found <<'\n';
	}
	else
	{
		std::cout <<"Not found!\n";
	}

	if (found2 != arr + size)
	{
		std::cout <<"Target: "<< *found2 <<'\n';
	}
	else
	{
		std::cout <<"Not found!\n";
	}

	getchar();
}