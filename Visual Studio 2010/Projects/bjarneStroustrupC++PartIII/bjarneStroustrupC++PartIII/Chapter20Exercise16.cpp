/*
	TITLE		    ovector		    		Chapter20Exercise16.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define an ovector just like pvector except that
				    operator[] and operator* return a reference to the
					object pointed to by an element rather than the 
					pointer.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 22. 02. 2017
*/
#include <iostream>
#include <vector>
#include "Chapter20Exercise16.h"

int main()
{
	try
	{
		Ovector<int> p;
		p.push_back(new int(5));
		std::cout <<"size: "<< p.size() <<'\n';
		std::cout <<"capacity: "<< p.capacity() <<'\n';
		std::cout << p[0];
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}