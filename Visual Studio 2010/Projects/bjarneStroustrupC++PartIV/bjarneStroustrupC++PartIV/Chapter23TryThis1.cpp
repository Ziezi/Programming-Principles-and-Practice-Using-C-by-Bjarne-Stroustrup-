/*
	TITLE		   Better Error Handling    		Chapter23TryThis1.cpp
	COMMENT
		Objective: What would be a better error handling?
				   Modify Mail_file's constructor to handle likely formatting
				   errors related to the use of "----" - (end of message indicator).
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 23.04.2017
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

#include "Chapter23Exercise1.h"

//---------------------------------------------------------------

Mail_file::Mail_file(const std::string& file_name)
{
	std::ifstream ifs(file_name.c_str());
	if (!ifs) 
	{
		throw std::runtime_error("Can't open input file: " + file_name);
	}

	// build the vector of lines
	std::string line;
	while (getline(ifs, line))
	{
		lines.push_back(line);
	}

	// switch indicating reading message
	bool new_message = false;

	// build the vector of Messages 
	Line_iter first = lines.begin();
	for (Line_iter p = lines.begin(); p != lines.end(); ++p)
	{
		// account for missing end-of-message indicators,  i.e. encounter the start of next message before end of previos
		// if: "From: " encountered before: "----" -> throw exception; (other marker could be chosen)
		if (is_prefix(*p, "From: "))
		{
			if (new_message)
			{
				throw std::runtime_error("Missing end-of-file indicator!\n");
			}
			new_message  = true;
		}

		if (is_end_of_message(p))
		{   
			// account for nested messages the lead to multiple end-of-message indicators, i.e. "----"
			// while loop till the last "----"
			while (is_end_of_message(p))
			{
				++p;
			}

			if (new_message)
			{
				new_message  = false;
			}

			// message is defined via iterators to its start and end	
			m.push_back(Message(first, p)); 

			// skip the end-of-message indicator
			first = p + 1; 
		}

		// account for wrong end-of-message indicators
	}
}

int main ()
{

}

