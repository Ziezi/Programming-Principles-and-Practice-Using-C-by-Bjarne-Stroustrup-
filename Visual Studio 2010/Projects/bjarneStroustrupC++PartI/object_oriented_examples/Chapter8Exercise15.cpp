/*
	TITLE			   Constant arguments	    Chapter8Exercise15.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Write a finction that has as argument const int.

					   Why declaring a parameter passed by value as 
					   constant? 

					   To signify to the caller that the parameter
					   will not be modified within the function.

					   To clarify the function action on the parameter.

					   For self-documentation and assumption clarification.

				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 11.03.2015
*/
#include <iostream>

// from the declaration I know that func() won't modify i
void func(const int i);

//==================================================================================================
int main()
{
	int par = 5;
	func(par);
}
//==================================================================================================
 
void func(const int i)
{
	std::cout <<"Print argument: "<< i << std::endl;
}
