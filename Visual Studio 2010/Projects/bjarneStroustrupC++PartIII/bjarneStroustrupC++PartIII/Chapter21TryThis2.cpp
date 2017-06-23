/*
	TITLE			Implicit parameters	      Chapter21TryThis2.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Why using implicit paremeters could lead to 
					obscure errors.
					List three examples where they should be 
					avoided.

					- non constant global variables can be modified by any function
					from everywhere whithout the knowledge of the programmer.
					- global variables reduces modularity.

		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 25. 02. 2017
*/
#include <iostream>
#include <algorithm>
#include <list>

int v_val; // global function implicit parameter
bool larger_than_v (int x ) { return x > v_val; }

void f (std::list<int>& l, int x)
{
	v_val = 31;
	std::list<int>::iterator p = find_if(l.begin(), l.end(), larger_than_v);

	if (p != l.end())
	{
		// found
	}
}
 
//----------------------------------------------------------------------------------

int main()
{
	 
	getchar();
}