/*
	TITLE		    Linked list             Chapter17Exercise11.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Complete and run the example from 17.10.1.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 07.12.2015
*/
#ifndef CHAPTER17EXERCISE11_H
#define CHAPTER17EXERCISE11_H

class Link
{
public:
	// public data member
	std::string value;

	// constructor
	Link (const std::string &v, Link *p = 0, Link *s = 0) 
		: value(v), prev(p), succ(s)
	{ 
	
	}

	// modifying member functions
	Link* insert (Link* n);  
	Link* add (Link *n);  
	Link* erase ();  
	Link* find (const std::string &v);

	// non-modifying member functions
	const Link* find(const std::string &v) const;

	Link* advance(int n); // couldn't implement it with: const specifier 

	Link* next() const { return succ; }
	Link* prevoius() const { return prev; }

	// private data members
private:
	Link *prev;
	Link *succ;
};

//---------------------------------------------------------------------------------

// non-member function
void print_all (Link* p);

#include "Chapter17Exercise11Def.cpp"
#endif