/*
	TITLE			   Concatenate two files	Chapter10Exercise8.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Create a file that contains the concatenated data
					   of two other files.
				Input: - 
			   Output: -
			   Author: Chris B. Kirov
			     Date: 03.05.2015
*/ 
#include <iostream>
#include <fstream>
#include <string>
#include"Chapter10Exercise8.h"
 
void test_function();

//==========================================================================================
int main()
{
	try
	{
		test_function();
	}
	catch(std::exception& e)
	{
		std::cerr<< e.what() << std::endl;
	}
}
//==========================================================================================

/*
	Function: test_function()

*/
void test_function()
{
	std::string source_file_name1 = "Chapter10Exercise8File1.txt";
	std::string source_file_name2 = "Chapter10Exercise8File2.txt";
	std::string destination_file_name = "Chapter10Exercise8Conc.txt";

	// print contents of source files
	std::ifstream ifs1(source_file_name1.c_str());
	if(!ifs1)
	{
		std::cerr <<"Can't open input file: "<< source_file_name1 <<'\n';
	}

	std::cout <<"Source file 1 contains:\n" << ifs1.rdbuf() <<'\n';

	std::ifstream ifs2(source_file_name2.c_str());
	if(!ifs1)
	{
		std::cerr <<"Can't open input file: "<< source_file_name2 <<'\n';
	}

	std::cout <<"Source file 2 contains:\n" << ifs2.rdbuf() <<'\n';

	// concatenate
	concatenate_two_files(source_file_name1, source_file_name2, destination_file_name);
	 
	// print contents of destination file
	std::ifstream ifs3(destination_file_name.c_str());
	if(!ifs1)
	{
		std::cerr <<"Can't open input file: "<< destination_file_name <<'\n';
	}

	std::cout <<"Destination file contains:\n" << ifs3.rdbuf() <<'\n';
}



 