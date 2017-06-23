/*
	TITLE		    Heap and stack addresses  Chapter17Exercise9.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Write a program that determines address order 
					in memory allocation in the heap, the stack (and static).
		     Input: -
			Output: -
			        addresses on stack grow down (to lower addresses),
					i.e. from large addresses to small addresses
					and addresses on heap grow up,
					i.e. from small to large addresses. 
			Author: Chris B. Kirov
			  Date: 07.12.2015
*/
#include <iostream>


void stack_address_order();

//------------------------------------------------------------------

int main () 
{
	try 
	{
		static int a[1], b[1];
		std::cout <<"Static address allocation order: \n";
		std::cout <<"First element address: "<< &a <<'\n';
		std::cout <<"Second element address:"<< &b <<'\n';

		stack_address_order();

		int *arr1 = new int[1];
		int *arr2 = new int [1];

		std::cout <<"\nHeap address allocation order: \n";
		std::cout << "First element address: "<< arr1 <<'\n';
		std::cout << "Second element address:"<< arr2 <<'\n';
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	getchar();
}

//------------------------------------------------------------------

void stack_address_order() 
{
	int elem_1 = 1;
	int elem_2 = 2;
	 
	std::cout <<"\nStack address allocation order: \n";
	std::cout <<"First element address: "<< &elem_1 <<'\n';
	std::cout <<"Second element address:"<< &elem_2 <<'\n';
}

 