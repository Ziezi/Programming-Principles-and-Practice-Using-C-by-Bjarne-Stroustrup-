/*
	TITLE		   Tempates and Generalization         Chapter24Exercise9.cpp
	COMMENT
		Objective: Rewrite the non-member apply() functions to return a Matrix 
				   of the return type of the function applied; 
				   that is, apply(f,a) should return a Matrix<R> where R is 
				   the return type of f
				   Warning: The solution requires inormation about templates
				   not available in this book. 

				   No variadic templates.
				   No default template arguments in functions.
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 07.05.2017
*/
#include <iostream>
#include <iomanip>
#include <functional>
#include "Matrix.h"
#include "MatrixIO.h"

//-----------------------------------------------------------------------------
namespace Numeric_lib
{
/*
	Returns a matrix of type matching the type of the functor passed as argument.
*/
template<
	template <typename T, typename N> class Container,
	typename Functor, 
	typename T,
	typename U,
	typename N
>
Container<U, N> apply (Container<T, N> x, Functor f)
{ 
	// construct a new Matrix, res, with element's that are modified x's by f 
	Container<std::result_of<Functor(T)>::type, N> res(x, f); 

	// let 'res' own its resources
	return xfer(res);			   
}

//-----------------------------------------------------------------------------

/*
	Returns a matrix of type matching the type of the functor passed as argument.
*/
template<
	template <typename T, typename N> class Container,
	typename Functor,
	typename T,
	typename U,
    typename Arg, 
	typename N
> 
Container<U, N> apply (Container<T, N> x, Functor f, Arg a) 
{ 
	Container<std::result_of<Functor(T)>::type, N> res(x, f, a); 

	return xfer(res); 
}

};

//-------------------------------------------------------------------------------

/*
	Functor:

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
	Function:

	Does not modify the input parameter.
	The, copy of, the result is meant to be
	used as an initialization value.
 */
template <class T> 
inline T Double(const T src) { return src * 2; }

//-------------------------------------------------------------------------------
 
int main()
{
	try
	{
		Numeric_lib::Matrix<double, 1> a(10), b(10), c(10);
		double arr[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};

		a = arr;
		std::cout <<"Initial Matrix:\n"<< a <<'\n';

		// non - member apply with function
		b = apply(Double<int>, a);
		std::cout <<"Matrix.apply(Double):\n"<< b <<'\n';

		// non - member apply with functor
		c = apply(DoubleF<int>(), a);
		std::cout <<"Matrix.apply(DoubleF):\n"<< c <<'\n';
	}
	catch(std::runtime_error& r)
	{
		std::cerr <<"Runtime error::"<< r.what();
		getchar();
		exit(1);
	}
	getchar();
}