/*
	TITLE		    Memory exhaustion	     Chapter17Exercise6.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Find a way to "exhaust your machine's memory".

					Expected: Actual limit is the address space of a pointer (32 - bit) -> 2^32 = 4 GB. 
					          + virtual memory?
		     Input: -
			Output: 2.09 GB
			        bad allocation

			Author: Chris B. Kirov
			  Date: 06.12.2015
*/
#include <iostream>

void memory_leak (int memory_size);

//----------------------------------------------------------------------------------------

int main () 
{
	try 
	{ 
		int count = 0;

		while (true)
		{ 
			int chunk = 100000;
			memory_leak(chunk);
			std::cout << count * sizeof(int) / 10000.0 <<" GB"<<'\n';

			++count;
		}
	} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	getchar();
}

//----------------------------------------------------------------------------------------

void memory_leak (int memory_size)
{
	int *leaked_dynamic_memory = new int[memory_size];
}