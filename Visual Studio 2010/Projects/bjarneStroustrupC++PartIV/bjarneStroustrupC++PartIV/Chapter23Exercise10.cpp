/*
	TITLE		   Merge rows of table  			     Chapter23Exercise10.cpp
	COMMENT
		Objective: Modify the table-checking program from §23.9 to write a new
				   table where the rows with the same initial digit are merged.
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 27.04.2017
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <map>

#include "Chapter23Exercise9.h"
#include "Chapter23Exercise10.h"

int main()
{
	std::string src_file("Chapter23Exercise9a.txt");
	std::string dest_file("Chapter23Exercise10merged.txt");

	// stores merged rows: grade, (boys, girls, total)
	std::map<char, table_data> table_rows;
	
	try
	{
		merge_rows(src_file, dest_file, table_rows);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}