/*
	TITLE		   Binding arguments with Function objects  	Chapter24Exercise3.cpp
	COMMENT
		Objective: Write an apply(f,a) that can takes a void f(T&), a T f(const T&), and
				   their function object equivalents. Hint: Boost::bind.

				   I'm clearly not getting something right.
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 05.05.2017
*/
#include <iostream>
#include <functional>  // std::bind
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

/*
	"Freestanding" function object:

	Does not modify the input parameter.
	The, copy of, the result is meant to be
	used as an initialization value.
 */
template <class T>
struct DoubleF
{
	T operator()(const T src) { return src * 2; }
}; 

//-------------------------------------------------------------------------------

/*
	"Broadcast" function object: 

	Modifies the input parameter.
	The result is the modified input parameter,
	i.e. an already existing value.
*/
template <class T>
struct DoubleRefF
{
	void operator()(T& ref_src) { ref_src *= 2; }
};
//-------------------------------------------------------------------------------

/*
	"Freestanding" function:

	Does not modify the input parameter.
	The, copy of, the result is meant to be
	used as an initialization value.
 */
template <class T> 
inline T Double(const T src) { return src * 2; }

//-------------------------------------------------------------------------------

/*
	"Broadcast" function:

	Modifies the input parameter.
	The result is the modified input parameter,
	i.e. an already existing value.
*/
template <class T>
inline void DoubleRef(T& ref_src) { ref_src *= 2; }

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
		a = apply(Double<int>, a);
		std::cout <<"Matrix.apply(Double):\n"<< a <<'\n';

		// broadcast function
		a.apply(DoubleRef<int>);
		std::cout <<"Matrix.apply(DoubleRef):\n"<< a <<'\n';
		
		// "freestanding" apply object
		a = apply(DoubleF<int>(), a);
		std::cout <<"Matrix.apply(DoubleF):\n"<< a <<'\n';

		// broadcast function object
		a.apply(DoubleRefF<int>());
		std::cout <<"Matrix.apply(DoubleRefF):\n"<< a <<'\n';
		
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}