/*
	TITLE		    pvector		    		Chapter20Exercise15.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define a `pvector` to be like `vector` of pointers
					except that it contains pointer to objects
					and its destructor deletes each object. 
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 22. 02. 2017
*/
#include <iostream>
#include <vector>
#include "Chapter20Exercise15.h"

int main()
{
	try
	{
		Pvector<int> p;
		p.push_back(new int(5));
		std::cout <<"size: "<< p.size() <<'\n';
		std::cout <<"capacity: "<< p.capacity() <<'\n';
		std::cout << *p[0];
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}