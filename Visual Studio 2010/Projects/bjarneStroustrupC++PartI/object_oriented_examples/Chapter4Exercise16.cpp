/* 
   TITLE            Mode					    Chapter4Exercise16.cpp
    Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
			Object: Find the mode of a set of positive numbers.
			 Input: -
			Output: Prints the most occuring value(s).
			Author: Chris B. Kirov
			  Data: 01.04.2015
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void find_mode(const std::vector<int>&);
void print_vector(const std::vector<int>&, unsigned int);

//=====================================================================
int main()
{
	std::vector<int> data;
	data.push_back(1);
	data.push_back(1);
	data.push_back(1);
	data.push_back(2);
	data.push_back(3);
	data.push_back(3);
	data.push_back(3);
	
	print_vector(data, 10);

	find_mode(data);

	getchar();
}
//=====================================================================

/*
	Function: find_mode(const std::vector<int>& v)
	Use: find_mode(vec_of_int)

	It finds and prints the element with the
	most frequenly occuring value.
*/
void find_mode(const std::vector<int>& v)
{
	// copy data 
	std::vector<int> temp(v);

	// sort data
	std::sort(temp.begin(), temp.end());
	
	temp.push_back(-1);
	struct Mode {
		int value;
		int freq;

		Mode (int v, int f)
			: value(v), freq(f) { }
	};

	std::vector<Mode> modes;
	int max = 0;
	int frequency = 1;

	// traverse and find the most frequently occuring value
	for (unsigned int i = 0; i < temp.size() - 1; ++i)
	{
		if (temp[i] == temp[i+1])
		{
			++frequency;
		}
		else
		{
			if (frequency > max || frequency == max )
			{
				max = frequency;
				modes.push_back(Mode(temp[i], frequency));
			}

			frequency = 1;
		}	
	}

	// print (multiple) modes 
	max = modes[modes.size() - 1].freq;
    std::cout <<"\nModes: "<< modes.size() <<"\n"; 
	for (unsigned int i = 0; i < modes.size(); ++i)
	{
	    if (modes[i].freq == max)
		{
			std::cout <<"Value: "<< modes[i].value <<" frequency: "<< modes[i].freq <<"\n"; 
		}
	}
}

/*
	Function: print_vector()
	Use: print_vector(vect, number_per_line)
	It prints all vector elements in a rows
	of "number_per_line".
*/
void print_vector(const std::vector<int>& v, unsigned int number_per_line)
{
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] <<" ";
		
		if (i % number_per_line == 0 && i != 0) 
		{
			std::cout << "\n";
		}
	}
}









