/*
	TITLE		   Numerical values of keys  Chapter25Exercise8.cpp
	COMMENT
		Objective: Write out the numerical values of each
				   character on your keyboard.
		   Output: -
		   Author: Chris B. Kirov
			 Date: 13.05.2017
*/
#include <iostream>
 
 
int main()
{
	try
	{ 
		 while (true)
		 {
			 int key = getchar();

			 if (iscntrl(key))
			 {
				std::cout <<"Control key pressed.\n";
			 }
			 std::cout <<"You pressed: "<< key <<'\n';
		 }
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}