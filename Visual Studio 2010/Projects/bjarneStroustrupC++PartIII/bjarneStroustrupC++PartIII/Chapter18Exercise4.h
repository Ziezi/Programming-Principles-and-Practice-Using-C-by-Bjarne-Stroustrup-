/*
	TITLE		    Compare strings			   Chapter18Exercise4.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective:- Test the functions for non-zero
					 terminated strings. 
				   - Modify the functions to handle 
					 non-zero terminated strings.

			         The modification to handle non-zero 
					 terminated strings is reflects in the
					 strlen() function where there is a limit
					 for the string lenght.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 25.12.2015
*/

#ifndef _Chapter18Exercise4_h_
#define _Chapter18Exercise4_h_

size_t my_strlen (const char* c);
char* find_char(char* s, char* c);
char* findx (char* s, char* x);
int strcmp (const char* s1, const char* s2);
char* m_strdup (const char*, size_t);

void test1();
void test2();

//-------------------------------------------------------------------

/*
	Reimplemented functions with argumet giving maximum number of 
	elements allowed in argument string.
*/
char* to_C_style_string(char*, size_t);
char const* to_C_style_string2(char* src);

void test3();

#include "Chapter18Exercise4Def.cpp" 

#endif