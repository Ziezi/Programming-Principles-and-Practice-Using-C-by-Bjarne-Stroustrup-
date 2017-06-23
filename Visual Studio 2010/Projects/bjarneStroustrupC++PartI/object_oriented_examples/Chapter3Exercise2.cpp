/* 
   TITLE		   Mile to Kilometer        	Chapter3Exercise2.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
		Objective: Convert input data from miles to kilomemts.
			Input: Requests distance in miles.
		   Output: Prints in kilometers.
		   Author: Chris B. Kirov
		     Date: 1.2.2015
*/
#include "../../std_lib_facilities.h"

int main()
{
	// prompt message
	cout << "Enter a distance in miles:\n";

	double distance;
	cin >> distance;

	// conversion
	cout << "The distance in kilometers is:\t" << distance * 1.609 << "[km]\n";
	cout << "Hit a key to continue:" << getchar(); 
}
