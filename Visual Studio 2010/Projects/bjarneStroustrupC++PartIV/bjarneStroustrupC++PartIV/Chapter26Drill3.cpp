/* 
	TITLE		   Generate test sequences				  Chapter26Drill3.cpp
	COMMENT
		Objective: Based on §26.3.2.3, complete a program that generates
				   - a very large sequence 
				   - ten sequences with random number of elements.
				   - ten ordered sequences with: 0, 1, 2,...,9 random elements.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 30.05.2017
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>		// time()

//----------------------------------------------------------------------------

int rand_int(int max) { return rand() % max; }

//----------------------------------------------------------------------------

void make_test(std::ostream& os, const std::string& label,
			   int elements_number, int base, int spread)
{
	os <<"{ "<< label <<" "<< elements_number <<" { ";

	std::vector<int> sequence;
	int element = base;

	for (int i = 0; i < elements_number; ++i)
	{
		element += rand_int(spread); // cumulative frequency? generate "randomness" around base
		sequence.push_back(element);
	}

	int target = base + rand_int(element - base);
	bool found = false;

	for (int i = 0; i < elements_number; ++i)
	{
		if (sequence[i] == target)
		{
			found = true;
		}
		os << sequence[i];

		if (i < elements_number - 1)
		{
			os <<",";
		}
	}

	os <<" } "<< found <<" }\n";
}

//----------------------------------------------------------------------------

void generate_tests(std::ostream& os, const std::string& label,
				    int elements_number, int base, int spread, 
					int no_of_tests)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < no_of_tests; ++i)
	{
		std:: string l = label;
		l += "rand_test_" + std::to_string((unsigned long long)i);

		make_test(os, l, elements_number, base, spread);
	}
}

//----------------------------------------------------------------------------

int main()
{
	try
	{
		std::string label("bsearh_");
		int elem_number = 10;
		int mean = 10;
		int stdev = 5;
		int test_number = 10;

		generate_tests(std::cout, label, elem_number, mean, stdev, test_number); 
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}