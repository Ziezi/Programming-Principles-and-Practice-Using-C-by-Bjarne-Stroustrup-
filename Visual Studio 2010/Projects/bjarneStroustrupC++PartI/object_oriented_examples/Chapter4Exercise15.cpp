   /* 
	TITLE 		   First n primes               Chapter4Exercise15.cpp
	 Bjarne Stroustrup "Programming: Principles and Practice Using C++"
    COMMENT
		Objective: Find first n prime numbers.
		    Input: Type number of primes to be found.
		   Output: Prints first n primes.
		   Author: Chris B. Kirov
			 Date: 5.1 . 2015
*/
#include <iostream>
#include <vector>
 
void find_primes(std::vector<int>&, unsigned int);
void print_vector(const std::vector<int>&, unsigned int);

//=========================================================================
int main() 
{
	unsigned int number_of_primes;
	std::vector<int> primes;

	std::cout <<"How many prime numbers you want to find:\n>>";
	std::cin >> number_of_primes;

	find_primes(primes, number_of_primes);
	print_vector(primes, 20);
}
//=========================================================================

/*
	Function: is_prime()';
	Use: bool prime = is_prime(vect, n);
	Checks whether n is a prime number.
	If tested number is divisible 
	(without remainder) by one of
	the previous primes, it is not prime. 
*/
bool is_prime(const std::vector<int>& v, int n)
{
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		if (n % v[i] == 0) return false;
	}
	return true;
}

/*
	Function: find_primes()
	Use: find_primes(vector_of_primes, num);

	It finds the first: "num" primes and stores them in
	vector_of_primes.
*/
void find_primes(std::vector<int>& prime_numbers, unsigned int first_n)
{
	// first prime number used as initial criterion
	int first_prime = 2;	
	prime_numbers.push_back(first_prime);
	
	// start searching from number 3
	int lower_bound = 3;
	int number = lower_bound;

	// search till first_n primes are found
	while (prime_numbers.size() <= first_n)													
	{	
		if (is_prime(prime_numbers, number)) 
		{
			prime_numbers.push_back(number);
		}
		++number;
	}
}

/*
	Function: print_vector()
	Use: print_vector(vect, number_per_line)
	It prints all vector elements in a rows
	of "number_per_line".
*/
void print_vector(const std::vector<int>& v, unsigned int number_per_line)
{
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] <<" ";
		
		if (i % number_per_line == 0 && i != 0) 
		{
			std::cout << "\n";
		}
	}
}
