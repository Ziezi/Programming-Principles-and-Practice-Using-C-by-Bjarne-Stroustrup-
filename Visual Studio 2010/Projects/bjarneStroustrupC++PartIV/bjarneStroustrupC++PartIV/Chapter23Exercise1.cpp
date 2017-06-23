/*
	TITLE		   Email file      						 Chapter23Exercise1.cpp
	COMMENT
		Objective: Get the Mail_file example to run with file of your creation.
				   Be sure to test with error-causing messages, such as:
				   ones with two addresses, multiple messages with same addresses
				   or same subject, and empty message.
				   Test with file containing someting that is not a message, such
				   as a file containing only ....
			Input: -
		   Output: -
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

	std::string target_sender = "John Doe <jdoe@machine.example>";

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