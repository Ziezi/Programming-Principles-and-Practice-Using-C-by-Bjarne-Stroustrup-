/* 
	TITLE	       Intrusive Doubly Linked List in C++	Chapter27Exercise4.cpp
	COMMENT
		Objective: If you didn't already, write a C++ version of the intrusive
				   list example in §27.9 and test it using every function. 
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 13.06.2017
*/
#include <iostream>
#include <string>
#include <time.h>
#include "Chapter27Exercise4.h"

int main()
{
	try
	{
		clock_t t = clock();

		DList l;
		Name n;

		std::size_t size = 10;
		std::string names1[ ] =  { "Epictetus", "Aurelius", "Epicurus", "Jesus", "Smith", "Marx", "Chomsky", "Jijek", "Varoufakis", "Corbin" };
		std::string names2[ ] = { "Copernikus", "Galilei", "Newton", "Hertz", "Maxwell", "Lorenz", "Minkowski", "Planck", "Einstein", "Musk" };

		// test push_front() 
		for (size_t i = 0; i < size; ++i)
		{
			l.push_front(new Name(names1[i]));
		}

		// test push_back()
		for (size_t i = 0; i < size; ++i)
		{
			l.push_back(new Name(names2[i]));
		}

		l.print();

		// test erase()
		l.erase(l.front());
		l.print();
		std::cout <<"List size: "<< l.size() <<'\n';

		// test insert()
		l.insert(l.front(), new Name(names1[5]));
		l.print();
		std::cout <<"List size: "<< l.size() <<'\n';

		l.erase(l.back());
		l.push_back(new Name(names2[9]));
		l.print();
		std::cout <<"List size: "<< l.size() <<'\n';

		// test advance()
		int steps = l.size() - 1;

		Link* curr = l.advance(l.front(), steps);
		if (curr == l.back())
		{
			std::cout <<"\nThis is the last element.\n";
		}

		curr = l.advance(l.back(), -steps);
		if (curr == l.front())
		{
			std::cout <<"\nThis is the first element.\n";
		}

		// test find()
		curr = l.find(names1[0]);
		if (curr != l.back())
		{
			std::cout <<"\nElement found = "<< n(curr) <<'\n';	// <------- ?!
			// std::cout <<"\nElement found = "<< reinterpret_cast<Name*>(curr)->s <<'\n';
		}

		t = clock() - t;

		std::cout <<"It took "<< t <<" clicks ("<< (((float)t) / CLOCKS_PER_SEC) <<")\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}