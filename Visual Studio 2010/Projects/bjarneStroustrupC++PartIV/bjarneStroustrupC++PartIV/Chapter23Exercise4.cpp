/*
	TITLE		   Mail_file on real emails    Chapter23Exercise4.cpp
	COMMENT
		Objective: Apply the previous program on real list of emails
				   and extract the lines containing the subject.
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 27.04.2017
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <regex>

#include "Chapter23Exercise3.h"

int main ()
{
	std::string file_name("Chapter23Exercise3.txt");
	Mail_file mf(file_name);

	// associates a sender with a message
	std::multimap<std::string, const Message*> sender;

	for (Mess_iter p = mf.begin(); p != mf.end(); ++p)
	{
		const Message& m = *p;
		std::string s;

		if (find_from_addr(&m, s))
		{
			sender.insert(std::make_pair(s, &m));
		}
	}

	std::cout <<"\nSenders: " << sender.size() <<'\n';

	// extract email subject of specific sender
	typedef std::multimap<std::string, const Message*>::const_iterator SM_iter;

	std::string target_sender = "Greg Nuckols <support@strengtheory.com>";

	// a pair of iterators to the start and end of the range
	std::pair<SM_iter, SM_iter> pp = sender.equal_range(target_sender);

	std::cout <<"Sender: "<< target_sender <<" has sent emails with subjects:\n";
	for (SM_iter it = pp.first; it != pp.second; ++it)
	{
		std::string subject;

		if (find_subject(it->second, subject))
		{
			std::cout << subject << '\n';
		}
	}

	getchar();
}