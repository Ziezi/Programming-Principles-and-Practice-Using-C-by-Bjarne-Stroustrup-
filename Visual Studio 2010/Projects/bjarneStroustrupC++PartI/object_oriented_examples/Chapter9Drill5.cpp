/*
	TITLE	           Test Class Date				Chapter9Drill5.cpp
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
#include <iostream>
#include "Chapter9Drill5.h"	

int main()
{
	try
	{
		Date today(1978, Date::jun, 25);

		Date tomorrow = today;
		tomorrow.add_day(1);

		std::cout << "Today: " << today.year() << ", " << today.month() << ", " << today.day() << std::endl;
		std::cout << "Tomorrow: " << tomorrow.year() << ", " << tomorrow.month() << ", " << tomorrow.day() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}