/*
	TITLE		   Reserve order of chars in file 	 Chapter11Exercise11.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Create a function that reverses the order of characters 
				   in a file. Hint: use file open modes
		    Input: -
		   Output: -
		     Date: 24.08.2015
		   Author: Chris B. Kirov
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void create_file(std::string&);
void reverse_file_characters(std::string&);

//-----------------------------------------------------------------------------------------------------
int main()
{
	try
	{
		std::string fileName("Chapter11Exercise11.txt");
		create_file(fileName);
		 
		reverse_file_characters(fileName);
		std::cout <<"File characters reversed.\n";
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
		ofs << letter;
	}

	ofs << '\n';

	for(letter = '0'; letter <= '9'; ++letter)
	{
		ofs << letter - '0';
	}
}
//-----------------------------------------------------------------------------------------------------

/*
	Function: reverse_file_characters()
	 
	It reverses the order of characters
	in a file.
*/
void reverse_file_characters(std::string& fn)
{
	std::ifstream ifs(fn.c_str(), std::ios_base::ate);
	if(!ifs) 
	{
		std::cerr <<"Can't open input file!\n";
	}

	std::string reversed_file;
 
	// get the size of the file in bytes
	std::streampos file_size = ifs.tellg();

	char c;
	for (int i = 1; i <= file_size; ++i)
	{
		ifs.seekg(-i, std::ios::end);
		ifs.get(c);

		reversed_file += c;
	}

	ifs.close();

	// erase the file contents
	std::ofstream ofs(fn.c_str(), std::ios_base::trunc);
	if(!ofs) 
	{
		std::cerr <<"Can't open output file!\n";
	}

	// write the reversed characters
	ofs << reversed_file;
}