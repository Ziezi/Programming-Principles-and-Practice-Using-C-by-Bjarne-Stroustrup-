/*
	TITLE			  Implement Rational Number Class 	Chapter9Exercise13.h
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Implement a class Rational representing a rational number.

					   Data members:	Member functions:	Overloaded operators:	Helper Function:
					   
					   numerator		get_numerator()		algebraic operations:	valid_rational()
					   denomenator		get_denominator() 	operator+				 
					   Invalid			to_fraction()		operator-				greatest_common_divisor()
															operator* 
															operator/				sign()
					   										operator= 
					   
															relational operators:
															operator==
															operator!= 
															operator<
															operator>
											 
															extraction / insertion
															operator<<
															operator>>

					   Why would someone want to use class Rational? 
					   To avoid rounding error (from algebraic operations) from floating polongrepresentation.
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 30.03.2015
*/
#ifndef CHAPTER9EXERCISE13_H
#define CHAPTER9EXERCISE13_H

/*
	Namespace Myrational

	Includes all functions
	related to clss Rational.
*/
namespace Myrational
{

/*
	Class Rarional

	Data structure representing 
	a rational number.
*/ 
class Rational
{
public:
	Rational();

	Rational(long numerator, long denominator);
	Rational(long numerator);

	Rational& operator= (const Rational& a); 
	/*
		Class Invalid

		Thrown as an exception.
	*/ 
	class Invalid 
	{

	};

	// non - modifying member functions
	long get_numerator() const { return numerator; }
	long get_denominator() const { return denominator; }

	// modifying member functions
	double to_fraction() { return (double(numerator) / denominator); }

private:

	// data members
	long numerator;
	long denominator;
};
//==================================================================================

// forward declarations
bool valid_rational(long d);
long greatest_common_divisor(long a, long b);
int sign(long a);
//===================================================================================

// Class Rational member implementation
/*
	Class Rational

	Default constructor.
*/ 
Rational::Rational()
	: numerator(0), denominator(1)
{

}
//-----------------------------------------------------------------------------------

/*
	Class Rational
	
	Consrtuctor.
*/ 
Rational::Rational(long n)
	: numerator(n), denominator(1)
{

}
//-----------------------------------------------------------------------------------

/*
	Class Rational
	
	Consrtuctor.
*/ 
Rational::Rational(long n, long d)
{
	if(!valid_rational(d))
	{
		throw Invalid();
	}

	// reduce to canonical form
	long gcd = greatest_common_divisor(n, d);

	numerator = (n == 0) ? 0 : n / gcd;
	denominator = (n == 0) ? 1 : d / gcd;

	// sign is stored in the numerator
	if (denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
}

//-----------------------------------------------------------------------------------

/*
	operator=
	 
*/
Rational& Rational::operator= (const Rational& a) 
{
	// overwrite values in this object
	numerator = a.get_numerator();
	denominator = a.get_denominator();

	return *this;
}
//===================================================================================

// Helper functions
/*
	Function: least_common_denominator();
	 
	Retuens the least common denominator
	of the two integers, a and b. 
	
	Intenally uses the Euclidian algorithm
	for LCD, recursively.
*/
long greatest_common_divisor(long a, long b)
{
	// base case
	if (b == 0) 
	{
		return a;
	}
	else // recursive step; takes the modulo(first argument) of the second argument, till it's zero 
	{
		return greatest_common_divisor(b, a % b);
	}
}
//-----------------------------------------------------------------------------------

/*
	Function: sign(n)


*/
int sign(long n)
{
	if (n > 0)
	{
		return 1;
	}

	if (n < 0)
	{
		return -1;
	}
	 
	return 0;
}
//-----------------------------------------------------------------------------------

/*
	Function: valid_rational();
	 
	Checks if the initialization 
	value of the conctructor is valid 
	rational number, i.e. denominator != 0.
*/
bool valid_rational(long d)
{
	if(d == 0)
	{
		return false;
	}
	else 
	{
		return true;
	}
}
//===================================================================================

// Overloaded operators
/*
	operator>> 

	Input format: (numerator, denominator)
*/
std::istream& operator>> (std::istream& is, Rational& r)
{
	// define input variables
	char p1, c, p2;
	long numerator, denominator; 

	// insert input
	is >> p1 >> numerator >> c >> denominator >> p2;

	// check stream status
	if (!is) return is;

	// check input format validity
	if (p1 != '('|| c != ',' || p2 != ')')
	{
		is.clear(std::ios_base::failbit);
		return is;
	}

	// initialize object in argument
	r = Rational (numerator, denominator);

	return is;
}
//-----------------------------------------------------------------------------------

/*
	operator<<

	Output format
*/
std::ostream& operator<< (std::ostream& os, Rational& r)
{
	// numerator rigth aligned, denominator left aligned 
	return os << r.get_numerator() 
			  <<"/"
			  << r.get_denominator(); 
}

//-----------------------------------------------------------------------------------

/*
	operator== 
	 
*/
bool operator== (const Rational& a, const Rational& b)
{
	return (a.get_numerator() == b.get_numerator() &&
			a.get_denominator() == b.get_denominator());
}
//-----------------------------------------------------------------------------------

/*
	operator!= 
	
*/
bool operator!= (const Rational& a, const Rational& b)
{
	return !(a.get_numerator() == b.get_numerator() &&
			a.get_denominator() == b.get_denominator());
}
//-----------------------------------------------------------------------------------

/*
	operator<
	 
*/
bool operator< (const Rational& a, const Rational& b)
{
	return ((a.get_numerator() * b.get_denominator()) < 
		    (b.get_numerator() * a.get_denominator()));
}
//-----------------------------------------------------------------------------------

/*
	operator>
	 
*/
bool operator> (const Rational& a, const Rational& b)
{
	return ((a.get_numerator() * b.get_denominator()) > 
			(b.get_numerator() * a.get_denominator()));
}
//-----------------------------------------------------------------------------------

/*
	operator+
 
*/
Rational operator+ (const Rational& a, const Rational& b)
{
	long g1 = greatest_common_divisor(a.get_denominator(), b.get_denominator()); 

	long numerator = 0;
	long denominator = 0;

	if (g1 == 1)
	{
		numerator = a.get_numerator() * b.get_denominator() + a.get_denominator() * b.get_numerator();
		denominator = a.get_denominator() * b.get_denominator();
	}
	else // recude to canonical form
	{
		long t = a.get_numerator() * (b.get_denominator() / g1) + (a.get_denominator() / g1) * a.get_numerator();

		long g2 = greatest_common_divisor(t, g1);

		numerator = t / g2;
		denominator = (a.get_denominator() / g1) * (b.get_denominator() / g2);
	}

	return Rational(numerator, denominator);
}
//-----------------------------------------------------------------------------------
/*
	operator+
 
*/
Rational operator- (const Rational& a, const Rational& b)
{
	long g1 = greatest_common_divisor(a.get_denominator(), b.get_denominator()); 

	long numerator = 0;
	long denominator = 0;

	if (g1 == 1)
	{
		numerator = a.get_numerator() * b.get_denominator() - a.get_denominator() * b.get_numerator();
		denominator = a.get_denominator() * b.get_denominator();
	}
	else // recude to canonical form
	{
		long t = a.get_numerator() * (b.get_denominator() / g1) - (a.get_denominator() / g1) * a.get_numerator();

		long g2 = greatest_common_divisor(t, g1);

		numerator = t / g2;
		denominator = (a.get_denominator() / g1) * (b.get_denominator() / g2);
	}

	return Rational(numerator, denominator);
}

//-----------------------------------------------------------------------------------

/*
	operator*

*/
Rational operator* (const Rational& a, const Rational& b)
{
	long g1 = greatest_common_divisor(a.get_numerator(), b.get_denominator());
	long g2 = greatest_common_divisor(a.get_denominator(), b.get_numerator());

	long numerator = (a.get_numerator() / g1) * (b.get_numerator() / g2);
	long denominator = (a.get_denominator() / g2) * (b.get_denominator()  / g1);

	return Rational(numerator, denominator);
}
//-----------------------------------------------------------------------------------

/*
	operator/
	 
*/
Rational operator/ (const Rational& a, const Rational& b)
{
	if (b == 0)
	{
		std::cerr <<"Division by 0!\n";
		throw Rational::Invalid();
	}

	long g1 = greatest_common_divisor(a.get_numerator(), b.get_numerator());
	long g2 = greatest_common_divisor(a.get_denominator(), b.get_denominator());

	long numerator = (a.get_numerator() / g1) * ( b.get_denominator() / g2) * (b.get_numerator());
	long denominator = std::abs((a.get_denominator() / g2) * (b.get_numerator() / g1));

	return Rational(numerator, denominator);
}

} // end of namespace Myrational

#endif