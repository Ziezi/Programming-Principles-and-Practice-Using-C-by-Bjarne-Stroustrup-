/* 
	TITLE			   Namespaces implementation	  Chapter8Drill3.h
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Global, namespace, class, function, block scope.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Data: 01.03.2015
*/
// Namespace declaration and inline member data, function definitions

namespace X
{
	int var;
	inline void print()
	{
		std::cout << "var X= " << var << std::endl;
	}
}

namespace Y
{
	int var;
	inline void print()
	{
		std::cout << "var Y= " << var << std::endl;
	}
}

namespace Z
{
	int var;
	inline void print()
	{
		std::cout << "var Z= " << var << std::endl;
	}
}

