/* 
	TITLE		   C-style string concatenation 				 Chapter27TryThis1.cpp
	COMMENT
		Objective: Test cat(). Why 2? We left a beginner's performance error in cat();
				   find it and remove it. We "forgot" to comment our code. 
				   Add comments suitable for someone who can be assumed to know the
				   standard C-string functions.  
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 09.06.2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>		// strlen, strcpy

/*
	Returns a pointer to a C-style string consisted 
	of the two concatenated input parameters with 
	an '@' in between.

	Parameters:
		const char* id 
		const char* addr
	Returns:
		char* id@addr\0
*/
char* cat (const char* id, const char* addr)
{
	int sz = strlen(id) + strlen(addr) + 2;				// final string length; 1 for '\0' and 1 for '@'

	char* res = 0;
	res = (char*) malloc(sizeof(char) * sz);			// allocate space for the new string

	if (!res)
	{
		perror("cat::malloc::Can't allocate memory!\n");
	}

	strcpy(res, id);									// initialize the new string

	res[ strlen(id) ] = '@';							// append '@'

	strcpy(res + strlen(id) + 1, addr);					// append a string at the end of the existing	

	res[sz - 1] = 0;									// terminate with '\0' == 0

	return res;
}

//---------------------------------------------------------------------------------------------------------

int main (int argc, int *argv[])
{
	const char* id = "hristo.kirov85";
	const char* addr = "gmail.com";
	char* email = 0;

	email = cat(id, addr);

	printf("My email is: %s, or is it?\n", email);

	free(email);

	getchar();
	return 0;
}
