/*
	TITLE			Class Int		          Chapter19Exercise5.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Define a class Int
					having a single member of type int.
					Define constructors, assignment, operators +,-,/,*,
					I/O opeators <<, >>.

					Test and improve desing as needed.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 24.1.2016
*/
#ifndef CHAPTER19EXERCISE5_H
#define CHAPTER19EXERCISE5_H

class Int 
{
public:
	// data member
	int value;

	// Constructors
	Int()
		: value(0) 
	{
	
	} 

	Int(int i)
		: value(i)
	{
		// type test
		// range test
	}

	Int(const Int& src)
		: value(src.value)
	{
		// type test
		// range test
	}

	Int& operator= (Int src)
	{ 
		std::swap(value, src.value);
		return *this;	
	}

	Int(Int&& src)
		: value(std::move(src.value)) 
	{
	
	}

	// Aritmetic operators 
	Int operator+ (Int rhs) { return value + rhs.value; }
	Int operator- (Int rhs) { return value - rhs.value; }
	Int operator/ (Int rhs) { return value / rhs.value; }
	Int operator* (Int rhs) { return value * rhs.value; }

	// I/O operations
	friend std::ostream& operator<< (std::ostream& os, const Int& src)
	{
		 return os << src.value;
	}

	friend std::istream& operator>> (std::istream& is, Int& dest) 
	{
		is >> dest.value;
		return is;
	}
};

#endif