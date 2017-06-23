/*
	TITLE			   Concatenate two files   Chapter10Exercise8.h
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Create a file that contains the concatenated data
					   of two other files.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 03.05.2015
*/ 

#ifndef CHAPTER10_EXERCISE8_H
#define CHAPTER10_EXERCISE8_H
/*
	Function: void concatenate_two_files()
	 
	It createa a file containing the data
	of source file 2 appended after the 
	data of source file 1.
*/
void concatenate_two_files(std::string& source_file_name1, std::string& source_file_name2, std::string& destination_file_name)
{
	std::ifstream ifs1(source_file_name1.c_str());
	if(!ifs1)
	{
		std::cerr <<"Can't open input file: "<< source_file_name1 <<'\n';
	}
		
	std::ifstream ifs2(source_file_name2.c_str());
	if(!ifs2)
	{
		std::cerr <<"Can't open input file: "<< source_file_name2 <<'\n';
	}
	
	// open the destination file with flag ate: append at end
	std::ofstream ofs(destination_file_name.c_str(), std::ios::ate);
	if(!ofs)
	{
		std::cerr <<"Can't open output file: "<< destination_file_name <<'\n';
	} 
	
	// dump the two files 
	ofs << ifs1.rdbuf() << ifs2.rdbuf(); 
}

#endif