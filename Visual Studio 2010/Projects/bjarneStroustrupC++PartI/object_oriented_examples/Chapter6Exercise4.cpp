/* 
  TITLE                Names & Score 		      Chapter6Exercise4.cpp
  Bjarne Stroustrup "Programming: Principles and Practice Using C++"
  COMMENT
			Objective: Store unique names and scores. 
					   Redo Exercise 19 from Chapter 4
					   using a single vector if type
					   Name_value.
			   	Input: Name followed by its score. 
				       (Input termination: "No more")
			   Output: Print all entered names and scores pairs.
			   Author: Chris B. Kirov
			     Data: 10.04.2015
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

/*
	classa: Name_value

	Data structure storing
	a pair of associated
	name and score.
*/
class Name_value
{
public:
	// data members
	std::string name;
	int score;

	// constructors
	Name_value();
	Name_value(std::string& n, int s)
		: name(n), score(s)
	{
	
	}

	// used in sort()
	bool operator< (const Name_value& rhs) const 
	{
		return name < rhs.name; 
	}
};

void populate_vector(std::vector<Name_value>&);
bool all_unique(const std::vector<Name_value>&);
void print_vector(const std::vector<Name_value>&);

//==============================================================================
int main(){
	// data structure holding names and scores
	std::vector<Name_value> pairs;

	// read input and store in vector
	populate_vector(pairs);
	 
	// check if all names unique and print
	if (all_unique(pairs))
	{
		 print_vector(pairs);
	}
	else 
	{
		std::cout <<"Name occuring more than once!\n";
	}
	getchar();
}

//==============================================================================

/*
	Function: populate_vector();

	It prompts the used to input
	string: name and int: score
	on a single line separated by
	whitespace and stores them in
	the vector passed by reference.
*/
void populate_vector(std::vector<Name_value>& v)
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
			v.emplace_back(Name_value(name, score));
		}
		else 
		{
			std::cout <<"Wrong input format!\n";
		}
		std::cout << prompt;
	}
}

/*
	Function: all_unique();

	Returns true if all the
	names are unique. 
*/
bool all_unique(const std::vector<Name_value>& v)
{
	std::vector<Name_value> temp(v);

	sort(temp.begin(), temp.end());

	for (size_t i = 0; i < temp.size() - 1; ++i)
	{
		if (temp[i].name == temp[i+1].name)
		{
			return false;
		}
	}
	return true;
}

/*
	Function: print_vector()
	Use: print_vector(vect)
	It prints all vector elements on a new line.
*/
void print_vector(const std::vector<Name_value>& v)
{
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i].name <<" "<< v[i].score <<'\n';
	}
}