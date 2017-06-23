 /* 
	TITLE 		   Prime numbers           Chapter4Exercise11.cpp
	 Bjarne Stroustrup "Programming: Principles and Practice Using C++"
    COMMENT
		Objective: Find prime numbers from 1 to 100.
			Input: -
		   Output: 2 3 5 7 11 13                                                                                                                                                       
				   17 19 23 29 31                                                                                                                                                      
				   37 41 43 47 53                                                                                                                                                      
				   59 61 67 71 73                                                                                                                                                      
				   79 83 89 97 

		   Author: Chris B. Kirov
			 Date: 5.1 . 2015
*/
#include "../../std_lib_facilities.h"

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
	 									
	
	int lower_bound = 3;
	int upper_bound = 100;
	for (int number = lower_bound ; number <= upper_bound; ++number)													
	{	
		if (is_prime(prime_numbers, number)) 
		{
			prime_numbers.push_back(number);
		}
	}

	cout << "\nThe Prime Numbers within ["<< lower_bound <<", "<< upper_bound <<"] are:\n";
	print_vector(prime_numbers, 5); 

	getchar();
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