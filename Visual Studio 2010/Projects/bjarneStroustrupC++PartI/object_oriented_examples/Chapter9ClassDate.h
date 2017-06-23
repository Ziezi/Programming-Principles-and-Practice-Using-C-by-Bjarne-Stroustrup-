/*
	TITLE			   Class Date					 Chapter9ClassDate.cpp
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective:  

			Class Date:

			Data Members:	Function Members:		      Overloaded operators:		Helper Functions:
										
			year			Date()						  operator=					isMonthWith30Days()		
			month			Date(int y, Month m, int d)	  operator==				isMonthWith31Days()
			day				get_year()					  operator!=				leapYear()
							get_month()					  operator<					isDate()
							get_day()					  operator>	
														  operator<<	
							add_day()				      operator>>
							add_month()
							add_year()

			//------------------------------------------------------------------------------------------

            Enum:		    Functions:
		    Day				dayOfWeekThirdVersion()  
							dayToString()
							nextSunday()
							nextWeekday()
			
			//------------------------------------------------------------------------------------------
			// Additional Algorithms from "Jean Meeus - Astronomical Algorithms copyright date 1991."
							
							Functions:
							myremquo()
							toJulianDateFomat()
							toClassDateFormat()
							numberOfDayInYear()
							dayImMonth()
							dateOfEaster()
							dateOfEasterJulian()

				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 17.03.2015
*/
#ifndef CHAPTER9CLASSDATE_H
#define CHAPTER9CLASSDATE_H

/*
	namespace Chrono
	
	Contains all members 
	relevant to class Date.
*/ 
namespace Chrono
{

/*
	Class Date

	Data structure representing
	an astronomical date.
*/
class Date
{
public:
	/*
		enum Month

		Data structure representing
		an astronomical month.
	*/
	enum Month{ jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

	/*
		class Invalid
		
		Thrown as an exception.
	*/ 
	class Invalid{};

	// default constructors
	Date();

	// constructor
	Date(int y, Month m ,int d);

	// non- modifying functions
	int get_year() const { return year; }
	Month get_month() const { return m; }
	int get_day() const { return day; }

	// modifying functions
	void add_year(int n);
	void add_month(int n);
	void add_day(int n);

	//overloaded operators
	void operator= (const Date& d);

private:

	// data members
	int year;
	Month m;
	int day;
};
//====================================================================================================

// Helper functions
/*
	Function: isMonthWith30Days(Date::Month m);
	 
	It returns true if month passed
	via the parameter has 30 days.
*/
bool isMonthWith30Days(Date::Month m)
{
	switch(m)
	{
		case Date::apr: case Date::jun: case Date::sep: case Date::nov: 
		{
			return true;
		}
		default:
		{
			return false;
		}
	}
}
//----------------------------------------------------------------------------------------------------

/*
	Function: isMonthWith31Days();
	 
	It returns true if month passed
	via the parameter has 31 days. 
*/
bool isMonthWith31Days(Date::Month m)
{
	switch(m)
	{
		case Date::jan: case Date::mar: case Date::may: case Date::jul: 
		case Date::aug: case Date::oct: case Date::dec:  
		{
			return true;
		}
		default:
		{
			return false;
		}
	}
}
//----------------------------------------------------------------------------------------------------

/*
	Function: leapYear();
	 
	It returns true if the 
	year passed by the parameter
	is a leap year.
*/
bool leapYear(int y)
{
	if (y % 4 != 0 )
	{
		return false;
	}
	else if (y % 100 != 0) 
	{
		return true;
	}
	else if (y % 400 != 0)
	{
		return false;
	}
	else 
	{
		return true ;
	}
}
//----------------------------------------------------------------------------------------------------

/*
	Function: isDate();
	 
	It returns true if the 
	values passed via the parameters
	constitute a valid astronomical date.
*/
bool isDate(int y, Date::Month m, int d)
{
	if (y < 0 || d < 0 || m < Date::jan || m > Date::dec)
	{
		return false;
	}

	if(isMonthWith30Days(m) && d > 30)
	{
		return false;
	}

	if(isMonthWith31Days(m) && d > 31)
	{
		return false;
	}

	if(m == Date::feb && leapYear(y) && d >= 29)
	{
		return false;
	}

	if(m == Date::feb && !leapYear(y) && d >= 28)
	{
		return false;
	}

	return true;
}
//====================================================================================================

// Overloaded operators
/*
	operator ==
	 
*/
bool operator== (const Date& a, const Date& b)
{
	return a.get_year() == b.get_year() &&
		   a.get_month() == b.get_month() &&
		   a.get_day() == b.get_day();
}
//----------------------------------------------------------------------------------------------------

/*
	oerator !=
	
*/
bool operator!= (const Date& a, const Date& b)
{
	return !(a == b);
}
//----------------------------------------------------------------------------------------------------

/*
	oerator <
	 
*/
bool operator< (const Date&a, const Date& b)
{
	return a.get_year() < b.get_year() ||
		   a.get_month() < b.get_month() || 
		   a.get_day() < b.get_day();
}
//----------------------------------------------------------------------------------------------------

/*
	operator >
	 
*/
bool operator> (const Date&a, const Date& b)
{
	return a.get_year() > b.get_year() ||
		   a.get_month() > b.get_month() || 
		   a.get_day() > b.get_day();
}
//----------------------------------------------------------------------------------------------------

/*
	operator <<
	
*/
std::ostream& operator<< (std::ostream& os, const Date& a)
{
	return os <<"("<< a.get_year()  <<", "
			       << a.get_month() <<", "
			       << a.get_day()   <<")";
}
//----------------------------------------------------------------------------------------------------


/*
	operator=
	 
*/
void Date::operator= (const Date& d)
{
	year = d.get_year();
	m = d.get_month();
	day = d.get_day();
}
//----------------------------------------------------------------------------------------------------

/*
	operator >>
	 
*/
std::istream& operator>> (std::istream& is, Date& a)
{
	// define input variables
	int y, m, d;
	char ch1, ch2, ch3, ch4;

	// extract input
	is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;

	// check stream state
	if(!is) 
	{
		return is;
	}

	// check input format validity
	if(ch1!='(' || ch2 != ',' || ch3 != ',' || ch4 !=')')
	{
		is.clear(std::ios_base::failbit);
		return is;
	}

	// initialize a new date with the input 
	a = Date(y, Date::Month(m), d);

	return is;
}
//====================================================================================================

// Class Date member implementations
/*
	Class Date

	Default constructor.
*/ 
Date::Date()
	: year(2015), m(jan), day(1)
{

}
//----------------------------------------------------------------------------------------------------

/*
	Class Date

	Constructor.
*/ 
Date::Date(int y, Month mo, int d)
	: year(y), m(mo), day(d) 
{
	if(!isDate(y, mo, d))
	{
		throw Invalid();
	}
}
//----------------------------------------------------------------------------------------------------

/*
	Function: add_year(n);
	 
	Increases the current date
	by the amount of years of
	its argument.
*/
void Date::add_year(int n)
{
	if (n < 0)
	{
		throw Invalid();
	}

	year += n;
}
//----------------------------------------------------------------------------------------------------

/*
	Function: add_month(n);
	 
	Increments the current date's
	month by n.  
*/
void Date::add_month(int n)
{
	if (n < 1 || n > 12) 
	{
		throw Invalid();
	}

    m = Month((m + n) % 12);
}
//----------------------------------------------------------------------------------------------------

/*
	Function: add_day(n);
	 
	It increments the date of the object 
    by the amount of days passed via the second.
	Checks for leap year; wraps up the days
	of months, without incrementing month.
*/
void Date::add_day(int n)
{
	if(n < 1 || n > 31) 
	{
		throw Invalid();
	}

	switch(m)
	{
		case feb:
		{
			if (leapYear(year))
			{
				day += n % 29;
			}
			else
			{
				day += n % 28;
			}
			break;
		}
		case apr: case jun: case sep: case nov:
		{
			day += n % 30;
			break;
		}
		default:
		{
			day += n % 31;
			break;
		}
	}
}
//====================================================================================================

/*
	enum Day

	Data structure representing 
	day of the week.
*/ 
enum Day{ sunday, monday, tuesday, wednesday, thursday, friday, saturday };
//----------------------------------------------------------------------------------------------------

// Day Helper functions
// Rerurns current day value of the object
/*
	Function: dayOfWeek();
	Use: Day d = dayOfWeek(object_date);

	This function calculates which day of 
	week the Date passed by reference is.

	Internally, it calculates the days
	passed from the first day(1.1.0001) 
	of the Gregorian calendar, accounting
	for leap years. The residue of the 
	division of the total days by 7 
	represents a day of the week.
*/
Day dayOfWeekThirdVersion(const Date& d)
{
	 
	int cyear = d.get_year();
	int cmonth = d.get_month();
	int cday = d.get_day();  /* 1 <= m <= 12,  y > 1752 or so */

    static int t[ ] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    cyear -= cmonth < 3;

    int dayofweek = (cyear + cyear/4 - cyear/100 + cyear/400 + t[cmonth-1] + cday) % 7;

	return Day(dayofweek);
}
//----------------------------------------------------------------------------------------------------

/*
	Function: dayToString();

	Returns a string representing
	the name of the respective
	day of the week passed via the
	parameter.
*/
std::string dayToString(const Day& d)
{
	static std::string days[] = {"Sunday", "Monday", "Tuesday",
								 "Wednesday", "Thursday", "Friday",
								 "Saturday"};
	return days[d];
}
//----------------------------------------------------------------------------------------------------

/*
	Function: nextSunday();

	Calculates the Date of the next Sunday
	after the date passed via the parameter.

	Internally it calls dayOfWeek() and 
	based on its result increments the day
	till it becomes Sunday.
*/
Date nextSunday(const Date& d)
{
	// it considers if next sunday is in next month as well
	Day currentday = dayOfWeekThirdVersion(d);

	Date::Month currentmonth = d.get_month();

	int i;
	// this loop incremenets the counter 'i' till the modulo 7 of its sum with the current date is 0
	// i.e. till current date is incremented to Sunday (with number 0)
	for (i = 0; i < 7; i++){
		if ((currentday + i) % 7 == 0)
		{
			// if month with 30 days
			if(isMonthWith30Days(currentmonth))
			{
				// increment month if added days are outside 30, days = remainder of (current days + i)/30  
				if ((d.get_day() + i) > 30) 
				{
					return Date(d.get_year(), Date::Month(d.get_month() + 1), (d.get_day() + i) % 30);
				}
				else
				{
					return Date(d.get_year(), d.get_month(), d.get_day() + i);
				}
			} // if month with 31 days
	        else if(isMonthWith31Days(currentmonth))
			{
				// increment month if added days are outside 31, days = remainder of (current days + i)/31  
				if ((d.get_day() + i) > 31)
				{
					return Date(d.get_year(), Date::Month((d.get_month()) + 1), (d.get_day() + i) % 31);
				}
				else
				{
					return Date(d.get_year(), d.get_month(), d.get_day() + i);
				}
			} // if current month february, check for leap year 
			else if(currentmonth == 2)
			{
				if(leapYear(d.get_year()) && (d.get_day()+i) > 29)
				{
					return Date(d.get_year(), Date::Month((d.get_month()) + 1), (d.get_day() + i) % 29);
				}
				else if(!leapYear(d.get_year()) && (d.get_day() + i) > 28) 
				{
					return Date(d.get_year(), Date::Month((d.get_month()) + 1), (d.get_day() + i) % 28);
				}
				else 
				{
					return Date(d.get_year(), d.get_month(),d.get_day() + i);
				}
			} // if current month december, increment: year, month and day, if day is > 31
			else if(currentmonth == 12)
			{
				if ((d.get_day() + i) > 31)
				{
					return Date(d.get_year(), Date::Month((d.get_month()) + 1), (d.get_day() + i) % 31);
				}
				else
				{
					return Date(d.get_year(), Date::Month((d.get_month() + 1) % 12), d.get_day() + i);
				}
			}
		}
	}
	return d;
}
//----------------------------------------------------------------------------------------------------

/*
	Function: nextWeekday();
	 
	This function calculates the Date of the 
	next weekday [Monday : Friday]
	of the passed parameter.
	
	Internally it calls dayOfWeek() and 
	based on its result increments the day
	till it becomes weekday.
*/
Date nextWeekday(const Date& day)
{
	Date d = day;

	// increment by one day
	d.add_day(1);
	Day currentday = dayOfWeekThirdVersion(d);
	Date::Month currentmonth = d.get_month();

	int i;
	// this loop incremenets the counter 'i' till
	// the modulo 7 of its sum with the current date is different than 0 or 6
	// i.e. not Saturday or Sunday 
	for (i = 0; i < 7; ++i)
	{
		if ((currentday + i) % 7 != 0 || (currentday + i) % 7 != 6)
		{
			// if month with 30 days
			if(isMonthWith30Days(currentmonth))
			{
				// increment month if added days are outside 30, days = remainder of (current days + i)/30  
				if ((d.get_day()+i) > 30) 
				{
					return Date(d.get_year(), Date::Month(d.get_month() + 1), (d.get_day() + i ) % 30);
				}
				else
				{
					return Date(d.get_year(), d.get_month(), d.get_day() + i);
				}
			} // if month with 31 days
	        else if(isMonthWith31Days(currentmonth))
			{
				// increment month if added days are outside 31, days = remainder of (current days + i)/31  
				if ((d.get_day() + i) > 31)
				{
					return Date(d.get_year(), Date::Month(d.get_month() + 1), (d.get_day() + i) % 31);
				}
				else 
				{
					return Date(d.get_year(), d.get_month(), d.get_day() + i);
				}
			} // if current month february, check for leap year 
			else if(currentmonth == 2)
			{
				if(leapYear(d.get_year()) && (d.get_day() + i) > 29)
				{
					return Date(d.get_year(), Date::Month(d.get_month() + 1), (d.get_day() + i) % 29);
				}
				else if(!leapYear(d.get_year()) && (d.get_day() + i) > 28)
				{
					return Date(d.get_year(), Date::Month(d.get_month() + 1), (d.get_day() + i) % 28);
				}
				else
				{
					return Date(d.get_year(), d.get_month(),d.get_day() + i);
				}
			} // if current month december, increment: year, month and day, if day is > 31
			else if(currentmonth == 12)
			{
				if ((d.get_day() + i) > 31)
				{
					return Date(d.get_year(), Date::Month(d.get_month() + 1), (d.get_day() + i) % 31);
				}
				else 
				{
					return Date(d.get_year(), Date::Month((d.get_month() + 1) % 12), d.get_day() + i);
				}
			}
		}
	}
	return d;
}

} // end namespace Chrono 


// ADDITIONAL ALGORITHMS related to Date calculations
//------------------------------------------------------------------------------------------------------------------------------

/* 
	Julian Calendar algorithms from
	"Jean Meeus - Astronomical Algorithms copyright date 1991."

	NB! There are a lot of magic numbers and single letter variables
	taken directly from the book above, there was no description there either.
*/
namespace Chrono
{

// Helper functions
/*
	Function: remquo();
	Use: double remainder = myremquo(double numer,
	                               double denom, 
								   int &quot)

	NB! quot must be initialized to zero before passed.

	This function divides the first argument
	by the second and returns the remaider as
	result and the quotient by reference to 
	the third argument.

	numer/denom = quotiend + remainder.
*/
double myremquo(double numer, double denom, double& quot)
{
	// integer division to get the quotient
	double temp = 0;

	// tests for next iteration 
	while((temp + denom) <= numer)
	{
		temp += denom;

		// quotient increments represent denom * quot
		++quot;
	}

	// return remainder
	return numer - temp;
}
//----------------------------------------------------------------------------------------------------

/*
	Function: toJulianDateFomat();
	 
	This function converts a date in the argunent
	into Julian Date format, i.e YYYY.MMDDdd 

	(year, month, day, time of day in decimal)

	Considering the Grigorian calendar correction
	i.e. : the following of 1582 Oct 4 is 1582 Oct 15.
*/
double toJulianDateFomat(const Date& d)
{
	double julYear = 0;
	double julMonth = 0;
	double julDay = 0;
	double tempJD = 0;
	int gregorianCorrectionTerm = 0;

	// checks if month is Jan, Feb or other
	if(d.get_month() > 2)
	{
		julYear = d.get_year();
		julMonth = d.get_month() / 100.0;
		julDay = d.get_day() / 10000.0;
	}
	else if (d.get_day() == 1 || d.get_day() == 2)
	{
		julYear = d.get_year() - 1;
		julMonth = (d.get_month() + 12) / 100.0;
		julDay = d.get_day() / 10000.0;
	}
	else
	{
		std::cerr <<"Not valid value for month!\n";
	}

	// check if year is negative, i.e BCE
	if (julYear > 0)
	{
		double tempJD = julYear + julMonth + julDay; // if year is negative, month day in abs value
	}
	else
	{
		double tempJD =  julYear - julMonth - julDay;
	}

	// checks if date in Julian (< 1582 Oct 15) or in Gregorian calendar
	double gregorianCalendarCorrectionYear = 1582.1015; // in JD format

	if (tempJD <= gregorianCalendarCorrectionYear)
	{
		if (tempJD >= 0)
		{
			// no correction needed, date in Julian calendar
			// date posivive
			double JD = floor(365.25 * julYear) + floor(30.6001 * (julMonth + 1)) + julDay + 1720994.5;
			return JD;
		}
		else 
		{
			// no correction needed, date in Julian calendar
			// date negative
			double JD = floor(365.25 * julYear - 0.75) + floor(30.6001 * (julMonth + 1)) + julDay + 1720994.5;
			return JD;
		}
	}
	else 
	{
		// correction added as date in Gregorian calendar
		gregorianCorrectionTerm  = int(2.0 - floor(julYear / 100.0) + floor(floor(julYear / 100.0) / 4.0));

		double JD = floor(365.25 * julYear)+ floor(30.6001 * (julMonth + 1)) + julDay + 1720994.5 + gregorianCorrectionTerm;

		return JD;
	}
}
//----------------------------------------------------------------------------------------------------

/*
	Function: toClassDateFormat();
	Use: Date date = toClassDateFormat(JulianDateFomat);

	Performs the reverse operation to
	toJulianDateFomat() function, i.e converts date 
	from (double JD= 2015.0328) to object Date(2015 March 28). 

	Assumes int paramters, no fractions for the hour.
*/
Date toClassDateFormat(double JD)	 
{
	double A = 0;
	double B = 0;
	double C = 0;
	double D = 0;
	double E = 0;
	double FractionalPart = 0;	// fractional part of JD
	double Z = 0;				// integral part of JD
	int alpha = 0;

	JD += 0.5;
	FractionalPart = modf(JD, &Z);

	if (Z < 2299161)
	{
		A = Z;
	}
	else 
	{
		alpha = (int) floor(Z - 1867216.25 / 36524.25);
		A = Z + 1 + alpha - floor(alpha / 4.0);
	}

	B = A + 1524;
	C = floor((B - 122.1) / 365.25);
	D = floor(365.25 * C);
	E = floor((B - D) / 30.6001);

	int day = int(B - D - floor(30.6001 * E) + FractionalPart); 
	int month = (int) floor((E < 13.5) ? (E - 1) :(E - 13));
	int year = int ((month > 2.5) ? (C - 4716) : (C - 4715));

	return Date(year, Date::Month(month), day);
}
//----------------------------------------------------------------------------------------------------

/*
	Function: numberOfDayInYear();
	 
	Converts the argument in Julian Calendar
	date representation and then calculates the number of
	the day [1,365(366 in leap)].
*/
int numberOfDayInYear(const Date & d)
{
	int month = d.get_month();
	int dayofmonth = d.get_day();
	int JD = (int) toJulianDateFomat(d);

	if(leapYear(d.get_year()))
	{
		return int(floor((275 * month) / 9.0) - floor((month + 9) / 12.0) + dayofmonth - 30);
	}
	else
	{
		return int(floor((275 * month) / 9.0) - 2 * floor((month + 9) / 12.0) + dayofmonth - 30);
	}
}
//----------------------------------------------------------------------------------------------------

/*
	Function: dayInMonth();
	 
	Performs the reverse operation
	of numberOfDayInYear(), i.e. converts a day 
	from range [1,356], to Date object. 

	The second argument specifies if the day 
	we convert is in leap or common year.
*/
Date dayImMonth(const double& numOfDayInY, int year)
{
	double A(0), B(0), C(0), E(0);
	 
	int month = 0;
	int day = 0;

	if(leapYear(year))
	{
		A = 1523;
	}
	else
	{
		A = 1889;
	}

	B = floor((numOfDayInY + A - 122.1) / 365.25);
	C = numOfDayInY + A - floor(365.25 * B);
	E = floor(C / 30.6001);

	month = int((E < 13.5) ? (E - 1) : (E - 13));
	day = int(C - floor(30.6001 * E));

	return Date(year, Date::Month(month), day);
}
//----------------------------------------------------------------------------------------------------

/*
	Funciton: dateOfEaster();
	 
	Calculates the month and the day of 
	the month on which Easter falls,
	depending on the argument.
	Result returned as Date object.
*/
Date dateOfEaster(int year)
{
	// remainder = fmod(nume, denom)
	// remainder = myremquo(nume, denom, quotient)

	double a = fmod(double(year), 19.0);
	double b(0);
	double c = myremquo(double(year), 100.0, b);
	double d = b / 4.0;
	double f = (b + 8) / 25.0;
	double g = (b - f + 1) / 3.0;
	double h = fmod(((19 * a) + b - d - g + 15), 30.0);
	double i(0);
	double k = myremquo(c, 4.0, i);
	double e(0);
	double l = fmod((32 + (2 * e) + (2 * i) - h - k), 7.0);
	double m = (a + (11 * h) + (22 * l)) / 451;
	double n(0);
	double p = myremquo((h + l - (7 * m) + 114), 31.0, n);
	
	int month = (int) floor(n);
	int day = int(floor(p) + 1);

	return Date(year, Date::Month(month), day);
}
//----------------------------------------------------------------------------------------------------

/*
	Funciton: dateOfEasterJulian();
	
	Calculates the month and the day of 
	the month on which Easter falls,
	depending on the argument (Julian Date Fomat)
	Result returned as Date object.
*/
Date dateOfEasterJulian(double JD)
{
	// remainder = fmod(nume, denom)
	// remainder = myremquo(nume, denom, quotient)

	double a = fmod(JD, 4.0);
	double b = fmod(JD, 7.0);
	double c = fmod(JD, 19.0);
	double d = fmod(((19 * c) + 15), 30.0);
	double e = fmod(((2 * a) + (4 * b) - d + 34), 7.0);
	double f(0);
	double g = myremquo((d + e + 114), 31.0, f);

	int year = (int) floor(JD);
	int month = (int) floor(f);
	int day = int (floor(g) + 1);

	return Date(year, Date::Month(month), day);
}

}  // end of namesapce Chrono

#endif