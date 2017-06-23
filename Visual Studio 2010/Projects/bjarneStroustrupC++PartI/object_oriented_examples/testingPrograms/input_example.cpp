/*
   TITLE           Input function   input_example.cpp
   COMMENT
 		Objective: Input commands, Introducing to: object, type, name, value. 				   
 			Input: Requests input information.
 		   Output: Prints the requested info along with standard text.
		   Author: Chris B. Kirov
		     Date: 01.01.2015
*/
#include	"../../std_lib_facilities.h"

int main(){
	// prompt message
	string name_string;														
	cout << "Please enter your first name (followed by CR (enter)):\n";		
	cin >> name_string;														
	cout << "Hello" << name_string << "!\n";
	return 0;
}