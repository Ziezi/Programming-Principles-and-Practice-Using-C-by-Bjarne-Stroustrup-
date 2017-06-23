/* 
	TITLE	       Use macros to obscure ineritance in C    Chapter27Exercise16.c 
	COMMENT
		Objective: Use macros to obscure (simplify the notation for)
				   the implementation in the previous exercise.  
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 21.06.2017
*/
#include <stdio.h>		// printf()
#include <stdlib.h>		// exit()
#include "Chapter27Exercise16.h"

#ifdef _cplusplus

#else // compile in C

int main()
{
	Shape s;
	Circle c;

	NAME(&s) = "Shape Object";
	TYPE(&s) = shape;

	NAME(&c) = "Circle Object";
	TYPE(&c) = circle;
	RADIUS(&c) = 10;

	draw(&s);
	draw((Shape*)&c);

	getchar();
}

#endif