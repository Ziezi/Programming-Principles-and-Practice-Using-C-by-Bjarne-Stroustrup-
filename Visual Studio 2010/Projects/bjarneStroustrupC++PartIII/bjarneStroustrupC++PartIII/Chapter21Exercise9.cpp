/*
	TITLE		    class Purchase & Order   Chapter21Exercise9.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define an Order class with (customer) 
					name, address, data and vector<Purchase>
					members.

					Purchase is a class with (product) name,
					unit prince, and count members.

					Define a mechanism for reading and writing
					to and from file. 

					Define a mechanism for printing orders.

					Create a file of at least 10 orders,
					read it into a vector<Order>, sort it by
					name (of customer), and write it back to
					file.

					Create another file of at least ten Orders,
					of which about the third are the same as in 
					the first file, read into a list<Order>, 
					sort by address of customer and write back
					out to file.

					Mergre the two files into third using std::merge();
				
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 28. 02. 2017
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include "Chapter21Exercise9.h"

int main()
{
	try
	{
		std::vector<Order> v;
		
		std::string file("Chapter21Exercise9v.txt");
		std::ifstream ifs(file.c_str());
		if (!ifs)
		{
			throw std::runtime_error("Can't open input file!\n");
		}

		// Read from file
		Order sale;
		while (ifs >> sale)  
		{
			v.push_back(sale);
			sale = Order();
		}

		for (auto it = v.begin(); it !=	v.end(); ++it)
		{
			std::cout << *it;
		}

		// Sort by name of customer
		std::sort(v.begin(), v.end());

		std::cout <<"SORTED by name of customer\n"; 
		for (auto it = v.begin(); it !=	v.end(); ++it)
		{
			std::cout << *it;
		}

		ifs.close();
		
		std::ofstream ofs(file.c_str(), std::ios_base::trunc);	// write sorted back to file

		for (auto it = v.begin(); it !=	v.end(); ++it)
		{
			ofs << *it;
		}

		std::list<Order> l;

		std::string file2("Chapter21Exercise9l.txt");
		std::ifstream ifs2(file2.c_str());
		if (!ifs2)
		{
			throw std::runtime_error("Can't open input file!\n");
		}

		Order sale2;
		while (ifs2 >> sale2) // read second file  
		{
			l.push_back(sale2);
			sale2 = Order();
		}

		for (auto it = l.begin(); it !=	l.end(); ++it)
		{
			std::cout << *it;
		}
		
		l.sort(Order_Customer_Address());

		std::cout <<"SORTED by address of customer\n"; 
		for (auto it = l.begin(); it !=	l.end(); ++it)
		{
			std::cout << *it;
		}

		ifs2.close();

		std::ofstream ofs2(file2.c_str(), std::ios_base::trunc);	// write sorted back to file
		for (auto it = l.begin(); it !=	l.end(); ++it)
		{
			ofs2 << *it;
		}

		// merge the two files into third
		std::string file3("Chapter21Exercise9m.txt");
		std::ofstream ofs3 (file3.c_str());
		 
		// sort list elements according to same criterion
		std::vector<Order> v2(l.begin(), l.end());
		std::sort(v2.begin(), v2.end());

		// merge 
		std::vector<Order> all(v.size() + v2.size());
		std::merge(v.begin(), v.end(), v2.begin(), v2.end(), all.begin());

		std::cout <<"\nMERGED:\n"; 
		for (auto it = all.begin(); it != all.end(); ++it)
		{
			std::cout << *it;
		}

		for (auto it = all.begin(); it != all.end(); ++it)
		{
			ofs3 << *it;
		}
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}