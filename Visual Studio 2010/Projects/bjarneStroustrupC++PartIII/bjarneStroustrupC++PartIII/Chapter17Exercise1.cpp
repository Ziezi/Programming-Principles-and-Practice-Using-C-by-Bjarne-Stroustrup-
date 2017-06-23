/*
	TITLE		    Pointer value 		      Chapter17Exercise1.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: What is the output format of a pionter value.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 02.12.2015
*/
#include <iostream>

// static
int arr[] = { 1, 2, 3 }; 

void f_stack()
{
	int arr [] = { 1, 2, 3 };
	int* ptr = arr;

	std::cout <<"Stack: ptr: "<< ptr <<" *ptr: "<< *ptr <<" &ptr: "<< &ptr <<'\n';
}

//----------------------------------------------------------------------

int main () 
{
	try 
	{
		int* staticPtr = arr;
		std::cout <<"Static: staticPtr: "<< staticPtr <<" *staticPtr: "<< *staticPtr <<" &staticPtr: "<< &staticPtr <<'\n';

		int* heapPtr = new int[3];
		std::cout <<"Static: heapPtr: "<< heapPtr <<" *heapPtr: "<< *heapPtr <<" &heapPtr: "<< &heapPtr <<'\n';

		f_stack();
		getchar();
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	getchar();
}