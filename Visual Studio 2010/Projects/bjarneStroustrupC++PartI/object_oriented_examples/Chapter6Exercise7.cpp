/* 
   TITLE		   Grammar for logical expressions Chapter6Exercise7.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 		Objective: Write a grammar for logical expressions. 
		           Consireding operation arity(unary,binary,etc.), 
				   affix(preffix,infix,suffix) and precedence . 
 			Input: -
 		   Output: -
		   Author: Chris B. Kirov
			 Date: 16.02.2015
*/
#include <iostream>
 
/*
	Operations: & (AND), ^ (XOR), | (OR), !(NEGATE), ~(COMPLEMENT)
	Operands: Propositions.

	Grammar:

	Expression:
		Term
		Term & Expression

	Term:
		Primary 
		Term ^ Primary

	Primary:
		Secondary
		Primary | Secondary
	
	Secondary:
		Proposition
		! Proposition
		~ Proposition
		'(' Expression ')'
*/

int main()
{

}