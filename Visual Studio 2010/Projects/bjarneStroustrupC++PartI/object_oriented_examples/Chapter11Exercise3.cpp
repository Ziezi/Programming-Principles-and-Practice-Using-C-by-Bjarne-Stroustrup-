/*
	TITLE		   I/O integers in different bases Chapter11Exercise3.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Reads input using decimal, octal or hexadecimal preffixes,
				   prints them in their original form and in decimal in a table.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
		     Date: 30.06.2015
*/
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

const std::string& baseid(const std::string& str);

//=============================================================================================
int main()
{
	try
	{
		// unset default flags so that prefixes are considered
		std::cin.unsetf(std::ios::dec | std::ios::oct | std::ios::hex);

		std::cout <<"How many integers you want to type?\n";
		int counter = 0;
		std::cin >> counter;

		// collect integers
		std::vector<std::string> numbers;
		for (int i = 0; i < counter; ++i)
		{
			std::cout <<"Type an integer with base prefix (i.e. 0, 0x)\n>>";
			std::string input;
			std::cin >> input;

			numbers.push_back(input);
		}

		// print base and convert to decimal
		for (size_t i = 0; i < numbers.size(); ++i)
		{
			std::stringstream ss(numbers[i]);
			ss.unsetf(std::ios::dec | std::ios::oct | std::ios::hex);

			int number;
			ss >> number;

			std::cout << std::setw(5) << std::left << numbers[i] <<" "
				      << std::setw(11) << baseid(numbers[i]) 
					  <<" converts to " 
					  << std::setw(5) << std::left << std::dec << number <<" decimal\n"; 
		}
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

//=============================================================================================

/*
	Funtion: baseid()

	It returns a string holding the integer
	base representation.
*/
const std::string& baseid(const std::string& str)
{
    static const std::string bases[] = { "decimal", "octal", "hexadecimal" };

    enum baseid { DEC, OCT, HEX };

    if ((str.length() < 2) || (str[0] != '0'))
	{
        return bases[DEC];
	}

    return str[1] == 'x' ? bases[HEX] : bases[OCT];
}