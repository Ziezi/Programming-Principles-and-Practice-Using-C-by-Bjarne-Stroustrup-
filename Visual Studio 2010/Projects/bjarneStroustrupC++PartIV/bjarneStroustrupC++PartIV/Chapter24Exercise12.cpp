/*
	TITLE		   Matrix addition & dot product Tensor & Vector  Chapter24Exercise12.cpp
	COMMENT
		Objective: Implement:
		           Matrix<double> operator* (Matrix<double, 2>&, Matrix<double>&);
				   and 
				   Matrix<double, N> operator+ (Matrix<double, N>&, Matrix<double, N>&); 
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 08.05.2017
*/
#include <iostream>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

/* dot product Tensor & Vector */
template <typename T>
Matrix<T> operator* (const Matrix<T, 2>& tensor, const Matrix<T>& vector)
{
	Index v_size = vector.size();
	
	if (v_size != tensor.dim1())
	{
		throw std::runtime_error("Tensor-vector dot product::size mismatch!\n");
	}

	Matrix<T> result(v_size);

	for (Index i = 0; i < v_size; ++i)
	{
		result[i] = dot_product(tensor[i], vector);
	}

	return result;
}

//--------------------------------------------------------------------------

/* randomly multidimensional Tensor addition */
template<typename T, size_t N>
Matrix<T, N> operator+ (const Matrix<T, N>& lhs, const Matrix<T, N>& rhs)
{
	Index size = lhs.size();

	if (size != rhs.size())
	{
		throw std::runtime_error("Tensor addition::size mismatch!\n");
	}

	Matrix<T, N> result = lhs;

	const T* data_array = rhs.data();
	T* accumulator = result.data();

	for (Index i = 0; i < size; ++i)
	{
		accumulator[i] += data_array[i];
	}

	return result;
}

//--------------------------------------------------------------------------

int main()
{
	try
	{
		int arr[3][3] = {{1, 2, 3}, {1 , 2, 3}, {1, 2, 3}};

		Matrix<int, 2> a(3, 3);
		Matrix<int, 1> b(3);

		a[0] = arr[0];
		a[1] = arr[1];
		a[2] = arr[2];

		b = arr[0];

		// tensor - vector dot product
		Matrix<int, 1> c = a * b;

		std::cout <<"3 x 3 Tensor a = \n"<< a <<'\n';
		std::cout <<"3 Vector b = \n"<< b <<'\n';
		std::cout <<"3 Vector c = a.b\n"<< c <<'\n';

		// tensor addition
		Matrix<int, 2> d(3, 3);
		d = a + a + a;
		
		std::cout <<"3 x 3 Tensor a = \n"<< a <<'\n';
		std::cout <<"3 x 3 Tensor d = a + a + a \n"<< d <<'\n';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}