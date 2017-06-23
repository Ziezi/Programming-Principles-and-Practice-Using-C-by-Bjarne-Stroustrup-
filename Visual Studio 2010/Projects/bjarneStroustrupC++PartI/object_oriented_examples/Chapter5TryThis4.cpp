 /*
   TITLE	           Exception			     Chapter5TryThis4.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 			Objective: Demonstrate uncaught exception throw.
 				Input: -
 			   Output: Even without try-catch block, there is break in the function.
			   Author: Chris B. Kirov
		         Data: 1.2.2015
*/
#include <iostream>
 
int area (int, int);

//=============================================================================================
int main()
{
	 int x = -1;
	 int y = 2;
	 int area1 = 0;

	 // try
	 // {
		area1 = area(x, y);
	 // }
	 // catch(std::runtime_error& re)
	 // {
	 //	std::cerr <<"Runtime error: "<< re.what() <<"\n"; 
	 // }

	 std::cout <<"area1: "<< area1 <<'\n';
	 
	 getchar();
}
//=============================================================================================

int area (int length, int width)
{
	// callee test
	if (length <= 0 || width <= 0)
	{
		throw std::runtime_error("area: Invalid parameter!\n");
	}
	return length * width;
}

 