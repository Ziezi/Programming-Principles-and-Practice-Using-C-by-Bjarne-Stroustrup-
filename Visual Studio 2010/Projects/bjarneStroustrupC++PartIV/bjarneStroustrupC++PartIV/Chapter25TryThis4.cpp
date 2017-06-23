/*
	TITLE		   Signed & Unsigned integers	Chapter25TryThis4.cpp
	COMMENT
		Objective: Inspect the loop with signed char as loop in §25.5.2
				   variable and unsigned char as termination variable. 
				   Why it's infinite?

				   unsigned char max = 160;
				   std::numeric_limits<char>::max() == 127

				   After it reaches 127, i, overflows back to -128
				   and the loop starts again.
				   i never reaches termination value >= 160.
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 10.05.2017
*/
#include <iostream>

void infinite()
{
	unsigned char max = 160;

	for (char i = 0; i < max; ++i)
	{
		std::cout << int(i) <<"\n";
		if (i < 0)
		{
			getchar();
		}
	}
}

//---------------------------------------------------------------------------

int main()
{
	try
	{
		infinite();
		std::cout <<"Done!\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}