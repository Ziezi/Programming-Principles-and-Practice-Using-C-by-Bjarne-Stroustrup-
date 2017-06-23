/* 
	TITLE			   Namespaces implementation	Chapter8Drill3.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Global, namespace, class, function, block scope.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Data: 01.03.2015
*/
#include <iostream>
#include "Chapter8Drill3.h"

//==========================================================================
int main()
{
	// initializes var from namespace X
	X::var = 7;

	// prints the above variable
	X::print();

	// change of scope from namespace X to namespace Y
	using namespace Y;
	var = 9;
	print();

	{
		// change of scope for the objects named var and print to namespace Z
		using Z::var;
		using Z::print;
		var = 11;
		print();
	}

	print();	// scope outside the block remains to be namespace Y
	X::print();
}