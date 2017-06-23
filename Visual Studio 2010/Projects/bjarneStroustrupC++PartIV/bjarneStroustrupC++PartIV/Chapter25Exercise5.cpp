/*
	TITLE		   Infinite loop     Chapter25Exercise5.cpp
	COMMENT
		Objective: Write an infinite loop. Execule it. 
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 13.05.2017
*/
#include <iostream>
 
 
//-----------------------------------------------------------------------------------------------------------
 
int main()
{
	try
	{ 
		while (true);			
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}