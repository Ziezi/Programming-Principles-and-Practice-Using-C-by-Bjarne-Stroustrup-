/* 
   TITLE           Definition, declaration, #include, function call  func_def.cpp
   COMMENT
		Objective: Introduce functions declaration and usage in third sorce code file.
			Input: -
		   Output: Returns type int named: sqr. (Square of a number.)
		   Author: Chris B. Kirov
		     Date: 01.01.2015
*/
#include "../../std_lib_facilities.h"

// Function Definition
int mysquared(int i){
	int sqr = 0;	
    // definition of the variable used in the for loop OUTSIDE, otherwise no access from outside of the FOR loop	
	for (int n = 1; n <= i; ++n){
		sqr += i;
	}
	return sqr;
}