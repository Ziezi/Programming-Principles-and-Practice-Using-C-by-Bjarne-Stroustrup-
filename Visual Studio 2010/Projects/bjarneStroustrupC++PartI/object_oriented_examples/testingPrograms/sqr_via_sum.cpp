/* 
   TITLE	       Square function		             num_sq_rt.cpp
   Bjarne Stroustrup's "C++ Programming: Principles and Practice."
   COMMENT
 		Objective: Introduction to functions: 
                   declaration, definition, call.
 			Input: Requests a number.
 		   Output: It prints the squared of the input number.
		   Author: Chris B. Kirov
		     Date: 06.10.2014
*/
#include "../../std_lib_facilities.h"

// used function declaration
int square(int i);
	 
// function calling and used parameter passed (by value), from the user
int main(){
	cout << "\t\tType a number to find its square: ";
	int par = 0;
	cin >> par;
	cout << "\n\t\tThe square of " << par <<" is " << square(par) << endl;
	cout << "\n\n\n" << endl;
	return 0;
}

// function definition
int square(int i){
	// definition of the variable used in the for loop OUTSIDE, 
	// otherwise no access from outside of the FOR loop
	int sqr = 0;
	for (int n = 1; n <= i; ++n){
		sqr += i;
	}
	return sqr;
}
