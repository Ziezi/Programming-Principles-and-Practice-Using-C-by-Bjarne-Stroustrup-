/*
   TITLE           I/O & variables				 Chapter3TryThis2.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
		Objective: Input/Output commands, 
		           Introducing to: object, type, name, value options. 
				   Basic algebraic operations: * 
			Input: Requests input information.
		   Output: Prints the requested info, 
		           after manipulation, along with standard text.
		   Author: Chris B. Kirov
		     Date: 02.02.2014
		   
*/
#include "../../std_lib_facilities.h"

int main(){ 

	cout << "Please enter a floating-point value: ";

	// declare (not initialized) a variable: type identifier;
	int n;
	cin >> n;

	double sqrt_param = n; 

	cout <<"n == "<< n
		 <<"\nn+1 == " << n + 1
		 <<"\nthree times n == " << 3 * n
		 <<"\ntwice n == " << n + n
		 <<"\nn squared == "<< n * n
		 <<"\nhalf of n == "<< n / 2
		 <<"\nsq uare root of n == " << sqrt(sqrt_param)  // defined only for type double
		 << endl; // another name for newline "\n" ("end of line"); additionally it empties the output stream
}
