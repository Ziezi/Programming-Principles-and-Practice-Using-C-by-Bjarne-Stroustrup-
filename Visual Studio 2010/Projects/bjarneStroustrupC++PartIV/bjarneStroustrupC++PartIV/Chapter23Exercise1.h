/*
	TITLE		   Email file			Chapter23Exercise1.h
	COMMENT
		Objective:   
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 23.04.2017
*/
#ifndef Chapter23Exercise1_h
#define Chapter23Exercise1_h

typedef std::vector<std::string>::const_iterator Line_iter;

class Message
{
public:
	Message(Line_iter p1, Line_iter p2) 
		: first(p1), last(p2) { }

	Line_iter begin() const { return first; }
	Line_iter end() const { return last; }

private:
	Line_iter first;
	Line_iter last;
};

//---------------------------------------------------------------

typedef std::vector<Message>::const_iterator Mess_iter;

class Mail_file
{
public:
	Mail_file(const std::string& file_name);

	Mess_iter begin() const { return m.begin(); }
	Mess_iter end() const { return m.end(); }

private:
	std::string name;
	std::vector<std::string> lines;
	std::vector<Message> m;
};

//---------------------------------------------------------------

int is_prefix(const std::string& s, const std::string& p);
bool find_from_addr(const Message* message, std::string& sender);
bool find_subject(const Message* message, std::string& subject);
bool is_end_of_message(Line_iter line);

#include "Chapter23Exercise1Def.cpp"

#endif


