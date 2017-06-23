/*
	TITLE			Iostream Iterators 	 	  Chapter21TryThis6.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Get the program from §21.7.2 to run and test with
					small files of few hundred words. 
					Try (the not recommended) guessing of the input size,
					potentially leading to buffer overflow.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 26. 02. 2017
*/
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
 
//--------------------------------------------------------------------

 

int main()
{
	try
	{
		 std::string from("Chapter21TryThis6From.txt"), to("Chapter21TryThis6To.txt");

		 std::ifstream ifs(from.c_str());
		 std::ofstream ofs(to.c_str());

		 if (!ifs || !ofs)
		 {
			throw std::runtime_error("Can't open input/output file!\n");
		 }

		 std::istream_iterator<std::string> ii(ifs);
		 std::istream_iterator<std::string> eos;			// default constructor as end-of-stream iterator
		 std::ostream_iterator<std::string> oo(ofs, "\n");  // use newline as delimiter to separate each word

		 /*
		 std::vector<std::string> b(50);					// buffer overflow as size 50 and words > 100	
		 std::copy(ii, eos, b.begin());
		 */
		 std::vector<std::string> b(ii, eos);				// initialize vector from file using iterators

		 std::sort(b.begin(), b.end());

		 std::copy(b.begin(), b.end(), oo);					// write vectir to output file using iterators
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}