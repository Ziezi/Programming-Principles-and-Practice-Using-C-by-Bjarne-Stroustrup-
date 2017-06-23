/*
	TITLE	           Test Class Date				Chapter9Drill5.h
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Test all the versions of the Date class. 
					   Instantiate an object, called "today" and initialize it 25 June 1978.
					   Intstantiate a second object, caled "tomorrow" by assignment from the first.
					   Add one day to "tomorrow".
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 12.03.2015
*/

#ifndef CHAPTER9DRILL5_H
#define CHAPTER9DRILL5_H

/*
	Class Date

	Data structure representing 
	an astronomical year.
*/ 
class Date
{
public:
	// plain data structure representing astronomical month
	enum Month { jan = 1, feb, mar, apr, may, jun, jul ,aug, sep, oct, nov, dec };

	// default constructor
	Date();
	// constructor
	Date(int y, Month m, int d);
	
	// non-modifying member functions
	int day() const { return d; }
	Month month() const { return m; }
	int year() const { return y; }

	// modifying member functions
	void add_day(int d);
	void add_month(int m);
	void add_year(int y);

private:
	// data members
	int y;
	Month m;
	int d;
};

// forward declarations
Date& default_date();
bool is_valid_input(int y, int m, int d);
bool is_leapyear(int year);

//-------------------------------------------------------------------------------------------
// class Date member implementation

/*
	class Date default constructor

*/ 
Date::Date()
	: y(default_date().year()), m(default_date().month()), d(default_date().day())
{
	
}
//-------------------------------------------------------------------------------------------

/*
	class Date constructor

*/ 
Date::Date(int y, Month m, int d ): y(y), m(m), d(d)
{
	if (!is_valid_input(y, m, d))
	{
		std::cerr <<"Invalid input!\n";
	}
}
//-------------------------------------------------------------------------------------------

/*
	Member Function: add_day();
	Use: add_day(days);

	It increments the date of the object 
    by the amount of days passed via the second.
	Checks for leap year; wraps up the days
	of months, without incrementing month.
*/
void Date::add_day(int n)
{
	if (n < 1 || n > 31)
	{
		std::cerr <<"invalid value!\n";
	}

	switch(month())
	{
		case feb:
		{
			if (is_leapyear(y))
			{
				d += n % 29;
			}
			else
			{
				d += n % 28;
			}
			break;
		}
		case apr: case jun: case sep: case nov:
		{
			d += n % 30;
			break;
		}
		default:
		{
			d += n % 31;
			break;
		}
	}
}
//-------------------------------------------------------------------------------------------

/*
	Function: add_month(n);

	Increments the current date's
	month by n.  
*/
void Date::add_month(int n)
{
	if (n < 1 || n > 12) 
	{
		std::cerr <<"Invalid value for month!\n";
	}

    m = Month((m + n) % 12);
}
//-------------------------------------------------------------------------------------------

/*
	Member function: add_year(n);

	It increments the current date's
	year by n years forward.  
*/
void Date::add_year(int n)
{
	if (n < 0) 
	{
		std::cerr <<"Invalid value for year!\n";
	}

	y += n;
}
//===========================================================================================

// Helper fucntions

/*
	Function: is_leapyear();
	Use: bool leap = is_leapyear(date);

	Returns true is the date is a
	a leap year;
*/
bool is_leapyear(int year)
{
	if (year % 4 != 0)
	{
		return false;
	}
	else if (year % 100 != 0)
	{
		return true;
	}
	else if (year % 400 != 0)
	{
		return false;
	}
	else return true;
}
//-------------------------------------------------------------------------------------------

/*
	Function: default_date();

	Initializes the default 
	constructor values.
*/ 
Date& default_date()
{
	// this date is created and initialized only ones(in memory),
	// during the first call of this function
	static Date dd(2001, Date::jan, 1);
	return dd;
}

//================================================================================================

// Helper functions
/*
	Function: is_valid_input();
	Use: bool valid = is_valid_input(year, month, day);

	It checks if the parameters are valid values
	for astronomical Date.
*/
bool is_valid_input(int y, int m, int d)
{
	if (y < 0)
	{
		return false;
	}

	if (m < 1 || m > 12)
	{
		return false;
	}

	if (d < 1 || d > 31)
	{
		return false;
	}

	return true;
}

//================================================================================================

// Overloaded operators
/*
	Overloaded Conditional operator==

	It returns true if every data 
	member of the two parameters
	are equal.
*/
bool operator== (Date& a, Date& b)
{
	return a.year() == b.year() &&
		   a.month() == b.month() &&
		   a.day() == b.day();
}

#endif