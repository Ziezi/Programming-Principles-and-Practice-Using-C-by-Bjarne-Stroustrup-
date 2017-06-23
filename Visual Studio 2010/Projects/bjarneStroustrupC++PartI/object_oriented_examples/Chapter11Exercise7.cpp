/*
	TITLE		   Create a dictionary			  Chapter11Exercise7.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Create a dictionary from a multipage text.
				   Code from Chapter 11.7 used instead of the trivial code 
				   from the previous exercise.
			Input: -
		   Output: - 
		     Date: 03.07.2015
		   Author: Chris B. Kirov
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // sort
#include "Chapter11Exercise7.h"

int main()
{
	try
	{
		std::string text_file("Chapter11Exercise7.txt"); 
		std::ifstream ifs(text_file.c_str());
		if(!ifs)
		{
			std::cerr <<"Can't open input file!\n";
		}

		// instantiate a PunctStream object and initialize it to: cin or file stream
		PunctStream ps(ifs);

		// construct initial set of characters to be replaced with whitepace 
		ps.whitespace(",./");

		// set case sensitivity
		ps.caseSensitive(false);

		// vector that will store the words of the dictionary
		std::vector<std::string> dictionary;
		
		std::cout <<"This program reads a text file, converts it to lower case and removes punctuation.\n";
		create_dictionary(ps, dictionary);
		 
		std::cout << "Dictionary:\n";
		print_dictionary(dictionary);			
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}