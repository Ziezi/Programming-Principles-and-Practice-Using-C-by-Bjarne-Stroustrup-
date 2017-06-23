 /* 
	TITLE 		   Sieve of Eratosthenes         Chapter4Exercise13.cpp
	 Bjarne Stroustrup "Programming: Principles and Practice Using C++"
    COMMENT
		Objective: Find prime numbers from 1 to 100 using 
				   the Sieve of Eratosthenes algorithm,
				   based on the exclusion of all composite numbers
				   composed of multiples (< 100) of already found prime
				   numbers (< sqrt(100)). 
			Input: -
		   Output: All the primes from 1 to 100.
		   Author: Chris B. Kirov
			 Date: 5.1 . 2015
*/
#include <iostream>
#include <cmath>

void find_primes(bool[], unsigned int);
void print_primes(bool [], unsigned int);

//=========================================================================
int main() 
{
	const unsigned int max = 100;
	bool sieve[max];
	
	find_primes(sieve, max);

	print_primes(sieve, max);
}
//=========================================================================

/*
	Function: find_primes()
	Use: find_primes(bool_array, size_of_array);

	It returns all the prime numbers till the
	number: size_of_array, in the form of the
	indexes of the array with value: true.

	It implements the Sieve of Eratosthenes,
	consisted of:

	a loop through the first "sqrt(size_of_array)"
	numbers starting from the first prime (2).

	a loop through all the indexes < size_of_array,
	marking the ones satisfying the relation i^2 + n * i
	as false, i.e. composite numbers, where i - known prime 
	number starting from 2.
*/
void find_primes(bool sieve[], unsigned int size)
{
	// by definition 0 and 1 are not prime numbers
	sieve[0] = false;
	sieve[1] = false;

	// all numbers <= max are potential candidates for primes
	for (unsigned int i = 2; i <= size; ++i)
	{
		sieve[i] = true;
 	}

	// loop through the first prime numbers < sqrt(max)  
	unsigned int first_prime = 2;
	for (unsigned int i = first_prime; i <= std::sqrt(double(size)); ++i)
	{
		// find multiples of primes till < max
		if (sieve[i] == true)
		{
			// mark as composite: i^2 + n * i 
			for (unsigned int j = i * i; j <= size; j += i)
			{
				sieve[j] = false;
			}
		}
	}
}

/*
	Function: print_primes()
	Use: print_primes(bool_array, size_of_array);

	It prints all the prime numbers, 
	i.e. the indexes with value: true.
*/
void print_primes(bool sieve[], unsigned int size)
{
	// all the indexes of the array marked as true are primes
	for (unsigned int i = 0; i <= size; ++i)
	{
		if (sieve[i] == true) 
		{
			std::cout << i <<" ";
		}
	}
}