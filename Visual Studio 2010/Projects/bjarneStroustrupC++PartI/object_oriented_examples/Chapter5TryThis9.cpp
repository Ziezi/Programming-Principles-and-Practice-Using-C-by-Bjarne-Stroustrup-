 /*
   TITLE	          Pre & Post Conditions		 Chapter5TryThis9.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 			Objective: Find values that doesn't hold for both 
					   conditions.
 				Input: -
 			   Output: -
			   Author: Chris B. Kirov
		         Date: 1.2.2015
*/
#include <iostream>
#include <limits> // to retrieve the maximum value stored in a int type

int area (int length, int width)
{
	// pre conditions: parameters > 0
	if (length < 0 || width < 0)
	{
		std::cerr <<"area() pre-condition\n";
	}
	int a = length * width;
	// post conditions: area > 0
	if (a <= 0)
	{
		std::cerr <<"area() post-condition\n";
	}
	return a;
}

//=======================================================================================
int main()
{
	 // a possible pair of values that would make pre condition hold 
	 // but post conditio fail would be a pair whose product makes "a" overflow 
	 // resulting in a negative value

	int length = std::numeric_limits<int>::max();
	int width = 2;

	area(length, width);
}

 