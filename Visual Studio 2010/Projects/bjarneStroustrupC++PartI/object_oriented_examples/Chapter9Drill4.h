/*
	TITLE	           Test Class Date				Chapter9Drill4.h
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

/*
	Class Year

	Data structure representing
	an astronomical year .
*/ 
class Year
{
	// referent values defining a valid value for year
	static const int min = 0;
	static const int max = 2100;

public:
	// class used to indicate invalid value; thrown as exception
	class Invalid{ };

	// constructor
	Year(int x)
		: y(x)
	{ 
		if (x < min || x > max)
		{
			throw Invalid();
		} 
	}

	// non-modification member function
	int year() { return y; }

private:
	int y;
};
//=========================================================================

/*
	 Class Date

	 Data structure representing an
	 astronomical date consisted of:
	 year, month, day
*/
class Date
{
public:
	// data structure repsresenting month
	enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

	// constructor
	Date(Year y, Month m, int d);

	// non - modifying member functions
	int year() { return y.year(); }
	int month() const {return m; }
	int day() const { return d; }

	// modifying members
	void add_day(int n);

private:
	Year y;
	Month m;
	int d;
};

// forward declaration
bool is_valid_input(Date::Month m, int d);
bool is_leapyear(Year y);

//-------------------------------------------------------------------------

// class Date Member implementations
/*
	Class Date constructor

*/ 
Date::Date(Year y, Month m, int d )
	: y(Year(y)), m(m), d(d)
{
	 if (!is_valid_input(m, d))
	 {
		std::cerr <<"Invalid input!\n";	 
	 }
}

//-------------------------------------------------------------------------

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
	if (n < 0 || n > 28)
	{
		std::cerr <<"invalid value!\n";
	}

	switch(m)
	{
		case 2:
		{
			if(d == 28)
			{ 
				d = (is_leapyear(y)) ? 29 : 1;
			}
			else
			{
				++d;
			}
			break;
		}
		case 4: case 6: case 9: case 11:
		{
			d = (d == 30) ? 1 : ++d;
			break;
		}
		default:
		{
			d = (d == 31) ? 1 : ++d;
			break;
		}
	}
}
//=========================================================================

// Helper fucntions
/*
	Function: is_leapyear();
	Use: bool leap = is_leapyear(Year);

	Returns true is the date is a
	a leap year;
*/
bool is_leapyear(Year y)
{
	int year = y.year();

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
//-------------------------------------------------------------------------

/*
	Function: is_valid_input();
	Use: bool valid = is_valid_input(year, month, day);

	It checks if the parameters are valid values
	for astronomical Date.
*/
bool is_valid_input(Date::Month m, int d)
{
	if (m < Date::jan || m > Date::dec)
	{
		return false;
	}

	if (d < 1 || d > 31)
	{
		return false;
	}

	return true;
}
