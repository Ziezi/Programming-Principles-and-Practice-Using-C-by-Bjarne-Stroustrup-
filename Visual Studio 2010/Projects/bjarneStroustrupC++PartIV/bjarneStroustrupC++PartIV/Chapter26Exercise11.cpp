/* 
	TITLE		   Matrix addition complexity and efficiency   Chapter26Exercise11.cpp
	COMMENT
		Objective: Time the sum example from §26.6 with m being square matrices 
				   with dimensions 100, 10.000, 1.000.000, and 10.000.000.
				   Use random element values in the range [-10: 10). 
				   Rewrite the calculation of v to use a more efficient 
				   (not O(n^2)) algorithm and compare the timings.  

				   Naive approach:
				   Size: 100. Time: 0.07 [s]. Sum = 0.97
				   Size: 10000. Time: 44.22 [s]. Sum = 25571.90
				   Abort: Invalid allocation size 65000 GB (1x10e12 double).

				   Summed area table:
				   Size: 100. Time: 0 [s]. Sum = 0.97
				   bad allocation

				   Naive: O(n^2), SAT: O(1) (Preprocessing + twice the memory)
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 08.06.2017
*/
#include <iostream>
#include <fstream>
#include <algorithm>	// std::generate, std::copy
#include <ctime>		// std::time
#include <time.h>		// std::clock
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>
#include "Matrix.h"
#include "MatrixIO.h"

#include "Chapter26Exercise11.h"
 
int main()
{
	try
	{
		 std::string file("Chapter26Exercise11Complexity.txt");
		 std::ofstream ofs(file.c_str(), std::ofstream::binary);

		 if (!ofs)
		 {
			throw std::runtime_error("Can't open file!\n");
		 }

		 std::vector<Measurement> data;

		 test_sum(data);

		 write_to_file(ofs, data);
	} 
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}
