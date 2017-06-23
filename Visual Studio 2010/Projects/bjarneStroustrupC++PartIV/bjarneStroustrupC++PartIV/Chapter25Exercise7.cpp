/*
	TITLE		   Hex values in a range    Chapter25Exercise7.cpp
	COMMENT
		Objective: Write out the hexadecimal values from 0 to 400; 
				   and from -200 to 200.  
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 13.05.2017
*/
#include <iostream>
 
void print_hex(int from, int to)
{
	for (int i = from; i < to; ++i)
	{
		std::cout << std::hex << i <<' ';

		if(i % 8 == 0 && i != 0)
		{
			std::cout <<'\n';
		}
	}
	std::cout <<'\n';
}

int main()
{
	try
	{ 
		 print_hex(0, 400);

		 print_hex(-200, 200);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}