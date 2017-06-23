// TITLE	Mix-mode Programming Parameter Passing (by-value; by-reference)  minmax_c.cpp
// COMMENT
//		Objective: To illustrate call-by-value and call-by-reference parameter passing 
//				   between C and assembly language modules.
//			Input: Requests three integer parameters.
//		   Output: Prints the minimum and maximum of the inputed integers.

#include <stdio.h>
int main(void)
{
	int value1, value2, value3;
	int minimum, maximum;
	extern void min_max (int, int, int, int*, int*);

	printf("Enter number 1 = ");
	scanf("%d", &value1);
	printf("Enter number 2 = ");
	scanf("%d", &value2);
	printf("Enter number 3 = ");
	scanf("%d", &value3);

	min_max(value1, value2, value3, &minimum, &maximum);
	printf("Minimum = %d, Maximum = %d\n", minimum, maximum);
 return 0;
 }