/*
   TITLE           I/O & variables				 Chapter3TryThis.cpp
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

	// variable definitions: type identifier operator= value;
	string name = "name";
	double age = 0.0;

	cout << "Please enter your name and age (separated by white space)\n.";

	// read input from keyboard: standard input stream extraction operator>> variable
	cin >> age >> name;

	cout << "Hello" << name << "(age in months:" << age * 12 << ")\n";

	return 0;
}