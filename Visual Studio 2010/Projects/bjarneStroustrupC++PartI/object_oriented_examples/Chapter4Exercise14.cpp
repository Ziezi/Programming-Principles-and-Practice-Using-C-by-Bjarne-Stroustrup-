  /* 
	TITLE 		   Sieve of Eratosthenes         Chapter4Exercise14.cpp
	 Bjarne Stroustrup "Programming: Principles and Practice Using C++"
    COMMENT
		Objective: Find prime numbers from 1 to max using 
				   the Sieve of Eratosthenes algorithm,
				   based on the exclusion of all composite numbers
				   composed of multiples (< max) of already found prime
				   numbers (< sqrt(max)). 
			Input: -
		   Output: All the primes from 1 to max.
		   Author: Chris B. Kirov
			 Date: 5.1 . 2015
*/
#include <iostream>
#include <vector>
#include <cmath>

void find_primes(std::vector<bool>&);
void print_primes(std::vector<bool>&, int);

//=========================================================================
int main() 
{
	unsigned int max;
	std::cout <<"Find all prime numbers from 1 to:\n>>";
	std::cin >> max;

	std::vector<bool> sieve(max);
	
	find_primes(sieve);

	print_primes(sieve, 50);
}
//=========================================================================

/*
	Function: find_primes()
	Use: find_primes(vector_bool);

	It returns all the prime numbers till the
	number: vector_bool.size(), in the form of the
	indexes of the vector with value: true.

	It implemenets the Sieve of Eratosthenes,
	consisted of:

	a loop through the first "sqrt(vector_bool.size())"
	numbers starting from the first prime (2).

	a loop through all the indexes < vector_bool.size(),
	marking the ones satisfying the relation i^2 + n * i
	as false, i.e. composite numbers, where i - known prime 
	number starting from 2.
*/
void find_primes(std::vector<bool>& sieve)
{
	// by definition 0 and 1 are not prime numbers
	sieve[0] = false;
	sieve[1] = false;

	// all numbers <= max are potential candidates for primes
	for (unsigned int i = 2; i <= sieve.size(); ++i)
	{
		sieve[i] = true;
 	}

	// loop through the first prime numbers < sqrt(max) (suggested by the algorithm)
	unsigned int first_prime = 2;
	for (unsigned int i = first_prime; i <= std::sqrt(double(sieve.size())); ++i)
	{

		// find multiples of primes till < max
		if (sieve[i] = true)
		{
			// mark as composite: i^2 + n * i 
			for (unsigned int j = i * i; j <= sieve.size(); j += i)
			{
				sieve[j] = false;
			}
		}
	}
}

/*
	Function: print_primes()
	Use: print_primes(vector_bool);

	It prints all the prime numbers, 
	i.e. the indexes with value: true.
*/
void print_primes(std::vector<bool>& sieve, int num_per_line)
{
	// all the indexes of the array marked as true are primes
	for (unsigned int i = 0; i <= sieve.size(); ++i)
	{
		if (sieve[i] == true) 
		{
			std::cout << i <<" ";

			if (i % num_per_line == 0 && i != 0) 
			{
				std::cout <<"\n";
			}
		}
	}
}