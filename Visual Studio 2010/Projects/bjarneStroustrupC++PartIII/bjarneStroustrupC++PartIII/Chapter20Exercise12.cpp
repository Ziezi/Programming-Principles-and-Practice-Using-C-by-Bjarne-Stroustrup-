/*
	TITLE		    Linked List			     Chapter20Exercise12.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Complete the definition of list from §20.4.1 - 2
					and get high() example to run. Allocate a List to
					represent one past the end.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 21. 02. 2017
*/
#include <iostream>
#include "Chapter20Exercise12.h"

int main()
{
	try
	{
		List<int> l;
		l.push_front(1);
		l.push_front(3);
		l.push_front(2);

		std::cout <<"size: " << l.size() <<'\n';
		l.print();
		std::cout <<'\n';

		List<int>::iterator p2 = high(l.begin(), l.end());
		if (p2 != l.end())
		{
			std::cout <<"High = " << *p2 <<'\n';
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}

