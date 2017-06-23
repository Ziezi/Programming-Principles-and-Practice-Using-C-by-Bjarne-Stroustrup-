/*
	TITLE		    Built-in type sizes		 Chapter17Exercise2.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: How many bytes are there in int, double, bool? 
					char - unit is measure = 1 byte
		            int - 4 bytes
					double - 8 bytes
					bool - 1 byte
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 02.12.2015
*/
#include <iostream>

struct X
{
	char a;
	std::string b;
};

int main () 
{
	try 
	{
		std::cout << "Size in bytes (or in terms of char):\n"; 
		std::cout <<"char "<< sizeof(char) <<'\n';

		std::cout <<"int "<< sizeof(int) <<'\n';
		std::cout <<"double "<< sizeof(double) <<'\n';
		std::cout <<"bool "<< sizeof(bool) <<'\n';

		std::cout <<"long int "<< sizeof(long int) <<'\n';
		std::cout <<"long double "<< sizeof(long double) <<'\n';

		std::cout <<"unsigned int "<< sizeof(unsigned int) <<'\n';

		std::cout <<"long long "<< sizeof(long long) <<'\n';

		X x;
		std::cout <<"Object size "<< sizeof(x) <<'\n';
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	getchar();
}