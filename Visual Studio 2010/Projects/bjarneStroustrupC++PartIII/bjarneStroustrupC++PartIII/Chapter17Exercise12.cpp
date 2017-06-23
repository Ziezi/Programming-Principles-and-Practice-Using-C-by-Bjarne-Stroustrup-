/*
	TITLE		    Linked list             Chapter17Exercise11.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Why are there two different definitions of find()?
		           
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 07.12.2015
*/
#include <iostream>
#include <string>

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
	Link* find (const std::string &v);

	// non-modifying member functions
	const Link* find(const std::string &v) const;

private:
	Link *prev;
	Link *succ;
};

//---------------------------------------------------------------------------------

Link* Link::find(const std::string &v) 
{
	Link* p = this;

	// loop over all valid links
	while (p)
	{
		// check for wanted value
		if (p->value == v) 
		{
			return p;
		}

		// if no match, go to successor
		p = p->succ;
	}

	return 0;
}

//---------------------------------------------------------------------------------
/*
	Member function: find()
	 
	It returns the first successor link containing
	string value: v. Read permission only.
*/
const Link* Link::find(const std::string &v) const
{
	const Link* p = this;
	
	while (p)
	{
		if (p->value == v)
		{
			return p;	
		}

		p = p->succ;
	}

	return 0;	
}

//---------------------------------------------------------------------------------

int main () 
{
	try 
	{
		// const implementation allows only to read the value.
		// non-const allows read and write the value of string.
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	getchar();
}