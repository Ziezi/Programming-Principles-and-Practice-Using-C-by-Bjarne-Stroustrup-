/*
	TITLE			   Class name-age pairs		 Chapter9Exercise3.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Implement a class Name_pairs: 

					   Data members:					Member functions:		Overloaded operator:
					   string name, double age;			read_names();           operator<<
					   vector<string> name;				read_ages();            operator==
					   vector<double> age;				sort();	                operator!=
					                                    size();
													    
				Input: Prompts user to type name-age pairs.
			   Output: Prints all the above / sorted.
			   Author: Chris B. Kirov
			     Date: 14.03.2015
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Chapter9Exercise3.h"

NamePairs::Name_pairs np;
void input_loop();

//=========================================================================================
int main()
{
	try
	{
		std::cout <<"\t\tWelcome to this simple name-age pair sorting algorithm.\n";
		input_loop();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
//=========================================================================================

void input_loop()
{
	std::cout <<"How many pairs do you want to enter:\n>>";
	int number_of_names;
	std::cin >> number_of_names;

	// read pairs
	np.read_names(number_of_names); 
	getchar();
	np.read_ages();

	// input confirmation
	std::cout << "You have typed the following pairs: \n";
	std::cout << np;

	// sort and print 
	np.sort();
	std::cout << "The ordered pairs are:\n";
	std::cout << np;


	if (np == np)
	{
		std::cout <<"Objects are identical.\n";
	}

	if (np != np)
	{
		std::cout <<"Objects are different.\n";
	}
}