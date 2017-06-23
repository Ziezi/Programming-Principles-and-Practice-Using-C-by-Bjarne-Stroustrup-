/* 
   TITLE               Correct errors           Chapter5Exercise2.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 			Objective: Remove and improve the code.
 				Input: Prompt message.
 			   Output: Conversion result.
			   Author: Chris B. Kirov
		         Data: 1.2.2015
*/
#include <iostream>

void celsiusToKelvin(void);
void prompt(void);
void calculate(void);

//===================================================================================================
// Execution Segment
int main()
{
	calculate();
	return 0;
}

//===================================================================================================
// Definition Segment
/*
	Function: void celsiusToKelvin(void)
	Use: celsiusToKelvin();

	Converts temperature from Celsius to Kelvin;
	Checks if input greater than absolute zero
*/ 
void celsiusToKelvin(void)
{
	const double absZeroCels = 273.15;
	double c = -500;

	std::cout <<"\nEnter the temperature (in Celsius): ";
	std::cin >> c;
	 
	// conversion
	double k = c - absZeroCels;

	// print result
	std::cout <<"\nThe temperature in Kelvin is: " << k << "[K]" << std::endl;
}

//--------------------------------------------------------------------------------------------------
/*
	Function: prompt()
	Use: prompt();

	It displays information 
	about the program and
	prompts the used for input.
*/
void prompt(void)
{
	std::cout  << "Convert temperature units of measurement." << std::endl;
	std::cout << " Type '1' for Celsius to Kelvin " << std::endl;
	std::cout << " Type '2' for Kelvin to Celsius " << std::endl;
	std::cout << " Type 'q' to exit. "	<< std::endl;
	std::cout << ">> ";
}

//--------------------------------------------------------------------------------------------------
/*
	Function: calculate()
	Use: calculate();
	
	Runs an input loop ajd
	calls the conversion programs.
*/
void calculate(void)
{
	const char quit = 'q'; 
	const char toKelvin = '1';

	while(true)
	{
		try{
				char select = 0;
				while (select == 0)
				{
					prompt();

					std::cin >> select;
					if (select == quit)
					{
						return;
					}
				}
				
				if (select == toKelvin)			 
				{
					celsiusToKelvin();
				}
				else
				{
					std::cerr <<"Supported commands 1, 2 or q!";
				}
			}
			catch(std::exception& e)
			{
				std::cerr << e.what() << std::endl;
				std::cin.ignore();
				getchar();
			}
			catch(...)
			{
				std::cerr << "unknown exception" << std::endl; 
				std::cin.ignore();
				getchar();
			}
	}
}