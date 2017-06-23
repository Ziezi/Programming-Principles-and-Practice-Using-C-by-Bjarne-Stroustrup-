/*
	TITLE			   Class Money				      Chapter9Exercise14.h
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Implement class Money.

					Data members:	Member functions:	Overloaded operators:	Helper functions:
									get_dollars()		copy assignment			round_and_convert()
								    set_dollars()		operator=				 
																				 
					cents			get_all_in_cents()	relational:				 
									set_all_in_cents()	operator<				convert_to_dollars_and_cents()
														operator>				convert_to_cents()
					Invalid			Money()  			operator==
									Money(all_cents)	operator!=
								 	Money(dollars)												
														algebracaic:
														operator+
														operator-
														 
														insertion / extraction:
														operator<<
														operator>>
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 31.03.2015
*/
#ifndef CHAPTER9EXERCISE14_H
#define CHAPTER9EXERCISE14_H

/*
	Namespace Mycurrency

	Encompasses the code
	related to class Money.
*/
namespace Mycurrency
{

/*
	Class Money

	Data structure representing
	a meduim of exchange. 
*/ 
class Money
{
public:
	// default constructor
	Money();

	// constructors
	Money(long long c);
	Money(double d);

	// copy assignment 
	Money& operator= (const Money& a); 

	/*
		Class Invalid

		Thrown as exception.
	*/ 
	class Invalid{};

	double get_dollars();
	long long get_all_in_cents() const { return cents; }

	void set_dollars(double d);
	void set_all_in_cents(long long c) { cents = c; } 

private:
	// private function members
	long long convert_to_cents(double d);
	double convert_to_dollars_and_cents(long long c);

	// data members
	long long cents;
};
//==============================================================================================

// forward declarations
long long round_and_convert(double d);

//==============================================================================================


// Class Money member implementations
/*
	Class Money

	Default constructor.
*/ 
Money::Money()
	: cents(0)
{

}
//----------------------------------------------------------------------------------------------

/*
	Class Money

	Constructor: initialize from amount expressed in terms of cents.
*/ 
Money::Money(long long all_cents)
	: cents(all_cents)
{

}
//----------------------------------------------------------------------------------------------

/*
	Class Money

	Constructor: initialize 
	from  dollars and cents
	as a floating point number.
*/ 
Money::Money(double d)
	: cents(round_and_convert(d))
{

}
//----------------------------------------------------------------------------------------------

/*

*/
Money& Money::operator= (const Money& a)
{ 
	cents = a.get_all_in_cents();
	return *this;
}
//----------------------------------------------------------------------------------------------

/*

*/ 
double Money::get_dollars()
{
	return convert_to_dollars_and_cents(cents);
}
//----------------------------------------------------------------------------------------------
	
/*

*/ 
void Money::set_dollars(double d)
{
	cents = round_and_convert(d);
}
//----------------------------------------------------------------------------------------------

/*
	Function: convert_to_cents(double dollars);
	 
	Converts an input amount of money from
	dollars and cents to cents,
	for the class data member.
*/
long long Money::convert_to_cents(double d) 
{
	 return round_and_convert(d);
}
//----------------------------------------------------------------------------------------------

/*
	Function: convert_to_dollars_and_cents(long long c);
	 
	Converts the value of the class data member from cents
	to dollars and cents, as floating point number.
*/
double Money::convert_to_dollars_and_cents(long long c)
{
	if (c >= -100 || c <= 100)
	{
		double fraction_part = static_cast<double>(c);

		return (fraction_part / 100.0);
	}

	long long dollars = c / 100;
	long long cents = c % (dollars * 100);
	 
	double fraction_part = static_cast<double>(cents) / 100.0;
	double decimal_part = static_cast<double>(dollars);

	return decimal_part + fraction_part;
}
//==============================================================================================

// Helper functions
/*
	Function: round_and_convert()

	It converts a double to unsigned long long
	and rounds to the second digit, 
	using 4/5 rule.
*/
long long round_and_convert(double d)
{
	 return static_cast<long long>((d + 0.005) * 100);
}
//==============================================================================================

// Overloaded operators
/*
	operator+
	 
*/
Money operator+ (const Money& a, const Money& b)
{
	long long sum = a.get_all_in_cents() + b.get_all_in_cents();

	// check for overflow
	if (sum < a.get_all_in_cents() || sum < b.get_all_in_cents())
	{
		std::cerr <<"Addition overflow!\n";
		throw Money::Invalid();
	}

	return Money(sum);
}
//----------------------------------------------------------------------------------------------

/*
	operator-
	 
*/
Money operator- (const Money& a, const Money& b)
{
	long long difference = a.get_all_in_cents() - b.get_all_in_cents();

	// check underflow
	if (difference > a.get_all_in_cents())
	{
		std::cerr <<"Addition underflow!\n";
		throw Money::Invalid();
	}

	return Money(difference);
}
//----------------------------------------------------------------------------------------------

/*
	operator== 
	 
*/
bool operator== (const Money& a, const Money& b)
{
	return a.get_all_in_cents() == b.get_all_in_cents();
}
//----------------------------------------------------------------------------------------------

/*
	operator!= 
	 
*/
bool operator!= (const Money& a, const Money& b)
{
	return !(a == b);
}
//----------------------------------------------------------------------------------------------

/*
	operator<

*/
bool operator< (const Money& a, const Money& b)
{
	return a.get_all_in_cents() < b.get_all_in_cents();
}
//----------------------------------------------------------------------------------------------

/*
	operator>

*/
bool operator> (const  Money& a, const  Money& b)
{
	return a.get_all_in_cents() > b.get_all_in_cents();
}
//----------------------------------------------------------------------------------------------

/*
	operator>>
	
*/
std::istream& operator>> (std::istream& is, Money& r)
{
	// define input variables
	double dollars; 

	// extract input
	is >> dollars;
	
	// check stream status
	if (!is) return is;

	// initialize object in argument
	r = Money(dollars);

	return is;
}
//----------------------------------------------------------------------------------------------

/*
	operator<<
	
*/
std::ostream& operator<< (std::ostream& os, Money& r)
{
	return os << std::setprecision(2)
			  << std::fixed
		      << r.get_dollars() 
			  <<" $"; 
}

} // end of namespace Mycurrency

#endif
