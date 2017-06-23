/*
	TITLE		   dot_product() and scale_and_add()           Chapter24Exercise6.cpp
	COMMENT
		Objective: In the Gaussian elimination example, replace the vector operations
				   dot_product() and scale_and_add() with loops. Test, and comment on
				   the clarity of the code.  
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 06.05.2017
*/
#include <iostream>
#include <sstream>
#include "Matrix.h"
#include "MatrixIO.h"
#include "Chapter24Exercise6.h"

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
		std::cerr <<"Runtime error::"<< r.what();
		getchar();
		exit(1);
	}

	std::cout <<"x = "<< x <<'\n';
	getchar();
}