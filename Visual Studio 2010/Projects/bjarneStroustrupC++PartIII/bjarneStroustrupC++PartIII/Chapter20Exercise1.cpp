/*
	TITLE			Do Try All This			 Chapter20Exercise1.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: 
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 18. 02. 2017
*/
#include <iostream>

int main()
{
	try 
	{

	} 
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}