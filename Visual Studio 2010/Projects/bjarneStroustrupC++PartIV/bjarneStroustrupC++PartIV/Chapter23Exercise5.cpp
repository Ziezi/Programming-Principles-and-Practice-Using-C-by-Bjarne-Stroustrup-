/*
	TITLE		   Multimap vs unordered_multimap     Chapter23Exercise5.cpp
	COMMENT
		Objective: Time multimap vs unordered_multimap.      
			Input: - 
		   Output: sample size & time written in file
				   There are 2 gnuplot scripts ploting the data.
		   Author: Chris B. Kirov
			 Date: 27.04.2017
*/
#include <iostream>
#include <iomanip>			// setw
#include <map>
#include <unordered_map>
#include <time.h>			// clock_t
#include <fstream>			

//--------------------------------------------------------------------------------------

/*
	Implemented as:			binary tree					hash table

	Operations	Complexity	std::map [msec]	Complexity	std::unordered_map [msec]

	insert		O(logN)						O(1)/O(N)
	access		O(logN)						O(1)/O(N)
	erase		O(logN)						O(1)/O(N)
	find		O(logN)						O(1)/O(N)
*/

//--------------------------------------------------------------------------------------

void test_map(int n)
{	
	// Container:	 Operation:
	// Sample:		 Time[msec]: 
	std::map<int,int> m;

	for (int i = 0; i < n; ++i)
	{
		m.insert(std::make_pair(i, i));
	}
}

//--------------------------------------------------------------------------------------

void test_unordered_map(int n)
{
	std::unordered_map<int,int> um;

	for (int i = 0; i < n; ++i)
	{
		um.insert(std::make_pair(i, i));
	}
}

//--------------------------------------------------------------------------------------

int main ()
{
	std::string file_name1("Chapter23Exercise5map.txt");
	std::string file_name2("Chapter23Exercise5unordered_map.txt");
	std::ofstream ofs(file_name2.c_str());
	if(!ofs)
	{
		std::cerr <<"Can't create and output file\n";
	}

	ofs << std::setw(11) <<"#Sample"<< std::setw(23) <<"Time[msec]\n";
	for (int n = 1; n < 10000000; n *=10)
	{
		clock_t start = clock();
		test_map(n);
		//test_unordered_map(n);
		clock_t end = clock();

		double time = (double) (end - start) / CLOCKS_PER_SEC * 1000.0;

		ofs << std::setw(11) << n << std::setw(22) << time <<"\n";
	}

	ofs.close();

	/*
	std::string command("gnuplot -p -e \"load '");
	command += "Chapter23Exercise5unordered_map.p";
	command +="'\"";
	system(command.c_str());
	*/

	std::cout <<"Done!\n";
	getchar();
}
