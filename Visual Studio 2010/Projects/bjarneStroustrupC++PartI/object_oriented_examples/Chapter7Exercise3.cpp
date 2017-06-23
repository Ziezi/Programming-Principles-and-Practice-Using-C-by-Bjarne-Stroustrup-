/*
	TITLE			   Constant variables        Chapter7Exercise3.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Provide constant variables declarations/ definitions
					   using specific identifier; they can't be reassigned.

					   Define a constant variable by using the following syntax:

					   # const variable_name = value 
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 24.02.2015
*/
#include <iostream>
#include <string>
#include <vector>
#include "Chapter7Exercise3.h" 

int main()
{
	std::cout << "\t\tWelcome to our calculator!" << std::endl;
	calculate();
	return 0;
}