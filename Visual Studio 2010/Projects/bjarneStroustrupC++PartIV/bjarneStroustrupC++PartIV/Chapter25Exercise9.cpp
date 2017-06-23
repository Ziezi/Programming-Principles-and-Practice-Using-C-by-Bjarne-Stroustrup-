/*
	TITLE		   Number of bits, signed or not			       Chapter25Exercise9.cpp
	COMMENT
		Objective: Without using any standard headers (such as <limits> or documentation,
				   compute the number of bits in an int and determine whether char is
				   signed or unsigned on your implementation.
		   Output: -
		   Author: Chris B. Kirov
			 Date: 13.05.2017
*/
#include <iostream>
 
 
int main()
{
	try
	{ 
		 // 1. bits in int
		 int a = 1;
		 int number_of_bits = 0;

		 do
		 {
			++number_of_bits;
			a <<= 1;
		 }
		 while (a != 0);

		 std::cout <<"Int has: "<< number_of_bits <<'\n';

		 // 2. char signed or unsigned

		 char b = 0;
		 bool is_unsigned = b - 1;
		 std::cout <<"Is char unsigned: "<< std::boolalpha << is_unsigned <<'\n';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}