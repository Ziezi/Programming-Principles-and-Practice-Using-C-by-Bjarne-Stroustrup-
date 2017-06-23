/*
	TITLE			   Generate random number   Chapter8exercise8.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++
	COMMENT
			Objective: Write a finction that generates random numbers.
					   Search at Knuth, 
					   The Art of Computer Programming Volume 2.
					   Page 10, Linear congruential generator.

				Input: Type an upper limit.
			   Output: Prints random numbers.
			   Author: Chris B. Kirov
			     Date: 05.03.2015
*/
#include <iostream>
#include <string>
#include <sstream>

void input_loop();
int randint();

//================================================================================================
int main()
{
	try
	{
		std::cout << "\t\tPseudo-random number generator using Linear Gongruential Method.\n";
		input_loop();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
//================================================================================================
/*
	Function:input_loop();

	It contains brief description, user prompt message,
	calling of the random number generator and printing
	of the result.
*/
void input_loop()
{
	std::string prompt("Random number within [0, MAX], type MAX; 'q' to exit.\n>>");
	std::string sentinel("q");

	while (true)
	{
		std::cout << prompt;  
		std::string input;
		getline(std::cin, input);

		if (input == sentinel)
		{
			break;
		}

		std::stringstream ss(input);

		int upper_limit;
		if (ss >> upper_limit)    // check format validity
		{
			if (upper_limit <= 0) // check value validity
			{
				std::cerr <<"Upper limit must be > 0!\n";
			}
			else 
			{
				std::cout << "A random number within [0," << upper_limit << "] is: " << randint() % upper_limit << "\n";
			}
		}
		else 
		{
			std::cout <<"Wrong input format!\n";
		}
	}
}

/*
	Function: randint();
	Use: int randomNumber = myRandInt(upper_limit);

	It returns a pseudo-random number within
	[0, upper_limit].

	n(x+1) = n(x) * A + C modulo M

	a = 1103515245, c = 12345, m = 2^31 
*/
static unsigned int seed = 1;
void srand(int newseed) 
{
    seed = (unsigned)newseed & 0x7fffffffU;
}

int randint() 
{
    seed = (seed * 1103515245U + 12345U) & 0x7fffffffU;
    return (int)seed;
}




