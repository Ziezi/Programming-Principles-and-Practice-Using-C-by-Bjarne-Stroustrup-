/* 
	TITLE			   Redirecting Calculator I/O   Chapter10Exercise10.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Add commands:
			          "from file_name" - making the calculator taking input from that file.
			           "to file_name" - making the calculator to output / error to that file.

					   Write a collection of test cases (based on ideas from §7.3) 
					   in the input file and test the calculator.

					   To test the calculator using a file:
					   - first redirect output to file using: to file_name
					   - second redirect input from file using: from file_name

					   Then, the calculator will read and evaluate the expressions
					   in the input file and will write the results in the output file.
			    Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Data: 04.05.2015
*/

/*
	Calculator Grammar:
	Calculation:
			Redirect Input
			Redirect Output
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
			Floating point Numbers / Roman numerals
			'(' Expressions ')'
			sqrt-----------------------------------> sqrt: "sqrt" "(" Expression ")"
			pow------------------------------------> pow: "pow" "("double, integer ")"
			factorial------------------------------> factorial: integer"!"
			+; - primary
			name-----------------------------------> returns the value of a defined variable previously introduced by "let" command
			sin------------------------------------> returns the sinus of the an angle within [0,360] degrees.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <forward_list>
#include "Chapter10Exercise10.h"

//=========================================================================
int main()
{
	std::cout << "\t\tWelcome to our calculator!" << std::endl;
	calculate(ts);
}