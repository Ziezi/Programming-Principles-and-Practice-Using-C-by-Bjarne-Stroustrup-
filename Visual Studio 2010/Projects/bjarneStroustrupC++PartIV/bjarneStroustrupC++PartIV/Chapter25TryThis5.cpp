/*
	TITLE		   Integer type Overflow		Chapter25TryThis5.cpp
	COMMENT
		Objective: Draw out the bit patterns on a piece or paper. 
				   Using paper, then figure out what the answer would 
				   be for si = 128 in §25.5.3.
				   Then run the program to see if your machine agrees. 
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 10.05.2017
*/
#include <iostream>

 
template <typename T>
void print(T& t)
{
	std::cout << int(t) <<'\n';
}

//---------------------------------------------------------------------------

int main()
{
	try
	{
		 int si = 257;
		 char c = si;					// overflow: 8 bit; 2^8 - 1 = 255, one bit possibly reserved for sign
		 unsigned char uc = si;			// same as c
		 signed char sc = si;			// same as us

		 print(si); print(c); print(uc); print(sc); std::cout <<'\n';

		 si = 129;
		 c = si;					    // char is signed -> 2^7 - 1= 127 !!!
		 uc = si;
		 sc = si;

		 print(si); print(c); print(uc); print(sc); std::cout <<'\n';

		 si = 128;
		 c = si;					     
		 uc = si;
		 sc = si;

		 print(si); print(c); print(uc); print(sc);  std::cout <<'\n';

		 si = 127;
		 c = si;					     
		 uc = si;
		 sc = si;

		 print(si); print(c); print(uc); print(sc);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}