/*
	TITLE		    Find String				 Chapter18Exercise2.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Write a function that finds the first occurence of
				    a C-style string x in s;
					without any standard library functions and with 
					the use of the dereference operator:* instead of 
					subscripting: [].
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 25.12.2015
*/
#include <iostream>
#include <assert.h>

char* findx (const char* s, const char* x);

//----------------------------------------------------------------------

int main () 
{
	try
	{
		// null is appended automatically in this kind of initialization
		char c_str [] = {"abcd"};
		char c_target_str [] = {"bc"};

		char *p =  findx(c_str, c_target_str);

		if (p)
		{
			// run through the original C-style till 0 char is reached
			for (auto i = c_str; *i; ++i) 
			{
				std::cout << *i <<" ";
			}

			std::cout <<"\n\n\n";

			// run through the first occurence of c_target_str till 0 char is reached
			for (auto i = p; *i; ++i) 
			{
				std::cout << *i <<" ";
			}
		} 
		else
		{
			std::cout << "No match found!\n";
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	catch (...)
	{
		std::cerr <<"Unhandled exception!\n";
	}
	getchar();
}
//----------------------------------------------------------------------

/*
	Function: strlen()
	 
	It returns the number of characters
	in the string, not counting the 
	termination character.
*/
size_t m_strlen (const char* c) 
{
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

//----------------------------------------------------------------------

/*
	Function: strdup()
	 
	It returns a pointer to the first occurence 
	of c_target withing c_string; otherwise it returns
	a null pointer indicating no match found.
*/
char* findx (const char* s, const char* x)
{
	if (!s)
	{
		return nullptr;
	}

	if (!x)
	{
		nullptr;
	}

	size_t len_s = m_strlen(s);
	size_t len_x = m_strlen(x);

	if (len_s < len_x)
	{
		return nullptr;
	}

	char* p_to_match = nullptr;

	for (size_t i = 0; i < len_s; ++i) 
	{
		if (*(s + i) == *x)
		{
			p_to_match = const_cast<char*>(s + i);
			//-----------^ can't assing const char* to char* ???

			if (len_x == 1)
			{
				return p_to_match;
			}

			// the current s's matched the x's zeroth, so next test is for the next elements
			const char* next_s = (s + i + 1);
			const char* first_x = (x + 1);

			for (size_t j = 0; j < len_x - 1; ++x) 
			{
				// if any of the rest of x's elements don't match, break the inner for loop
				if (*(next_s + j) != *(first_x + j))
				{
					break;
				}

				// if all the rest of x's elements match return ref_to_match
				if (j == len_x - 2)
				{
					return p_to_match;
				}
			}
		}
	}

	return nullptr;
}