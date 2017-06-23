/* 
	TITLE	       Implement operator>> in C 				       Chapter27Exercise13.c 
	COMMENT
		Objective: Write a program that does the equivalent of string s; cin >> s; in C;
				   that is, define an input operation that reads an arbitrarily long 
				   sequence of whitespace-terminated characters into a zero-terminated  
				   array of chars.

				   Note: Pointer arguments are COPIES of the actual passed pointers. 
					     (Use pointer of pointer to keep the modifications applied within the function.)

			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 16.06.2017
*/
#include <stdio.h>		// printf()
#include <stdlib.h>		// malloc(); realloc()
#include <string.h>		// strcmp
#include <stddef.h>		// size_t

// Reads characters till a sentinel is encountered, then it returns the previous characters as a single word.
char* get_word(char sentinel)
{
	size_t size = 8;
	size_t index = 0;

	int c = 0;
	char* word = 0;
	char* expand_word = 0;

	word = (char*) malloc(sizeof(char) * size);

	if (word == NULL)
	{
		perror("get_word::bad malloc!\n");
		exit(-1);
	}

	while ((c = getchar()) != EOF && c != sentinel && c != '\n')
	{
		if (index >= size)
		{
			size *= 2;

			expand_word = (char*) realloc(word, sizeof(char) * size);

			if (expand_word == NULL)
			{
				perror("get_word::bad realloc!\n");
				exit(-1);
			}

			word = expand_word;
		}

		word[index++] = c;
	}

	word[index] = 0;

	return word;
}

//-------------------------------------------------------------------------------------

// Stores words (white-space-separated sequences of characters) in string array till "quit" is encountered. Updates size.
void to_array(char** arr[ ], size_t* size, char* quit)
{
	size_t index = 0;
	char* word = 0;
	char** expand_arr = 0;
	char sentinel = ' ';

	while ((word = get_word(sentinel)) && strcmp(word, quit) != 0)
	{
		if (index >= (*size))
		{
			(*size) *= 2;
			 
			expand_arr = (char**) realloc((*arr), sizeof(char*) * (*size));

			if (expand_arr == NULL)
			{
				perror("to_array::bad realloc!\n");
				exit(-1);
			}

			(*arr) = expand_arr;
		}

		(*arr)[index++] = word;
	}

	(*size)  = index;
}

//-------------------------------------------------------------------------------------

void print_array(char* arr[ ], size_t size)
{
	size_t i = 0;

	printf("{ ");
	for (i; i < size; ++i)
	{
		printf("%s", arr[i]);

		if (i < size - 1)
		{
			printf(", ");
		}
	}
	printf(" }\n");
}

//-------------------------------------------------------------------------------------

void clear_arr(char* arr[ ], size_t size)
{
	size_t i = 0;
	for (i; i < size; ++i)
	{
		free(arr[i]);
	}
}

//-------------------------------------------------------------------------------------

int main()
{
	size_t size = 4;
	char** arr = 0;
	char* quit = "quit";

	arr = (char**) malloc(sizeof(char*) * size);

	if (arr == NULL)
	{
		perror("array of strings::bad malloc!\n");
		exit(-1);
	}

	printf("Type a sentence and get each word as an array element:\n");
	to_array(&arr, &size, quit);

	printf("Words:\n");
	print_array(arr, size);

	clear_arr(arr, size);
	getchar();
}