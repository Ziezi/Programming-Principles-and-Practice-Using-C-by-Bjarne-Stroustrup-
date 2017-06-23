/*
	TITLE		   new[] vs pool vs stack     	    Chapter25Exercise15.cpp
	COMMENT
		Objective: Measure the time it takes to de / allocate 10000 objects 
				   of random sizes in [10000:0) - byte range.
				   Do this twice:
				   a). Deallocate in reverse order.
				   b). Deallocate in random order.

				   Selected range:
				   bytes: 100, 1000, 10000, 100000, 1000000
				   number of allocations: 20000, 40000, 60k, 80k, 100k, 120k,...,200k

				   Done:
				   - new tested for sizes: 100, 1000 in both reverse and random deallocations.

				   Issues:
				   - can't vary dynamically the size of Test_Object: separate measurement for each size.
				   - not sure if times correct due to compiler optimizations.
				   - not sure it the method of measuring time performance is right.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 27.05.2017
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>					// std::clock_t
#include <numeric>					// std::iota
#include <algorithm>				// std::random_shuffle
#include <limits>					// max()

#define BLOCK_SIZE 100			    // Test_Object size and postfix in file name
#define NUMBER 20000				// Number of memory blocks in Stack and Pool

struct Measurement
{
	Measurement(std::size_t n, double t)
		: blocks_number(n), cpu_time(t)
	{
	
	}

	std::size_t blocks_number;
	double cpu_time;
};

class Test_Object
{
	char data[BLOCK_SIZE];
};

void write_to_file(const std::string& name, std::vector<Measurement>& data)
{
	std::ofstream ofs(name.c_str(), std::ios_base::app); // create new or append to existing
	if (!ofs)
	{
		throw std::runtime_error("write_to_file::can't open output file!\n");
	}

	ofs <<"Block Number\t time[ms]\n";
	for (std::size_t i = 0; i < data.size(); ++i)
	{
		ofs << data[i].blocks_number <<"\t"<< data[i].cpu_time <<'\n';
	}
}
 
#include "Chapter25Exercise15Stack.h"
#include "Chapter25Exercise15Pool.h"
#include "Chapter25Exercise15New.h"

//----------------------------------------------------------------------------

int main ()
{
	try
	{
		// test_stack();		// test functionality of Stack
		// test_pool();			// test functionality of Pool

		// New_run_time_test();			// test performance of new
		// Stack_run_time_test();		// test performance of Stack
		Pool_run_time_test();			// test performance of Pool
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	getchar();
}

