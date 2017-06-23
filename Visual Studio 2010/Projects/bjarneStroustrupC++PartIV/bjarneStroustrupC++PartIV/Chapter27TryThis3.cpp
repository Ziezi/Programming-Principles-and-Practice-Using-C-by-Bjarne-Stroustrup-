/* 
	TITLE		   From C to C++ Doubly Linked List		Chapter27TryThis3.cpp
	COMMENT
		Objective: Rewrite the intrusive list example in C++, showing how to 
				   make it shorter and easier to use without making the code 
				   slower or the objects bigger. 

				   Note: Be aware of locally defined pointers, especially when their
						 value should be reassigned.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 09.06.2017
*/
#include <iostream>
#include <string>
#include "Chapter27TryThis3.h"

int main ()
{
	try
	{
		DList l;

		std::size_t size = 6;
		std::string names1[ ] = { "Giorikas", "Kostikas", "Foo", "Bar", "Gosho", "Pesho" };
		std::string names2[ ] = { "Giorgena", "Kotsena", "Foo's", "Bar's", "Gergevica", "Peshovica" };

		for (size_t i = 0; i < size; ++i)
		{
			l.push_front(make_name(names1[i]));
		}

		l.print();
		std::cout <<"List size: "<< l.size() <<'\n';
		getchar();

		for (size_t i = 0; i < size; ++i)
		{
			l.push_back(make_name(names2[i]));
		}

		l.print();
		std::cout <<"List size: "<< l.size() <<'\n';
		getchar();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}
 