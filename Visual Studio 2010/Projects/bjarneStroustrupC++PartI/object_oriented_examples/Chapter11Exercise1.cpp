/*
	TITLE		   Convert to lower case		Chapter11Exercise1.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Read a file, 
				   convert its contents to lower case 
				   and write them to a newly created file.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
		     Date: 30.06.2015
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

void populate_vector(std::string& file_name, std::vector<std::string>& v);
void convert_to_lowercase(std::vector<std::string>& v);
void write_to_file(std::string& file_name, std::vector<std::string>& v);

//==========================================================================================================================================
int main()
{
	try
	{
		std::string information ("Read text file, convert to lower case and write to new file.\n");
		std::cout << information;

		std::vector<std::string> lines_of_text;

		std::string source_file ("Chapter11Exercise1Source.txt");
		populate_vector(source_file, lines_of_text);

		convert_to_lowercase(lines_of_text);

		std::string destination_file ("Chapter11Exercise1Destination.txt");
		write_to_file(destination_file, lines_of_text);
	} 
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
//==========================================================================================================================================

/*
	Function: populate_vector()
*/
void populate_vector(std::string& file_name, std::vector<std::string>& v)
{
	std::ifstream ifs(file_name.c_str());
	if (!ifs)
	{
		std::cerr <<"Can't open input file!\n";
	}

	std::string line;

	while(getline(ifs, line))
	{
		v.push_back(line);
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------

/*
	Function: convert_to_lowercase()

*/
void convert_to_lowercase(std::vector<std::string>& v)
{
	// traverse all the lines
	for (size_t i = 0; i < v.size(); ++i)
	{
		// traverse characters of the words in the lines
		for (size_t j = 0; j < v[i].size(); ++j)
		{
			// if uppercase character convert to lowercase
			if (isalpha(v[i][j]) && isupper(v[i][j])) 
			{
				v[i][j] = tolower(v[i][j]);
			}
		}
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------

/*
	Function: write_to_file()

*/
void write_to_file(std::string& file_name, std::vector<std::string>& v)
{
	std::ofstream ofs(file_name.c_str());
	if (!ofs)
	{
		std::cerr <<"Can't open output stream!\n";
	}

	for (size_t i = 0; i < v.size(); ++i)
	{
		ofs << v[i] <<'\n';	
	}
}