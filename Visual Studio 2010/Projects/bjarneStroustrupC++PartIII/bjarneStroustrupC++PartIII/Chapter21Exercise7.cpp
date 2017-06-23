/*
	TITLE		    Binary search 		      Chapter21Exercise7.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Implement a `binary_search()` function for
					`std::vector` and `std::list`. Test it. 
					How much do they resemble each other?
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 27. 02. 2017
*/
#include <iostream>
#include <vector>
#include <list>

template <class Iterator, class T>
Iterator binary_search(Iterator first, Iterator last, T target)
{
	if (first == last)
	{
		return last;
	}
	 
	Iterator middle = first;
	std::advance(middle, std::distance(first, last) / 2);

	if (target == *middle)
	{
		return middle;
	}
	else if (target > *middle)
	{
		return binary_search(middle, last, target);
	}	
	else
	{
		return binary_search(first, middle, target);
	}
}

//------------------------------------------------------------------------------------

void test_vector()
{
	std::vector<int> v0;

	std::vector<int>::iterator found = binary_search(v0.begin(), v0.end(), 3);
	if (found != v0.end())
	{
	std::cout <<"Found: "<< *found <<'\n';
	}
	else
	{
	std::cout <<"Not found\n";
	}

	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	std::vector<int>::iterator found2 = binary_search(v.begin(), v.end(), 5);
	if (found2 != v.end())
	{
	std::cout <<"Found: "<< *found2 <<'\n';
	}
	else
	{
	std::cout <<"Not found\n";
	}
}

//------------------------------------------------------------------------------------

void test_list()
{
	std::list<double> l0;

	std::list<double>::iterator found3 = binary_search(l0.begin(), l0.end(), 5);
	if (found3 != l0.end())
	{
	std::cout <<"Found: "<< *found3 <<'\n';
	}
	else
	{
	std::cout <<"Not found\n";
	}

	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
		 
	std::list<double> l(v.begin(), v.end());

	std::list<double>::iterator found4 = binary_search(l.begin(), l.end(), 4);
	if (found4 != l.end())
	{
	std::cout <<"Found: "<< *found4 <<'\n';
	}
	else
	{
	std::cout <<"Not found\n";
	}
}

//------------------------------------------------------------------------------------

int main()
{
	try
	{
		test_vector();
		test_list();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}