/*
	TITLE			Inner product of Class Number    Chapter19Exercise7.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Find the inner product of 
				    two vectors of types Number<T>.

					Combine Ex: 2 and Ex 6.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 24.1.2016
*/
#include <iostream>
#include <vector>
#include "Chapter19Exercise2.h"
#include "Chapter19Exercise6.h"


int main () 
{
	std::vector<Number<double>> v1(10, 5.5);
	std::vector<Number<double>> v2(10, 2.5);

	Number<double> dot_product = inner_product(v1, v2);

	std::cout <<"Dot product: "<< dot_product <<'\n';

	getchar();
}


