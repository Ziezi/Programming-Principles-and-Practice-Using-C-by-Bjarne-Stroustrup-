/* 
   TITLE               Quadratic Equation	    Chapter4Exercise18.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
			Objective: Solve a quadratic equation. (ax^2 + bx + c)
				Input: Requests all an equation.
			    Ouput: Prints the roots.
			   Author: Chris B. Kirov
			     Data: 01.04.2015
*/
#include <iostream>
#include <string>
#include <sstream>

void solve_quadratic(double, double, double);

//==============================================================================================================
int main(){
	std::string prompt = "\nType the quadratic, linear and constant terms separated by whitespace\n>>";
	std::string input;
	std::string sentinel = "|";

	std::cout << prompt;
	while (getline(std::cin, input) && input != sentinel)
	{
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
		std::cout << prompt;
	}
}

//==============================================================================================================
void solve_quadratic(double quadratic, double linear, double constant)
{
	double discriminant = pow(linear, 2) - (4 * quadratic * constant);

	std::cout << "\nSolution: \n";
	if (discriminant == 0)
	{
		std::cout << "\nSingle Root: x= " << (-linear ) / (2 * quadratic);
	}
	if (discriminant > 0)
	{
		std::cout << "\nTwo Real roots.\n";
		std::cout << "\nFirst Root: x1= " << ((-linear) + discriminant) / (2 * quadratic) <<'\n';
		std::cout << "Second Root: x2= " << ((-linear) - discriminant) / (2 * quadratic);
	}
	if (discriminant < 0)
	{
		std::cout << "\nTwo Complex roots.\n";
		std::cout << "\nFirst Root: x1= " << 1 / (2 * quadratic) << " * (" << -linear << " + i." << sqrt(abs(discriminant)) << ")" <<'\n';
		std::cout << "Second Root: x2= " << 1 / (2 * quadratic) << " * (" << -linear << " - i." << sqrt(abs(discriminant))<< ")";
	}
}

