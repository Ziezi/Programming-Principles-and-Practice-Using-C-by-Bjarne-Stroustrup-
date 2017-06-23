/*
	TITLE		   Code Refactoring - Generalize Type				   Chapter24Exercise7.cpp
	COMMENT
		Objective: Rewrite the Gaussian elimination program without using the Matrix library;
				   that is, use built-in arrays or vectors instead of Matrixes.
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 07.05.2017
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <numeric>
#include <algorithm>
#include "Chapter24Exercise7.h"

void init_2DVector(std::vector<std::vector<double>>& v)
{
	double arr_A[2][2] = { { 3, 2 }, { 2, 3} };

	for (size_t i = 0; i < v.size(); ++i)
	{
		for (size_t j = 0; j < v[i].size(); ++j)
		{
			v[i][j] = arr_A[i][j];
		}
	}
}

int main()
{
	std::array<double, 2> arr_b = { 3, 15 };

	Matrix A(2, std::vector<double>(2, 0));
	init_2DVector(A);

	Vector b(arr_b.begin(), arr_b.end());

	Vector x(2);

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