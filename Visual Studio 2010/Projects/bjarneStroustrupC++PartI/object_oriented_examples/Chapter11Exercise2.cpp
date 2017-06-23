/*
	TITLE		   Remove vowels from file	    Chapter11Exercise2.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Read a file, 
				   remove all vowels from its contents 
				   and write them to the std output.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
		     Date: 30.06.2015
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void remove_vowels(std::string& file_name);

//==========================================================================================================================================
int main()
{
	try
	{
		std::cout <<"Remove vowels from text file.\n";

		std::string source_file("Chapter11Exercise2.txt");
		remove_vowels(source_file);

		std::cout <<"Done.\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
//==========================================================================================================================================

/*
	Function: isVowel();
	 
	It returns true if a character 
	passed as parametes is a vowel. 
*/
bool is_vowel(char letter)
{
	letter = tolower(letter);
	std::string vowels = "aoeiyu";

	for (size_t i = 0; i < vowels.size(); i++)
	{
		if (letter == vowels[i])
		{
			return true;
		}
	}
	return false;
}

//------------------------------------------------------------------------------------------------------------------------------------------
/*
	Function: removeVowelsInFile()
	 
	It reads a text file and removes all the vowels. 
*/
void remove_vowels(std::string& file_name)
{
	std::ifstream ifs(file_name.c_str());
	if(!ifs)
	{
		std::cerr <<"Can't open input file!\n";
	}

	std::vector<std::string> lines_of_text;
	std::string line;

	// read line by line
	while(getline(ifs, line))
	{
		// skip all vowels
		std::string removed_vowels;
		for (size_t i = 0 ; i < line.size(); ++i)
		{
			if (!is_vowel(line[i]))
			{
				removed_vowels += line[i];
			}
		}

		// store modified line in vector
		lines_of_text.push_back(removed_vowels);
	}

	ifs.close();

	// rewrite the file with the modified lines
	std::ofstream ofs(file_name.c_str(), std::ios_base::trunc);
	if (!ofs)
	{
		std::cerr <<"Can't open output file!\n";
	}

	for (size_t i = 0; i < lines_of_text.size(); ++i)
	{
		ofs << lines_of_text[i] <<'\n';
	}
}