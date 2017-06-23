/*
	TITLE		    Compare vector and list Chapter20Exercise20.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Generate N random int numbers in the range [0, N).
					As each int is generated insert it into a vector<int>.
					Keep the vector sorted; that is, a value is inserted
					after every previous value that is less than or equal
					to the new value and before every value that is larger
					than the new value; do the same for the list. 
					Explain result. (§26.6.1 explains how to time a program.) 

					Results for 10.000 elements
					list: 34.67
					vector: 39.15

		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 24. 02. 2017
*/
#include <iostream>
#include <vector>
#include <list>	
#include <random>
#include <ctime>

void vect(int a, std::vector<int>& v)
{
	std::vector<int>::iterator it = v.begin();

    while (it != v.end() && *it <= a)
	{
		++it;
	}
    v.insert(it, a);
}

//--------------------------------------------------------------------------------------

void test_vector()
{
	std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator

	int iterations = 10000;

	std::uniform_int_distribution<> distr(0, iterations); // define the range

	std::vector<int> v;
	 
	clock_t start_v = clock();
	if (start_v == clock_t(-1))
	{
		throw std::runtime_error("No clock!");
	}

	for (int i = 0; i < iterations; ++i)
	{
		vect(distr(eng), v);
	}

	clock_t end_v = clock();
	if (end_v == clock_t(-1))
	{
		throw std::runtime_error("No clock!");
	}

	std::cout << "\nVector::sort via insert and iterator: " << iterations << " times took: "
			  << double(end_v - start_v) / CLOCKS_PER_SEC << " seconds"
			  <<"\n(measurement granularity: " << CLOCKS_PER_SEC << " of a second)\n";
}

//--------------------------------------------------------------------------------------

void lis(int a, std::list<int>& l)
{
	std::list<int>::iterator it = l.begin();

    while (it != l.end() && *it <= a)
	{
		++it;
	}
    l.insert(it, a);
}

//--------------------------------------------------------------------------------------

void test_list()
{
	std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator

	int iterations = 10000;

	std::uniform_int_distribution<> distr(0, iterations); // define the range

	std::list<int> v;

	clock_t start_v = clock();
	if (start_v == clock_t(-1))
	{
		throw std::runtime_error("No clock!");
	}

	for (int i = 0; i < iterations; ++i)
	{
		lis(distr(eng), v);
	}

	clock_t end_v = clock();
	if (end_v == clock_t(-1))
	{
		throw std::runtime_error("No clock!");
	}

	std::cout << "\nList::sort via insert and iterator: " << iterations << " times took: "
			  << double(end_v - start_v) / CLOCKS_PER_SEC << " seconds"
			  <<"\n(measurement granularity: " << CLOCKS_PER_SEC << " of a second)\n";
}

//--------------------------------------------------------------------------------------

int main()
{
	try
	{
		test_list();
		test_vector();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}