/*
	TITLE		   Find primary numbers		PrimalityTestNoFactorization.cpp
	COMMENT
		Objective: Find prime numbers without using
		           explicit factorization.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 1.03.2016
*/
#include <iostream>
#include <cmath>

bool isPrime(double, int);

//==============================================================================
int main()
{
	for (int constant = 1; constant <= 10; ++constant)
	{
		std::cout <<"Constant: "<< constant <<"\n";
		for (int i = 1; i < 100; ++i)
		{
			if (isPrime(constant, i))
			{
				std::cout <<"Prime: "<< i <<"\n";
			}
			std::cout << i <<"\n";
		}
		getchar();
	}
}
//==============================================================================

/*
	Function: isPrimary(int testNumber);

	It performs a quick test on the parameter
	an returns whether it is a prime or not.
	If p - primary and a < p, then:

	a^(p - 1) % p == 1

	However it finds primes up to a specific
	upper bound, possibly depending from the 
	"constant".

	Maximum primes found for constant = 2.
*/
bool isPrime(double constant, int testNumber)
{
	int a = pow(constant, testNumber - 1);
	if (a % testNumber == 1)
	{
		return true;
	}
	return false;
}