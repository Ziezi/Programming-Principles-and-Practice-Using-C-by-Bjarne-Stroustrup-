/*
	TITLE		   Reserve order of words in file 	 Chapter11Exercise12.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Create a function that reverses the order of words
				   (whitespace-separated strings) in a file.
		    Input: Text file. 
		   Output: Input text file.
		     Date: 25.08.2015
		   Author: Chris B. Kirov
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void create_file(std::string&);
void reverse_words_order(std::string&);

//-----------------------------------------------------------------------------------------------------
int main()
{
	try
	{
		std::string file_name("Chapter11Exercise12.txt");
		create_file(file_name);

		reverse_words_order(file_name);
		std::cout <<"File words reversed.\nPress a button to exit:\n>>";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
//-----------------------------------------------------------------------------------------------------

/*
	Function: create_file()
	 
	It creates a text file with the 
	characters of the English alphabet,
	followed by the digits from 0 to 9.
*/
void create_file(std::string& fn)
{
	std::ofstream ofs(fn.c_str());
	if(!ofs)
	{
		std::cerr <<"Can't open output file!\n";
	}

	char letter;

	for(letter = 'a'; letter <= 'z'; ++letter)
	{
		ofs << letter <<" ";
	}

	ofs << '\n';

	for(letter = '0'; letter <= '9'; ++letter)
	{
		ofs << letter - '0' <<" ";
	}
}

//-----------------------------------------------------------------------------------------------------
/*
	Function: reverse_words_order()
	 
	It reverses the order of strings
	in a file.
*/
void reverse_words_order(std::string& fn)
{
	std::ifstream ifs(fn.c_str());
	if(!ifs)
	{
		std::cerr <<"Can't open input file!\n";
	}

	std::vector<std::string> reversed_text;
	std::string line;

	// read a line of text
	while(getline(ifs, line))
	{
		std::stringstream ss(line);

		// separate the line in words and store them in vector
		std::vector<std::string> individual_words;
		std::string word;

		while(ss >> word)
		{
			individual_words.push_back(word);
		}

		// concatenate the words from the vector in reverse order, separating them with whitespace
		std::string reversed_line;

		for(size_t i = individual_words.size() - 1; i > 0 ; --i) 
		{
			reversed_line += individual_words[i] + " ";
		}

		reversed_line += individual_words[0];
		reversed_text.push_back(reversed_line);
	}
	ifs.close();
	 
	// truncate and write the content in reversed order
	std::ofstream ofs(fn.c_str(), std::ios_base::trunc);

	for(size_t i = 0; i < reversed_text.size(); ++i)
	{
		ofs << reversed_text[i] <<'\n';
	}
}