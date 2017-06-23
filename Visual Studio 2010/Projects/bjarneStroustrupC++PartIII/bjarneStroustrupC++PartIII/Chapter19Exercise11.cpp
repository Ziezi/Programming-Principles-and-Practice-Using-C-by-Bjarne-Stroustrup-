/*
	TITLE			counted_ptr<T>          Chapter19Exercise11.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Design and implement a counted_ptr<T> that is 
					a type that holds a pointer to an object of 
					type T and a pointer to a "use count" (an int)
					shared by all counted pointers to the same object
					of type T.

					The us count should hold the number of counted 
					pointers pointing to a given T.
		     Input: -
			Output: - 
			Author: Chris B. Kirov
			  Date: 27.1.2016
*/
#include <iostream>
#include "Chapter19Exercise11.h"

#include "assert.h"

void test1 () 
{
	std::cout <<"\nTest constructor and get() member.\n";
	Counted_ptr<int> p(new int);
	*p.get() = 5;
	std::cout <<"p points to: "<< *p << "\n";

	assert(*p, 5);
	std::cout <<"TEST 1 DONE\n";
}

//----------------------------------------------------------------------------------------------- 

void test2 ()
{
	std::cout <<"\nTest reset() and release() members.\n";
	Counted_ptr<int> p(new int);
	*p.get() = 5;
	std::cout <<"p points to: "<< *p << "\n";

	p.reset(new int(10));
	std::cout <<"reset() p points to: "<< *p << "\n";
	assert(*p, 10);

	int *temp = p.release();
	std::cout <<"caller of release(), temp points to: "<< *temp << "\n";
	assert(*temp, 10);

	// nullptr dereferece error 
	// std::cout <<"p after being release()d points to: "<< *p << "\n";

	std::cout <<"TEST 2 DONE\n";
}

//----------------------------------------------------------------------------------------------- 

void test3 ()
{
	std::cout <<"\nTest copy constructor and copy assignment.\n";
	Counted_ptr<int> p1(new int(10));
	Counted_ptr<int> p2(p1);
	
	std::cout <<"copy constructed p2 points to: "<< *p2 << "\n";
	assert(*p2, 10);

	Counted_ptr<int> p3(new int(20));
	p1 = p3;
	std::cout <<"copy assigned p1 points to: "<< *p1 << "\n";
	assert(*p1, 20);

	std::cout <<"TEST 3 DONE\n";
}

//----------------------------------------------------------------------------------------------- 

void test4 () 
{
	std::cout <<"\nTest multiple instantiations and shared ownership.\n";
	Counted_ptr<int> p1(new int(10));
	Counted_ptr<int> p2(p1);	// p1 & p2 share ownership of int = 10;
	Counted_ptr<int> p3(p2);    // p1 & p2 & p3 share ownership of int = 10;

	std::cout <<"p1: "<< *p1 <<"\n";
	Counted_ptr<int> p4(p1.release());
	std::cout <<"p2: "<< *p2 <<"\n";
	std::cout <<"p3: "<< *p3 <<"\n";
	std::cout <<"p4: "<< *p4 <<"\n";

	std::cout <<"TEST 4 DONE\n";
}

//----------------------------------------------------------------------------------------------- 

int main () 
{
	test1 ();
	test2 ();
	test3 ();
	test4 ();

	getchar();
}