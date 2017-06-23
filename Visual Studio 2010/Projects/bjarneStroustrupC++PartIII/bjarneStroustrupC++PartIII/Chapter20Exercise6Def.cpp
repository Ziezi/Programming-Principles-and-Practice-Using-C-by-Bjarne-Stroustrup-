/*
	TITLE		    Find & Replace for Document    Chapter20Exercise6Def.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Write find and replace operation for class Document
					based on §20.6.2.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 19. 02. 2017
*/

Text_iterator::Text_iterator(std::list<Line>::iterator l, std::list<Line>::iterator le, Line::iterator p)			 
	: ln(l), ln_end(le), pos(p)
{
	
}

//-------------------------------------------------------------------------

Text_iterator::Text_iterator(const Text_iterator& src)									 
	: ln(src.ln), ln_end(src.ln_end), pos(src.pos)
{
	
}

//-------------------------------------------------------------------------

Text_iterator& Text_iterator::operator= (const Text_iterator& src)					 
{
	Text_iterator temp(src);
	this->swap(temp);
	return *this;
}

//-------------------------------------------------------------------------

Text_iterator& Text_iterator::operator++ ()											 
{
	++pos;
	if (pos == ln->end())		 
	{
		++ln;
		if (ln != ln_end)
		{
			pos = ln->begin();
		}
	}
	return *this;
}

//-------------------------------------------------------------------------

bool Text_iterator::operator== (const Text_iterator& other) const						 
{
	return ln == other.ln && ln_end == other.ln_end && pos == other.pos;
}

//-------------------------------------------------------------------------

bool Text_iterator::operator!= (const Text_iterator& other) const						 
{
	return !(*this == other);
}

//-------------------------------------------------------------------------

void Text_iterator::swap(Text_iterator& src)											 
{
	std::swap(src.get_line(), ln);
	std::swap(src.ln_end, ln);
	std::swap(src.get_column(), pos);
}

//-------------------------------------------------------------------------

void swap (Text_iterator& lhs, Text_iterator& rhs)							 
{
	lhs.swap(rhs);
}

//-------------------------------------------------------------------------

Document::Document()															 
{
	text.push_back(Line()); // initial call to front() or back() is not undefined behaviour
}

//-------------------------------------------------------------------------

Document::iterator Document::begin()														 
{ 
	return iterator(text.begin(), text.end(), text.front().begin());
}

//-------------------------------------------------------------------------

Document::iterator Document::end()															 
{ 
	return iterator(text.end(), text.end(), text.back().end());
}

//-------------------------------------------------------------------------

Document::iterator Document::find(iterator first, const char c)
{
	while (first != end())
	{
		if (c == *first)
		{
			return first;
		}
		++first;
	}
	return end();
}

//-------------------------------------------------------------------------

Document::iterator Document::find_txt (const std::string& s)
{
	if (s.size() == 0)
	{
		return end();
	}

	char first_char = s[0];
	int iter = 0;
	Text_iterator first = begin();
	while (true)
	{
		Text_iterator p = find(first, first_char);

		if (p == end() || match(p, end(), s.begin(), s.end()))
		{
			return p;	
		}

		++first;
	}
}

//-------------------------------------------------------------------------

Document::iterator Document::erase(Document::iterator position)
{
	std::list<Line>::iterator y = position.get_line();
	Line::iterator x = position.get_column();
	(*y).erase(x); 

	return iterator(y, position.get_line_end(), x);
}

//-------------------------------------------------------------------------

Document::iterator Document::insert(Document::iterator position, const char c)
{
	std::list<Line>::iterator y = position.get_line();
	Line::iterator x = position.get_column();
	(*y).insert(x, c);  

	return iterator(y, position.get_line_end(), x);
}

//-------------------------------------------------------------------------

Document::iterator Document::replace (const std::string& search, const std::string& src)
{
	iterator f = find_txt(search);

	if (f == end())
	{
		return end();
	}
	else							// replace
	{
		iterator p = f;

		size_t index;

		for (index = 0; index < search.size(); ++index) 
		{
			if (index < src.size()) // equal
			{
				*p = src[index];	// handle newline character 
				++p;
			}
			else					// search >  ; erase
			{
				 p = erase(p);
			}
		}
		
		while (index < src.size())  // search <  ; insert
		{
			p = insert(p, src[index]);
			++index;
		}
	}

	return f;						// return beginning of new word
}

//-------------------------------------------------------------------------

void Document::print()
{ 
	for (Document::iterator p = begin(); p != end(); ++p)
	{
		std::cout << *p;
	}
}

//-------------------------------------------------------------------------

int Document::get_char_number()
{
	int count = 0;
	for (Document::iterator p = begin(); p != end(); ++p)
	{
		++count;
	}
	return count;
}

//-------------------------------------------------------------------------

int Document::get_word_number()
{
	char c = ' '; // word number defined as the number of white spaces
	int count = 1;// last word does not contain white space after it
	for (Document::iterator p = begin(); p != end(); ++p)
	{
		if (c == *p)
		{
			++count;
		}
	}
	return count;
}

//-------------------------------------------------------------------------

template<class T, class U>
bool match(T first, T last, U begin, U end)
{
	while (first != last && begin != end)
	{
		if (*first != *begin)
		{
			return false;
		}
		++first;
		++begin;
	}
	return true;
}

//-------------------------------------------------------------------------

template <class Iterator>
Iterator advance(Iterator p, int n)
{
	while (n > 0)
	{
		++p;
		--n;
	}
	return p;
}

//-------------------------------------------------------------------------

void erase_line(Document& d, size_t n)
{
	if (n < 0 || n > d.text.size())
	{
		throw std::out_of_range("Document::erase_line: index out of range!\n");
	}

	d.text.erase(advance(d.text.begin(), n));
}

//-------------------------------------------------------------------------

std::istream& operator>> (std::istream& is, Document& d)
{
	char c;
	while (is >> std::noskipws >> c)
	{
		d.text.back().push_back(c);

		if (c == '\n')
		{
			d.text.push_back(Line());
		}
	}

	return is;
}

//-------------------------------------------------------------------------

std::ostream& operator<< (std::ostream& os, Document& d)
{
	for (Document::iterator p = d.begin(); p != d.end(); ++p)
	{
		os << *p;
	}

	return os;
}