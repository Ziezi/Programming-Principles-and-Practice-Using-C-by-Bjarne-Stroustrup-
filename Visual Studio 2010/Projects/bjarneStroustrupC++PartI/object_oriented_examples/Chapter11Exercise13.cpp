/*
	TITLE		   Classify and count characters 	 Chapter11Exercise13.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Create a function that classifies and counts
				   each type of characters in a text file.
		    Input: -
		   Output: -
		            
		     Date: 25.08.2015
		   Author: Chris B. Kirov
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

void character_classification(std::string&);

//-----------------------------------------------------------------------------------------------------
int main()
{
	try
	{
		std::cout <<"This program reads a text file, classifies and counts each character type found.\n";

		std::string file_name("Chapter11Exercise13.txt");
		character_classification(file_name);		
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
//-----------------------------------------------------------------------------------------------------


/*
	Function: character_classification()

*/
void character_classification(std::string& file_name)
{
	std::ifstream ifs(file_name.c_str());
	if(!ifs)
	{
		std::cerr <<"Can't open output file!\n";
	}

	// counters and identifiers for each character type
	const size_t array_size = 8;
	std::string types[array_size] = { "space", "alpha", "digit", "xdigit", "upper", "lower", "cntrl", "punct" };
	int counts[array_size]  = { 0, 0, 0, 0, 0, 0, 0, 0 };

	// classify each type
	char c;
	while(ifs.get(c))
	{
		if(isspace(c)) ++counts[0];
		else if(isalpha(c)) ++counts[1];
		else if(isdigit(c)) ++counts[2];
		else if(isxdigit(c)) ++counts[3];
		else if(isupper(c)) ++counts[4]; // these two should be subcategorised under isalpha 
		else if(islower(c)) ++counts[5]; // using putback and secondary classification, their sum = isalpha
		else if(iscntrl(c)) ++counts[6]; 
		else if(ispunct(c)) ++counts[7];
		else std::cerr <<"No such character!\n";
	}
	ifs.close();

	// print result
	std::cout << std::setw(8) << std::left <<"Types: "<<"Number: "<<'\n'; 
	for(size_t i = 0; i < array_size; ++i) 
	{
		std::cout << std::setw(8) << types[i] << std::setw(8) << counts[i] <<'\n'; 
	}
}