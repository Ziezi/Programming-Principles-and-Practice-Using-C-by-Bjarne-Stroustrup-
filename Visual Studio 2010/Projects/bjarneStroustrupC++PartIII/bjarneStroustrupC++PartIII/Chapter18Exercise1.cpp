/*
	TITLE		    String Copy                    Chapter18Exercise1.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Write a function that copies a C-style string 
				    into free store memory and returns a pointer to it.
					Use dereference operatator: *, instead of subscripting: [];
					and no standard library functions.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 25.12.2015
*/
#include <iostream>

size_t m_strlen (const char*); 
char* m_strdup (const char*, size_t);

//-------------------------------------------------------------------------------

int main ()
{
	try
	{
		// null is appended automatically in this kind of initialization
		char c_str [] = {"abcd"};

		char *p =  m_strdup(c_str, m_strlen(c_str));

		if (p) 
		{
			// run through the original C-style till 0 char is reached
			for (auto i = c_str; *i; ++i)
			{
				std::cout << *i <<" ";
			}

			std::cout <<"\n\n\n";

			// run through the copied C-style till 0 char is reached
			for (auto i = p; *i; ++i)
			{
				std::cout << *i <<" ";
			}
		}
		else
		{
			std::cout << "Copy failed!\n";
		}
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	catch(...)
	{
		std::cerr << "Unhandled exception!\n";
	}
	getchar();
}
//-------------------------------------------------------------------------------

 
/*
	Function: strlen()
	 
	It returns the number of characters
	in the string, not counting the 
	termination character.
*/
size_t m_strlen (const char* c) 
{
	// check whether c is the null pointer
	if (!c)
	{
		return 0;
	}

	size_t len = 0;

	// run through the c-string while c != 0  
	while (*c++)
	{
		++len;
	}

	return len;
}

//-------------------------------------------------------------------------------

/*
	Function: strdup()
	 
	It copies a C-style string on heap allocated
	memory and returns a pointer to it.
*/
char* m_strdup (const char* c, size_t size) 
{
	// check if c is the null pointer
	if (!c) 
	{
		return nullptr;
	}

	// allocate dynamic memory, accounting for the termination char '\0'
	char * heap_p = new char[size + 1];

	// check if allocation successful
	if (!heap_p) 
	{
		throw std::bad_alloc("m_strdup: bad allocation.");
	}

	// copy C-string on heap
	for (size_t i = 0; i < size; ++i) 
	{
		*(heap_p + i) = *(c + i);
	}

	// C- style strings
	*(heap_p + size) = '\0';

	// return pointer to the free storage
	return heap_p;
}

 