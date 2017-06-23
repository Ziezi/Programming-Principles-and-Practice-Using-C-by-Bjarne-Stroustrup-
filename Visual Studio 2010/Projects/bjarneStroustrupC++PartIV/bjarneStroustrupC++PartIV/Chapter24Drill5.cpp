/*
	TITLE	       IO Matrix		         	 Chapter24Drill5.cpp
	COMMENT
		Objective: Read ten floating-point values from input and
		           put them into a Matrix<double>. 
				   Matrix has no push_back() so be careful to handle 
				   an attempt to enter a wrong number of doubles. 
				   Print out the Matrix.   
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

void populate_1DMatrix(Matrix<double>& m)
{
	 int size = m.size();

	 std::cout <<"Type "<< size <<" matrix elements of type double: \n";

	 double element;
	 int i = 0;
	 while(i < size)
	 {
		std::cout <<"Type an element and press enter: ";
		std::string line;
		getline(std::cin, line);

		std::stringstream ss(line);
		if (ss >> element)
		{
			m[i++] = element;
		}
		else 
		{
			std::cout <<"Wrong element type. Try again!\n";
		}
	 }
}

//-------------------------------------------------------------------------------

int main()
{
	try
	{
		Matrix<double, 1> a(10);
		populate_1DMatrix(a);

		std::cout << a;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}