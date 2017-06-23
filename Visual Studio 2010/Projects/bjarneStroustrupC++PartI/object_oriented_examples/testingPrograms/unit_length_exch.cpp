/*
   TITLE	       Unit length conversion		unit_length_exch.cpp
   COMMENT
		Objective: To convert different length units to SI. 
		           (Implemented using: swith(constance expression)
				   { case'variable' break;} , statements)
			Input: Prompts the user to select length unit 
			       conversion to SI units and its value.
		   Output: It prints length in SI units[m].
		   Author: Chris B. Kirov
		     Date: 01.01.2015
*/
#include "../../std_lib_facilities.h"

int main(){
	// prompt message
	cout << "Convert length in SI units[meters].\n" << endl;
	cout << "\t 1. Mile (International)" << endl;
	cout << "\t 2. League (English Land)" << endl;
	cout << "\t 3. Foot" << endl;
	cout << "\t 4. Yard" << endl;
	// input interface
	cout << "\nType length and unit[m,l,f,y], separated by single space: ";
	double init_len = 0.0;
	char unit = 0;
	cin >> init_len >> unit;
	// conversion and output
	switch (unit){
		case 'm':case 'M': 
			cout << "\n\t" << init_len << " miles = " << init_len*1609.34 << " meters" << endl;
			break;
		case 'l':case 'L':
			cout << "\n\t" << init_len << " leagues = " << init_len * 5556 << " meters" << endl;
			break;
		case 'f':case 'F':
			cout << "\n\t" << init_len << " feet = " << init_len * 0.3048 << " meters" << endl;
			break;
		case 'y':case 'Y':
			cout << "\n\t" << init_len << " yards = " << init_len * 0.9144 << " meters" << endl;
			break;
		default: 
			cout << "\n\tYou have typed an invalid unit!" << endl;
			break;
	}
	cout << "\n";
	getchar();
	return 0;
}
