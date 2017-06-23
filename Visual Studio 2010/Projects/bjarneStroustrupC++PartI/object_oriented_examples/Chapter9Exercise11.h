/*
	TITLE			   Expand class Date		  Chapter9Exercise11.h
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective:  

				Functions:				Helper Functions:

				next_workday()			initializeBulgarianHolidays()
				week_of_year()			isBankHolidaysinBulgaria()
				dayNumberInYear()
										initializeGreekHolidays()
										isBankHolidaysinGreece()

										initializeBriatainHolidays()
										isBankHolidaysinBriatain()

										initializeUSHolidays()
										isBankHolidaysinUS()
				
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 19.03.2015
*/
#ifndef CHAPTER9EXERCISE11_H
#define CHAPTER9EXERCISE11_H

namespace Chrono
{

// Helper function declaration
bool isBankHolidaysinBulgaria(const Date& d);

bool isBankHolidaysinGreece(const Date& d);

bool isBankHolidaysinBriatain(const Date& d);

bool isBankHolidaysinUS(const Date& d);

int dayNumberInYear(const Date& d);

//------------------------------------------------------------------------------------------------------

/*
	Function: next_workday()
	Use: Date nextworkday = next_workday(cont Date& d)

	This function returns the next workday based on the
	date in the argument.

	Internally it calls nextWeekday function, checks if
	next day is holiday, if not it returns it. If next
	week day is holiday, it calls itself with argument
	the next week day.
*/
Date next_workday(const Date& d)
{
	// get next week day 
	Date nextWorkday = nextWeekday(d);

	while(isBankHolidaysinBulgaria(nextWorkday))
	{
		Date date = nextWeekday(nextWorkday);
		nextWorkday = date;
	}

	return nextWorkday;
}
//------------------------------------------------------------------------------------------------------

/*
	Function: week_of_year()

	This function calculates the consequtive week
	number of the date passed as argument.

	Internally calculates what day is January the 1st
	of the same year and loops from it till the 
	number of the day in the date, counting how many
	times their sum's modulo7 is zero, 
	counting it as a weeks .
*/
int week_of_year(const Date& d)
{
	// calculate what day was January the 1st of the same year
	Date temp(d.get_year(), Date::Month::jan, 1);

	int januaryTheFirst = dayOfWeekThirdVersion(temp);
	int dayNumber = dayNumberInYear(d);

	int numberOfWeeks = 1;
	for (int i = januaryTheFirst; i <= dayNumber; ++i)
	{	
		if(i % 7 == 0)
		{ 
			++numberOfWeeks;
		}
	}

	return numberOfWeeks;
}
//------------------------------------------------------------------------------------------------------

// Helper functions implementation
/*
	Function: dayNumberinYear();
	Use: int numofday = dayNumberinYear(const Date& d);

	This function calculates the consequtive 
	day number of the date in the argument. 
*/
int dayNumberInYear(const Date& d)
{
	// holds number of the day in year 
	int numberOfDayInYear = 0;

	// initialized to number of days in specific month
	int daysPerMonth = 0;
	for (int i = 1; i < d.get_month(); i++)
	{
		if (i == 2 && leapYear(d.get_year()))
		{
			daysPerMonth = 29;
		}
		else if (i == 2 && !leapYear(d.get_year())) 
		{
			daysPerMonth = 28;
		}
		else if (isMonthWith30Days(Date::Month(i)))
		{
			daysPerMonth = 30;
		}
		else if (isMonthWith31Days(Date::Month(i)))
		{
			daysPerMonth = 31;
		}

		numberOfDayInYear += daysPerMonth;
	}

	// the total sum is all the previous months plus the date of the current month
	return (numberOfDayInYear + d.get_day());
}
//------------------------------------------------------------------------------------------------------

/*
	Function: initializeBulgarianHolidays(std::vector<Date>& bankHolidays, const Date& d);

*/
static void initializeBulgarianHolidays(std::vector<Date>& bankHolidays, const Date& d)
{
	// Christmas Eve
	bankHolidays.push_back(Date(0, Date::Month::dec, 24));

	// Christmas Days
	bankHolidays.push_back(Date(0, Date::Month::dec, 25));
	bankHolidays.push_back(Date(0, Date::Month::dec, 26));

	// New Year's Day
	bankHolidays.push_back(Date(0, Date::Month::jan, 1));

	// Bulgaria's Liberation from the Ottoman Empire.
	bankHolidays.push_back(Date(0, Date::Month::mar,3));

	// Easter according to the Orthodox calendar of the year
	Date easterdate = dateOfEaster(d.get_year());

	// Good Friday
	// error-prone; if first days of months
	bankHolidays.push_back(Date(0, easterdate.get_month(), easterdate.get_day() - 2));

	// Holy Saturday
	bankHolidays.push_back(Date(0, easterdate.get_month(), easterdate.get_day() - 1));

	// Easter Sunday
	bankHolidays.push_back(Date(0, easterdate.get_month(), easterdate.get_day()));

	// Easter Monday
	easterdate.add_day(1);
	bankHolidays.push_back(Date(0, easterdate.get_month(), easterdate.get_day()));

	// Labour and International Worker's Solidarity Day.
	bankHolidays.push_back(Date(0, Date::Month::may, 1));

	// Gergyovden St. George's Day and the Bulgarian Army's Day.
	bankHolidays.push_back(Date(0, Date::Month::may, 6));

	// Bulgarian Education and Culture, and Slavic Script Day.
	bankHolidays.push_back(Date(0, Date::Month::may, 24));

	// Unification Day.
	bankHolidays.push_back(Date(0, Date::Month::sep, 6));

	// Independence Day.
	bankHolidays.push_back(Date(0, Date::Month::sep, 22));

	// Day of the Bulgarian Enlighteners (Holiday for all educational institutions)
	bankHolidays.push_back(Date(0, Date::Month::nov, 1));
}
//------------------------------------------------------------------------------------------------------

/*
	Function: isBankHolidaysinBulgaria();
	Use: isBankHolidaysinBulgaria(Date)

	This function compares the argument
	to existing data base of Dates and 
	if there is a match, i.e. the date
	is Bank Holiday in Bulgaria, 
	it returns true.
*/
bool isBankHolidaysinBulgaria(const Date& d)
{
	std::vector<Date> bankHolidays;

	initializeBulgarianHolidays(bankHolidays, d);
	// Stable dates: month and day always the same
	// only months and days are significant

	for (unsigned int i = 0; i < bankHolidays.size(); ++i)
	{
		if (d.get_month() == bankHolidays[i].get_month() && d.get_day() == bankHolidays[i].get_day())
		{
			return true;
		}
	}
	return false;
}
//------------------------------------------------------------------------------------------------------

/*
	Function: initializeGreekHolidays(std::vector<Date>& bankHolidays, const Date& d);

*/
static void initializeGreekHolidays(std::vector<Date>& bankHolidays, const Date& d)
{
	// Christianity related
	// Christmas
	bankHolidays.push_back(Date(0, Date::Month::dec, 25));

	// Glorifying Mother of God
	bankHolidays.push_back(Date(0, Date::Month::dec, 26));

	// First day of New Year 
	bankHolidays.push_back(Date(0, Date::Month::jan, 1));

	// Theopháneia
	bankHolidays.push_back(Date(0, Date::Month::jan, 6));

	// Kathará Deutéra (48 days before Easter)
	bankHolidays.push_back(Date(0, Date::Month::feb, 5));

	// Independence Day
	bankHolidays.push_back(Date(0, Date::Month::mar, 25));

	// Easter according to the Orthodox calendar of the year
	Date easterdate = dateOfEaster(d.get_year());

	// Good Friday
	// error-prone; if first days of months
	bankHolidays.push_back(Date(0, easterdate.get_month(), easterdate.get_day() - 2));

	// Holy Saturday
	bankHolidays.push_back(Date(0, easterdate.get_month(), easterdate.get_day() - 1));

	// Easter Sunday
	bankHolidays.push_back(Date(0, easterdate.get_month(), easterdate.get_day()));

	// Easter Monday
	easterdate.add_day(1);
	bankHolidays.push_back(Date(0, easterdate.get_month(), easterdate.get_day()));

	// Labour and International Worker's Solidarity Day.
	bankHolidays.push_back(Date(0, Date::Month::may, 1));

	// Pentikostí (49 days after Easter)
	bankHolidays.push_back(Date(0, Date::Month::may, 31));
	bankHolidays.push_back(Date(0, Date::Month::jun, 1));

	// Koímisi tis Theotókou
	bankHolidays.push_back(Date(0, Date::Month::aug, 15));

	// Oxi Day
	bankHolidays.push_back(Date(0, Date::Month::oct, 28));
}
//------------------------------------------------------------------------------------------------------

/*
	Function: isBankHolidaysinBulgaria();
	Use: isBankHolidaysinBulgaria(Date);

	This function compares the argument
	to existing data base of Dates and 
	if there is a match, i.e. the date
	is Bank Holiday in Greece, 
	it returns true.
*/
bool isBankHolidaysinGreece(const Date& d)
{
	std::vector<Date> bankHolidays;
	// Stable dates: month and day always the same
	// only months and days are significant
	initializeGreekHolidays(bankHolidays, d);

	for (unsigned int i = 0; i < bankHolidays.size(); ++i) 
	{
		if (d.get_month() == bankHolidays[i].get_month() && d.get_day() == bankHolidays[i].get_day())
		{
			return true;
		}
	}

	return false;
}
//------------------------------------------------------------------------------------------------------

/*
	Function: initializeBritainHolidays(std::vector<Date>& bankHolidays, const Date& d);

*/
static void initializeBritainHolidays(std::vector<Date>& bankHolidays, const Date& d)
{
	// New Year's Day
	bankHolidays.push_back(Date(0, Date::Month::jan, 1));

	// Christmas day
	bankHolidays.push_back(Date(0, Date::Month::dec, 25));

	// Boxing day
	bankHolidays.push_back(Date(0, Date::Month::dec, 26));

	// Early May bank holiday
	bankHolidays.push_back(Date(0, Date::Month::may, 2));

	// Spring bank holiday
	bankHolidays.push_back(Date(0, Date::Month::may, 30));

	// Summer bank holiday
	bankHolidays.push_back(Date(0, Date::Month::aug, 29));
}
//------------------------------------------------------------------------------------------------------

/*
	Function: isBankHolidaysinBulgaria();
	Use: isBankHolidaysinBulgaria(Date);

	This function compares the argument
	to existing data base of Dates and 
	if there is a match, i.e. the date
	is Bank Holiday in Britain, 
	it returns true.
*/
bool isBankHolidaysinBriatain(const Date& d)
{
	std::vector<Date> bankHolidays;
	// Stable dates: month and day always the same
	// only months and days are significant
	initializeBritainHolidays(bankHolidays, d);

	for (unsigned int i = 0; i < bankHolidays.size(); ++i)
	{
		if (d.get_month() == bankHolidays[i].get_month() && d.get_day() == bankHolidays[i].get_day())
		{
			return true;
		}
	}

	return false;
}
//------------------------------------------------------------------------------------------------------

/*
	Function: initializeUSHolidays (std::vector<Date>& bankHolidays, const Date& d);

*/
static void initializeUSHolidays (std::vector<Date>& bankHolidays, const Date& d)
{
	// First New Year's Day
	bankHolidays.push_back(Date(0, Date::Month::jan, 1));

	// Martin Luther King, Jr. Day
	bankHolidays.push_back(Date(0, Date::Month::jan, 19));

   // George Washington’s Birthday
	bankHolidays.push_back(Date(0, Date::Month::feb, 16));

	// Memorial Day
	bankHolidays.push_back(Date(0, Date::Month::may, 25));

	// Independence Day
	bankHolidays.push_back(Date(0, Date::Month::jul, 3));

	// Labor Day
	bankHolidays.push_back(Date(0, Date::Month::sep, 7));

	// Columbus Day
	bankHolidays.push_back(Date(0, Date::Month::oct, 12));

	// Veterans Day
	bankHolidays.push_back(Date(0, Date::Month::nov, 11));

	// Thanksgiving Day
	bankHolidays.push_back(Date(0, Date::Month::nov, 26));

	// Christmas Day
	bankHolidays.push_back(Date(0, Date::Month::dec, 25));
}

//------------------------------------------------------------------------------------------------------

/*
	Function: isBankHolidaysinBulgaria();

	This function compares the argument
	to existing data base of Dates and 
	if there is a match, i.e. the date
	is Bank Holiday in the US, 
	it returns true.
*/
bool isBankHolidaysinUS(const Date& d)
{
	std::vector<Date> bankHolidays;
	// Stable dates: month and day always the same
	// only months and days are significant
	initializeUSHolidays(bankHolidays, d);

	for (unsigned int i = 0; i < bankHolidays.size(); ++i)
	{
		if (d.get_month() == bankHolidays[i].get_month() && d.get_day() == bankHolidays[i].get_day())
		{
			return true;
		}
	}
	return false;
}

} // namespace Chrono

#endif