/*
	TITLE	       Size of built-in types   	  Chapter24Drill1.cpp
	COMMENT
		Objective: Print the size of a char, a short, an int, a long,
		           a float, a double, an int*, and a double*. 
				   (use sizeof, not <limits>).  
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 01.05.2017
*/
#include <iostream>
#include <iomanip>
#include <limits>

int main()
{
	try
	{
		 std::cout << std::left << std::setw(15) <<"sizeof(char)"<<" : "<< std::setw(3) << sizeof(char) <<'\n';
		 std::cout << std::setw(15) <<"sizeof(int)"<<" : "<< std::setw(3) << sizeof(int) <<'\n';
		 std::cout << std::setw(15) <<"sizeof(long)"<<" : "<< std::setw(3) << sizeof(long) <<'\n';
		 std::cout << std::setw(15) <<"sizeof(float)"<<" : "<< std::setw(3) << sizeof(float) <<'\n';
		 std::cout << std::setw(15) <<"sizeof(double)"<<" : "<< std::setw(3) << sizeof(double) <<'\n';
		 std::cout << std::setw(15) <<"sizeof(int*)"<<" : "<< std::setw(3) << sizeof(int*) <<'\n';
		 std::cout << std::setw(15) <<"sizeof(double*)"<<" : "<< std::setw(3) << sizeof(double*) <<'\n';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}

