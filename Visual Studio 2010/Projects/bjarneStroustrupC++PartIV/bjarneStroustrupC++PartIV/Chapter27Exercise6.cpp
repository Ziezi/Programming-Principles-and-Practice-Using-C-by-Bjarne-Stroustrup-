/* 
	TITLE	       Change the Representation of DList		       Chapter27Exercise6.cpp
	COMMENT
		Objective: Change the representation of Link and List from §27.9 without changing
				   the user interface provided by the functions. 
				   Allocate Links in an array of Links and have the members:
				   first, last, prev, and next be ints (indices into the array).  

				   Note: 
				   1. Reassigning members of a Link passed as a pointer, requires passing it by reference.
				   2. Free pointer to array of pointers; (allocated by new);
						- loop over all pointers and delete them with delete head[i].
						- delete the head with: delete[] head.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 13.06.2017
*/
#include <iostream>
#include <string>
#include <iterator>
#include <time.h>
#include "Chapter27Exercise6.h"
 
int main()
{
	try
	{
		clock_t t = clock();

		DList<Name> l;
		std::cout <<"List capacity: "<< l.capacity() <<'\n';
		Name n;

		std::size_t size = 10;
		std::string names1[ ] =  { "Epictetus", "Aurelius", "Epicurus", "Jesus", "Smith", "Marx", "Chomsky", "Jijek", "Varoufakis?", "Corbin?" };
		std::string names2[ ] = { "Copernikus", "Galilei", "Newton", "Hertz", "Maxwell", "Lorenz", "Minkowski", "Planck", "Einstein", "Musk?" };
		 
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
		std::cout <<"\nList size: "<< l.size() <<'\n';
		l.print();
		
		// test erase()
		l.erase(l.front());
		std::cout <<"\nList size: "<< l.size() <<'\n';
		l.print();
		
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
		else
		{
			std::cout <<"Error in advance()!\n";
		}

		curr = l.advance(l.back(), -steps);
		if (curr == l.front())
		{
			std::cout <<"\nThis is the first element.\n";
		}
		else
		{
			std::cout <<"Error in advance()!\n";
		}
		
		// test find()
		curr = l.find(names1[0]);
		if (curr != l.back())
		{
			std::cout <<"\nElement found = "<< n(curr) <<'\n';	// <------- evil ?
			// std::cout <<"\nElement found = "<< reinterpret_cast<Name*>(curr)->s <<'\n';
		}
		else
		{
			std::cout <<"\nElement NOT found!\n";
		}
		
		t = clock() - t;

		std::cout <<"It took "<< t <<" clicks ("<< (((float)t) / CLOCKS_PER_SEC) <<")\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}

 