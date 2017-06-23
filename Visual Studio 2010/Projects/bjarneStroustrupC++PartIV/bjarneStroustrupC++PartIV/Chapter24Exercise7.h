/*
	TITLE		   Code Refactoring - Generalize Type				   Chapter24Exercise7.h
	COMMENT
		Objective: Rewrite the Gaussian elimination program without using the Matrix library;
				   that is, use built-in arrays or vectors instead of Matrixes.
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 07.05.2017
*/
#ifndef Chapter24Exercise7_h
#define Chapter24Exercise7_h

template<class T>
std::ostream& operator<< (std::ostream& os, std::vector<T>& v)
{
	os <<"{ ";
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		os << std::setw(3) << *it <<" ";
	}
	os <<"}\n";
	return os;
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

typedef std::vector<std::vector<double>> Matrix;
typedef std::vector<double> Vector;

//-----------------------------------------------------------------------------

class Scale_and_Add
{
public:
	Scale_and_Add(double m)
		: multiplier(m)
	{
	
	}

	double operator()(const double& lhs, const double& rhs)
	{
		return lhs + rhs * multiplier;
	}

private:
	double multiplier;
};

//-----------------------------------------------------------------------------

/*
	Converts A to upper triangular matrix, 
	modifying b as necessary.
	Otherwise throws exception reflecting inability
	to convert A to upper triangular.
*/
void classical_elimination(Matrix& A, Vector& b)
{
	const int n = A.size();

	for (int j = 0; j < n - 1; ++j)
	{
		// scale every element of the current row by the main-diagonal-element
		const double pivot = A[j][j]; 

		if (pivot == 0)	// zero element on the main diagonal
		{
			std::stringstream ss;
			ss << j;
			throw Elim_failure(ss.str());
		}

		for (int i = j + 1; i < n; ++i)
		{
			const double multiplier = A[i][j] / pivot;

			// input_it1b, input_it1e, input_it2b, output_itb, binary_op
			std::transform(A[i].begin() + j, A[i].end(), A[j].begin() + j, A[i].begin() + j, Scale_and_Add(-multiplier));          
			// A[i][j] = my_scale_and_add(A[j][j], -multiplier, A[i][j]);  

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
	const int n = A.size();

	for (int j = 0; j < n; ++j)
	{
		int pivot_row = j;

		// find largest magnitude element in current column 
		for (int k = j + 1; j < n; ++k)
		{
			if (abs(A[k][j]) > abs(A[pivot_row][j])) 
			{
				pivot_row = j;
			}

			// place new pivot on main diagonal
			if (pivot_row != j)
			{
				std::swap_ranges(A[j].begin(), A[j].end(), A[pivot_row].begin());
				// A.swap_rows(j, pivot_row);

				// reflect row changes in rhs
				std::swap(b[j], b[pivot_row]);
			}

			// proceed with elimination from j + 1 and on
			for (int i = j + 1; i < n; ++i)
			{
				const double pivot = A[j][j];

				if (pivot == 0)
				{
					std::stringstream ss;
					ss << j;
					throw Elim_failure(ss.str());
				}

				const double multiplier = A[i][j] / pivot;

				// input_it1b, input_it1e, input_it2b, output_itb, binary_op
				std::transform(A[i].begin() + j, A[i].end(), A[j].begin() + j, A[i].begin() + j, Scale_and_Add(-multiplier));  
				// A[i].slice(j) = scale_and_add(A[j].slice(j), -multiplier, A[i].slice(j));

				b[i] -= multiplier * b[j];
			}
		}
	}
}

//-----------------------------------------------------------------------------

/*
	
*/
Vector back_substitution(Matrix& A, Vector& b)
{
	const int n = A.size();
	Vector x(n);

	for (int i = n - 1; i >= 0; --i)
	{
		double s = b[i] - std::inner_product(A[i].begin() + (i + 1), A[i].end(), x.begin() + (i + 1), 0.0);
		// double s = b[i] - dot_product(A[i].slice(i + 1), x.slice(i + 1)); 

		if (double m  = A[i][i])
		{
			x[i] = s / m;
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