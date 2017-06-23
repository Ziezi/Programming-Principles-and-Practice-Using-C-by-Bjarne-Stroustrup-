/*
	TITLE		   Animate the Gaussian Elimination  Chapter24Exercise8.cpp
	COMMENT
		Objective: Animate the Gaussian Elimination. 
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 07.05.2017
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <array>
#include <numeric>
#include <algorithm>
#include "Chapter24Exercise8.h"

void init_2DVector(std::vector<std::vector<double>>& v)
{
	double arr_A[4][4] = { { 3, 2, 1, 5 }, {1, 2, 3, 5}, {7, 11, 13, 5}, { 3, 7, 13, 67} };

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
	std::array<double, 4> arr_b = { 3, 15, 27, 81 };

	Matrix A(4, std::vector<double>(4, 0));
	init_2DVector(A);

	Vector b(arr_b.begin(), arr_b.end());

	Vector x(4);

	std::cout <<"Initial System of liner equations in matrix form Ax = b:\n";
	std::cout <<"A = \n"<< A <<'\n';
	std::cout <<"b = \n"<< b <<'\n';

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

	std::cout <<"Result:\n";
	std::cout <<"x = "<< x <<'\n';
	getchar();
}