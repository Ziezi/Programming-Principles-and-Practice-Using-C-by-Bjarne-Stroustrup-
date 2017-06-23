/*
	TITLE		   Binary files					Chapter11Exercise8.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: It reads and writed to binary files.
		    Input:  
		   Output: 
		     Date: 24.08.2015
		   Author: Chris B. Kirov
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/* It returns the address of the first byte of an object representation. */
template<class T>
char* as_bytes(T& i)
{
	void* addr = &i;
	return static_cast<char*>(addr);
}

void read_binary(std::vector<int>& v);
void write_binary(std::vector<int>& v);

//--------------------------------------------------------------------------------

int main()
{
	try
	{
		std::cout <<"This program reads and writes binary files.\n";
		std::vector<int> binary_file_content;

		read_binary(binary_file_content);
		write_binary(binary_file_content);

		std::cout <<"Input file copied into the output file.\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

//--------------------------------------------------------------------------------

/*
	Function: read_binary()

	It reads a binary file 
	and stores its content
	(assumes integers) in the vector. 
*/
void read_binary(std::vector<int>& v)
{
	std::string file_name;
	std::cout <<"Please type and input file name:\n";
	std::cin >> file_name;

	std::ifstream ifs(file_name.c_str(), std::ios_base::binary);
	if (!ifs)
	{
		std::cerr <<"Can't open input file!\n";
	}

	int i;
	while ( ifs.read( as_bytes(i), sizeof(int) ) )
	{
		v.push_back(i);
	}
}
//--------------------------------------------------------------------------------

/*
	Function: void write_binary()
 
	It writes to a binary file 
	the integers stored in the vector. 
*/
void write_binary(std::vector<int>& v)
{
    std::string file_name;
	std::cout <<"Please type an output file name:\n";
	std::cin >> file_name;

	std::ofstream ofs(file_name.c_str(), std::ios_base::binary);
	if (!ofs)
	{
		std::cerr <<"Can't open output file!\n";
	}

	for (size_t i = 0; i < v.size(); ++i)
	{
		ofs.write( as_bytes(v[i]), sizeof(int) );
	}
}

 