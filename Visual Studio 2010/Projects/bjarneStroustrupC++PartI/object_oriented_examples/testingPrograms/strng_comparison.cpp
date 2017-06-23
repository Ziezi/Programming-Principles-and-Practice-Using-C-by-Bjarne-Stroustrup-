/* 
   TITLE		   Basic String Operators   string_comparison.cpp
   Bjarne Stroustrup's "C++ Programming: Principles and Practice."
   COMMENT
 		Objective: Introduces relational operators over strings. 		   
 			Input: Requests input strings.
 		   Output: Prints their alphabetical order.
		   Author: Chris B. Kirov
		     Date: 01.10.2014
*/
#include "../../std_lib_facilities.h"

int main()
{
	cout << "Please enter two names\n:";
	string first;
	string second;
	cin >> first >> second;
	if (first == second) cout << "That is the same name twice\n";
	if (first < second)
		cout << first << "is alphabetically before" << second << "\n";
	if (first > second)
		cout << first << "is alphabetically after" << second << "\n";
	return 0;
}
