/*
	TITLE			   Revisit two exercises      Chapter7Exercise13.cpp
	"Software - Principles and Practice using C++" by Bjarne Stroustrup"
	COMMENT
			Objective: Revisit two exercises from Chapter 4 and 5.
					   Clean up the code and check for bugs.
				Input: - 
			   Output: -
			   Author: Chris B. Kirov
			     Date: 25.02.2015
*/
#include <iostream>
#include <string>
#include <sstream>

void calculateGrainsOfRice();
long long find_rice_grains(int);

void calculateQuadratic();
void solve_quadratic(double, double, double);

//===============================================================================================================

int main()
{
	try
	{
		calculateGrainsOfRice();

		calculateQuadratic();
	}
	catch (std::runtime_error& e)
	{
		std::cerr <<"Runtime error; "<< e.what() << "\n";
		getchar();
	}
}

//===============================================================================================================
// Chapter 4 Exercise 9
/*
	Function: find_rice_grains();

	Takes a number representing the 
	number of doublings of 1.
	Returns the accumulated value after
	"doublings" iterations.
*/
long long find_rice_grains(int doublings)
{
	unsigned long long initial_value = 1;
	int current_doublings = 0;

	while (current_doublings <= doublings)		 
	{		
		// check for overflow
		if (initial_value * 2 < initial_value)
		{
			std::cerr <<"Overlow occured at: "<< current_doublings << " iteration.\n";
			return 0;
		}

		initial_value = initial_value * 2;
		++current_doublings;
	}

	return initial_value;
}
//---------------------------------------------------------------------------------------------------------
/*
	Function: calculateGrainsOfRice();

	Interface to function find_rice_grains().
	Runs an input loop, calls functions.
*/
void calculateGrainsOfRice()
{
	std::cout << "\t\tCalculate rice grains after n doublings; 'q' to exit.\n";
	std::string prompt = "Please type number of doublings:\n>>";	
	std::string sentinel = "q";
	std::string input;

	while (true)
	{
		std::cout << prompt;	
		getline(std::cin, input);

		std::stringstream ss(input);

		if (input == sentinel)
		{
			break;
		}

		int number_of_doublings;	 
		if (ss >> number_of_doublings)
		{
			std::cout <<"After: "<< number_of_doublings <<" doublings there are: "<<  find_rice_grains(number_of_doublings) <<" grains of rice\n";
		}
		else
		{
			std::cerr <<"Wrong input formar!\n";
		}
	}
}


//---------------------------------------------------------------------------------------------------------
// Chapter 5 Exercise 7
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
		std::cout << "\nFirst Root: x1= " << ((-linear) - sqrt(discriminant)) / (2 * quadratic) <<'\n';
		// check for loss of precision between subtraction of two nearly equal numbers 
		// solved by algebraic transformation: ( numerator / denominator) * (+/-)(numerator / numerator)
		std::cout << "Second Root: x2= " << (-2.0 * constant) / (linear + sqrt(discriminant));
	}
	else if (discriminant < 0)
	{
		throw std::runtime_error("Discriminant < 0\n");
	}
}
//---------------------------------------------------------------------------------------------------------

/*
	Function: calculate()
	Use: calculate();

	Inteface to the quadratic equation solver
	Runs an input loop, calls functions.
*/
void calculateQuadratic()
{
	std::cout <<"Find roots of a quadratic equation: '|' to exit.";
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