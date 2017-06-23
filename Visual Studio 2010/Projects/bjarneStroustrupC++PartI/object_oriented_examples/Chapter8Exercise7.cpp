/*
	TITLE			   Name-age ordered pairs	Chapter8exercise7.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++
	COMMENT
			Objective: Save pair of name and age into two different vectors.
					   Sort the names while keeping the connection with ages.
				Input: Promps the user to enter pairs of name and age separated by whitespace. 
			   Output: Prints vector elements in sorted order.
			   Author: Chris B. Kirov
			     Date: 04.03.2015
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

void calculate();
void populate(std::vector<std::string>&, std::vector<int>&);
void print(const std::vector<std::string>&, const std::vector<int>&);

//=====================================================================================================
int main()
{
	try
	{
		std::cout << "\t\tWelcome to this simple name - age sorting algorithm.\n";
		calculate();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(...)
	{
		std::cerr << "Unknown exception!" << std::endl;
	}
}

//=====================================================================================================

/*
	Function: calculate();

	It reads input pairs and populates 
	two vectors.

	Sorts names and matches ages to the 
	sorted names.

	Prints sorted pairs.
*/
void calculate()
{
	std::vector<std::string> names;
	std::vector<int> ages;

	// read input
	populate(names, ages);

	// print input
	print(names, ages);

	// sort pairs

	// sort names and map the indexes between the ordered and unordered names
	std::vector<std::string> sortedNames(names);
	std::sort(sortedNames.begin(), sortedNames.end());

	// contains the ordered names in terms of indexes of the nameVect  
	std::vector<int> indexMap;

	for(unsigned int i = 0; i < sortedNames.size(); ++i)
	{
		for (unsigned int j = 0; j < names.size(); ++j)
		{
			if (sortedNames[i] == names[j]) 
			{
				indexMap.push_back(j);
				break;
			}
		}
	}

	// use the index mapping to match the ages to the names
	std::vector<int> sortedAges;
	for(size_t i = 0; i < indexMap.size(); ++i)
	{
		sortedAges.push_back(ages[indexMap[i]]);
	}

	// print ordered pairs
	std::cout << "Ordered pairs:\n";
	print(sortedNames, sortedAges); 
}

/*
	Function: populate(names, ages);

	Reads input and populats vectors
	with names and ages.
*/
void populate(std::vector<std::string>& n, std::vector<int>& a)
{
	std::string prompt("Type name followed by age, separated by whitespace; 'q' to exit.\n>>");
	std::string sentinel = "q";

	while (true)
	{
		// read input
		std::cout << prompt;
		std::string input;
		getline(std::cin, input);

		// exit input loop
		if (input == sentinel)
		{
			break;
		}

		std::stringstream ss(input);

		// extract input
		std::string name;
		int age;
		if (ss >> name >> age)
		{
			n.push_back(name);
			a.push_back(age);
		}
		else
		{
			std::cout <<"Wrong input format!\n";
		}
	}
}

/*
	Function: print(container1, container2);

	It prints the elements of the two containers
	in the format (elem1, elem2).
*/
void print(const std::vector<std::string>& n, const std::vector<int>& a)
{
	if (n.size() != a.size())
	{
		std::cerr <<"Different number of names and ages!\n";
		return;
	}

	for (unsigned int i = 0; i < n.size(); ++i)
	{
		 std::cout <<'(' << n[i] << ", " << a[i] << ')' << "\n";
	}
}

