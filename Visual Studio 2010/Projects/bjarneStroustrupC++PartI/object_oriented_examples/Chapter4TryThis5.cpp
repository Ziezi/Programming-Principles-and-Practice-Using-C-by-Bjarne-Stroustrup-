/* 
   TITLE  		  Function square() 			 Chapter4TryThis5.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
       Objective: Implement square function using addition.
           Input: - 
          Output: -
		  Author: Chris B, Kirov
            Date: 01. 04. 2015

*/
#include "../std_lib_facilities.h"

// function declaration
int square(unsigned int n);

//=====================================================================
int main() 
{	
	int n = 10;

	int res = square(n);

	std::cout << n <<" squared is: "<< res <<"\n";

	getchar();
}
//=====================================================================

/*
	Function: square()
	Use: int sqrd_num = square(num);

	It implements square function
	using iterative addition.
*/
int square(unsigned int n) 
{
	int res = 0;

	for (unsigned int i = 0; i < n; ++i)
	{
		res += n;
	}

	return res;
}