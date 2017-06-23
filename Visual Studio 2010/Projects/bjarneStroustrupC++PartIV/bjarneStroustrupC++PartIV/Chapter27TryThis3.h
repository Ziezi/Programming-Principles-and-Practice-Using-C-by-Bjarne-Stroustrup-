/* 
	TITLE		   From C to C++ Doubly Linked List		 Chapter27TryThis3.h
	COMMENT
		Objective: Rewrite the intrusive list example in C++, showing how to 
				   make it shorter and easier to use without making the code 
				   slower or the objects bigger.

				   Note: Be aware of locally defined pointers, especially when their
						 value should be reassigned.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 09.06.2017
*/

#ifndef Chapter27TryThis3_h
#define Chapter27TryThis3_h

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

	std::string s;
};

//--------------------------------------------------------------------------

Name* make_name(const std::string& str); 
void print_name(Link* l);

#include "Chapter27TryThis3Def.cpp"

#endif