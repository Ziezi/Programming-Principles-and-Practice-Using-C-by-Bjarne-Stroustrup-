/* 
	TITLE		   "Hello, World!" in C  Chapter27Drill1.c
	COMMENT
		Objective: Write a "'Hello, World!" program in C, 
				   compile it, and run it.  
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 12.06.2017
*/
#include <stdio.h>

#ifdef __cplusplus

#else	// compiling in C.

int main()
{
	printf("Hello, World!\n");
	getchar();
}

#endif