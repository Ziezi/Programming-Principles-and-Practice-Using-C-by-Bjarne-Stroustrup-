/*
	TITLE		   Analyse table data    			     Chapter23Exercise11.cpp
	COMMENT
		Objective: Modify the table-checking program from §23.9 to see if the 
				   number of students is increasing or decreasing over the 
				   years in question.

				   .txt file and .p files must be placed in current Gnuplot
				   directory (Documents) to before loading from Gnuplot.
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

/* generates a .txt file to be used as gnuplot source file for graphical representation of grade vs students. */
void analyse_data(std::map<char, table_data>& m, const std::string& f)
{
	std::ofstream ofs(f.c_str());
	if (!ofs)
	{
		throw std::runtime_error("Can't open output file!\n");
	}

	ofs <<"#Grades\tStudents\n";

	for (auto it = m.begin(); it != m.end(); ++it)
	{
		char d = it->first;
		if (isdigit(d))
		{
			ofs << d <<"\t"<< it->second.total <<"\n";
		}
	}
}

//-------------------------------------------------------------------------------------------------------------------

int main()
{
	std::string src_file("Chapter23Exercise9a.txt");
	std::string dest_file("Chapter23Exercise10merged.txt");
	std::string gnuplot_file("Chapter23Exercise11.txt");

	// stores merged rows: grade, (boys, girls, total)
	std::map<char, table_data> table_rows;
	
	try
	{
		merge_rows(src_file, dest_file, table_rows);
		analyse_data(table_rows, gnuplot_file);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}