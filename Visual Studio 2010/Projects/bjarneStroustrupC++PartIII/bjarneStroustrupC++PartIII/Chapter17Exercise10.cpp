/*
	TITLE		    Dynamic memory reallocation  Chapter17Exercise10.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Redo Exercise 7 and use malloc() and realloc() 
				    to extend input char array.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 07.12.2015
*/
#include <iostream>
#include <cstdio>

char* resize(char* src, size_t src_size, size_t dest_size);

//------------------------------------------------------------------------------------------------

int main () 
{
	try 
	{
		size_t size = 1, counter = 0;
		char* s = (char*) malloc(sizeof(char) * size);

		if (!s) 
		{
			throw std::bad_alloc("bad allocation\n");
		}

		char c, sentinel = '!';

		while (true)
		{
			printf("Type input\n>>");
			std::cin >> c;

			if (c == sentinel) 
			{
				break;
			}

			// resize
			if (counter == size)
			{
				s = resize(s, size, size * 2);

				// update to current size
				size *= 2;
			}

			s[counter++] = c;
		}

		getchar();

		printf("Buffer content: \n");
		for (size_t i = 0; i < counter; ++i) 
		{
			std::cout << s[i] <<", ";
		}

		free(s);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	getchar();
}

//------------------------------------------------------------------------------------------------

char* resize(char* src, size_t src_size, size_t dest_size)
{
	if (!src)
	{
		return 0;
	}

	char *dest = (char*) realloc(src, sizeof(char) * dest_size);

	if (!dest)
	{
		throw std::bad_alloc("resize: bad allocation\n");
	}

	for (size_t i = 0; i < dest_size; ++i)
	{
		if (i < src_size) // copy elements
		{
			dest[i] = src[i];
		}
		else // initialize new elements to 0
		{
			dest[i] = 0;
		}
	}

	return dest;
}