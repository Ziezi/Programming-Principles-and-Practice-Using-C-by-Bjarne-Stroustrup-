/*
   TITLE	          Syntax errors			    	Chapter5TryThis.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 			Objective: Observe the response from the syntax errors.
 				Input: -
 			   Output: IntelliSense responds with error messages.
			   Author: Chris B. Kirov
		         Data: 1.2.2015
*/
#include <iostream>
 
int area(int length, int width);

int main()
{
	 int s1 = area(7;	// expected a ')'
	 int s2 = area(7)   // too few arguments in function call
	 Int s3 = area(7);  // expected a ; 
	 int s4 = area('7); // missing closing quote
}