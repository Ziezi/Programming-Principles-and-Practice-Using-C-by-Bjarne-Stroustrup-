/* 
   TITLE		   Type char manipulation		  unit_length_exch.cpp
   COMMENT
 		Objective: To manipulate characters using 
		           algebraic operations and integers.
 			Input: -
 		   Output: It prints two arrays: 
		           char and int, associated with each other.
		   Author: Chris B. Kirov
		     Date: 01.01.2015
*/
#include "../../std_lib_facilities.h"

int main(){
	// principle used for the body of the while statement:  
	// the english alphabet characters are represented as consecutive numbers of ASCII code. 
	char la = 'a';
	/*
	cout << la << endl;		// Prints: a
	char lb = la + 1;		// translates to the next character
	cout << lb << endl;		// Prints: b
	*/
	int num = 0;
	while (num < 26){
		char lchar = la + num;							 		
		cout << lchar  << "\t" << num + 1 << endl;
		++num;
	}
	return 0;
}
