/* 
   TITLE           Basic Algebraic Operator    basicAlgebraicOperations.cpp
   COMMENT
		Objective: Introduce basic operators.    
			Input: Requests input integer.
		   Output: Prints the requested integer, after operator action.
		   Author: Chris B. Kirov
		     Date: 1.10.2015
*/
#include "../../std_lib_facilities.h"

int main()
{
	cout << "Please enter a floating-point value: ";
	int n = 1;
	double m = 1.0;
	cin >> n;
	cout << "n ==" << n
		<< "\nn+1==" << n + 1
		<< "\nthree times n==" << 3 * n
		<< "\ntwice n==" << n + n
		<< "\nn squared==" << n*n
		<< "\nhalf of n==" << n / 2
		<< m << n
		<< "\nsquare root of n==" << sqrt(m)
		<< endl;									// end of line 
	return m;
}
