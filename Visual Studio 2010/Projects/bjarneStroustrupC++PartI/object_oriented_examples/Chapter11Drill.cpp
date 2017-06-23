/*
	TITLE	       I/O manipulators and streams    Chapter11Drill.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: 1. Declare an integer and assign your age to it.
				   2. Output age in decimal, hexadecimal and octal.
				   3. Label the base being printed.
				   4. Tab-separate all the values.
				   5. -
				   6. -
				   7. Show bases of representation.
				   8. Read decimal, octal, hexadecimal etc.:
				   9. Floating point numbers manipulators.
				   10. Done in Try This.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
		     Data: 30.06.2015
*/
#include <iostream>
#include <iomanip>
/*
	Function: ios_base& general(ios_base& b);
	 
	It clears all floating-piont format flags
	back to default.
*/
std::ios_base& general(std::ios_base& b)
{
	b.setf(std::ios_base::fmtflags(0), std::ios_base::floatfield);
	return b;
}

//=============================================================================================================
int main()
{
	// 1.
	int birth_year = 30;

	// 2. & 3. & 7.
	std::cout << std::showbase <<"decimal: "<< birth_year <<'\t'
			  <<"hexadecimal: "<< std::hex << birth_year <<'\t'
			  <<"octal: "<< std::oct << birth_year << std::endl;

	// 4. & 5.
	int current_age = 30;
	std::cout << general << current_age << std::endl;

	// 8.
	std::cout << "Type decimal, octal and hexadecimal-base integer, separated by whitespace.\n>>";
	int deci = 0, octa = 0, hexa = 0;
	 
	// unset default integer base interpretation, i.e. prefix determines base system
	std::cin.unsetf(std::ios_base::dec | std::ios_base::oct | std::ios_base::hex);
	std::cin >> deci >> octa >> hexa;

	// Comment: all values are printed in octal base as it's persistent from line 44
	std::cout <<"decimal: "<< deci << '\t'
		      <<"octal: "<< octa << '\t'
		      <<"hexadecimal: "<< hexa << '\n';

	// 9.
	double number = 1234567.89;
	
	std::cout <<"general: "<< general << number <<'\t'
		      <<"fixed: "<< std::fixed << number <<'\t' 
	          <<"scientific: "<< std::scientific << number <<'\n';
	// Comment: most accurate representation in in the fixed notation as there are 6 digits after the decimal point printed
}


