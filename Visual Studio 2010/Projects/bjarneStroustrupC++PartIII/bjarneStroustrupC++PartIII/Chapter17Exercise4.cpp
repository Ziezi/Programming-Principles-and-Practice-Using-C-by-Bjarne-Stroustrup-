/*
	TITLE		    Copy C-string to free store  Chapter17Exercise4.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Write a function char* strdup(char*)
		            that copies C-style string on free store.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 02.12.2015
*/
#include <iostream>

char* strdup (char*);

//---------------------------------------------------------------------------------------------------------
int main () 
{
	try 
	{
		char stack_array[] = "ABC\0";

		char* heap_array = strdup(stack_array);

		for (size_t i = 0; i < strlen(heap_array); ++i) std::cout << heap_array[i];  

		delete [] heap_array;
	}
	catch (std::exception &e)
	{
	std::cerr << e.what() << std::endl;
	getchar();
	}
	getchar();
}

//---------------------------------------------------------------------------------------------------------

/*
	Function my_strlen();

	It returns the lenght of a C-style 
	string (in bytes).
*/
size_t my_strlen (char* s)
{
	if (!s)
	{
		return 0; // check is s null pointer
	}

	size_t len = 0;
	
	while (*s != '\0') // traverse the string to the end
	{ 
		len++; // increment length   
		
		s++; // go to the next string character
	}
	return len;
}

//---------------------------------------------------------------------------------------------------------

/*
	Function: my_strcpy();
	 
	It copies the source to the
	destination, both C-style 
	strings.
*/
void my_strcpy (char* src, char* dest)
{
	if (!src || !dest)
	{
		return; // check if parameters are nullptr 
	}

	while (*src != '\0') // traverse the source string till the end
	{
		*dest = *src; // copy source to destination

		// increment both 
		src++;
		dest++;
	}
	// make it C-style string by appending a '\0' at the end
	*dest = '\0';
}

//---------------------------------------------------------------------------------------------------------

/*
	Function: char* strdup (char*);
 
	It copies a string from stack to heap.
*/
char* strdup (char* s)
{
	if (!s) 
	{
		return 0;
	}

	 size_t len = my_strlen(s);

	 // allocate memory on free storage, accounting for one additinal character '\0'.
	 char* dup  = new char[sizeof(char) * (len + 1)];
	 
	 if (dup) // check if dup not null pointer, copy: s to: dup
	 {
		 my_strcpy(s, dup);
	 }
	 else
	 {
		return 0;
	 }

	 return dup;
}