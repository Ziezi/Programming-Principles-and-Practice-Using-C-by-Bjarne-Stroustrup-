/*
	TITLE		   Matrix swap columns              Chapter24Exercise11.cpp
	COMMENT
		Objective: Write a swap_columns() to match swap_rows() from §24.S.3.
				   Obviously, to do that you have to read and understand 
				   some of the existing Matrix library code. 
				   Don't worry too much about efficiency: it is not possible to
				   get swap_columns() to run as fast as swap_rows().
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 08.05.2017
*/
#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

//--------------------------------------------------------------------------

template <typename T, size_t N>
void increment_2DArray(T arr[N][N])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			arr[i][j] += 1; 
		}
	}
}

//--------------------------------------------------------------------------

template <typename T, size_t N>
void swap_columns2D(Matrix<T, N>& m, Index i, Index j)
{
	if (i == j)
	{
		return;
	}

	Index size = m.dim1();
	for (Index row = 0; row < size; ++row)
	{
		std::swap(m[row][i], m[row][j]);	
	}
}

//--------------------------------------------------------------------------

// y   z
// |  /
// | /
// |/_ _ _ _ x
// for y1 = i and y2 = j 
template <typename T, size_t N>
void swap_columns3D(Matrix<T, N>& m, Index i, Index j)
{
	if (i == j)
	{
		return;
	}

	Index size3 = m.dim3();
	for (Index z = 0; z < size3; ++z)
	{
		swap_columns2D(m[z], i, j);
	}
}

//--------------------------------------------------------------------------

int main()
{
	try
	{
		int arr[3][3] = {{1, 2, 3}, {1 , 2, 3}, {1, 2, 3}};
		Matrix<int, 2> a(3, 3);
		a[0] = arr[0];
		a[1] = arr[1];
		a[2] = arr[2];

		std::cout <<"a = "<< a <<'\n';
		swap_columns2D(a, 0, 1);

		std::cout <<"Column 0 <-> 1.\n";
		std::cout <<"a = "<< a <<'\n';

		Matrix<int, 3> b(3, 3, 3);
		b[0][0] = arr[0];
		b[0][1] = arr[1];
		b[0][2] = arr[2];

		increment_2DArray<int, 3>(arr);

		b[1][0] = arr[0];
		b[1][1] = arr[1];
		b[1][2] = arr[2];

		increment_2DArray<int, 3>(arr);

		b[2][0] = arr[0];
		b[2][1] = arr[1];
		b[2][2] = arr[2];

		std::cout <<"b = "<< b <<'\n';
		swap_columns3D(b, 0, 1);

		std::cout <<"2D Matrix behind Column 0 <-> 1.\n";
		std::cout <<"b = "<< b <<'\n';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}