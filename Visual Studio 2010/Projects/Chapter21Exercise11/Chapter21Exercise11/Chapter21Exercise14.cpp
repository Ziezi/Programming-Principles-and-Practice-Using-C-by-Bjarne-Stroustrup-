/*
	TITLE		    Text statistics 		 Chapter21Exercise14.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Write a program (using the output from the previous exercise) to answer
					questions such as:
					"How many occurrences of ship are ther in a file?"
					"Which word occurs most frequently?" 
					"Which is the longest word in the file?" 
					"Which is the shortest?" 
					"List all words starting with s."
					"List all four-letter words." 
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 06. 03. 2017
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <iterator>

#include "Chapter21Exercise13.h"
#include "Chapter21Exercise14.h"

int main()
{
	try
	{
		std::vector<std::string> modified_text;
		std::string input_file_name("Chapter21Exercise13.txt");
		std::string output_file_name("Chapter21Exercise13.txt");

		cleaup_text_file(input_file_name,  modified_text, output_file_name);

		std::map<std::string, int> dictionary;
		populate_map(modified_text, dictionary);

		std::string target("do");
		std::cout << target <<" has: " << find_occurrences_of(target, dictionary) <<" occurrences\n";
		std::cout <<"Mode: " << find_mode(dictionary) <<'\n';
		std::cout <<"Longest word is: " << find_longest_word(dictionary) <<'\n';
		std::cout <<"Shortgest word is: " << find_shortest_word(dictionary) <<'\n';

		char c = 's';
		std::vector<std::string> s_words = find_words_starting_with(dictionary, c);
		std::cout <<"Words starting with: "<< c <<" are:\n";
		std::copy(s_words.begin(), s_words.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

		size_t l = 2;
		std::vector<std::string> l_words = find_words_of_length(dictionary, l);
		std::cout <<"Words of length: "<< l <<" are:\n";
		std::copy(l_words.begin(), l_words.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}