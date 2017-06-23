/* 
   TITLE		   Type safety					 Chapter3TryThis6.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 		Objective: Operations on types; 
				   Type conversions. Truncation (Slicing).
 			Input: - 
   		   Output: -
		   Author: Chris B. Kirov
			 Date: 01.02.2014
*/
#include "../std_lib_facilities.h"

int main() {	

	double d = 0;

	// repeat the statement below as long as we type in numbers
	while (cin >> d) { // if input type different than double the input stream fails and the loop terminates

		// try to squeeze a double in to an int
		int i = d;	// truncation (looses everyuthing after decimal point)

		// try to squeeze an int into a char
		char c = i; // truncation (looses everything > 128 or < -127) char is an int type; ASCII numerical values represt all characters

		// get tne integer value of the character
		int i2 = c; // implicit convertion of the character ASCII value to int

		cout <<"d=="<< d			// the original double
			 <<" i=="<< i			// converted to int
			 <<" i2=="<< i2			// int value of char
			 <<" char("<< c <<")\n";// the char
	}
}