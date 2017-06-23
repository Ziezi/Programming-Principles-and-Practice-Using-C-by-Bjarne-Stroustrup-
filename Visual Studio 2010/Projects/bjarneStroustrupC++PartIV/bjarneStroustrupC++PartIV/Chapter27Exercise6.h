/* 
	TITLE	       Change the Representation of DList		     	 Chapter27Exercise6.h
	COMMENT
		Objective: Change the representation of Link and List from §27.9 without changing
				   the user interface provided by the functions. 
				   Allocate Links in an array of Links and have the members:
				   first, last, prev, and next be ints (indices into the array).  
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 13.06.2017
*/
#ifndef Chapter27Exercise6_h
#define Chapter27Exercise6_h

//--------------------------------------------------------------------------

struct Link
{
	int next;
	int prev;
};

//--------------------------------------------------------------------------

template <typename T>
class DList
{
	T** head;  
	int first;
	int last;

	bool* available;
	int list_size;

	int get_index();
	void return_index(int i);

	std::ptrdiff_t link_index(T*& l) const { return &l - &head[0];}

	void init();
	void create();

	void clear();
	void destroy();

public:
	DList();
	~DList();

	T*& front() const { return head[first]; }
	T*& back() const { return head[last]; }

	void push_back(T* l);
	void push_front(T* l);
	void insert(T*& ref, T* l);					// insert l before ref

	T* erase(T* l);								// erase current (i.e. l) and return next
	T* advance(T* l, int n);					// return n-th link before or after currnet
	T* find(const std::string& name) const;

	void print() const;
	std::size_t size() const;
	int capacity () const { return list_size; }
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

#include "Chapter27Exercise6Def.cpp"

#endif
