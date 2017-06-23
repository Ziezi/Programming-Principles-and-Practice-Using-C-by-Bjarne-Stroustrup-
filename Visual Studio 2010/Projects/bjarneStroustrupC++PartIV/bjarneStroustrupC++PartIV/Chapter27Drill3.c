/* 
	TITLE		   Output in C					  Chapter27Drill3.c
	COMMENT
		Objective: Define a C function that takes a char* parameter p 
				   and an int parameter x and prints out their values
				   in this format: p is "foo" and x is 7.
				   Call it with a few argument pairs.  
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 12.06.2017
*/
#include <stdio.h>		// printf
 
//-------------------------------------------------------------------

void print_name_value(char* p, int x)
{
	printf("p is %s and x is %d.\n", p, x);
}

//-------------------------------------------------------------------

#ifdef __cplusplus

#else	// compiling in C.

int main()
{
	const int size = 6;
	int i = 0;

	char* p[ ] = {"foo", "bar", "Ginka", "Penka", "Mitsina", "Kotsena" };
	int* x[ ] = { 7, 8, 9, 10, 11, 12 };

	for (i; i < size; ++i)
	{
		print_name_value(p[i], x[i]);
	}

	getchar();
}

#endif