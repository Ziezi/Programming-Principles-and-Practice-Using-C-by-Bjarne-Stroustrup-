/*
	TITLE		   Input manipulators			 Chapter11TryThis2.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Input & Output data in:
				   decimal, hexadecimal and octal format.
			Input: 1234 4d2 2322 2322        //		1234 1234 1234 1234     
		    Ouput: 1234 1234 1234 1234       //     1234    4660    668     668   // the last three values are interpreted as hex , oct ,oct
				
		   Author: Chris B. Kirov
		     Data: 19.05.2015
*/
#include <iostream>
#include <iomanip>

int main()
{
	std::cout << "Type four integers separated by white space.\n";

	int a = 0, b = 0, c = 0, d = 0;

	// to read and interpred integers with different bases correctly by their prefix unset the default settings
	// std::cin.unsetf(std::ios::dec); // don't assume decimal
	// std::cin.unsetf(std::ios::oct); // don't assume octal
	// std::cin.unsetf(std::ios::hex); // don't assume hexadecimal

	std::cin >> a >> std::hex >> b >> std::oct >> c >> d;

	std::cout << std::showbase << a <<'\t'<< b <<'\t'<< c <<'\t'<< d << std::endl;
}