 /* 
	TITLE 		   Prime numbers                 Chapter4Exercise12.cpp
	 Bjarne Stroustrup "Programming: Principles and Practice Using C++"
    COMMENT
		Objective: Find prime numbers from 1 to max.
			Input: Prompts the user to type value for max.
		   Output: All the primes from 1 to max.

		   Author: Chris B. Kirov
			 Date: 5.1.2015
*/
#include "../../std_lib_facilities.h"

void find_primes(vector<int>&, int);
bool is_prime(const vector<int>&, int);
void print_vector(const vector<int>&, int);

//=========================================================================
int main()
{
	// first prime number used as initial criterion
	int first_prime = 2;	

	// vector holding the prime numbers
	vector<int>prime_numbers;
	prime_numbers.push_back(first_prime);
	 								
	cout <<"Find all prime numbers till\n>>";
	int max = 0;
	cin >> max;

	find_primes(prime_numbers, max);
	
	cout << "\nThe Prime Numbers within ["<< 1 <<", "<< max <<"] are:\n";
	print_vector(prime_numbers, 5); 

	getchar();
}
//=========================================================================

/*
	Function: find_primes()
	Use: find_primes(max)

	Finds all primes till the
	number max.
*/
void find_primes(vector<int>& v, int max)
{
	int lower_bound = 3;
	int upper_bound = max;
	for (int number = lower_bound ; number <= upper_bound; ++number)													
	{	
		if (is_prime(v, number)) 
		{
			v.push_back(number);
		}
	}
}

/*
	Function: is_prime()';
	Use: bool prime = is_prime(vect, n);

	Checks whether n is a prime number.
	If tested number is divisible 
	(without remainder) by one of
	the previous primes, it is not prime. 
*/
bool is_prime(const vector<int>& v, int n)
{
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		if (n % v[i] == 0) return false;
	}
	return true;
}

/*
	Function: print_vector()
	Use: print_vector(vect, number_per_line)

	It prints all vector elements in a rows
	of "number_per_line".
*/
void print_vector(const vector<int>& v, int number_per_line)
{
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		cout << v[i] <<" ";
		
		if (i % number_per_line == 0 && i != 0) 
		{
			cout << "\n";
		}
	}
}