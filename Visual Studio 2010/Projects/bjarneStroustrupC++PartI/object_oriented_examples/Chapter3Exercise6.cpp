/* 
	TITLE		   Comparison & Ordering		 Chapter3Exercise6.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
    COMMENT
	 	Objective: Put in order three input numbers; 
				   Next to each other if they are equal.  
			Input: Requests 3 numbers.
		   Output: Prints numbers in order.
		   Author: Chris B. Kirov
		     Date: 01.02.2014
*/
#include "../../std_lib_facilities.h"

int main()
{
	cout << "Please enter three numbers." << endl;

	cout << "The first number:\t" << endl;
	int var1 = 0;
	cin >> var1;

	cout << "The second number:\t" << endl;
	int var2 = 0;
	cin >> var2;

	cout << "The third number:\t" << endl;
	int var3 = 0;
	cin >> var3;

	// Brute force  (all possible permutations) = 3! => (number of comparisons) = 6
	string res_msg = "The numbers in ascending order are: ";

	if (var1 <= var2 && var2 <= var3)
	{
		cout << res_msg << var1 << ',' << var2 << ',' << var3 << endl;
	}
	else if (var1 >= var2 && var1 <= var3)
	{
		cout << res_msg << var2 << ',' << var1 << ',' << var3 << endl;
	}
	else if (var1 > var2 && var1 >= var3 && var2 <= var3)
	{ 
		cout << res_msg << var2 << ',' << var3 << ',' << var1 << endl; 
	}
	else if (var1 >= var2 && var2 >= var3)
	{ 
		cout << res_msg << var3 << ',' << var2 << ',' << var1 << endl;
	}
	else if (var1 >= var3 && var1 >= var2)
	{ 
		cout << res_msg << var3 << ',' << var1 << ',' << var3 << endl; 
	}
	else if (var1 <= var3 && var3 <= var2)
	{ 
		cout << res_msg << var1 << ',' << var3 << ',' << var2 << endl; 
	}

	return 0;
}