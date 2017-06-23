/*
	TITLE		    Iterator for List	    Chapter20Exercise19.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define a range-checked iterator for list
		 			(a bidirectional iterator). 
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 24. 02. 2017
*/
#include <iostream>
#include "Chapter20Exercise19.h"

int main()
{
	try
	{
		List<int> l;
		l.push_front(1);
		l.push_front(2);
		l.push_front(3);
		l.push_front(4);
		l.push_front(5);
		
		// defualt constructor, copy assignment
		List<int>::iterator p = l.begin();

		// write dereferencing 
		*p = 100;

		// incrementation, read dereferencing
		List<int>::iterator i;
		for (i = l.begin(); i != l.end(); ++i)
		{
			std::cout << *i <<' ';
		}

		if (i == l.end() && i != l.begin())
		{
			std::cout <<"\ncomparison correct!\n";
		}

		// postfix and prefix decrementation; maintain dereferenceability
		List<int>::iterator ii = l.end();
		ii--;
		for (; ii != l.begin(); ii--)
		{
			std::cout << *ii <<' ';
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}