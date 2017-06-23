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
#ifndef Chapter24Exercise6_h
#define Chapter24Exercise6_h

double my_dot_product(const Numeric_lib::Matrix<double, 1>& lhs,
			          const Numeric_lib::Matrix<double, 1>& rhs)
{
	Numeric_lib::Index size = lhs.dim1();
	if (size != rhs.dim1())
	{
		throw std::runtime_error("my_dot_product::size mismatch!");
	}

	double sum = 0;
	for (Numeric_lib::Index i = 0; i < size; ++i)
	{
		sum += lhs[i] * rhs[i];
	}

	return sum;
}

//-----------------------------------------------------------------------------

Numeric_lib::Matrix<double, 1> my_scale_and_add(const Numeric_lib::Matrix<double, 1>& lhs,
											    double scale,
												const Numeric_lib::Matrix<double, 1>& rhs)
{
	Numeric_lib::Index size = lhs.dim1();
	if (size != rhs.dim1())
	{
		throw std::runtime_error("my_scale_and_add::size mismatch!");
	}

	Numeric_lib::Matrix<double, 1> resultant(size);
	for (Numeric_lib::Index i = 0; i < size; ++i)
	{
		resultant[i] = scale * lhs[i] + rhs[i];
	}

	return resultant;
}

//-----------------------------------------------------------------------------

class Elim_failure: public std::runtime_error
{
public:
	Elim_failure(std::string msg)
		: std::runtime_error(msg), what_msg(msg) 
	{ 
		what_msg.append("\n");
	}

	virtual const char* what() const throw()  
	{
		return what_msg.c_str();
	}
private:
	std::string what_msg;
};

//-----------------------------------------------------------------------------

class Back_subst_failure: public std::runtime_error
{
public:
	Back_subst_failure(std::string msg)
		: std::runtime_error(msg), what_msg(msg)
	{
		what_msg.append("\n");
	}

	virtual const char* what() const throw()
	{
		return what_msg.c_str();
	}

private:
	std::string what_msg;
};

//-----------------------------------------------------------------------------

typedef Numeric_lib::Matrix<double, 2> Matrix;
typedef Numeric_lib::Matrix<double, 1> Vector;

//-----------------------------------------------------------------------------

/*
	Converts A to upper triangular matrix, 
	modifying b as necessary.
	Otherwise throws exception reflecting inability
	to convert A to upper triangular.
*/
void classical_elimination(Matrix& A, Vector& b)
{
	const Numeric_lib::Index n = A.dim1();

	for (Numeric_lib::Index j = 0; j < n - 1; ++j)
	{
		// scale every element of the current row by the main-diagonal-element
		const double pivot = A(j, j); 

		if (pivot == 0)	// zero element on the main diagonal
		{
			std::stringstream ss;
			ss << j;
			throw Elim_failure(ss.str());
		}

		for (Numeric_lib::Index i = j + 1; i < n; ++i)
		{
			const double multiplier = A(i, j) / pivot;

			A[i].slice(j) = my_scale_and_add(A[j].slice(j), -multiplier, A[i].slice(j)); // <-------------------------------

			b[i] = multiplier * b[j];
		}
	}
}

//-----------------------------------------------------------------------------


/*
	The element with largest magnitude (abs(value)) in
	each column is found and chosen as pivot 
	(placed on main diagonal) through row swaps.
	Then elimination is done similarly to the classical cale.
*/
void partial_pivoting_elimination(Matrix& A, Vector& b)
{
	const Numeric_lib::Index n = A.dim1();

	for (Numeric_lib::Index j = 0; j < n; ++j)
	{
		Numeric_lib::Index pivot_row = j;

		// find largest magnitude element in current column 
		for (Numeric_lib::Index k = j + 1; j < n; ++k)
		{
			if (abs(A(k, j)) > abs(A(pivot_row, j))) 
			{
				pivot_row = j;
			}

			// place new pivot on main diagonal
			if (pivot_row != j)
			{
				A.swap_rows(j, pivot_row);
				// reflect row changes in rhs
				std::swap(b(j), b(pivot_row));
			}

			// proceed with elimination from j + 1 and on
			for (Numeric_lib::Index i = j + 1; i < n; ++i)
			{
				const double pivot = A(j, j);

				if (pivot == 0)
				{
					std::stringstream ss;
					ss << j;
					throw Elim_failure(ss.str());
				}

				const double multiplier = A(i, j) / pivot;

				A[i].slice(j) = scale_and_add(A[j].slice(j), -multiplier, A[i].slice(j));

				b(i) -= multiplier * b(j);
			}
		}
	}
}

//-----------------------------------------------------------------------------

/*
	
*/
Vector back_substitution(Matrix& A, Vector& b)
{
	const Numeric_lib::Index n = A.dim1();
	Vector x(n);

	for (Numeric_lib::Index i = n - 1; i >= 0; --i)
	{
		double s = b(i) - my_dot_product(A[i].slice(i + 1), x.slice(i + 1)); // <----------------------------------------

		if (double m  = A(i, i))
		{
			x(i) = s / m;
		}
		else	// zero or infinite number of solutions
		{
			std::stringstream ss;
			ss << i;
			throw Back_subst_failure(ss.str());
		}
	}

	return x;
}

//-----------------------------------------------------------------------------

Vector classical_gaussian_elimination(Matrix& A, Vector& b)
{
	classical_elimination(A, b);
	// partial_pivoting_elimination(A, b);
	return back_substitution(A, b);
}

#endif