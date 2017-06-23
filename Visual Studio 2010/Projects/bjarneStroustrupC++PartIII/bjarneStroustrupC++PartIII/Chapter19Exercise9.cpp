/*
	TITLE			Allocator			     Chapter19Exercise9.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Re-implement vector::operator() (§19.2.5)
					using an allocator §19.3.6 for memory management.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 24.1.2016
*/
#include <iostream>
#include "Chapter19Exercise9.h"

int main ()
{
	try
	{
		// default
		Vector<int> v1;
		v1.push_back(2);
		std::cout <<"v1::size: " << v1.size();
		std::cout <<"\nv1::capacity: " << v1.capacity();
		std::cout <<"\nv1::operator[]: " << v1[0];

		//
		Vector<double> v2(10);
		std::cout <<"v2::size: " << v2.size();
		std::cout <<"\nv2::capacity: " << v2.capacity();
		std::cout <<"\nv2::operator[]: " << v2[9];

		//
		Vector<char> v3(20, 'a');
		std::cout <<"\nv3::size: " << v3.size();
		std::cout <<"\nv3::capacity: " << v3.capacity() <<'\n';
		v3[9] = 'b';

		for (int i = 8; i < v3.size(); ++i)
		{
			std::cout << v3[i] <<' ';
		}

		std::cout <<"\nat[0]: "<< v3.at(0) <<'\n';

		// 
		Vector<char> v4 = v3;

		for (int i = 0; i < v4.size(); ++i)
		{
			std::cout << v4[i] <<' ';
		}
		 
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}