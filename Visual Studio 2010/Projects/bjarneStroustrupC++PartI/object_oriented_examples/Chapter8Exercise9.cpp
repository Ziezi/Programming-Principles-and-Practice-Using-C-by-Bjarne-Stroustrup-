 /*
	TITLE			   Generate random number   Chapter8exercise9.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++
	COMMENT
			Objective: Write a finction that generates random numbers
					   within [min, max].

				Input: Type a lower and upper limit.
			   Output: Prints random numbers.
			   Author: Chris B. Kirov
			     Date: 05.03.2015
*/
#include <iostream>
#include <string>
#include <sstream>

void input_loop();
int rand_in_range(int, int);
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
	std::string prompt("Random number within [MIN, MAX], type MIN MAX; 'q' to exit.\n>>");
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

		int lower_limit, upper_limit;
		if (ss >> lower_limit >> upper_limit)    // check format validity
		{
			if (upper_limit <= 0) // check value validity
			{
				std::cerr <<"Upper limit must be > 0!\n";
			}
			else 
			{
				std::cout <<"A random number within ["<< lower_limit <<","<< upper_limit <<"] is: "<< rand_in_range(lower_limit, upper_limit)  <<"\n";
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

/*
	Function: int psrandom = rand_in_range(lower_limit, upper_limit);

	Returns a pseudo-random number within [lower_limit, upper_limit].
*/
int rand_in_range(int lower_limit, int upper_limit)
{
	int range_of_values = upper_limit - lower_limit;

	int pseudo_random = randint() % range_of_values + lower_limit;

	return pseudo_random;
}



