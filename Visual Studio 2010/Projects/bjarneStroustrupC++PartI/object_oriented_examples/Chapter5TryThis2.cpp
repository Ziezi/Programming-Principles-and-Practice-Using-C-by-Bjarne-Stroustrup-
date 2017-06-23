/*
   TITLE	          Type errors			    Chapter5TryThis2.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 			Objective: Observe the response from the type errors.
 				Input: -
 			   Output: IntelliSense responds with error messages.
			   Author: Chris B. Kirov
		         Data: 1.2.2015
*/
#include <iostream>
 
int area(int length, int width);

int main()
{
	int x1 = arena(7);			// identifier "arena " is undefined
	int x2 = area(7);			// too few arguments in a function call
	int x3 = area("seven", 2);  // argument of type "const char*" is inconpatible with parameter of type int
}