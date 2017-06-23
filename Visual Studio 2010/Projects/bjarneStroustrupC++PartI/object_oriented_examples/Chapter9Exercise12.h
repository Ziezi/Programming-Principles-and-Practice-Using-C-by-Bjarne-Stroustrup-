/*
	TITLE			   Number of days after (1970, Jan, 1) 	Chapter9Exercise12.h
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: 
				
				Functions:
					daysFrom0Date()
					myUnixTime()

				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 30.03.2015
*/

#ifndef CHAPTER9EXERCISE12_H
#define CHAPTER9EXERCISE12_H

namespace Chrono
{

/*
	Function: daysFrom0Date();
	 
	This function calcuales the number of
	days passed from 1970 Jan 1, 
	till the date in the argument.
*/
long daysFrom0Date(const Date& d)
{
	// check if in allowed range
	Date dateZero = Date(1970, Date::Month::jan, 1);

	if (d < dateZero)
	{
		throw Date::Invalid();
	}

	// holds total days passed from zero days till date in argument
	long totaldays = 0;
	int daysofeachyear = 0;

	for (int i = dateZero.get_year(); i < d.get_year(); ++i)
	{
		if (leapYear(i)) 
		{
			daysofeachyear = 366;
		}
		else
		{
			daysofeachyear = 365;
		}

		totaldays += daysofeachyear;
	}
	
	// dayNumberInYear(): determines the number of the day in the year
	return totaldays + dayNumberInYear(d);
}
//-----------------------------------------------------------------------------------------

/*
	Function: myUnixTime()
	 
	This function calculates the 
	time ellapsed from the "0 Date"
	till the date in the argument.
	in seconds.
*/
long myUnixTime(const Date& d)
{
	long days = daysFrom0Date(d);

	int secondsInDay = 86400;

	return days * secondsInDay;
}

} // end of namesapce Chrono

#endif