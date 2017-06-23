  /* 
  TITLE                Find Names & Score 	  Chapter4Exercise21.cpp
  Bjarne Stroustrup "Programming: Principles and Practice Using C++"
  COMMENT
			Objective: Store and find unique names and scores. 
				Input: Name followed by its score. 
				       (Input termination: "No more")

					   search score
			   Output: Print all entered names and scores pairs.

					   found names
			   Author: Chris B. Kirov
			     Data: 01.04.2015
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>


void create_list(std::vector<std::string>&, std::vector<int>&);
bool all_unique(const std::vector<std::string>&);
void print_vector(const std::vector<std::string>&, const std::vector<int>&);
void find_name(const std::vector<std::string>&, const std::vector<int>&, int);

//==============================================================================
int main(){
	std::vector<std::string> names;
	std::vector<int> scores; 
	
	create_list(names, scores);

	int score;
	std::cout <<"Type a score and find names with it: \n>>";
	std::cin >> score;

	find_name(names, scores, score);

	getchar();
}

//==============================================================================

void find_name(const std::vector<std::string>& names, const std::vector<int>& scores, int score)
{
	static bool found = false;
	for (size_t i = 0; i < scores.size(); ++i)
	{
		if (score == scores[i])
		{
			std::cout <<"name: "<< names[i] <<"\n";	
			found = true;
		}
	}

	if (!found)
	{
		std::cout <<"Score not found!\n";
	}

	getchar();
}

void create_list(std::vector<std::string>& names, std::vector<int>& scores)
{
	std::string prompt = "Please type a name, followed by score:\n>>"; 
	std::string sentinel = "No more";
	std::string line;

	// input loop
	std::cout << prompt;
	while (getline(std::cin, line) && line != sentinel)
	{
		std::stringstream ss(line);

		std::string name;
		int score = 0;

		// check input format
		if (ss >> name >> score)
		{
			names.push_back(name);
			scores.push_back(score);
		}
		else 
		{
			std::cout <<"Wrong input format!\n";
		}

		std::cout << prompt;
	}

	// check if all names unique and print
	if (all_unique(names))
	{
		 print_vector(names, scores);
	}
	else 
	{
		std::cout <<"Name occuring more than once!\n";
	}
}

bool all_unique(const std::vector<std::string>& v)
{
	std::vector<std::string> temp(v);

	sort(temp.begin(), temp.end());

	for (size_t i = 0; i < temp.size() - 1; ++i)
	{
		if (temp[i] == temp[i+1])
		{
			return false;
		}
	}
	return true;
}

/*
	Function: print_vector()
	Use: print_vector(vect, number_per_line)
	It prints all vector elements in a rows
	of "number_per_line".
*/
void print_vector(const std::vector<std::string>& v, const std::vector<int>& n)
{
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] <<" "<< n[i] <<'\n';
	}
}