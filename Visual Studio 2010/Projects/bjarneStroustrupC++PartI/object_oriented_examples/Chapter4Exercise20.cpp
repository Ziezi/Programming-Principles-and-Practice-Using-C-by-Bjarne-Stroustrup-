 /* 
  TITLE                Find Names & Score 	  Chapter4Exercise20.cpp
  Bjarne Stroustrup "Programming: Principles and Practice Using C++"
  COMMENT
			Objective: Store and find unique names and scores. 
				Input: Name followed by its score. 
				       (Input termination: "No more")

					   search name
			   Output: Print all entered names and scores pairs.

					   found score
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
void find_score(const std::vector<std::string>&, const std::vector<int>&, const std::string&);

//==============================================================================
int main(){
	std::vector<std::string> names;
	std::vector<int> scores; 
	
	create_list(names, scores);

	std::string name;
	std::cout <<"Type a name and find its score: \n>>";
	std::cin >> name;

	find_score(names, scores, name);

	getchar();
}

//==============================================================================

void find_score(const std::vector<std::string>& names, const std::vector<int>& scores, const std::string& name)
{
	for (size_t i = 0; i < names.size(); ++i)
	{
		if (name == names[i])
		{
			std::cout <<"score: "<< scores[i] <<"\n";	

			getchar();
			return;
		}
	}
	std::cout <<"No such name!\n";

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