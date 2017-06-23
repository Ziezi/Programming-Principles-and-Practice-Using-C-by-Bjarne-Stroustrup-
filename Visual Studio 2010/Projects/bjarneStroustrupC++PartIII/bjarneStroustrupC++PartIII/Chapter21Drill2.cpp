/*
	TITLE			Map use 	 				Chapter21Drill2.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: After each line print the container.
					1. Define a std::map<std::string, int> msi.
					2. Insert 10 (name, value) pairs into it.
					3. Output the pairs in any wanted format.
					4. Erase the pairs from msi.
					5. Write a function that reads pairs from std::cin and places them into msi.
					6. Read 10 pairs from input to msi.
					7. Write msi to output.
					8. Output the sum of integer values of msi.
					9. Define map<int, string> called mis.
					10. Enter the values from msi to mis. Note: pairs are reversed.
					11. Print mis to std::cout.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 26. 02. 2017
*/
#include <iostream>
#include <sstream>
#include <string> 
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

//--------------------------------------------------------------------

void initialize_map(std::map<std::string, int> & m)
{
	m["Chris"] = 31;
	m["Juli"] = 63;
	m["Pesho"] = 25;
	m["Gosho"] = 19;
	m["Ivan"] = 28;
	m["Anton"] = 45;
	m["Vasil"] = 44;
	m["Veso"] = 29;
	m["Marto"] = 33;
	m["Asen"] = 66;
}

//--------------------------------------------------------------------

template <class Container>
void print(Container& c)
{
	std::cout <<'\n';
	for (auto i = c.begin(); i != c.end(); ++i)
	{
		std::cout << i->first <<" "<< i->second <<'\n';
	}
	std::cout <<'\n';
}

//--------------------------------------------------------------------

void populate_map(std::map<std::string, int>& m, std::istream& is)
{
	std::string sentinel = "exit";

	while (true)
	{
		std::cout <<"Type: name and age; ""exit"" to quit:\n";
		std::string input;
		getline(is, input);

		if (input == sentinel)
		{
			break;
		}

		std::stringstream ss(input);
		std::string n;
		int a;

		if (ss >> n >> a)
		{
			m[n] = a;
		}
		else
		{
			std::cerr <<"Wrong format! Try again: name, age.\n";
		}
	}
}

//--------------------------------------------------------------------

template <class T>
struct Add_Map 
{
	T operator() (T v, const std::pair<std::string, T>& p)
	{
		return v + p.second;
	}
		
};
//--------------------------------------------------------------------

int main()
{
	try
	{
		// 1.
		std::map<std::string, int> msi;	 

		// 2.
		initialize_map(msi);

		// 3.
		print(msi);

		// 8.
		int total = std::accumulate(msi.begin(), msi.end(), 0, Add_Map<int>());
		std::cout <<"Pairs sum: "<< total <<'\n';

		// 4.
		msi.clear();
		initialize_map(msi);

		// 5.
		// populate_map(msi, std::cin);
		print(msi);

		// 9. 
		std::map<int, std::string> mis;

		// 10.
		for (auto i = msi.begin(); i != msi.end(); ++i)
		{
			mis[i->second] = i->first; 
		}

		// 11.
		print(mis);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}