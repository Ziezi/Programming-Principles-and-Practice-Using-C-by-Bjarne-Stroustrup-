/*
	TITLE			Vector use 	 				Chapter21Drill3.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: 1. Read at least 16 floating point values from a 
					   file into vector<double> vd.
					2. Output vd to std::cout.
					3. Make a vector vi of type vector<int> with the
					   same number of elements as vd; copy the elements
					   vd to vi.
					4. Output the pairs (vd[i], vi[i]), one pair per line.
					5. Output the sum of the elements of vd.
					6. Output the difference betweem the sum of the elements 
					   of vd and vi.
					7. Reverse and print vd.
					8. Compute and output the mean value of vd.
					9. Make a new vector<double> - vd2 and copy all the values
					   from vd that are less than the mean.
					10. Sort vd and output it.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 26. 02. 2017
*/
#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <numeric>
#include <algorithm>

//--------------------------------------------------------------------

void initialize_vector(std::vector<double>& v)
{
	std::string name("Chapter21Drill3InitializeVector.txt");
	std::ifstream ifs(name.c_str());

	if (!ifs) 
	{
		throw std::runtime_error("Can't open input file!\n");
	}

	double input;
	while (ifs >> input)
	{
		v.push_back(input);
	}

	std::cout <<"Populated with: "<< v.size() <<" elements.\n";
}

//--------------------------------------------------------------------

void print(std::vector<double>& v)
{
	std::cout <<"\n";
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		std::cout << *i <<" ";
	}
	std::cout <<"\n";
}

//--------------------------------------------------------------------

struct Less_than_mean
{
	Less_than_mean (double m) : mean(m) { }
	bool operator() (double x) { return x < mean; }

	double mean;
};

//--------------------------------------------------------------------

int main()
{
	try
	{
		// 1.
		std::vector<double> vd;
		initialize_vector(vd);

		// 2.
		print(vd);

		// 3. 
		std::vector<int> vi(vd.size());

		std::copy(vd.begin(), vd.end(), vi.begin());

		// 4.
		for (auto i = 0; i < vd.size(); ++i)
		{
			std::cout <<"(" << vd[i] <<", "<< vi[i] <<")\n";
		}

		// 5.
		double total = std::accumulate(vd.begin(), vd.end(), 0.0, std::plus<double>());
		std::cout <<"\nTotal: "<< total;

		// 6. 
		int total_int = std::accumulate(vi.begin(), vi.end(), 0, std::plus<int>());
		std::cout <<"\nDifference: Sum(vd[i]) - Sum(vi[i]) = "<< total - total_int;

		// 7. 
		std::reverse(vd.begin(), vd.end());
		print(vd);

		// 8.
		double mean = total / vd.size();
		std::cout <<"\nMean(vd[i]) = "<< mean;

		// 9.
		std::vector<double> vd2(vd.size());
		std::copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than_mean(mean));
		print(vd2);

		// 10.
		std::sort(vd.begin(), vd.end());
		print(vd);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}