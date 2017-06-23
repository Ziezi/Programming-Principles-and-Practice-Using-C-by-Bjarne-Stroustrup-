/*
	TITLE			Inner product   		 Chapter19Exercise2.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: A function that calculates inner product
		            of vectors of any type.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 21.1.2016
*/
#include <iostream>
#include <vector>
#include <assert.h>
#include "Chapter19Exercise2.h"

int main () 
{
	try
	{
		std::vector<double> v1(10, 2.5);
		std::vector<double> v2(10, 3.5);

		double in_prod = 0;
		in_prod = inner_product(v1, v2);
		std::cout <<"Inner product: "<< in_prod <<"\n";

		std::vector<int> v11(10, 2);
		std::vector<int> v22(10, 3);

		int in_prod2 = 0;
		in_prod2 = inner_product(v11, v22);
		std::cout <<"Inner product: "<< in_prod2 <<"\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	catch (...)
	{
		std::cerr << "Unhandled Exception!\n";
	}
	getchar();
}