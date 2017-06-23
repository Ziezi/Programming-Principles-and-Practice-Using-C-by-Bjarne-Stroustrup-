/*
	TITLE		   Function & apply 							   Chapter24xercise1.cpp
	COMMENT
		Objective: The function arguments f for a.apply(f) and apply(f,a) are different.
				   Write a double() function for each and use each to double the elements
				   of an array {1, 2, 3, 4, 5 }. Define a single double() function that 
				   can be used for both a.apply(double) and apply(double, a).
				   Explain why it could be a bad idea to write every function to be used
				   by apply() that way. 
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
	"Freestanding" function:

	Does not modify the input parameter.
	The, copy of, the result is meant to be
	used as an initialization value.
 */
inline int Double(int src) { return src * 2; }

//-------------------------------------------------------------------------------

/*
	"Broadcast" function:

	Modifies the input parameter.
	The result is the modified input parameter,
	i.e. an already existing value.
*/
inline int DoubleRef(int& ref_src) { return ref_src *= 2; }

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
		a = apply(Double, a);
		std::cout <<"Matrix.apply(Double):\n"<< a <<'\n';

		// broadcast function
		a.apply(DoubleRef);
		std::cout <<"Matrix.apply(DoubleRef):\n"<< a <<'\n';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}