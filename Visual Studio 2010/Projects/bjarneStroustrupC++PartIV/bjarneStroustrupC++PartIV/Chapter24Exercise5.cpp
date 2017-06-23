/*
	TITLE		   Partial Pivot Gaussian Elimination  Chapter24Exercise5.cpp
	COMMENT
		Objective: Try the Gaussian elimination program with 
				   A={ {O 1} {1 O} } and b=={ 5 6 } and watch it fail. 
				   Then, try elim_with_partiat_pivot(). 

				   If det(A) == 0, no unique solution, i.e. exception thrown.
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 06.05.2017
*/
#include <iostream>
#include <sstream>
#include "Matrix.h"
#include "MatrixIO.h"
#include "Chapter24Exercise5.h"

int main()
{
	double arr_A[2][2] = { { 0, 1 }, { 1, 0} };
	double arr_b[2] = { 5, 6 };

	Matrix A(2,2); 
	Vector b(2);
	Vector x(2);

	A[0] = arr_A[0];
	A[1] = arr_A[1];
	b = arr_b;

	std::cout <<"A = "<< A <<'\n';
	std::cout <<"b = "<< b <<'\n';

	try
	{
		x =  classical_gaussian_elimination(A, b);
	}
	catch(std::runtime_error& r)
	{
		std::cerr <<"Runtime error::"<< r.what();
		getchar();
		exit(1);
	}

	std::cout <<"x = "<< x <<'\n';
	getchar();
}