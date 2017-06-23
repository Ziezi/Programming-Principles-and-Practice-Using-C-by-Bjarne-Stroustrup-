/*
	TITLE	 	       Print untill            Chapter8Exercise13.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++
	COMMENT
			Objective: Write a function that prints the elements of a vector
					   till it reaches a specific value.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 10.03.2015
*/
#include <iostream>
#include <string>
#include <vector>

void populate(std::vector<std::string>&);
void print_until_s(const std::vector<std::string>& v, const std::string&);
void print_until_ss(const std::vector<std::string>& v, const std::string&);
 
//==================================================================================================
int main()
{
	try
	{
		 std::vector<std::string> names;
		 populate(names);

		 std::string quit("Joseph Herbst");

		 print_until_s(names, quit);
		 print_until_ss(names, quit);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
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
			break;
		}

		v.push_back(input);
	 }
}

/*
	Function: print_until_s(container, quit);

	Print elements till value stored in quit
	is reached.
*/
void print_until_s(const std::vector<std::string>& v, const std::string& quit)
{
	std::cout <<"Vector of names:\n";
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (v[i] == quit)
		{
			return;
		}
		std::cout << v[i] <<'\n';
	}
}

/*
	Function: print_until_ss(container, quit);
	
	Print elements till value stored in quit
	is reached for a second time.
*/
void print_until_ss(const std::vector<std::string>& v, const std::string& quit)
{
	std::cout <<"Vector of names:\n";
	int count = 0;
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (v[i] == quit)
		{
			count++;

			if (count == 2)
			{
				return;
			}
		}
		std::cout << v[i] <<'\n';
	}
}


 