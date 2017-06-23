/* 
	TITLE		   Parity check		             Chapter3Exercise8.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
    COMMENT
		Objective: Determine the parity of an integer.
				   Useful terms: odd, even, modulo divison.
			Input: Requests an integer.
		   Output: Prints odd or even. 
		   Author: Chris B. Kirov
		     Date: 10.02.2014
*/
#include "../../std_lib_facilities.h"

int main()
{
	cout <<"Please type an integer: ";
	int num = 0;
	cin >> num; 
	
	// parity test 
	int par = num % 2;

	cout <<"\nRemainder: " << par << endl;

	if (par == 0)
	{ 
		cout <<"\nThe number: "<< num <<" is even.\n"; 
	}
	else 
	{ 
		cout <<"\nThe number: "<< num <<" is odd.\n";
	}

	getchar();
	return 0;
}