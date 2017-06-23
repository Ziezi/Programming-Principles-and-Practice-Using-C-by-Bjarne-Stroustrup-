/* 
	TITLE	       Simulate single inheritance in C.        				    Chapter27Exercise15.c 
	COMMENT
		Objective: Let each "base class" contain a pointer to an array of pointers to functions 
				   (to simulate virtual functions as free standing functions taking a pointer to 
				   a "base class" object as their first argument see §27.2.3. 
				   Implement "derivation" by making the "base class" the type of the first member 
				   of the derived class. For each class, initialize the array of "virtual functions" 
				   appropriately. 
				   To test the ideas, implement a version of "the old Shape example" with the base and 
				   derived draw() just printing out the name of their class. Use only language features 
				   and library facilities available in standard C.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 20.06.2017
*/
#include <stdio.h>		// printf()
#include <stddef.h>		// size_t
#include <stdlib.h>		
#include "Chapter27Exercise15.h"

#ifdef _cplusplus

#else


int main()
{
	Base_class a;
	Derived_1 b;

	initialize_base(&a);
	initialize_derived(&b);

	print_base(&a);
	print_derived(&b);

	getchar();
}


#endif