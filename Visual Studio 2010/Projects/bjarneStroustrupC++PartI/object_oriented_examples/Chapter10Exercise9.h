/*
	TITLE			   Merge two files with sorted words    Chapter10Exercise9.h
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Write a program that takes two files
					   containing sorted whitspace-separated
					   words and merges them, preserving order.  
				Input: - 
			   Output: -
			   Author: Chris B. Kirov
			     Date: 03.05.2015
*/ 
#ifndef CHAPTER10EXERCISE9_H
#define CHAPTER10EXERCISE9_H


/*
	Function: fill_vector();

*/
void fill_vector(std::istream& is, std::vector<std::string>& v)
{
		if(!is)
		{
			std::cerr <<"Can't open input stream!\n";
		}

		std::string line;
		while(getline(is, line))
		{
			std::stringstream ss(line);
			std::string word;

			while (ss >> word)
			{
				v.emplace_back(word);
			}
		}
}
//--------------------------------------------------------------------

/*
	Function: print_vector(std::string& label, std::ostream& os, std::vector<std::string>& v);

*/
void print_vector(std::string& label, std::ostream& os, std::vector<std::string>& v)
{
	os << label;
	for(size_t i = 0; i < v.size(); ++i)
	{
		os << v[i];

		if (i < v.size() - 1)
		{
			os <<" ";
		}
	}
}

 //--------------------------------------------------------------------
/*
	Function: concatenate_and_sort_two_files()
	 
	It creates a destination file containing 
	the sorted data from the two source files.
*/
void concatenate_and_sort_two_files(std::string& source_file_name1, std::string& source_file_name2, std::string& destination_file_name)
{
	std::ifstream ifs1(source_file_name1.c_str());
	if(!ifs1)
	{
		std::cerr <<"Can't open input file: "<< source_file_name1 <<'\n';
	}
		
	std::vector<std::string> files_data;
	fill_vector(ifs1, files_data);

	std::ifstream ifs2(source_file_name2.c_str());
	if(!ifs2)
	{
		std::cerr <<"Can't open input file: "<< source_file_name2 <<'\n';
	}

	fill_vector(ifs2, files_data);
	
	// sort data
	std::sort(files_data.begin(), files_data.end());

	// open the destination file 
	std::ofstream ofs(destination_file_name.c_str(), std::ios::ate);
	if(!ofs)
	{
		std::cerr <<"Can't open output file: "<< destination_file_name <<'\n';
	} 
	
	// write the sorted data
	std::string label;
	print_vector(label, ofs, files_data); 
}

#endif 