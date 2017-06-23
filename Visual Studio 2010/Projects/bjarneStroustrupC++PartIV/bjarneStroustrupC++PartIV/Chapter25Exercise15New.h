/*
	TITLE		   new[] vs pool vs stack     	       Chapter25Exercise15New.h
	COMMENT
		Objective: Measure the time it takes to de / allocate 10000 objects 
				   of random sizes in [10000:0) - byte range.
				   Do this twice:
				   a). Deallocate in reverse order.
				   b). Deallocate in random order.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 27.05.2017
*/
#ifndef Chapter25Exercise15New_h
#define Chapter25Exercise15New_h

void time_test_new_seq(std::size_t number)
{
	std::vector<Test_Object*> obj_arr(number + 1);

	// allocate
	for (std::size_t allocations = 0; allocations <= number; ++allocations)
	{
		obj_arr[allocations] = new Test_Object;
	}

	// deallocate in reverse order
	for (std::size_t allocations = number; allocations-- > 0;)
	{
		delete obj_arr[allocations];
	}
}

//----------------------------------------------------------------------------

void time_test_new_rand(std::size_t number)
{
	std::vector<Test_Object*> obj_arr(number + 1);

	std::vector<std::size_t> indexes(number + 1);
	std::iota(indexes.begin(), indexes.end(), 0);
	std::random_shuffle(indexes.begin(), indexes.end());

	// allocate
	for (std::size_t allocations = 0; allocations <= number; ++allocations)
	{
		obj_arr[allocations] = new Test_Object;
	}

	// deallocate in random order
	for (std::size_t allocations = number; allocations-- > 0;)
	{
		delete obj_arr[indexes[allocations]];
	}
}

//----------------------------------------------------------------------------

void New_run_time_test()
{
	std::vector<Measurement> data; 

	for (std::size_t number = 20000; number <= 200000; number += 20000) // memory block number 
	{
		std::clock_t start = std::clock();

		time_test_new_seq(number);
			
		double time = 1000.0 * (std::clock() - start) / CLOCKS_PER_SEC;	// find CPU execution time

		data.emplace_back(Measurement(number, time));
	}

	std::string name("Chapter25Exercise15PoolSize");					// add R for random
	name += std::to_string((unsigned long long)BLOCK_SIZE) + ".txt";
	write_to_file(name, data);
}

#endif