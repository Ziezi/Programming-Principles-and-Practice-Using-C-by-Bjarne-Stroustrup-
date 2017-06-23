/* 
	TITLE			   Roman numerals	        Chapter10Exercise7.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Include calculations with Roman numerals.
			    Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Data: 15.02.2015
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
#include <string>
#include <vector>
#include <map>
#include <forward_list>
#include "Chapter10Exercise7.h"

int main()
{
	std::cout << "\t\tWelcome to our calculator!" << std::endl;
	calculate(ts);
}