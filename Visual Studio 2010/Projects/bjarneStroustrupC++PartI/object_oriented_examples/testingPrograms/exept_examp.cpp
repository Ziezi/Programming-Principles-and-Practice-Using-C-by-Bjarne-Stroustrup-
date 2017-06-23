/* 
  TITLE	               Exceptions example		            exept_examp.cpp
  COMMENT
 			Objective: Introduce the notion of exceptions and error handling.
 				Input: Out of range values, Bad Arguments, Bad Input.
 		       Output: Program response according to the error handling procedures.
			   Author: Chris B. Kirov
			     Date: 01.01.2015
*/
#include "../../std_lib_facilities.h"

int main(){ 
	/*
	int d = 0;
	cout << "Type a value: ";
	cin >> d;
	if (!cin) error("Couldn't read doube!");	
	{
		cout << "Wrong input type!!!" << endl;
		return 1;
	}
	cout << "d = " << d << endl;
	*/
	try{
		vector<int>nums(2);

		cout << "Element with index [2] = " << nums[2] << endl;
		return 0;						// Indicates no problem
	}catch (...)							 {
		cerr << "Oops: unknown exception!\n";
		keep_window_open();
		return 2;						// Indicates failure 
	}
	return 0;
}