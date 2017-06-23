/*
	TITLE			    Unix / POSIX / Epoch time   Chapter9Exercise12.cpp
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Change the representation of a Date
					   to be the number of days since
					   January 1st, 1970 (known as day 0),
					   represented as a long, and reimplement
					   the functions from §9.8.
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 30.03.2015
*/
#include <iostream>
#include <string>
#include <vector>

#include "Chapter9ClassDate.h"     
#include "Chapter9Exercise11.h"    
#include "Chapter9Exercise12.h"

void test_function();

//==========================================================================
int main()
{
	try
	{
		test_function();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
//==========================================================================

/*
	Function: test_function()

	It tests Class Date 
	related members.
*/
void test_function()
{
	// testing class Date methods

	// isMonthWith30Days();
	Chrono::Date testdate = Chrono::Date(2015, Chrono::Date::Month::mar,11); 

	if (isMonthWith30Days(testdate.get_month()))
	{
		std::cout << "Month is with 30 days.\n";
	}
	else 
	{
		std::cout << "Month is NOT with 30 days.\n";
	}

	// isMonthWith31Days() 
	if (isMonthWith31Days(testdate.get_month()))
	{
		std::cout << "Month is with 31 days.\n";
	}
	else 
	{
		std::cout << "Month is NOT with 31 days.\n";
	}

	// leapYear()
	if (Chrono::leapYear(testdate.get_year()))
	{
		std::cout << "The year is leap.\n";
	}
	else
	{
		std::cout << "The year is NOT leap.\n";
	}

	// isDate()
	if (isDate(testdate.get_year(), testdate.get_month(), testdate.get_day())) 
	{
		std::cout << "The date is valid.\n";
	}
	else 
	{
		std::cout << "The date is NOT valid.\n";
	}

	// operator==()
	Chrono::Date d2(2000, Chrono::Date::Month::jan, 1);
	if(d2 == testdate) 
	{
		std::cout << "\nDates are equivalent.\n";
	}
	else
	{
		std::cout << "\nDates are NOT equivalent.\n";
	}

	// operator!=()
	if(d2 != testdate)
	{
		std::cout << "\nDates are equivalent.\n";
	}
	else
	{
		std::cout << "\nDates are NOT inequivalent.\n";
	}

	// operator<<()
	std::cout << "\nDate: "<< testdate << std::endl;

	// operator>>()
	std::cout << "\nPlease enter a date by typing: (Year,Month[1-12],Day).\n>>";
	Chrono::Date dIN;
	std::cin >> dIN;
	std::cout << "You have typed: "<< dIN <<'\n';

	// add_year()
	dIN.add_year(1);
	std::cout << "\nYour typed year incremented by 1 is: "<< dIN <<'\n';

	// add_month()
	std::cout << "\nDate's month to be incremented: " << testdate <<'\n';
	testdate.add_month(1);
	std::cout << "\nYour typed year's month has been incremented by 1 is: "<< testdate <<'\n';

	// add_day()
	std::cout << "\nDay to be incremented: " << testdate <<'\n';
	testdate.add_day(1);
	std::cout << "\nDay has bee incremented by 1 is: "<< testdate <<'\n';

	// dayOfWeekThird(); dayToString();
	Chrono::Date dayofw = Chrono::Date(2015,Chrono::Date::Month::mar,30);
	Chrono::Day currentday = dayOfWeekThirdVersion(dayofw);
	std::cout << "\nDate: " << dayofw << "is: "<< dayToString(currentday) <<'\n';
	
	// nextSunday()
	Chrono::Date t2 = Chrono::nextSunday(Chrono::Date(2015,Chrono::Date::Month::mar,30));
	Chrono::Date nextsunday = nextSunday(t2);
	std::cout << "Next Sunday is: " << nextsunday <<'\n';

	// nextWeekday()
	Chrono::Date nextweekday = nextWeekday(t2);
	std::cout << "Next week day is: " << nextweekday <<'\n';

	// next_workday() exercise 11
	Chrono::Date d = Chrono::Date(2015,Chrono::Date::Month::dec,25);
	Chrono::Date nextwd = Chrono::next_workday(d);
	std::cout << "Next work day is: " <<  nextwd <<'\n';

	// week_of_year(); dayNumberInYear() 
	Chrono::Date t3 = Chrono::Date(2015,Chrono::Date::Month::jul,1);
	int weekofy = Chrono::week_of_year(t3);
	std::cout << "\nDate: " << t3 << ", is: " << dayNumberInYear(t3) << " consecutive day in the year.\n";
	std::cout << "Is in the: "<<  weekofy <<" week of the year.\n";

	// daysFrom0Date() exercise 12
	Chrono::Date t4= Chrono::Date(2015, Chrono::Date::Month::jan, 1);
	long daysfrom0date = Chrono::daysFrom0Date(t4);
	std::cout << "\nDate: " << t4 << " is: " << daysfrom0date << " from 0 date.\n";

	// myUnixTime()
	long secondfrom0d = myUnixTime(t4);
	std::cout <<"\nUnix time of date: "<< t4 << " is: " <<  secondfrom0d <<'\n'; 
}