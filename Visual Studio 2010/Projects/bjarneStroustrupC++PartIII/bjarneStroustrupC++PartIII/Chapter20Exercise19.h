/*
	TITLE		    Iterator for List         Chapter20Exercise19.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define a range-checked iterator for list
		 			(a bidirectional iterator).  
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 24. 02. 2017
*/

#ifndef Chapter20Exercise19_h
#define Chapter20Exercise19_h

template <class Elem>
struct Link
{
	Link();
	Link (Link<Elem>* s, Link<Elem>* p, const Elem& v);
	Link (const Link<Elem>& src);

	Link<Elem>& operator= (const Link<Elem>& src);
	bool operator== (const Link<Elem>& src) const;
	bool operator!= (const Link<Elem>& src) const;

	void swap(Link<Elem>& src);

	Link* succ;
	Link* prev;
	Elem val;
};

//-----------------------------------------------------------------------------

template<class Elem>
void swap(Link<Elem>& lhs, Link<Elem>& rhs);

//-----------------------------------------------------------------------------

template <class Elem>
class List
{
public:
	class iterator;

	List();

	iterator begin() { return iterator(first, first , last); }
	iterator end() { return iterator(last, first, last); }

	//iterator insert(iterator p, const Elem& v); 				// insert before specified position; return it	
	//iterator erase(iterator p);									// erase at specified position; return next
	 
	//void push_back(const Elem& v);	 
	void push_front(const Elem& v);

	//void pop_front(); //
	//void pop_back();  //

	Elem& front();
	//Elem& back(); //

	size_t size(); 
	void print();

private:
	Link<Elem> *first;
	Link<Elem> *last;
};

//-----------------------------------------------------------------------------

/* a bidirectional iterator */
template <class Elem>
class List<Elem>::iterator
{
public:
	iterator();											// default constructor
	iterator(Link<Elem>* c, Link<Elem>* b, Link<Elem>* e);					
	iterator(const iterator& src);						// copy constructor
	iterator operator= (const iterator& src);			// copy assignment 

	iterator& operator++();								// incrementations
	iterator operator++(int);							// postfix
	iterator& operator--();								// decrementations
	iterator operator--(int);							// postfix

	Elem& operator*();									// dereferenceable lvalue
	const Elem& operator*() const;						// dereferenceable rvalue

	bool operator== (const iterator& b) const;			// equality comparisons
	bool operator!= (const iterator& b) const;

	void swap(iterator& src);

private:
	Link<Elem>* curr;
	Link<Elem>* begin;
	Link<Elem>* end;
};

//-----------------------------------------------------------------------------

template<class Elem>
void swap(typename List<Elem>::iterator& lhs, typename List<Elem>::iterator& rhs);

//-----------------------------------------------------------------------------

#include "Chapter20Exercise19Def.cpp"

#endif