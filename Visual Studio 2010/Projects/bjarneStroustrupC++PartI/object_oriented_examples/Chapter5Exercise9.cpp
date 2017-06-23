 /* 
     TITLE	        Temperature conversion        Chapter5Exercise9.cpp
	 Bjarne Stroustrup "Programming: Principles and Practice Using C++"
     COMMENT
	     Objective: Write out an error is the result cannot be 
					represented as int.
			 Input: Select conversion, 
		            enter the selected units of measurement.
		    Output: Print the converted value.
			Author: Chris B. Kirov
			  Date: 23. 02. 2015
*/
#include <iostream>

void prompt();
void calculate();
double ftoc(double faren);
double ctof(double celsius);
bool isInteger(double);

//=====================================================================================

int main()
{
	calculate();
}
//=====================================================================================

/*
	Function: prompt()
	Use: prompt();
	It gives information about
	the program and prompts the
	user to type input.
*/
void prompt()
{
	std::cout << "\nConvert temperature units of measurement; 'q' to exit.\n";
	std::cout << "1.Fahrenheit to Celsius.\n";
	std::cout << "2.Celsius to Fahrenheit.\n";
	std::cout << "Select conversion (1 or 2): ";
}

//----------------------------------------------------------------------------------
/*
	Function: calculate()
	Use: calculate();
	It runs an input loop,
	error handling and 
	convertion function calling.
*/
void calculate()
{
	const double abs_zero_farenh = -459.67;
	const double abs_zero_celsiu = -273.15;

	const char toCelsius = '1';
	const char toKelvin = '2';
	const char exitProgram = 'q';

	while(true) 
	{
		try 
		{
			// prompt message
			char selection = '0';
			prompt();
			std::cin >> selection;

			// selection block
			if (selection == exitProgram)
			{
				return;
			}
			else if (selection == toCelsius)
			{
				std::cout << "Type temperature value (in Fahrenheit): ";
				double far = 0;
				std::cin >> far;
	
				// pre-condition: input check
				if (far < abs_zero_farenh)
				{
					throw std::runtime_error("Third law of thermodynamics violated!\n");
				}

				// conversion function call
				double cels = ftoc(far);
		
				// post-condition: result check
				if (cels < abs_zero_celsiu)
				{
					throw std::runtime_error("Invalid convertion to celsius!\n");
				}

				// test if result is integer
				if(!isInteger(cels))
				{
					std::cerr << "The result cannot be represented as an int!\n";
				}

				// print result
				std::cout << "Temperature in Celsius is: " << cels << "[C]" << std::endl;
			}
			else if (selection == toKelvin)
			{
				std::cout << "Type temperature value (in Celsius): ";
				double celsi = 0;
				std::cin >> celsi;

				// pre-condition: input check
				if (celsi < abs_zero_celsiu)
				{
					throw std::runtime_error("Third law of thermodynamics violated!\n");
				}

				// conversion function call
				double faren = ctof(celsi);

				// post-condition: result check
				if (faren < abs_zero_farenh)
				{
					throw std::runtime_error("Invalid convertion to fahrenheit!\n");
				}

				// test if result is integer
				if(!isInteger(faren))
				{
					std::cerr << "The result cannot be represented as an int!\n";
				}

				// print result
				std::cout << "Temperature in Fahrenheit is: " << faren << "[F]" << std::endl;
			}
		}
		catch (std::runtime_error& e)
		{
			std::cerr << "Runtime error caught: "<< e.what() <<'\n';
		}
		catch (...)
		{
			std::cerr << "Uncaught exception!\n";
		}
	}
}

//----------------------------------------------------------------------------------
/*
	Function: ftoc();
	Use: double temp_c = ftoc(temp_f);
	Converts Fahrenheit to Celsius by
	taking one double input parameter 
	and returning a double which is
	the converted in celsius temperature.
*/
double ftoc(double faren)
{
	const double conv_const1 = 1.8;
	const double conv_const2 = 32;
	const double abs_zero_farenh = -459.67;
	return (faren - conv_const2) * conv_const1;
}

//----------------------------------------------------------------------------------
/*
	Function: ctof();
	Use: double temp_k = ctof(temp_celsius);
	Converts Celsius to Fahrenheit by
	taking one double input parameter 
	and returning a double which is
	the converted in kelvin temperature.
*/
double ctof(double celsius)
{
	const double conv_const1 = 1.8;
	const double conv_const2 = 32;
	const double abs_zero_celsiu = -273.15;
	return (celsius / conv_const1) + conv_const2;
}

//----------------------------------------------------------------------------------
/*
	Function: isInteger
	Use: bool is_int = isInteger(val);

	Check if val is an integer value.
	Rounds the value and compares it 
	to the initial, if equal the val
	is integer.
*/
bool isInteger(double v)
{
	if (floor(v) == v)
	{
		return true;
	}
	else 
	{
		return false;
	}
}