// TITLE  Mix-mode programming functrion call  testex_c.cpp
// COMMENT
//		Objective: To show C++ procedure call from an assemlby module.
//			Input: - (immediate parameter passing).
//		   Output: It prints the result from the assembly procedure manipulation over the parameters passed from the C++ module.

#include <stdio.h>
#include <StdAfx.h>

int main (void)
{
	int x=26, y=70;
	int value;
	extern int __test(int, int, int);

	value = __test(x, y, 5);
	printf("result= %d\n", value);
	return 0;
}