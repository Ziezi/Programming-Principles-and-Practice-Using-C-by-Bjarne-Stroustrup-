/*
	TITLE		    Linked List			     Chapter20Exercise13.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Modify the solution to the previous exercise to use
					0 to represent the (non- existent) one-past-the-end
					Link (list<Elem>::end()); that way the size of empty
					list is equal to the size of simple pointer.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 22. 02. 2017
*/
#include <iostream>
#include "Chapter20Exercise13.h"

int main()
{
	try
	{
		List<int> l;
		List<int>* l_ptr = nullptr;
		std::cout <<"list size: "<< sizeof(l) <<'\n';
		std::cout <<"pointer size: "<< sizeof(l_ptr) <<'\n';

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

