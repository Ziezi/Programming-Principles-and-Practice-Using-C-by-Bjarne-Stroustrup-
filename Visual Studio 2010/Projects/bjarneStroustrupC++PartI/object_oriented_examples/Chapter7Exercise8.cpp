/*
	TITLE			   Grammar and factorial	      Chapter7exercise8.cpp
	"Software - Principles and Practice using C++" by Bjarne Stroustrup"
	COMMENT
			Objective: Write the calculator grammar, include comments
					   and add additional functionality (factorial).
				Input: - 
			   Output: -
			   Author: Chris B. Kirov
			     Date: 25.02.2015
*/

/*
	Calculator Grammar:

	Calculation:
			Print
			Quit
			Statement
			Calculation Statement

	  Statement:
			Declaration --------------------------> Declaration: "let" [const] name "=" Expression
			Expression

	 Expression:

			Term
			Expression + Term
			Expression - Term

		 Term:
			Primary
			Term * Primary
			Term / Primary
			Term % Primary

		 Primary:
			Floating Point Numbers
			'(' Expressions ')'
			sqrt----------------------------------> Square roor: "sqrt" "(" Expression ")"
			pow-----------------------------------> Rise to Power: "pow" "("double "," integer ")"
			Factorial-----------------------------> Factorial: integer"!"
			+ Primary
			- Primary
			name----------------------------------> Call defined variable previously introduced by "let" command
*/
#include <iostream>
#include <string>
#include <vector>
#include "Chapter7Exercise8.h"	

int main()
{
	std::cout << "\t\tWelcome to our calculator!" << std::endl;
	calculate();
}