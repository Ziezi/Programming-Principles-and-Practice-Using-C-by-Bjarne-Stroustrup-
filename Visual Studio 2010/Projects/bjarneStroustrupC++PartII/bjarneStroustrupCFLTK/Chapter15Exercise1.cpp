/*
	TITLE		   Iterative factorial			  Chapter15Exercise1.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Implement an iterative factorial function. 
		           Compare it to recursive, comment complexity? 
				   Can't measure execution time precise enough :(

		    Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>
#include <ctime>

long fac (long n) { return n > 1 ? n * fac(n - 1) : 1; }

long fac_iter (long n)
{
	int res = 1;

	if (n <= 1)
	{
		return res;
	}
	else
	{
		while (n > 1)
		{
			res *= n;
			--n;
		}

		return res;
	}

}
//---------------------------------------------------------------------------

int main( )
{
	try
	{
		int n = 16;

		clock_t begin1 = clock();
		std::cout <<"Fact of "<< n << " = " << fac(n) <<'\n';
		clock_t end1 = clock();

		double diff1 = double(end1 - begin1) / CLOCKS_PER_SEC;
		std::cout <<"Recursive factorial: t = "<< diff1 <<'\n';


		clock_t begin2 = clock();
		std::cout <<"Fact of "<< n << " = " << fac_iter(n) <<'\n';
		clock_t end2 = clock();

		double diff2 = double(end2 - begin2) / CLOCKS_PER_SEC;
		std::cout <<"Iterative factorial: t = "<< diff2 <<'\n';

		getchar();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() <<'\n';
		getchar();
	}
}