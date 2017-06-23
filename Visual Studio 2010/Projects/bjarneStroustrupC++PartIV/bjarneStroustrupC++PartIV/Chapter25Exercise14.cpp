/*
	TITLE		   Vector with pool allocator   	Chapter25Exercise14.cpp
	COMMENT
		Objective: Implement a simple vector that can hold at most N elements 
				   allocated from a pool. Test it for N == 1000 and integer clements.  

				   Possibly not right!!! 

				   How use pool instead of malloc() when I need to pool.get()/free() 
				   each and every element of the vector?
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 15.05.2017
*/
#include <iostream>
#include "Chapter25Exercise14.h"

void test_fixed_vector()
{
	Vector<int> v;
	std::cout <<"v::size: " << v.size() <<'\n';
	v.push_back(1);
	v.push_back(2);

	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] <<' ';
	}

	std::cout <<'\n';
	getchar();

	Vector<int> v1(2);
	v1[0] = 1;
	v1[1] = 2;
	std::cout <<"v1::size: " << v1.size() <<'\n';

	for (int i = 0; i < v1.size(); ++i)
	{
		std::cout << v1[i] <<' ';
	}

	std::cout <<'\n';
	getchar();

	Vector<int> v2(2, 10);
	std::cout <<"v2::size: " << v2.size() <<'\n';

	for (int i = 0; i < v2.size(); ++i)
	{
		std::cout << v2[i] <<' ';
	}

	Vector<int> v3(1000, 1);
	std::cout <<"v3::size: " << v3.size() <<'\n';

	for (int i = 0; i < v3.size(); ++i)
	{
		std::cout << v3[i] <<' ';
	}
}

//----------------------------------------------------------------------

int main ()
{
	try
	{ 
		test_fixed_vector();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}