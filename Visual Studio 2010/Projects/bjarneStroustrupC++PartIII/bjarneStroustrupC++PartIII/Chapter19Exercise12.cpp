/*
	TITLE			File Handler          Chapter19Exercise12.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Design and implement a file handler that
					takes a string argument (file name),
					opens the file in the constructor and
					closes it in the destructor.

		     Input: -
			Output: - 
			Author: Chris B. Kirov
			  Date: 06. 2. 2016
*/

#include <iostream>
#include <fstream>
#include <string>

#include <cstdio>
#include <memory>
#include "Chapter19Exercise12.h"

void test1 () 
{
	std::cout <<"Test class File_handle writing.\n";
	std::string file_name1 = "Chapter19Exercise12.txt";
	File_handle fh(file_name1);
	
	std::string text = "Just write to file"; 
	fh.get_file() << text;


	std::cout <<"\nTest class CFile_handle writing.\n";
	std::string file_name = "Chapter19Exercise12v2.txt", mode = "w";

	CFile_handle cfh (file_name, mode);
	fwrite(text.c_str(), sizeof(char), text.size(), cfh.get_file());
}

//-------------------------------------------------------------------------------------------

void test2 () 
{
	std::cout <<"Test class File_handle reading.\n";
	std::string file_name1 = "Chapter19Exercise12.txt";
	File_handle fh(file_name1);
	
	std::string input; 
	getline(fh.get_file(), input);
	std::cout << input;

	std::cout <<"\nTest class CFile_handle reading.\n";
	std::string file_name = "Chapter19Exercise12v2.txt", mode = "r";
	CFile_handle cfh (file_name, mode);

	std::string text = "Just write to file"; 
	char buffer[20];

	fread(buffer, sizeof(char), text.size(), cfh.get_file());

	std::cout << buffer;
}

//-------------------------------------------------------------------------------------------

int main () 
{
	test1 ();
	test2 ();

	getchar();
}