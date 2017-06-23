/*
	TITLE		   Hidden Infinite loop							   Chapter25Exercise6.cpp
	COMMENT
		Objective: Write an infinite loop that is hard to recognize as an infinite loop. 
				   A loop that isn't really infinite because it terminates after completely 
				   consuming some resource is acceptable.  
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 13.05.2017
*/
#include <iostream>
 
int main()
{
	try
	{ 
		while (double* ptr = new double [1]);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}