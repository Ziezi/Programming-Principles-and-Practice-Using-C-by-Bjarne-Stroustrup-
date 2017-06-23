/*
	TITLE	       Print Elements of Matrix	 Chapter24Drill3.cpp
	COMMENT
		Objective: Print out the elements of the matrixes from
				   the previous exercise. 
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 03.05.2017
*/
#include <iostream>
#include <iomanip>
#include <limits>
#include "Matrix.h"
#include "MatrixIO.h"

int main()
{
	try
	{
		 Numeric_lib::Matrix<int> a(10);
		 Numeric_lib::Matrix<int> b(10);
		 Numeric_lib::Matrix<double> c(10);
		 Numeric_lib::Matrix<int, 2> d(10, 10);
		 Numeric_lib::Matrix<int, 3> e(10, 10, 10);

		 std::cout <<"Number of elements in:\n";
		 std::cout << std::left << std::setw(20) <<"Matrix<int> a"<<" : "<< a.dim1() <<'\n';
		 std::cout << std::setw(20) <<"Matrix<int> b"<<" : "<< b.dim1() <<'\n';
		 std::cout << std::setw(20) <<"Matrix<double> c"<<" : "<< c.dim1() <<'\n';
		 std::cout << std::setw(20) <<"Matrix<int, 2> d"<<" : "<< d.dim1() * d.dim2() <<'\n';
		 std::cout << std::setw(20) <<"Matrix<int, 3> e"<<" : "<< e.dim1() * e.dim2() * e.dim3() <<" or "<< e.size() <<'\n';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}

