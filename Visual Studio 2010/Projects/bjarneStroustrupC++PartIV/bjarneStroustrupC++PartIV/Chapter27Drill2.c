/* 
	TITLE		   Strings in C					  Chapter27Drill2.c
	COMMENT
		Objective: Define two variables holding "Hello" and "World!" 
				   respectively; concatenate them with a space in between; 
				   and output them as Hello, World!.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 12.06.2017
*/
#include <stdio.h>		// printf
#include <stdlib.h>		// malloc
#include <string.h>		// strlen, strcpy, strcat

#ifdef __cplusplus

#else	// compiling in C.

int main()
{
	char* a = "Hello,";
	char* b = "World!";

	int length = strlen(a) + strlen(b) + 2;
	
	char* c = (char*) malloc(sizeof(char) * length);

	strcpy(c, a);
	strcat(c, " ");
	strcat(c, b);

	printf("%s\n", c);
	getchar();
}

#endif