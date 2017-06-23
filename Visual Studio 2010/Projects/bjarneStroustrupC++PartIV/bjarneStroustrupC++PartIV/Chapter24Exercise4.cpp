/*
	TITLE		   Gaussian Elimination   	Chapter24Exercise4.cpp
	COMMENT
		Objective: Get the Gaussian elimination program to work;
				   that is, complete it, get it to compile, 
				   and test it with a simple example. 
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 05.05.2017
*/
#include <iostream>
#include <sstream>
#include "Matrix.h"
#include "MatrixIO.h"
#include "Chapter24Exercise4.h"

int main()
{
	double arr_A[2][2] = { { 3, 2 }, { 2, 3} };
	double arr_b[2] = { 3, 15 };

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
		std::cerr << r.what();
	}

	std::cout <<"x = "<< x <<'\n';
	 
	getchar();
}