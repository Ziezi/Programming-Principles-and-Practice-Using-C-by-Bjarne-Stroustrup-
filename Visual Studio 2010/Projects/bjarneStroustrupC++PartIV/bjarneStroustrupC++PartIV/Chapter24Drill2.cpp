/*
	TITLE	       Sizeof Matrix		   	  Chapter24Drill2.cpp
	COMMENT
		Objective: Print out the size as reported by sizeof of 
				   Matrix<int> a(10), Matrix<int> b(10), 
				   Matrix<double> c(10), Matrix<int,2> d(10,10), 
				   Matrix<int,3> e(10, 10, 10). 
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 03.05.2017
*/
#include <iostream>
#include <iomanip>
#include <limits>
#include "Matrix.h"

int main()
{
	try
	{
		 Numeric_lib::Matrix<int> a(10);
		 Numeric_lib::Matrix<int> b(10);
		 Numeric_lib::Matrix<double> c(10);
		 Numeric_lib::Matrix<int, 2> d(10, 10);
		 Numeric_lib::Matrix<int, 3> e(10, 10, 10);

		 std::cout << std::left <<std::setw(20) <<"sizeof(Matrix<int>)"<<" : "<< std::setw(3) << sizeof(a) <<'\n';
		 std::cout << std::setw(20) <<"sizeof(Matrix<double>)"<<" : "<< std::setw(3) << sizeof(c) <<'\n';
		 std::cout << std::setw(20) <<"sizeof(Matrix<int, 2>)"<<" : "<< std::setw(3) << sizeof(d) <<'\n';
		 std::cout << std::setw(20) <<"sizeof(Matrix<int, 3>)"<<" : "<< std::setw(3) << sizeof(e) <<'\n';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}

