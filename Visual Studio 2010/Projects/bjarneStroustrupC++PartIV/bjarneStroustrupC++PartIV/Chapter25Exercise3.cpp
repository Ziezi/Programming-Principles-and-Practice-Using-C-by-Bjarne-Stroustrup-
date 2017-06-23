/*
	TITLE		   Integer bit patterns   Chapter25Exercise3.cpp
	COMMENT
		Objective: Initialize a 32-bit signed integer with the bit
				   pattern and print the result:
				   - a. all zeroes.
				   - b. all ones.
				   - c. altenating 1's and 0's, with LSB: 1.
				   - d. altenating 1's and 0's, with LSB: 0.
				   - e. 110011001100....
				   - f. 001100110011....
				   - g. all-one bytes and all-zero bytes starting with an all-one byte.
				   - h. all-one bytes and all-zero bytes starting with an all-zeros byte.
				   Repeat that exercise with a 32-bit unsigned integer.

			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 12.05.2017
*/
#include <iostream>
#include <bitset>

template<typename T>
void print(T i)
{
	std::cout << std::dec <<"dec: "<< i << std::hex <<" hex: "<< i <<" bits: "<< std::bitset<sizeof(T) * 8>((int)i) <<'\n';
}

//-----------------------------------------------------------------------------------------------------------
 
int main()
{
	try
	{ 
		 signed int a = 0x00000000;
		 print(a);

		 signed int b = 0xffffffff;
		 print(b);

		 signed int c = 0xaaaaaaab;
		 print(c);

		 signed int d = 0xaaaaaaaa;
		 print(d);

		 signed int e = 0xcccccccc;
		 print(e);

		 signed int f = 0x33333333;
		 print(f);

		 signed int g = 0x0f0f0f0f;
		 print(g);

		 signed int h = 0xf0f0f0f0;
		 print(h);

		 std::cout <<'\n';

		 unsigned int a1 = 0x0000;
		 print(a1);

		 unsigned int b1 = 0xffffffff;
		 print(b1);

		 unsigned int c1 = 0xaaaaaaab;
		 print(c1);

		 unsigned int d1 = 0xaaaaaaaa;
		 print(d1);

		 unsigned int e1 = 0xcccccccc;
		 print(e1);

		 unsigned int f1 = 0x33333333;
		 print(f1);

		 unsigned int g1 = 0x0f0f0f0f;
		 print(g1);

		 unsigned int h1 = 0xf0f0f0f0;
		 print(h1);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}