/*
	TITLE	           Test Class Date				Chapter9Drill3.h
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
	struct Date
	
	It represents an astronomical 
	date consisted of:
	year, month and day.
*/
class Date
{
public:	
	// constructor
	Date(int y, int m, int d);

	// non-modifying member
	int year() const { return y; }
	int month() const { return m; }
	int day() const { return d; }

	// modifying member function
	void add_day(int n);

private:
	// data members
	int y, m, d;

};

// forward declaration
bool is_leapyear(int year);
bool is_valid_input(int y, int m, int d);

//--------------------------------------------------------------

// Class Date member implementations
/*
	Class Date constructor
*/
Date::Date(int yy, int mm ,int dd)
	: y(yy), m(mm), d(dd) 
{
	if (!is_valid_input(yy, mm, dd))
	{
		std::cerr <<"Not valid input\n";
	}
	
}
//--------------------------------------------------------------

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
//=============================================================

// Helper fucntion
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
//--------------------------------------------------------------

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