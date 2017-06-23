/*
	TITLE			   Expand class Date				 Chapter9Exercise11.h
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Create a function for class Date:
					   next_workday();
					   week_of_year();

					   Check result:
					   http://www.epochconverter.com/weeks/2016
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 19.03.2015
*/
#include <iostream>
#include <vector>
#include "Chapter9ClassDate.h"
#include "Chapter9Exercise11.h"

//=================================================================================
int main()
{
	Chrono::Date today(2016, Chrono::Date::mar, 29);

	std::cout <<"Next work day: "<< next_workday(today) <<'\n';
	std::cout <<"This week is the: "<< week_of_year(today) <<"th of the year\n";
}
//=================================================================================