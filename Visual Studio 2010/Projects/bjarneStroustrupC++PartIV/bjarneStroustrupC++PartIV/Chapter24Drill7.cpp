/*
	TITLE	       Complex numbers	       Chapter24Drill7.cpp
	COMMENT
		Objective: Read ten complex<double>s from std::cin and 
				   put them into a Matrix. Calculate and output 
				   the sum of the ten complex numbers.  
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 04.05.2017
*/
#include <iostream>
#include <sstream>
#include <string>
#include <array>
#include <complex>
#include <numeric>		// accumulate
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

void populate_arr(std::complex<double>* a, int size)
{
	 std::cout <<"Type: " << size <<" complex tuples (Im, Re):\n";

	 std::complex<double> element;
	 int i = 0;
	 while(i < size)
	 {
		std::cout <<"Type: "<< i+1 <<" tuple: ";
		std::string line;
		getline(std::cin, line);

		std::stringstream ss(line);
		if (ss >> element)
		{
			a[i++] = element;
		}
		else
		{
			std::cout <<"Wrong format! Try again.\n";
		}
	 }
}

//-------------------------------------------------------------------------------

int main()
{
	try
	{
		 int size = 10;
		 Matrix<std::complex<double>, 1> a(size);
		 std::complex<double>* arr = new std::complex<double> [size]; 

		 // read 10 complex numbers form std::cin
		 populate_arr(arr, size);
		 
		 // Store in Matrix
		 a = *arr;
		 std::cout <<"Matrix<std::complex<double>, 1>: \n"<< a <<'\n'; 

		 // Sum 10 complex numbers
		 std::complex<double>* end = arr + size;
		 std::complex<double> initial = std::complex<double>(0.0, 0.0);
		 std::cout <<"Sum : " << std::accumulate(arr, end, initial,
			                     [](std::complex<double>& lhs, std::complex<double>& rhs) { return lhs + rhs; } );
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}