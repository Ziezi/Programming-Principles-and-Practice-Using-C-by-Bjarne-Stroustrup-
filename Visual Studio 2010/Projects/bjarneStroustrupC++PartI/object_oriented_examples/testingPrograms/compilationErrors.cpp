/* 
   TITLE           Compile-time Errors	   compilationErrors.cpp
   COMMENT
 		Objective: Test compiler response to 
		           intendedly left syntax and type errors.
			Input: -
		   Output: Compiler Error-response.
		   Author: Chris B. Kirov
		     Date: 1.10.2015
*/	   
#include "../../std_lib_facilities.h"

int main(){
	int arena(int lenght, int width);
	// Syntax ERRORS examples
	//int s1 = area(7; 
	//int s1 = area(7)
	//Int s1 = area(7);
	//int s1 = area('7);

	// Type ERRORS examples
	//int s2 = arena(7);
	//int s2 = area(7);   
	//int s3 = area("seven", 3);
	return 0;
}