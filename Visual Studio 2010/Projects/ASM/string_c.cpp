// TITLE	String processing, demonstrating global variables	string_c.cpp
// COMMENT
//		Objective: String processing implemented by mix-mode programming, with the use og global variables.
//			Input: Requests a string. 
//		   Output: Prints the lenght of the string calculated from a assembly procedure.

#include <stdio.h>
#define LENGTH 256					// defining maximum length of the string

char string[LENGTH];				// defined outside the main (global variable definition)
int	main(void)
{
	extern int string_length (void);

	printf("Enter a string: ");
	scanf("%s", string);
	printf("sting length= %d\n", string_length());

	return 0;
}
