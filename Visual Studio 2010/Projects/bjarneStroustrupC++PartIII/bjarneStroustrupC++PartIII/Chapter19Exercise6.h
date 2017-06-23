/*
	TITLE			Templatized Class Number    Chapter19Exercise6.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Define a class Number<T>
					having a single member of numeric type.
					Define constructors, assignment, operators +,-,/,*,
					I/O opeators <<, >>.

					Test and improve desing as needed.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 24.1.2016
*/

#ifndef CHAPTER19EXERCISE6_H
#define CHAPTER19EXERCISE6_H
#include <algorithm> // swap
#include <limits>    // epsilon() and min()

template<class T>
class Number 
{
public:
	T value;

	// Constructors
	Number<T> ()
		: value(T()) 
	{
	
	}

	Number<T> (T v)
		: value(v)
	{
		// type check
		// range check
	}

	Number<T> (const Number<T>& src) 
		: value(src.value) 
	{
	
	}

	Number<T> operator= (Number<T> n) 
	{ 
		std::swap(value, n.value);
		return *this;
	}

	// move constuctor
	Number<T> (Number<T>&& src)
		: value(std::move(src.value)) 
	{
	
	}

	// Aritmetic operators 
	Number<T> operator+ (Number<T>& rhs) { return Number<T>(value + rhs.value); }
	Number<T> operator- (Number<T>& rhs) { return Number<T>(value - rhs.value); }
	Number<T> operator/ (Number<T>& rhs) { return Number<T>(value / rhs.value); }
	Number<T> operator* (Number<T>& rhs) { return Number<T>(value * rhs.value); }

	/* 
	   To allow multipliation in: 
	   dot_product += num1 * num2 
	   in the dot product function
	   between the elements of
	   const vectors, we need to
	   return by value.
	*/
	friend Number<T> operator* (const Number<T>& lhs, const Number<T>& rhs) { return Number<T>(lhs.value * rhs.value); } 

	Number<T> operator% (Number<T>& rhs) { return Number<T>(value % rhs.value); }
	// compound operators
	// operator +=
	Number<T>& operator+= (const Number<T>& rhs) 
	{
		this->value += rhs.value;
		return *this; 
	} 

	// I/O operations
	friend std::ostream& operator<< (std::ostream& os, const Number<T>& src)
	{
		return os << src.value;
	}

	friend std::istream& operator>> (std::istream& is, Number<T>& dest) 
	{
		is >> dest.value;
		return is;
	}

	// Relational operators
	bool operator< (const Number<T>& rhs);
	bool operator> (const Number<T>& rhs);
	bool operator== (const Number<T>& rhs);
};

//-------------------------------------------------------------------------------------------------

// Relational operators
template <class T>
bool Number<T>::operator< (const Number<T>& rhs) 
{
	return value  < rhs.value;
} 

//-------------------------------------------------------------------------------------------------

template <class T>
bool Number<T>::operator> (const Number<T>& rhs)
{
	return value > rhs.value;
}

//-------------------------------------------------------------------------------------------------

// precision in ULPs (units in the last place)
template <class T>
bool Number<T>::operator== (const Number<T>& rhs) 
{
	T res = value - rhs.value;

	// mimics std::abs for type T
	res *= (res < 0) ? -1 : 1;
	return res < std::numeric_limits<double>::epsilon() ||
		   res < std::numeric_limits<double>::min();
} 
		 
#endif