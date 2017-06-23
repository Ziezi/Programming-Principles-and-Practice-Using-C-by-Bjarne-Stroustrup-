 /*
	TITLE			   Find statisics      		        Chapter8Exercise14.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Write a function that returns
			           all the lengths, min and max length,
					   and the lexicographically first and last 
					   of strings stored in a vector.
			    Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 10.03.2015
*/
#include <iostream>
#include <string>
#include <vector>
#include <limits>    // std::numeric_limits<_type_>::max() / min()
#include <algorithm> // sort 

/*
	Class: Statistics

	Data structure holding all the wanted
	statistical data.
*/
class Statistics
{
public:
	 Statistics()
		 :  minLength(""), maxLength(""), firstLexicographically(""), lastLexicographically("") 
	 {
	 
	 }

	 void print() const 
	 {
		std::cout <<"Shortest: "<< minLength <<'\n';
		std::cout <<"Longest: "<< maxLength <<'\n';
		std::cout <<"Lexicographically first: "<< firstLexicographically <<'\n';
		std::cout <<"Lexicographically last: "<< lastLexicographically <<'\n';

		std::cout <<"Lengths of elements:\n";
		for (size_t i = 0; i < lengths.size(); ++i)
		{
			std::cout << lengths[i] <<'\n';
		}
	 }

	 std::string minLength;
	 std::string maxLength;
	 std::string firstLexicographically;
	 std::string lastLexicographically;
	 std::vector<size_t> lengths;
};

void populate(std::vector<std::string>&);
void find_statistics(const std::vector<std::string>&, Statistics&);
std::string findMax(const std::vector<std::string>&);
std::string findMin(const std::vector<std::string>&);

//==================================================================================================
int main()
{
		std::cout << "Find element lengths, min and max length and lexicographically first and last.\n";

		std::vector<std::string> names;
		populate(names);

		Statistics statistics;
		find_statistics(names, statistics);

		statistics.print();
}

//==================================================================================================

/*
	Function: populate(container);

	It runs an input loop populating 
	the container with stings.
*/
void populate(std::vector<std::string>& v)
{
	 std::cout <<"Populate a vector with strings; 'q' to exit.\n";

	 std::string prompt("Type a string:\n>>");
	 std::string sentinel("q");

	 while(true)
	 {
		std::cout << prompt;
		std::string input;
		getline(std::cin, input);

		if (input == sentinel)
		{
			return;
		}

		v.push_back(input);
	 }
}

/*
	Function: find_statistics(container, statistics);

	It finds elements with min, max length,
	and lexicographically first and last element
	stored in object Statistics.
*/
void find_statistics(const std::vector<std::string>& v, Statistics& s)
{
	// find lenghts
	for (size_t i = 0; i < v.size(); ++i)
	{
		s.lengths.push_back(v[i].size());	
	}

	s.minLength = findMin(v);
	s.maxLength = findMax(v);

	std::vector<std::string> temp(v);
	sort(temp.begin(), temp.end());

	s.firstLexicographically = temp[0];
	s.lastLexicographically = temp[temp.size() - 1];
}

/*
	Function: std::string min = findMin(container);

	It returns the shortest element. 
*/
std::string findMin(const std::vector<std::string>& v)
{
	std::string shortest;
	size_t length = std::numeric_limits<size_t>::max();
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (length > v[i].size())
		{
			length = v[i].size();
			shortest = v[i];
		}
	}
	return shortest;
}

/*
	Function:  std::string max = findMax(container);

	It returns the longest element.
*/
std::string findMax(const std::vector<std::string>& v)
{
	std::string longest;
	size_t length = std::numeric_limits<size_t>::min();
	for (size_t i = 0; i < v.size(); ++i)
	{
		 if (length < v[i].size())
		 {
			length = v[i].size();
			longest = v[i];
		 }
	}
	return longest;
}

