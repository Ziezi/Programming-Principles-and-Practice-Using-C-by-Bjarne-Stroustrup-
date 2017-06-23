/*
	TITLE	           Test Class Date				Chapter9Drill1.h
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
	Struct: Date 
	
	Represents astronomical 
	date consisted of:
	year, month and day.
*/
struct Date
{
	int y;
	int m;
	int d;
};
//--------------------------------------------------------------

// Helper fucntions

/*
	Function: is_leapyear();
	Use: bool leap = is_leapyear(date);

	Returns true is the date is a
	a leap year;
*/
bool is_leapyear(Date& dd)
{
	int year = dd.y;

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
	Function: init_day();
	Use: init_day(date, 2015, 3, 11);

	It initializes the date object passed
	as first parameter to the values passed
    via the rest of the parameters. 

	Checks initialization value validity.
*/
void init_day(Date& dd, int y, int m, int d)
{
	if (y < 0)
	{
		std::cerr <<"not valid value for year!\n";
	}
	if (m < 1 || m > 12)
	{
		std::cerr <<"not valid value for month!\n";
	}
	if (d < 1 || d > 31) 
	{
		std::cerr <<"not valid value for day!\n";
	}

	dd.y = y;
	dd.m = m;
	dd.d = d;
}
//--------------------------------------------------------------

/*
	Function: add_day();
	Use: add_day(date, 4);

	It increments the date of the object 
	passed as first parameter by the 
	amount of days passed via the second.

	Checks for leap year; wraps up the days
	of months, without incrementing month.
*/
void add_day(Date& dd, int n)
{
	if (n < 0 || n > 31) 
	{
		std::cerr << "add_day(): Invalid argument!\n";
	}	

	switch(dd.m)
	{
		case 2:
		{
			if(dd.d == 28) 
			{ 
				dd.d = (is_leapyear(dd)) ? 29 : 1;
			}
			else
			{
				++dd.d;
			}
			break;
		}
		case 4: case 6: case 9: case 11:
		{
			dd.d = (dd.d == 30) ? 1: ++dd.d;
			break;
		}
		default:
		{
			dd.d = (dd.d == 31) ? 1: ++dd.d;
			break;
		}
	}
}




