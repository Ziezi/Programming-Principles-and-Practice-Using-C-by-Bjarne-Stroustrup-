/* 
	TITLE			  Calculate the n-th Fibonacci number	nThFibonacci.cpp
	 
	COMMENT
			Objective: Calculates the n-th fibonacci number 
					   using the golden ratio.
				Input: Prompts for the number(index) of the Fionacci in the sequence. 
			   Output: Prints its value. (up to the 46th before overflow)
			   Author: Chris B. Kirov
			     Data: 03.03.2015
*/
//----------------------------------------------------------------------------
// Declaration segment
#include "stdafx.h"
inline double fibonacci(int nthFibonacci);
const double goldenRatio = 1.618034;
 
//----------------------------------------------------------------------------
// Execution segment
int main(){
	cout << "\t\tFind the n-th Fibonacci number." << endl;
	cout << "Type number in the sequence:";
	int index;
	cin >> index;

	int fib = int(fibonacci(index));

	cout << "\nThe " << index << "th Fibonacci number value is: " << fib << "\n" << endl;
	system("pause");
	return 0;
}

//----------------------------------------------------------------------------
// Definition segment
inline double fibonacci(int nthFibonacci){ return ((pow(goldenRatio,nthFibonacci) - pow((1 - goldenRatio), nthFibonacci)) / sqrt(5));}

 