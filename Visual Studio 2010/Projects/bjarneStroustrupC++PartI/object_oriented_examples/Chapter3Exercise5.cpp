/* 
   TITLE		   Algebraic operations           Chapter3Exercise5.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
		Objective: Performs algebraic operations between two int variables.

				   Infers division from the variable type, if type int,
				   division conventional.

				   NaN values could be produced by dividion by 0. 

			Input: Requests two variables.
		   Output: Prints: 
		           smallest, largest, sum, difference, product, ratio.
		   Author: Chris B. Kirov
		     Date: 01.02.2014
*/
#include "../../std_lib_facilities.h"

int main()
{
	// prompt message
	cout << "Please enter two variables.\n";														 
	cout << "The first variable is:\t";				 

	// in case of type-int-variavbles, noticeable difference in ratio between the two (integer division)
	int var1 = 0, var2 = 0;
	cin >> var1;
	cout << "The second variable is:\t";
	cin >> var2;

	// selection block
	if (var1 != var2 && var1 < var2)																 
	{ 
		cout <<"\nVariable one is smaller than variable two:\t" <<  var1 << " < " << var2 << endl;
	}
	else if (var1 != var2 && var1 > var2)
	{
		cout << "\nVariable one is bigger than variable two:\t" << var1 << " > " << var2 << endl; 
	}
	else 
	{
		cout << "\nVariable one is equal to variable two:\t"<< var1 << " = " << var2 << endl;
	}
	
	// calculation block
	cout << "\nThe sum of the two variables is:\t" << var1 + var2 << endl;					// calculates and prints the sum

	cout << "\nThe difference of the two is:" << endl;										// calculates and prints the difference
	cout << "Variable 1 - Variable 2:\t" << var1 - var2 << endl;
	cout << "Variable 2 - Variable 1:\t" << var2 - var1 << endl;

	cout << "\nThe product between the two variables is:\t" << var1*var2 << endl;			// calculates and prints the product

	if (var1 == 0)																			// calculates and prints the valid ratio
	{
		cout << "\nVariable one / Variable two = " << var1 / var2 << endl;
		cout << "Variable two/ Varible one: UNDEFINED!" << endl;
	}
	else if (var2 == 0)
	{
		cout << "\nVariable two / Variable one = " << var2 / var1 << endl;
		cout << "Variable one/ Varible two: UNDEFINED!" << endl;
	}
	else 
	{
		cout << "\nVariable one / Variable two = " << var1 / var2 << endl;
		cout << "Variable two / Variable one = " << var2 / var1 << endl;
	}

	return 0;
}