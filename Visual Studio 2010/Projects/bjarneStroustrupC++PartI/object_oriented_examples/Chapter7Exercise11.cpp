/*
	TITLE			    Operate only on int                 Chapter7Exercise11.cpp
	"Software - Principles and Practice using C++" by Bjarne Stroustrup"
	COMMENT
			Objective: Modify the calculator to work only on integer
			           values. 
					   
					   Handle overflow and underflow in
					   addition
					   subtractiom
					   multiplication
					   division

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
#include <limits>
#include "Chapter7Exercise11.h"	

int main()
{
	std::cout << "\t\tWelcome to our calculator!" << std::endl;
	calculate();
}