/*
	TITLE		    Memory layout		     Chapter18Exercise9.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Write a program showing the orders of:
				    - static,
					- stack and
					- heap memory.

					Expectations: 
					Static and Heap memory addresses are allocated in increaing order,
			        while Stack memory addresses are allocated in decreasing order.
					However, the arrays' elements are allocated as consecutive memory locations.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 26.12.2015
*/
#include <iostream>

void stack_f( )
{
	// array on stack
	char stack_arr[3] = {'a', 'b', 'c'};

	// stack memory addresses
	std::cout <<"\nStack memory addresses.\n";
	for (size_t i = 0; i < 3; ++i) std::cout <<"&stack_arr["<< i <<"] "<< reinterpret_cast<void*>(&stack_arr[i]) <<'\n';

	// array on stack
	char stack_arr1[3] = {'c', 'h', 'z'};

	// stack memory addresses
	std::cout <<"\nStack memory addresses1.\n";
	for (size_t i = 0; i < 3; ++i) std::cout <<"&stack_arr["<< i <<"] "<< reinterpret_cast<void*>(&stack_arr1[i]) <<'\n'; 
}
 
//--------------------------------------------------------------------------------------------------------------------------

int main () 
{
	try
	{
		// array on static storage
		static char global_arr[3] = {'a', 'b', 'c'};

		// array on heap
		char *heap_arr = new char[3];
		for (size_t i = 0; i < 3; ++i) heap_arr[i] = 'a' + i;
	
		// Print addresses of the three arrays and compare them

		// static memory addresses
		std::cout <<"Static memory addresses.\n";
		for (size_t i = 0; i < 3; ++i) std::cout <<"&global_arr["<< i <<"] "<< reinterpret_cast<void*>(&global_arr[i]) <<'\n';

		// stack memory addresses
		stack_f( );

		// heap memory addresses
		std::cout <<"\nHeap memory addresses.\n";
		for (size_t i = 0; i < 3; ++i) std::cout <<"&heap_arr["<< i <<"] "<< reinterpret_cast<void*>(&heap_arr[i]) <<'\n';

		delete [] heap_arr;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	catch(...)
	{
		std::cerr << "Unhandled exception!\n";
	}
	getchar();
}
