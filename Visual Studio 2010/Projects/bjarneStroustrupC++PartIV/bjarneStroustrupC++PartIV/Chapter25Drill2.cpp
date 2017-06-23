/*
	TITLE		   Unsigned short Bit manipulations		     Chapter25Drill2.cpp
	COMMENT
		Objective: 3. Using hex literals, define short unsigned ints:
						a. With every bit set.
						b. The lowest (lsb) set.
						c. The highest (msb) set.
						d. The lowest byte all set.
						e. The highest byte all set.
						f. Every second bit set and the lowest bit 1.
						g. Every second bit set and the lowest bit 0.
				   4. Print each as decimal and hexadecimal.
				   5. Do 3 and 4 using bit manipulation operations
					  (|, &, <<) and only the literals 1 and 0.
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 11.05.2017
*/
#include <iostream>
#include <iomanip>
#include <bitset>

void print(unsigned short a)
{
	std::cout << std::dec <<"dec: "<< std::setw(6) << a << std::setw(4) << std::hex <<" , hex: "<< a <<'\n';
}

//-----------------------------------------------------------------------------------------------------------
 
int main()
{
	try
	{ 
		// 3. a
		unsigned short a = 0xffff; // 2 bytes

		// 3. b
		unsigned short b = 0x0001;

		// 3. c
		unsigned short c = 0x8000;  

		// 3. d
		unsigned short d = 0x00ff;

		// 3. e
		unsigned short e = 0xff00;

		// 3. f
		unsigned short f = 0xAAAB;

		// 3. g
		unsigned short g = 0xAAAA;

		// 4.
		print(a);
		print(b);
		print(c);
		print(d);
		print(e);
		print(f);
		print(g);

		// 5. b
		unsigned short b1 = 0x0001;

		// 5. a
		unsigned short a1 = b1;

		int i = 1;
		int number_of_bits =  16;
		while (i < number_of_bits)
		{
			a1 |= b1 << i;
			++i;
		}

		// 5. c
		unsigned short c1 = a << (number_of_bits - 1);

		// 5. d
		unsigned short d1 = b1;

		int j = 1;
		int byte = 8;
		while (j < byte)
		{
			d1 |= b1 << j;
			++j;
		}

		// 5. e
		unsigned short e1 = d1 << byte;
 
		// 5. f
		unsigned short f1 = b1;
 
		int k = 1;
		while (k < number_of_bits)
		{
			f1 |= b1 << k;
			k += 2;
		}

		// 5. g
		unsigned short g1 = 0x0000;

		k = 1;
		while (k < number_of_bits)
		{
			g1 |= b1 << k;
			k += 2;
		}

		//std::bitset<16> x = g1;
		//std::cout << x;
		//print(g1);
		std::cout <<'\n';
		// 5. print
		print(a1);
		print(b1);
		print(c1);
		print(d1);
		print(e1);
		print(f1);
		print(g1);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}