 /*
	TITLE			  Propose 3 & Implement 1 feature  Chapter7Exercise10.cpp
	"Software - Principles and Practice using C++" by Bjarne Stroustrup"
	COMMENT
			Objective: Propose three possible improvemenets and implement
					   one.

					   Proposals:

					   1. Include epxression in '{'  '}'.

					   2. Include trigonometric functions.

					   3. Scientific mode.

					   4. Units conversion

					   5. Currency conversion.

					   Implemented now:

					   1 and 2 (only sin())

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
			'{' Expressions '}'
			sqrt----------------------------------> Square root: "sqrt" "(" Expression ")"
			pow-----------------------------------> Rise to Power: "pow" "("double "," integer ")"
			Factorial-----------------------------> Factorial: integer"!"
			+ Primary
			- Primary
			name----------------------------------> Call defined variable previously introduced by "let" command
			sin-----------------------------------> Trigonometric Sinus: "sin" "(" Expression ")"
*/

#include <iostream>
#include <string>
#include <vector>
#include "Chapter7Exercise10.h"	

int main()
{
	std::cout << "\t\tWelcome to our calculator!" << std::endl;
	calculate();
}