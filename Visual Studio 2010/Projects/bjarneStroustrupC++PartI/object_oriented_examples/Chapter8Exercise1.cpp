/* 
	TITLE			   Stream parameter				Chapter8Exercise1.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Make the input stream an explicit parameter.
					   Add contructor to Token_stream and istream& parameter
					   to read from external files.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Data: 01.03.2015
*/
/*
	Calculator Grammar:

	Calculation:
			Print
			Quit
			Statement
			Calculation Statement
			 
	Statement:
			Declaration ----------------------------> Declaration: "let" name "=" Expression
									constant variable Declaration: "let" "const" name "=" Expression
			Expression

	Expression:
			Term
			Expression +;- Term
	Term:
			Primary
			Term *; / ; % Primary

	Primary:
			Floating point Numbers
			'(' Expressions ')'
			sqrt-----------------------------------> sqrt: "sqrt" "(" Expression ")"
			pow------------------------------------> pow: "pow" "("double, integer ")"
			factorial------------------------------> factorial: integer"!"
			+; - primary
			name-----------------------------------> returns the value of a defined variable previously introduced by "let" command
			sin------------------------------------> returns the sinus of the an angle within [0,360] degrees.

*/
#include <iostream>
#include <string>
#include <vector>
#include "Chapter8Exercise1.h"

int main()
{
	std::cout << "\t\tWelcome to our calculator!" << std::endl;
	calculate(ts);
}
