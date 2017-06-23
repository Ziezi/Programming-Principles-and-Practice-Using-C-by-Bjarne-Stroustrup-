/*
	TITLE		   Function objects  			Chapter24Exercise2.cpp
	COMMENT
		Objective: Do exercise 1 again, but with function objects, 
				   rather than functions. 
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 05.05.2017
*/
#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

/*
	"Freestanding" function object:

	Does not modify the input parameter.
	The, copy of, the result is meant to be
	used as an initialization value.
 */
struct Double 
{
	int operator()(int src) { return src * 2; }
}; 

//-------------------------------------------------------------------------------

/*
	"Broadcast" function object: 

	Modifies the input parameter.
	The result is the modified input parameter,
	i.e. an already existing value.
*/
struct DoubleRef
{
	int operator()(int& ref_src) { return ref_src *= 2; }
};
//-------------------------------------------------------------------------------
 
int main()
{
	try
	{
		Matrix<int, 1> a(10);
		int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		a = arr;

		std::cout <<"Initial Matrix:\n"<< a <<'\n';

		// "freestanding" apply
		a = apply(Double(), a);
		std::cout <<"Matrix.apply(Double):\n"<< a <<'\n';

		// broadcast function
		a.apply(DoubleRef());
		std::cout <<"Matrix.apply(DoubleRef):\n"<< a <<'\n';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}