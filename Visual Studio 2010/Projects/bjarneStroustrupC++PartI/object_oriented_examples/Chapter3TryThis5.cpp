/* 
   TITLE		   Syntax Errors		     Chapter3TryThis5.cpp
    Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 		Objective: Present name errors that should be avoided.
                   (Undeclared identifiers)		
 			Input: - 
   		    Output: It causes compilation errors due to syntax/type errors. 
			Author: Chris B. Kirov
			  Date: 01.02.2014
*/
#include "../std_lib_facilities.h"

int Main()											// error:"main" is with capital "M", missing: "{"
	String s = "Goodye, cruel world!\n";			// error: type "string" with capital "S"
	cOut << S << "\n";								// error: wrong stream object name 
}