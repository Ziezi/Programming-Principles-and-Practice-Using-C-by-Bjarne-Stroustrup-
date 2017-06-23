/* 
	TITLE		   Random floating point numbers sorting   Chapter26Exercise12.cpp
	COMMENT
		Objective: Write a program that generates random floating-point numbers
				   and sorts them using std::sort. 
				   Measure the time used to sort 500,000 doubles and 5,000,000 doubles.  
			Input: -
		   Output: Size: 500.000	Time: 1.15
				   Size: 5.000.000	Time: 9.43
		   Author: Chris B. Kirov
			 Date: 08.06.2017
*/
#include <iostream>
#include <algorithm>	// std::generate, std::copy
#include <string>
#include <vector>
#include <iterator>
#include <ctime>		// std::time
#include <time.h>		// std::clock

double random_double (double min, double max) 
{ 
	return min + static_cast<double>(rand()) / static_cast<double>(RAND_MAX / (max - min)); 
}

//---------------------------------------------------------------------------------------
 
double our_random()
{
	return random_double (-10, 10); 
	// return random_double (-100, 100); 
	// return random_double (-1000, 1000); 
	// return random_double (-500, 100);
}

//---------------------------------------------------------------------------------------

void populate_vector(std::vector<double>& v)
{
	std::generate(v.data(), v.data() + v.size(), our_random); 
}

//---------------------------------------------------------------------------------------

void test_sort()
{
	int max = 5000000;
	for (auto i = 500000; i <= max; i *= 10)
	{
		std::vector<double> v(i);
		populate_vector(v);

		std::clock_t t = clock();

		std::sort(v.begin(), v.end());

		t = clock() - t;

		double time = double(t) / CLOCKS_PER_SEC;

		std::cout <<"Size: "<< v.size() <<"\tTime: "<< time <<'\n';
	}
}

//---------------------------------------------------------------------------------------

int main()
{
	try
	{
		test_sort();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}