/*
	TITLE		    Arrays                     Chapter18TryDriil1.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Drill 1 : arrays part.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 23.12.2015
*/
#include <iostream>

// 1. Define a global int array of ten ints initialized to 1,2 ,4, 8, etc
int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

// 2. Define a function f(), taking an int array argument and array size argument.
void f (int a[], int size);

int factorial (unsigned int i);

//--------------------------------------------------------------------------------

int main () 
{
	try
	{
		// 4. In main:

		// a. call f with ga as its argument
		size_t size_ga = sizeof(ga) / sizeof(int);
		f(ga, size_ga);
		
		// b. define an array, aa, with ten elements and initialize it with the first ten factorial values 
		const size_t aa_size = 10;
		int aa[aa_size];

		for (auto i = 0; i < aa_size; ++i)
		{
			aa[i] = factorial(i);
		}
		
		// c. call f() with aa as its argument
		size_t size_aa = sizeof(aa) / sizeof(int);
		f(aa, size_aa);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	catch (...)
	{
		std::cerr << "Unhandled exception!\n";
	}
	getchar();
}

//--------------------------------------------------------------------------------

// 3. In f() define:
void f (int a[], int size)
{
	// a. a local int array of ten ints
	int la[10];

	// b. copy the values from ga into la
	for (auto i = 0; i < size; ++i) 
	{
		la[i] = ga[i];
	}

	// c. print out the elements of la
	for (auto i = 0; i < size; ++i) 
	{
		std::cout << la[i] <<" ";
	}
	std::cout << "\n";

	// d. define a pointer to int and initialized it with an array on free store with size: a_size
	int *p = new int[size];

	// e. copy the values of the argument array into the free-store array
	for (auto i = 0; i < size; ++i) 
	{
		p[i] = a[i];
	}

	// f. print out the elements of the free-store array
	for (auto i = 0; i < size; ++i) 
	{
		std::cout << p[i] <<" "; 
	}
	std::cout << "\n";

	// g. deallocate the free-store array
	delete[] p;
}

//--------------------------------------------------------------------------------

int factorial (unsigned int i) 
{
	if (i <= 1) 
	{
		return 1;
	}

	return i * factorial(--i);
}