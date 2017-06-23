/*
	TITLE		   2D Matrix IO	           Chapter24Drill8.cpp
	COMMENT
		Objective: Read six ints into a Matrix<int, 2> m(2, 3)
				   and print them out.
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
#include <numeric>		 
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

void populate_2DMatrix(Matrix<int, 2>& m)
{
	Index row = m.dim1(), column = m.dim2();
	std::cout <<"Type: "<< row*column <<" matrix elements of type int:\n";
	for(auto i = 0; i < row; ++i)
	{
		for (auto j = 0; j < column;)
		{
			std::cout <<"Type ["<< i <<"]["<< j <<"] = ";
			std::string line;
			getline(std::cin, line);

			std::stringstream ss(line);

			int element;
			if (ss >> element)
			{
				m[i][j++] = element;
			}
			else
			{
				std::cout <<"Wrong input format! Try again.";
			}
		}
	}
}

//-------------------------------------------------------------------------------

int main()
{
	try
	{
		Matrix<int, 2> m(2, 3);

		populate_2DMatrix(m);
		getchar();
		std::cout <<"m = \n"<< m;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}