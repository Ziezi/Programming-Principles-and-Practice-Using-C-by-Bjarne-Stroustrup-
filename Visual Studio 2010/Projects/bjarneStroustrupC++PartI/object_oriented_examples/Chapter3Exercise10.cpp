/*
	TITLE	       Binary operations		    Chapter3Exercise_10.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Implements simple binary operation. (containing two operands)
			Input: Requests two operands and a operation to be performed.
		   Output: Prints result from selected operation.
		   Author: Chris B. Kirov
			 Date: 10.02.2014
*/
#include "../../std_lib_facilities.h"

int main()
{
	// supported operations
	string addition = "+";
	string subtraction = "-";
	string multiplication = "*";
	string division = "/";

	cout <<"Please type two operands and an opeation to be perfomed on them.\n" << endl;
	cout <<"Type the first operand: ";
	double first_operand = 0;
	cin >> first_operand;

	cout <<"Type the second operand: ";
	double second_operand = 0;
	cin >> second_operand;

	cout <<"Type opeation (+, -, *, /): ";
	string operation;
	cin >> operation;
	
	if (operation == addition) 
	{ 
		cout <<"\nThe addition between the two operands equals: "<< first_operand + second_operand << endl;
	}
	else if (operation == subtraction)
	{ 
		cout << "\nThe subtracion between the two operands equals: " << first_operand - second_operand << endl; 
	}
	else if (operation == multiplication) 
	{ 
		cout << "\nThe multiplication between the two operands equals: " << first_operand * second_operand << endl; 
	}
	else if (operation == division) 
	{ 
		cout << "\nThe division between the two operands equals: " << first_operand / second_operand << endl;
	}
	else {
		cout << "\nYou have entered an undefined operation." << endl;
	}

	getchar();
	return 0;
}