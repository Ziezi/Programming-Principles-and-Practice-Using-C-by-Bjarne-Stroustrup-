/*
	TITLE		   Do Try This Exercise 	     Chapter25Exercise1.cpp
	COMMENT
		Objective: If you haven't already, 
		           do the Try this exercises in this chapter.  
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 12.05.2017
*/
#include <iostream>
 
//-----------------------------------------------------------------------------------------------------------
 
int main()
{
	try
	{ 
	 
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}