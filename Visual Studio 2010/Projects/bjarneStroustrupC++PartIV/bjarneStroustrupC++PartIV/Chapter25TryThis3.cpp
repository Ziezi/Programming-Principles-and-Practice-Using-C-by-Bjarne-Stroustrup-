/*
	TITLE		   Bit patterns, hex and oct					Chapter25TryThis3.cpp
	COMMENT
		Objective: Get the bits example to work and try out a few values to develop a
				   feel for binary and hexadecimal representations. 
				   If you get confused about the representation of negative values, 
				   just try again after reading §25.5.3.  

				   negative: two's complement: the negated positive + 1
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 10.05.2017
*/
#include <iostream>
#include <iomanip>
#include <bitset>

//---------------------------------------------------------------------------

int main()
{
	try
	{
		 int i;
		 while (std::cin >> i)
			std::cout << std::dec << i <<" == "
					  << std::hex << "0x" << i <<" == "
					  << std::bitset<8 * sizeof(int)>(i) <<'\n';
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}