/*
	TITLE		   Email file      						 Chapter23Exercise2.cpp
	COMMENT
		Objective: Add a multimap and have it hold subjects. 
				   Let the program take an input string from the keyboard and 
				   print out every message with that string as its subject.
			Input:  
		   Output: 
		   Author: Chris B. Kirov
			 Date: 25.04.2017
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

#include "Chapter23Exercise1.h"

int main()
{
	std::string file_name("Chapter23Exercise1.txt");
	Mail_file mf(file_name);

	// associates a subject with a message
	std::multimap<std::string, const Message*> subject;

	for (Mess_iter p = mf.begin(); p != mf.end(); ++p)
	{
		const Message& m = *p;
		std::string s;

		if (find_subject(&m, s))
		{
			subject.insert(std::make_pair(s, &m));
		}
	}
	std::cout <<"\nEmail Subjects: " << subject.size() <<'\n';

	// extract email message of specific subject
	typedef std::multimap<std::string, const Message*>::const_iterator SM_iter;

	// ask for subject
	std::string target_subject = "Re: Saying Hello";

	// a pair of iterators to the start and end of the range of messages with same subject
	std::pair<SM_iter, SM_iter> pp = subject.equal_range(target_subject);

	std::cout <<"Emails with subject: \""<< target_subject <<"\" have the following messages:\n";
	for (SM_iter it = pp.first; it != pp.second; ++it)
	{
		// print messages associated to that subject
		std::cout << it->second <<'\n';
	}

	getchar();
}