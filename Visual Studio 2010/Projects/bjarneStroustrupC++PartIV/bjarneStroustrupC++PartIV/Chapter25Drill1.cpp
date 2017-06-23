/*
	TITLE		   Bit shifting & multiplication		Chapter25Drill1.cpp
	COMMENT
		Objective: 1. Run the code with v being of type int. (-> overflow) after 35th doubling
				   2. Run the same code with v being of type unsigned int. (on more bit)
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 11.05.2017
*/
#include <iostream>
 
 
int main()
{
	try
	{
		 // 1.
		 // int v = 1;

		 // 2. 
		 unsigned int v = 1;

		 for (int i = 0; i < sizeof(int) * 8; ++i)
		 {
			std::cout << v <<' ';
			v <<= 1;
		 }
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}