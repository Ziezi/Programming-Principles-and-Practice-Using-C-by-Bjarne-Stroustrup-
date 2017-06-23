/*
	TITLE		    Singly Linked List		Chapter20Exercise14.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define a singly-linked list, `slist`, 
				    in the style of `std::list`.
					Which operations from `List` should be kept?  
					All operations remian.
					Iterator is forward only.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 22. 02. 2017
*/
#include <iostream>
#include "Chapter20Exercise14.h"

int main()
{
	try
	{
		SList<int> l;
		SList<int>* l_ptr = nullptr;
		std::cout <<"list size: "<< sizeof(l) <<'\n';
		std::cout <<"pointer size: "<< sizeof(l_ptr) <<'\n';

		std::cout <<"\npush_front(): \n";
		l.push_front(1);

		l.print();
		std::cout <<'\n';

		l.push_front(3);

		l.print();
		std::cout <<'\n';

		l.push_front(2);
		l.print();

		std::cout <<"\npush_back(): \n";
		l.push_back(19);

		l.print();
		std::cout <<'\n';

		l.push_back(59);

		l.print();
		std::cout <<'\n';

		l.push_back(12);

		l.print();
		std::cout <<"\ninsert() at begin(): \n";

		SList<int>::iterator p = l.begin();
		p = l.insert(p, 5);

		std::cout <<"size: " << l.size() <<'\n';
		l.print();
		std::cout <<"\nerase() at begin(): \n";

		SList<int>::iterator b = l.begin();
		b = l.erase(b);
		l.print();
		std::cout <<'\n';

		std::cout <<"front(): \n";
		std::cout << l.front(); 
		std::cout <<'\n';

		std::cout <<"back(): \n";
		std::cout << l.back(); 
		std::cout <<'\n';

		l.print();
		std::cout <<'\n';
		std::cout <<"\npop_back(): \n";
		l.pop_back();

	 
		l.print();
		std::cout <<'\n';
		std::cout <<"\npop_front(): \n";
		l.pop_front();
		l.print();
		std::cout <<'\n';

		l.push_front(100);
		l.push_back(191);

		l.print();
		std::cout <<'\n';

		SList<int>::iterator p2 = high(l.begin(), l.end());
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

