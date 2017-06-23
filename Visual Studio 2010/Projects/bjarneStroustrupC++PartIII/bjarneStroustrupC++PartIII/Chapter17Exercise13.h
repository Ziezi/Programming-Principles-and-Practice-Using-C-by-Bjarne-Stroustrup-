/*
	TITLE		    Linked list             Chapter17Exercise13.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Modify Link to include struct God,
				    containing members of type string:
					name, mythology, vehicle, weapon.
					Write: print_all(), add_ordered() functions.  
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 07.12.2015
*/

#ifndef CHAPTER17EXERCISE13_H
#define CHAPTER17EXERCISE13_H

struct God 
{
	std::string name;
	std::string mythology;
	std::string vehicle;
	std::string weapon;

	// constructor
	God (std::string n, std::string m, std::string v = " ", std::string w = " ")
		: name(n), mythology(m), vehicle(v), weapon(w) 
	{
	
	}

	friend bool operator< (const God& lhs, const God& rhs);
};

//------------------------------------------------------------------------

bool operator< (const God& lhs, const God& rhs) 
{
	return lhs.name < rhs.name;
}

//------------------------------------------------------------------------

std::ostream& operator<< (std::ostream& os, God& g)
{
	return os << g.name <<", "
			  << g.mythology <<", "
			  << g.vehicle <<", "
			  << g.weapon;
}

//------------------------------------------------------------------------

class Link 
{
public:
	God god;

	// consructor
	Link (God g, Link* p = 0, Link* s = 0)
		: god(g), prev(p), succ(s) { } 

	// destructor
	~Link ()
	{
		// traverse to one end and erase() all till other
	}

	// modifying member functions
	Link* insert (Link* n);
	Link* add (Link* n);
	Link* add_ordered (Link* n);
	Link* erase (void);
	Link* find (const std::string& v);

	// non - modifying member functions
	Link* advance (int n);
	const Link* find (const std::string& n) const;
	Link* previous () { return prev; }
	Link* next () { return succ; }

private:
	Link* prev;
	Link* succ;
};

//------------------------------------------------------------------------

// non - member function
void print_all_front_to_back(Link* n);
void print_all_back_to_front(Link* n);
void order_list (Link* src, Link*& dest);

#include "Chapter17Exercise13Def.cpp"
#endif