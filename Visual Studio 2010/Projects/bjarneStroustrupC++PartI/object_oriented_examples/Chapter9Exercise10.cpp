/*
	TITLE			   Function leap year	       Chapter9Exercise10.cpp
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Create a function 
					   that discerns leap from odrinary year.
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 19.03.2015
*/
#include <iostream>

bool leapyear(int year);

//========================================================================
int main()
{
	// int thisYear = 2016; // it is a leap year
	int thisYear = 2015; // not a leap year 

	std::cout << thisYear <<" is";
	if (!leapyear(thisYear))
	{
		std::cout <<" not";
	}
	std::cout <<" a leap year.\n";
}
//========================================================================

/*
	Function: leapyear(int year);

	It returns true if the year 
	passed via the parameter is 
	a leap year.

	Assumes valid year. 
*/
bool leapyear(int year)
{
	if(year % 4 != 0) 
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
	else
	{
		return true;
	}
}