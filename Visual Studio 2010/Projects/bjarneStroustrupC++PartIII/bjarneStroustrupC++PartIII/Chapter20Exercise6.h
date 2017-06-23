/*
	TITLE		    Find & Replace for Document    Chapter20Exercise6.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Write find and replace operation for class Document
					based on §20.6.2.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 19. 02. 2017
*/

#ifndef Chapter20Exercise6_h
#define Chapter20Exercise6_h

//-------------------------------------------------------------------------

typedef std::vector<char> Line;																	// line of text

//-------------------------------------------------------------------------

class Text_iterator
{
public:
	Text_iterator(std::list<Line>::iterator l, std::list<Line>::iterator le, Line::iterator p);	// constructor
	Text_iterator(const Text_iterator& src);													// copy constructor
	Text_iterator& operator= (const Text_iterator& src);										// copy assignment

	char& operator*() { return *pos; }															// dereferencing
	Text_iterator& operator++ ();																// incrementation

	bool operator== (const Text_iterator& other) const;											// comparison
	bool operator != (const Text_iterator& other) const;										// comparison
	 
	void swap(Text_iterator& src);																// helper: swap

	std::list<Line>::iterator get_line() { return ln; }											// accesors
	std::list<Line>::iterator get_line_end() { return ln_end; }
	Line::iterator get_column() { return pos; }								

private:
	std::list<Line>::iterator ln;																// data members
	std::list<Line>::iterator ln_end;
	Line::iterator pos;
};

//-------------------------------------------------------------------------

void swap(Text_iterator& lhs, Text_iterator& rhs);												// object swap

//-------------------------------------------------------------------------

class Document
{
public:
	typedef Text_iterator iterator;
public:
	Document();																					// constructor

	iterator begin();																			// iterator to first element
	iterator end();																				// iterator to last element

	iterator find (iterator first, const char c);												// find a letter 
	iterator find_txt (const std::string& s);													// find a word 
	iterator erase (iterator position);															// erase letter at position
	iterator insert (iterator position, const char c);											// insert letter to position
	iterator replace (const std::string& search, const std::string& src);						// replace a word 
	void print ();																				// print all text
	int get_char_number ();
	int get_word_number ();																		// number of white spaces

	std::list<Line> text;																		// data member
};

//-------------------------------------------------------------------------

template<class T, class U>
bool match(T first, T last, U begin, U end);

//-------------------------------------------------------------------------

template <class Iterator>
Iterator advance(Iterator p, int n);

//-------------------------------------------------------------------------

void erase_line(Document& d, size_t n);

//-------------------------------------------------------------------------

std::istream& operator>> (std::istream& is, Document& d);

//-------------------------------------------------------------------------

std::ostream& operator<< (std::ostream& os, Document& d);

#include "Chapter20Exercise6Def.cpp"

#endif