/*
	TITLE		   Create a dictionary			  Chapter11Exercise7.h
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Create a dictionary from a multipage text.
		           Code from Chapter 11.7 used instead of the trivial code 
				   from the previous exercise.
			Input: -
		   Output: - 
		     Date: 03.07.2015
		   Author: Chris B. Kirov
*/
#ifndef _CHAPTER11EXERCISE7_H
#define _CHAPTER11EXERCISE7_H
/*
	Class: PunctStream

	It provides stream parsing for
	replacing specificic kind of 
	characters with whitespace.
*/
class PunctStream
{
public:
	// constructors
	PunctStream(std::istream& is)
		: source(is), sensitive(true)
	{
	
	}

	// member-functions
	void whitespace (const std::string& s) { white = s; } 
	void addWhitespace (char c) { white += c; }
	bool isWhitespace (char c);
	void caseSensitive (bool b) { sensitive = b; }
	bool isCaseSensitive () { return sensitive; }

	// overwritten extraction operator
	PunctStream& operator>> (std::string& s);

	// operator that returns a bool value on success/failure of PunctStream object
	operator bool ();

private:
	// stream containing text to be parsed
	std::istream& source;

	// stringstream containing a parsed text
	std::istringstream buffer;

	// case sensitivity 
	bool sensitive;

	// characters to be replaced with whitespace
	std::string white;
};

// Non-member functions
void create_dictionary (PunctStream& ps, std::vector<std::string>& d);
void print_dictionary (std::vector<std::string>& d);

#include "Chapter11Exercise7Def.cpp"
#endif