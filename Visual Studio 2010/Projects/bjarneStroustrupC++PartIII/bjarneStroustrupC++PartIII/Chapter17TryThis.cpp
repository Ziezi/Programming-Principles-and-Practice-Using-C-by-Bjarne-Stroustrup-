/*
	TITLE		    Try This		           Chapter17TryThis.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Apply sizeof() operator to the fundamental types.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 26.11.2015
*/
#include <iostream>

int main ()
{
	try 
	{
		char a = '0';
		int b = 0;
		int *ptr = 0;

		bool c = 0;
		double d = 0;

		std::cout <<"the size of char: "<< sizeof(char) <<", a: "<< sizeof(a) <<" bytes"<<'\n';
		std::cout <<"the size of int: "<< sizeof(int) <<", b: "<< sizeof(b) <<" "<< sizeof(2+2) <<" bytes"<< '\n';
		std::cout <<"the size of ptr: "<< sizeof(int*) <<", ptr: "<< sizeof(ptr) <<" bytes"<<'\n';
		std::cout <<"the size of bool: "<< sizeof(bool) <<", c: "<< sizeof(c) <<" bytes"<<'\n';
		std::cout <<"the size of double: "<< sizeof(double) <<", d: "<< sizeof(d) <<" bytes"<<'\n';
		getchar();

	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
}