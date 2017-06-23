/* 
   TITLE		   Simple calculator			 Chapter4Exercise5.cpp
    Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 		Objective: Implement basic-algebraic-funtion-calculator.
		           (+,-,*,/,%)
 			Input: Requests two usigned integers and operation. 
			       (using vector objects)
		   Output: Prints the respective result.
		   Author: Chris B. Kirov
			 Data: 01.04.2015
*/
#include "../../std_lib_facilities.h"

void simple_calculator(double, char, double);

//=======================================================================================================================================
int main(){
	cout <<"Simple calculator; exit with ""|""\n";

	string sentinel = "|";
	string input;

	cout <<"Type two floating point numbers followed by a binary algebraic operator, separated by white space:\n>>";
	while(getline(cin, input) && input != sentinel)
	{
		cout <<"Type two floating point numbers followed by a binary algebraic operator, separated by white space:\n>>";
		stringstream ss(input);

		double operand1, operand2;
		char operation;

		if (ss >> operand1 >> operand2 >> operation)
		{
			simple_calculator(operand1, operand2, operation);
		}
		else 
		{
			cout <<"Wrong input format!\n";
		}
	}
	getchar();
}
//=======================================================================================================================================

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