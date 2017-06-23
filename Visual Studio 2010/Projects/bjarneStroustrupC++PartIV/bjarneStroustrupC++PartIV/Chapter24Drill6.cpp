/*
	TITLE	       Tensor Multiplication	 Chapter24Drill6.cpp
	COMMENT
		Objective: Compute a multiplication table for [O,n)*[O,m)
				   and represent it as a 2D Matrix. 
				   Take n and m from std::cin and print out the 
				   table nicely (assume that m is small enough that 
				   the results fit on a line). 
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 04.05.2017
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

//-------------------------------------------------------------------------------

/*
	Initializes the 1D input Matrix elements with
	integers from [0, size).
*/
void init_1DMatrix(Matrix<int>& a)
{
	Index size = a.dim1();

	for (int i = 0; i < size; ++i)
	{
		a[i] = i;
	}
}

//-------------------------------------------------------------------------------

/*
	Returns a 2D (n x m) matrix resulting from the tensor product
	between the two input 1D matrixes, with sizes n and m.
*/
Matrix<int, 2> operator*(const Matrix<int>& a, const Matrix<int>& b)
{
	Index row = a.dim1();
	Index column = b.dim1();

	Matrix<int, 2> tensor(row, column);

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			tensor(i, j) = a[i] * b[j];
		}
	}

	return tensor;
}

//-------------------------------------------------------------------------------

int main()
{
	try
	{
		int n = 3, m = 3;

		Matrix<int> a(n), b(m);

		init_1DMatrix(a);
		init_1DMatrix(b);

		std::cout <<"a = \n"<< a <<'\n';
		std::cout <<"b = \n"<< b <<'\n';

		Matrix<int, 2> c(n, m);
		 
		c = a * b;
	 
		std::cout <<"Tensor = \n" << c;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}