/*
	TITLE		    Singly Linked list        Chapter17Exercise14.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Reimplement the example from Chapter 17.10.1
		            and modify it to a sinlgly-linked list.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 21.12.2015
*/
#ifndef CHAPTER17EXERCISE14_H
#define CHAPTER17EXERCISE14_H

class Singly_linked_list 
{
public:
	// public data member
	std::string value;

	// constructor
	Singly_linked_list (const std::string& v, Singly_linked_list* s = 0)
		: value(v), succ(s)
	{
	
	}

	// non-modifying members
	Singly_linked_list* add(Singly_linked_list* n);
	Singly_linked_list* insert(Singly_linked_list* n);
	Singly_linked_list* erase();

	// modifying members
	const Singly_linked_list* find(const std::string& v) const;
	Singly_linked_list* advance (unsigned int n);
	Singly_linked_list* next() const { return succ; }

	// private data member
private:
	Singly_linked_list* succ;
};

void print_all (Singly_linked_list* src);

#include "Chapter17Exercise14Def.cpp"

#endif