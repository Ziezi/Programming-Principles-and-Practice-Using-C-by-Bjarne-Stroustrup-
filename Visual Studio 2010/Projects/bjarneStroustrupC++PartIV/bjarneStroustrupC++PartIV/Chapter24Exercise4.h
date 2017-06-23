/*
	TITLE		   Gaussian Elimination   	Chapter24Exercise4.h
	COMMENT
		Objective: Get the Gaussian elimination program to work;
				   that is, complete it, get it to compile, 
				   and test it with a simple example. 
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 05.05.2017
*/
#ifndef Chapter24Exercise4_h
#define Chapter24Exercise4_h

class Elim_failure: public std::runtime_error
{
public:
	Elim_failure(std::string msg)
		: std::runtime_error(msg), what_msg(msg) 
	{ 
	
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

			A[i].slice(j) = scale_and_add(A[j].slice(j), -multiplier, A[i].slice(j));

			b[i] = multiplier * b[j];
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
		double s = b(i) - dot_product(A[i].slice(i + 1), x.slice(i + 1));

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
	return back_substitution(A, b);
}

#endif