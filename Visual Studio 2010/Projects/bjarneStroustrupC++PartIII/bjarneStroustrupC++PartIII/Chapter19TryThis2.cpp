/*
	TITLE		    Exceptions & Resource Management  Chapter19TryThis2.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Add try-blocks to ensure that all resources are 
		            properly released in all cases where an exception
					might be thrown.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 18.1.2016
*/
#include <iostream>
#include <vector>

void suspicous (std::vector<int>& v, int x);

//------------------------------------------------------------------------------------------------

int main ()
{
	  std::vector<int> v;

	  // n = 1 is 4 bytes, n = 10 => 40 bytes
	  int n = 1;

	  // run while possible to allocate
	  while (true) 
	  {
       
        if (n % 1000000 == 0) std::cout << "4 x "<< n / 1000000 <<" MB allocated.\n";
		else if (n % 1000000000 == 0) std::cout << "4 x "<< n / 1000000000 <<" GB allocated.\n";
		else std::cout << "4 x "<< n <<" bytes allocated.\n"; 

		// allocate n number of intergers
		suspicous (v, n);

		// increase n 
		n *= 10;
	  }
	  getchar();
}

//------------------------------------------------------------------------------------------------

void suspicous (std::vector<int>& v, int s) 
{
	int *p = nullptr;
	int *q = nullptr;

	// check if allocations successfull
	try
	{
		p = new int[s];
		std::cout << "allocated\n";
	} 
	catch (std::bad_alloc& e) 
	{
		std::cerr << e.what() <<"\nCan't allocate: "<< s <<" ints!\n";
	}

	std::vector<int> v1;

	// check if allocations successfull
	try 
	{
		q = new int[s];
		std::cout << "allocated again\n";
	} 
	catch (std::bad_alloc& e)
	{
		std::cerr << e.what() <<"\nCan't allocate another: "<< s <<" ints!\n";
	}
	
	std::vector<double> v2;

	if (p) 
	{
		std::cout << "ints deallocated\n";
		delete[] p;
	} 

	if (q)
	{
		std::cout << "ints deallocated again\n";
		delete[] q;
	}
}