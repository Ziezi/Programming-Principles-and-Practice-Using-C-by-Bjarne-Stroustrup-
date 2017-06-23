/*
	TITLE		   Output manipulators		     Chapter11TryThis.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Output date of birth and age in:
				   decimal, hexadecimal and octal.
			Input: -
		    Ouput: -
		   Author: Chris B. Kirov
		     Data: 19.05.2015
*/
#include <iostream>
#include <iomanip>

int main()
{
	int date_of_birth = 1985;
	int current_age = 30;

	// save std::cout initial format 
	std::ios initial(NULL);
	initial.copyfmt(std::cout);

	std::cout <<"Birth Year:\n "<< date_of_birth <<'\t'<< std::hex << date_of_birth <<'\t'<< std::oct << date_of_birth <<'\n'; 

	// restore initial format of std::cout
	std::cout.copyfmt(initial);

	std::cout <<"Age:\n "<< std::showbase << current_age <<'\t'<< std::hex << current_age <<'\t'<< std::oct << current_age <<'\n';
}