/* 
	TITLE		   strcpy() implementation 				 Chapter27TryThis2.cpp
	COMMENT
		Objective: Is this implementation of strcpy() correct? Explain why.

				   Not correct: returns the end of the dest string.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 09.06.2017
*/
#include <stdio.h>
#include <stdlib.h>		// malloc
#include <string.h>		// strlen

/*
	Returns a pointer to the first argument,
	which now contains a copy of the content
	pointed to by second paramter.

	Parameters:
		const char* src
		const char* dest
	Returns:
		char* dest
*/
char* m_strcpy(char* dest, const char* src)
{
	char* temp = dest;							// store the beginning of the returned string before pointer arithmetic
	while (*dest++ = *src++);					// copy a char from src, test whether it's 0 (i.e. '\0'), increment pointers

	return temp;
}
 
//---------------------------------------------------------------------------------------------------------

#ifdef __cplusplus	// compiling as C++ 

int main()
{
	const char* src = "Theresa May Lost the 2017 Elections - Hung Parliament.";
	char* dest = 0;
	dest = (char*)malloc(sizeof(char) * (strlen(src) + 1));

	if (!dest)
	{
		perror("malloc::Can't allocate memory!\n");
	}
	 
	dest = m_strcpy(dest, src);

	printf("Source: %s, Destination: %s \n", src, dest);

	free(dest);

	getchar();
}

#else				// compiling as C

int main (int argc, int *argv[])
{
	const char* src = "Theresa May Lost the 2017 Elections - Hung Parliament.";
	char* dest = 0;
	dest = (char*)malloc(sizeof(char) * (strlen(src) + 1));

	if (!dest)
	{
		perror("malloc::Can't allocate memory!\n");
	}
	 
	dest = m_strcpy(dest, src);

	printf("Source: %s, Destination: %s \n", src, dest);

	free(dest);

	getchar();
	return 0;
}

#endif