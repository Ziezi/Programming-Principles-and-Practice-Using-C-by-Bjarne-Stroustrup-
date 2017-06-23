/*
	TITLE		    Range-checked iterator  Chapter20Exercise18.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define a range-checked iterator for Vector.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 22. 02. 2017
*/
#include <iostream>
#include "Chapter20Exercise18.h"

int main()
{
	try
	{
		 Vector<int> v;
		 v.push_back(5);
		 v.push_back(3);
		 v.push_back(2);
		 v.push_back(1);

		 std::cout <<"size: " << v.size() <<'\n';
		 std::cout <<"capacity: " << v.capacity() <<'\n';
		 std::cout <<"v[0]: " << v[0] <<'\n';

		 // test iterators

		 // default constructor, copy assignment, Vector::begin()
		 Vector<int>::iterator p = v.begin();

		 // copy constructor
		 Vector<int>::iterator pp(p);

		 // read dereference operator*()
		 std::cout << *p <<'\n';
		 std::cout << *pp <<'\n';
		 
		 // write dereference operator*()
		 p[2] = 100;

		 // subscript operator[]
		 for (size_t i = 0; i < v.size(); ++i)
		 {
			 std::cout << p[i] <<'\n';
		 }
		
		 // postfix incrementation; end() 
		 Vector<int>::iterator i;
		 for (i = v.begin(); i != v.end(); i++)
		 {
			std::cout << *i <<' ';
		 }
		 std::cout <<'\n';

		 i--;
		 // prefix decrementation;  multi-pass & maintains dereferenceability
		 for (; i == v.begin(); --i)
		 {
			std::cout << *i <<' ';
		 }
		 std::cout <<'\n';

		 // Comparison <, <=, >, >=, ==, !=
		 Vector<int>::iterator b = v.begin();
		 Vector<int>::iterator e = v.end();

		 if (b < e && b != e && b == b && b <= e && e > b && e >= b)
		 {
			std::cout <<"Comparison works\n";
		 }

		 // arithmetic operations: +n
		 Vector<int>::iterator c = v.begin();
		 b = b + v.size();

		 Vector<int>::iterator d = v.end(); 
		 d = d - v.size();

		 if (b == v.end() && d == v.begin())
		 {
			 std::cout <<"Algebraic operations work\n";
		 }

		 // compound operations
		 Vector<int>::iterator g = v.begin();
		 g += 1;
		 g -= 1;

		 if (g == v.begin())
		 {
			std::cout <<"Compound operations work\n";
		 }
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}