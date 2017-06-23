/* 
   TITLE		   Calculator with word/number input		Chapter4Exercise7.cpp
    Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 		Objective: Implement basic algebraic calculator.(+,-,*,/,%)
				   with input where digits can either be typed as
				   digits or by name ("zero") string.
 			Input: Requests two operands(as digits or spelled-out) and an operation.  
		   Output: Prints the respective result.
		   Author: Chris B. Kirov
			 Data: 01.04.2015
*/
#include "../../std_lib_facilities.h"

void simple_calculator(double, char, double);
bool is_number(const string&);
int word_to_digit(const string&);

//=======================================================================================================================================
int main()
{
	cout <<"Simple calculator; exit with ""|""\n";

	string sentinel = "|";
	string input;

	cout <<"Type two floating point numbers followed by a binary algebraic operator, separated by white space:\n>>";
	while(getline(cin, input) && input != sentinel)
	{
		cout <<"Type two floating point numbers followed by a binary algebraic operator, separated by white space:\n>>";
		stringstream ss(input);

		string operand1, operand2;
		char operation;

		if (ss >> operand1 >> operand2 >> operation)
		{
			double op1, op2;

			// check if operand is digit or string
			if (is_number(operand1))
			{
				op1 = atof(operand1.c_str());
			}
			else 
			{
				op1 = word_to_digit(operand1);

				int invalid_value = -1;
				if (op1 == invalid_value) 
				{
					cout <<"Name not supported!.";
				}
			}

			if (is_number(operand2))
			{
				op2 = atof(operand2.c_str());
			}
			else 
			{
				op2 = word_to_digit(operand2);

				int invalid_value = -1;
				if (op2 == invalid_value) 
				{
					cout <<"Name not supported!.";
				}
			}

			// calculate result
			simple_calculator(op1, operation, op2);
		}
		else 
		{
			cout <<"Wrong input format!\n";
		}
	}
	getchar(); 
}

//=======================================================================================================================================

/*
	Function: simple_calculator()
	Use: simple_calculator(first_operand, operation, second_operand);

	It takes two operands (1st & 3rd parameters) as doubles and
	a binary operation (+,-,/,*,%) as a char.

	It prints the operatin and its result.
*/
void simple_calculator(double first_operand, char binary_operation, double second_operand)
{
	if (binary_operation == '+')
	{
		cout <<"The sum of: "<< first_operand <<" and "<< second_operand <<" is: "<< first_operand + second_operand <<"\n";
	}
	else if (binary_operation == '-')
	{
		cout <<"The subtaction between: "<< first_operand <<" and "<< second_operand <<" is: "<< first_operand - second_operand <<"\n";
	}
	else if (binary_operation == '*')
	{
		cout <<"The multiplication between: "<< first_operand <<" and "<< second_operand <<" is: "<< first_operand * second_operand <<"\n";
	}
	else if (binary_operation == '/')
	{
		cout <<"The division of: "<< first_operand <<" with "<< second_operand <<" is: "<< first_operand / second_operand <<"\n";
	}
	else if (binary_operation == '%')
	{
		int temp1, temp2;
		if (int (first_operand) != first_operand)
		{
			cout <<"First operand truncated!\n";
			temp1 = int (first_operand);
		}
		else
		{
			temp1 = first_operand;
		}

		if (int (second_operand) != second_operand)
		{
			cout <<"Second operand truncated!\n";
			temp2 = int (second_operand);
		}
		else
		{
			temp2 = second_operand;
		}

		cout <<"The modulo of: "<< temp1 <<" to "<< temp2 <<" is: "<< temp1 % temp2 <<"\n";
	}
	else 
	{
		cout <<"Not supported operation\n";
	}
}

/*
	Function: is_number()
	Use: bool number = is_number(num_string);

	It checks whether the string parameter
	contains a number and returns true if so;
	otherwise returns false.
*/
bool is_number(const string& s)
{
    string::const_iterator it = s.begin();

	// stop traversal if there is a non-digit char  
    while (it != s.end() && isdigit(*it))
	{
		++it;
	}

    return !s.empty() && it == s.end();
}

/*
	Function: word_to_digit(const string& number)
	Use: int op = word_to_digit(string_number);

	It compares whether the string parameters
	matches the predefined list of digit names
	and returns it as an int value, of there is a
	match.
*/
int word_to_digit(const string& number)
{
	vector<string> numword(10);
	numword[0] = "zero";
	numword[1] = "one";
	numword[2] = "two";
	numword[3] = "three";
	numword[4] = "four";
	numword[5] = "five";
	numword[6] = "six";
	numword[7] = "seven";
	numword[8] = "eight";
	numword[9] = "nine";

	for (unsigned int i = 0; i < numword.size(); ++i)
	{
		if (number == numword[i])
		{
			return i;
		}
	}
	// not found
	return -1;
}