/* 
	TITLE	       Intrusive Doubly Linked List in C++	   Chapter27Exercise4.h
	COMMENT
		Objective: If you didn't already, write a C++ version of the intrusive
				   list example in §27.9 and test it using every function. 
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 13.06.2017
*/
#ifndef Chapter27Exercise4_h
#define Chapter27Exercise4_h

struct Link
{
	Link* next;
	Link* prev;
};

//--------------------------------------------------------------------------

struct List 
{
	Link* first;
	Link* last;
};

//--------------------------------------------------------------------------

class DList
{
	List* head;

	void init();
	void create();

	void clear();
	void destroy();

public:
	DList();
	~DList();

	Link* front() const { return head->first; }
	Link* back() const { return head->last; }

	void push_back(Link* l);
	void push_front(Link* l);
	void insert(Link* ref, Link* l);				// insert l before ref

	Link* erase(Link* l);							// erase current (i.e. l) and return next
	Link* advance(Link* l, int n);					// return n-th link before or after currnet

	std::size_t size() const;
	void print() const;
	Link* find(const std::string& name) const;
};

//--------------------------------------------------------------------------

class Name: public Link
{
public:
	Name(): s(std::string()) { }
	Name(const std::string& ss) : s(ss) { }

	// evil?!
	std::string operator() (Link* l) { return reinterpret_cast<Name*>(l)->s; }

	std::string s;
};

//--------------------------------------------------------------------------

#include "Chapter27Exercise4Def.cpp"

#endif