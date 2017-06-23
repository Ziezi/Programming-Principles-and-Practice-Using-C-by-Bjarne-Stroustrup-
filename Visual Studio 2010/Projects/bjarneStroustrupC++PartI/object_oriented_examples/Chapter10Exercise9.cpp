/*
	TITLE			   Merge two files with sorted words 		Chapter10Exercise9.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Write a program that takes two files containing
					   sorted whitspace-separated
					   words and merges them, preserving order.	  
				Input: - 
			   Output: -
			   Author: Chris B. Kirov
			     Date: 03.05.2015
*/ 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include"Chapter10Exercise1.h"
#include"Chapter10Exercise9.h"

void test_function();

//======================================================================================
int main()
{
	try
	{
		test_function();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
//======================================================================================

/*
	Function: void test_function();
*/
void test_function()
{
	std::string source_file_name1 = "Chapter10Exercise9File1.txt";
	std::string source_file_name2 = "Chapter10Exercise9File2.txt";
	std::string destination_file_name = "Chapter10Exercise9SortedFile.txt";
	
	std::cout <<"Source file 1 contains:\n";
	std::ifstream ifs1(source_file_name1.c_str());
	if(!ifs1)
	{
		std::cerr <<"Can't open input file!\n";
	}
	std::cout << ifs1.rdbuf() <<'\n';

	std::cout <<"Source file 2 contains:\n";
	std::ifstream ifs2(source_file_name2.c_str());
	if(!ifs2)
	{
		std::cerr <<"Can't open input file!\n";
	}
	std::cout << ifs2.rdbuf() <<'\n';

	concatenate_and_sort_two_files(source_file_name1, source_file_name2, destination_file_name);

	std::cout <<"Destination file contains:\n";
	std::ifstream ifs3(destination_file_name.c_str());
	if(!ifs3)
	{
		std::cerr <<"Can't open output file!\n";
	}
	std::cout << ifs3.rdbuf() <<'\n';
}
