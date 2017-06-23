/*
	TITLE		Solution to the quadratic equation		Chapter5Exercise7.cpp
	 Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Object: Find the roots of a quadratic equation
				and throw exception if over complex numbers.
		 Input: Type the three coefficients: quadratic, linear and free term.
        Output: Prints result.
		Author: Chris B. Kirov
		  Date: 5. 1 . 2015	
*/
#include <iostream>
#include <string>
#include <sstream>

void solve_quadratic(double, double, double);
void calculate();

//==============================================================================================================
int main(){
	try
	{
		calculate();
	}
	catch(std::runtime_error& e)
	{
		std::cerr <<"Runtime error: "<< e.what() <<'\n';
	}
}

//==============================================================================================================

/*
	Function: calculate()
	Use: calculate();

	Runs an input loop,
	calls functions.
*/
void calculate()
{
	std::string prompt = "\nType the quadratic, linear and constant terms separated by whitespace\n>>";
	std::string input;
	std::string sentinel = "|";

	while (true)
	{
		std::cout << prompt;
		getline(std::cin, input);

		if (input == sentinel)
		{
			break;
		}

		double quadratic = 0, linear = 0, constant = 0;
		std::stringstream ss(input);

		// check input validity
		if (ss >> quadratic >> linear >> constant)
		{
			// check whether equation quadratic
			if (quadratic != 0)
			{
				solve_quadratic(quadratic, linear, constant);
			}
			else 
			{
				std::cout <<"Not a quadratic equation!\n";
			}
		}
		else 
		{
			std::cout <<"Wrong input format!\n"; 
		}
	}
}

//----------------------------------------------------------------------------------------------------------
/*
	Function: solve_quadratic()
	Use: solve_quadratic(quad_term, line_term, cons_term);

	Takes three double input parameters
	that represent the coefficients of
	a quadratuic equation and calculates
	its roots. Throws exception in case
	of comlex roots.
*/
void solve_quadratic(double quadratic, double linear, double constant)
{
	double discriminant = pow(linear, 2) - (4 * quadratic * constant);

	std::cout << "\nSolution: \n";
	if (discriminant == 0)
	{
		std::cout << "\nSingle Root: x= " << (-linear ) / (2 * quadratic);
	}
	else if (discriminant > 0)
	{
		std::cout << "\nTwo Real roots.\n";
		std::cout << "\nFirst Root: x1= " << ((-linear) + sqrt(discriminant)) / (2 * quadratic) <<'\n';
		std::cout << "Second Root: x2= " << ((-linear) - sqrt(discriminant)) / (2 * quadratic);
	}
	else if (discriminant < 0)
	{
		throw std::runtime_error("Discriminant < 0\n");
	}
}