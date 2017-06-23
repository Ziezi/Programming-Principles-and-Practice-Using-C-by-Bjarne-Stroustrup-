/*
	TITLE		    Compare strings				 Chapter18Exercise3.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Write a function that compares C-style string
				    and returns negative value if first argument 
					lexicographically before the second, positive
					value otherwise and 0 of they match.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 25.12.2015
*/
#include <iostream>

int strcmp (const char* s1, const char* s2);

//----------------------------------------------------------------------------

int main ()
{
	try
	{
		// null is appended automatically in this kind of initialization
		char c_str1 [] = {"abc"};
		char c_str2 [] = {"abb"};

		int cmp = 2;
		cmp = strcmp (c_str1, c_str2);

		if (cmp == -1)
		{
		 		std::cout << c_str1 << " smaller than " << c_str2 <<"\n";
		} 
		else if (cmp == 0)
		{
				std::cout << c_str1 << " equal to " << c_str2 <<"\n";
		} 
		else if (cmp == 1)
		{
				std::cout << c_str1 << " larger than " << c_str2 <<"\n";
		}
		else 
		{
			throw std::runtime_error("strcmp:: invalid returing value!\n");
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	catch (...)
	{
		std::cerr << "Unhadled exception!\n";
	}
	getchar();
}

//----------------------------------------------------------------------------

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

	// handle non-zero terminated strings
	const int max_string_length = 1000;

	// run through the c-string while c != 0  
	while (*c++)
	{
		++len;

		// limit the lenght of a string 
		if (len > max_string_length ) 
		{
			return ++len;
		}
	}

	return len;
}

//----------------------------------------------------------------------------

/*
	Function: strcmp ()
	 
	It compares lexicographically two C-style
	strings and returns: 0 if strings equal,
	-1 if c_style < c_style2 and
	1 if c_style > c_style2. 
*/
int strcmp (const char* s1, const char* s2) 
{
	if (!s1)
	{
		throw std::invalid_argument("strcmp: null pointer passed as argument.");
	}

	if (!s2)
	{
		throw std::invalid_argument("strcmp: null pointer passed as argument.");
	}

	size_t len_s1 = m_strlen(s1);
	size_t len_s2 = m_strlen(s2);

	// run though the size of the smaller string
	for (size_t i = 0; i < std::min(len_s1, len_s2); ++i)
	{
		// if characters different, check character order
		if (*(s1 + i) != *(s2 + i)) 
		{
			// if s1 smaller than s2, return -1
			if (*(s1 + i) < *(s2 + i))
			{
				return -1;
			}
			else 
			{
				return 1;
			}
		}

		// if all the elements are not different and the lenghts are equal, strings equal
		if ((i == std::min(len_s1, len_s2) - 1) && (len_s1 == len_s2)) 
		{
			return 0;
		}
	} 

	// if all compared elements equal but lenghts not equal, determine order by lenght 
	return (len_s1 < len_s2) ? -1 : 1; 
}