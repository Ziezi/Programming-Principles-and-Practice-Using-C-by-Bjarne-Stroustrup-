/*
	TITLE			Inner product   		 Chapter19Exercise2.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: A function that calculates inner product
		            of vectors of any type.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 21.1.2016
*/
#ifndef CHAPTER19EXERCISE2_H
#define CHAPTER19EXERCISE2_H
#include "assert.h"
/*
	Function: inner_product()
	Use: T sum_of_products = inner_product(vector<T>, vector<T>);

	It returnrs the sum of products of all the elements of the vectors
	passed as arrguments.
*/
template <class T>
T inner_product (const std::vector<T>& a, const std::vector<T>& b, T sum = T())
{
	assert(a.size() == b.size());

	for (size_t i = 0; i < a.size(); ++i) 
	{
		sum += a[i] * b[i];
	}

	return sum;
}


#endif 