/*
	TITLE	           Test Class Date				Chapter9Drill1.cpp
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
#include "Chapter9Drill1.h"

int main()
{
	try
	{
		Date today;
		init_day(today, 2016, 3, 28);  
		std::cout <<"Today: "<< today.y <<", "<< today.m <<", "<< today.d << std::endl;

		Date tomorrow = today;
		int incrementBy = 1;
		add_day(tomorrow, incrementBy);

		std::cout <<"Tomorrow: "<< tomorrow.y <<", "<< tomorrow.m <<", "<< tomorrow.d << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
 }