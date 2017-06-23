/* 
   TITLE	      Invalid name declaration      Chapter3Exercise3.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
       Objective: To test the compiler responce
				  to invalid name declaration.
	       Input: -
          Output: Compile-time errors.
		  Author: Chris B. Kirov
		    Date: 01.02.2014
*/
#include "../../std_lib_facilities.h"

int main()
{
	int 2a;				// syntax error: bad prefix on number; missing ';' before constant; missing ';' before indentifier 'a'; undeclared identifier 'a'
	int _ab;			// no error
	int @ab;			// uknown character '0x40'
	int $d;				// no error
	int d a;			// syntax error: missing ';'before identifier 'a';  'a' undeclared indentifier
	int					// no variable declared 


	return 0;			// ';' before return; 
}