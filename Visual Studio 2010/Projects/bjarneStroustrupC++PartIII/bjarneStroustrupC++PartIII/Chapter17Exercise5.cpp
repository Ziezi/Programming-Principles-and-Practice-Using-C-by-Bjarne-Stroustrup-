/*
	TITLE		    Find char in C-string	Chapter17Exercise5.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Write a function char* find(const char* s, const char* x),
					that finds first occurence of the C-style string x in s.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 02.12.2015
*/
#include <iostream>

char* find_char(char* s, char* c);
char* find (char* s, char* x);
char* find2_0 (char* s, char* x);
size_t my_strlen (char *s);

//--------------------------------------------------------------------------------

int main ()
{
	try 
	{
		char* source = "abcde\0";
		char* target = "cd\0";

		char* match_found = 0;
		match_found = find (source, target);

		if (match_found) 
		{
			std::cout <<"matching char: \n";
			
			for (size_t i = 0; i < my_strlen(target); ++i) std::cout << match_found[i];
		}
		else 
		{
			std::cout <<"no match!\n";
		}


		char* match_found2 = 0;
		match_found2 = find2_0 (source, target);

		if (match_found2) 
		{
			std::cout <<"\nmatching char: \n";
			
			for (size_t i = 0; i < my_strlen(target); ++i) std::cout << match_found2[i];
		}
		else 
		{
			std::cout <<"no match!\n";
		}
	}
	catch (std::exception &e) 
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	getchar();
}

//--------------------------------------------------------------------------------

/*
	Function: my_strlen();
 
	It returns the lenght of a C-style
	string.
*/
size_t my_strlen (char *s) 
{
	if (!s)
	{
		return 0;
	}

	size_t len = 0;

	while (*s != '\0')
	{
		++len;
		++s;
	}

	return len;
}

//--------------------------------------------------------------------------------

/*
	Function: find_char()
	 
	Returns a pointer to the first char from
	source that matches: target, where source
	is C-style string.
*/
char* find_char(char* s, char* c) 
{
	if (!s || !c) 
	{
		return 0;
	}

	// traverse the source string till the end
	while (*s != '\0')
	{
		// return true at the first occurence of: c
		if (*s == *c)
		{
			return s;
		}

		// if there is no match, increment s to the next character
		++s;
	}
	return 0;
}

//--------------------------------------------------------------------------------

/*
	Function: find()
	 
	It returns a pointer of the first 
	character of source's substring matching 
	target, if all of target's characters match
	a substring of source.
	Assumes target "shorter" than source, if not
	returns nullptr, the same is returned if no
	full match found.
*/
char* find (char* s, char* x) 
{ 
	if (!s || !x) 
	{
		return 0;
	}

	// first char of matching substring of s
	char* match = nullptr;

	// control variable indicating full match between x and substring of s
	bool full_match = false;

	size_t len_s = my_strlen(s);
	size_t len_x = my_strlen(x); 

	// target must be shorter 
	if (len_s < len_x)
	{
		return 0;
	}

	// pointers to beginning and end of s and x
	char *s_begin = s;
	char *s_end = s + len_s;

	char *x_begin = x;
	char *x_end = x + len_x;

	// traverse s 
	for (char* i = s_begin; i != s_end; ++i)
	{
		// test for match between s and the first char of x
		if (*i == *x_begin) 
		{
			// assign s's matching char
			match = i;

			// if x's lenght is 1 return match
			if (len_x == 1)
			{
				return match;
			}

			// define new pointer to the next element of s
			char *i_next = i + 1;

			// traverse the rest of x 
			for (char* j = x_begin + 1; j != x_end; ++j)
			{

				// if there is even one mismatch brake loop and continue traversing s
				if (*i_next != *j)
				{
					break;
				}

				// if the rest of x matches the rest of s, switch to full_match
				if (j == x_end - 1)
				{
					full_match = true; 
				}

				// increment i_next
				++i_next;
			}

			// when x traversed and there is full_match, return the first matching char
			if (full_match) 
			{
				return match;
			}
		}
	}

	// return nullptr to indicate no match
	return 0;
}

//--------------------------------------------------------------------------------

/*
	Function: find2_0 ()

	Returns the beginning
	substring of s matching x;
	or nulllptr.
*/
char* find2_0 (char* s, char* x)
{
	if (!s || !x) // check for null pointers
	{
		return 0;
	}

	if (my_strlen(s) < my_strlen(x)) // is success possible 
	{
		return 0;
	}

	while (*s != '\0') // traverse s 
	{
		char* beg = 0;
		beg = find_char(s, x); // search first matching char

		if (beg)
		{
			char *s_ptr = beg, *x_ptr = x;

			if (my_strlen(s_ptr) < my_strlen(x_ptr)) // is success possible 
			{
				return 0;
			}

			while (*x_ptr != '\0') 
			{
				if (*s_ptr != *x_ptr) // search all matching chars
				{
					break;
				}

				++s_ptr;
				++x_ptr;
			}

			return beg;
		}

		++s;
	}

	return 0;
}