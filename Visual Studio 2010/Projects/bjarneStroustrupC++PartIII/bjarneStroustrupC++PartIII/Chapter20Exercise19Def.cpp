/*
	TITLE		    Iterator for List       Chapter20Exercise19Def.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define a range-checked iterator for list
		 			(a bidirectional iterator).  
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 24. 02. 2017
*/

//-----------------------------------------------------------------------------

template <class Elem>
Link<Elem>::Link()
	: succ(nullptr), prev(nullptr), val(Elem())
{
	
}

//-----------------------------------------------------------------------------

template <class Elem>
Link<Elem>::Link (Link<Elem>* s, Link<Elem>* p, const Elem& v)
	: succ(s), prev(s->prev), val(v)
{
	 
}

//-----------------------------------------------------------------------------

template <class Elem>
Link<Elem>::Link (const Link<Elem>& src)
	: succ(src.succ), prev(src.prev), val(src.val)
{
	
}

//-----------------------------------------------------------------------------

template <class Elem>
Link<Elem>& Link<Elem>::operator= (const Link<Elem>& src)
{
	Link<Elem> temp(src);
	swap(*this, temp);
	return *this;
}

//-----------------------------------------------------------------------------

template <class Elem>
bool Link<Elem>::operator== (const Link<Elem>& src) const
{
	return succ == src.succ && prev == src.prev;
}

//-----------------------------------------------------------------------------

template <class Elem>
bool Link<Elem>::operator!= (const Link<Elem>& src) const
{
	return !(*this == src);
}

//-----------------------------------------------------------------------------

template <class Elem>
void Link<Elem>::swap(Link<Elem>& src)
{
	std::swap(prev, src.prev);
	std::swap(succ, src.succ);
	std::swap(val, src.val);
}

//-----------------------------------------------------------------------------


template<class Elem>
void swap(Link<Elem>& lhs, Link<Elem>& rhs)
{
	lhs.swap(rhs);
}

//-----------------------------------------------------------------------------

template<class Elem>
List<Elem>::List()
	: first(new Link<Elem>()), last(first)
{

}

//-----------------------------------------------------------------------------

template<class Elem>
void List<Elem>::push_front(const Elem& v)
{ 
	first = new Link<Elem>(first, nullptr, v); 
	first->succ->prev = first;
}

//-----------------------------------------------------------------------------

template<class Elem>
Elem& List<Elem>::front()
{
	return first->val; 
}

//-----------------------------------------------------------------------------

template<class Elem>
size_t List<Elem>::size() 
{
	size_t count = 0;
	for (iterator p = begin(); p != end(); ++p)
	{
		++count;	 
	}
	return count;
}

//-----------------------------------------------------------------------------

template<class Elem>
void List<Elem>::print()
{
	for (iterator p = begin(); p != end(); ++p)
	{
		std::cout << *p <<' ';	 
	}
}

//-----------------------------------------------------------------------------

template<class Elem>
List<Elem>::iterator::iterator()
	: curr(nullptr), begin(nullptr), end(nullptr)
{

}

//-----------------------------------------------------------------------------

template<class Elem>
List<Elem>::iterator::iterator(Link<Elem>* p, Link<Elem>* b, Link<Elem>* e)
	: curr(p), begin(b), end(e)
{

}

//-----------------------------------------------------------------------------

template<class Elem>
List<Elem>::iterator::iterator(const iterator& src)
	: curr(src.curr), begin(src.begin), end(src.end)
{

}

//-----------------------------------------------------------------------------

template<class Elem>
typename List<Elem>::iterator List<Elem>::iterator::operator= (const iterator& src)
{
	iterator temp(src);
	this->swap(temp);
	return *this;
}

//-----------------------------------------------------------------------------

template<class Elem>
typename List<Elem>::iterator& List<Elem>::iterator::operator++()
{
	if (curr == end)
	{
		throw std::out_of_range("List<Elem>::iterator::operator++(): out of range!\n");
	}

	curr = curr->succ;

	return *this; 
}

//-----------------------------------------------------------------------------

template<class Elem>
typename List<Elem>::iterator List<Elem>::iterator::operator++(int)
{
	if (curr == end)
	{
		throw std::out_of_range("List<Elem>::iterator::operator++(): out of range!\n");
	}

	Link<Elem>* old = curr;
	curr = curr->succ;
	return old; 
}

//-----------------------------------------------------------------------------

template<class Elem>
typename List<Elem>::iterator& List<Elem>::iterator::operator--()
{ 
	if (curr == begin)
	{
		throw std::out_of_range("List<Elem>::iterator::operator--(): out of range!\n");
	}

	curr = curr->prev;
		
	return *this; 
}

//-----------------------------------------------------------------------------

template<class Elem>
typename List<Elem>::iterator List<Elem>::iterator::operator--(int)
{ 
	if (curr == begin)
	{
		throw std::out_of_range("List<Elem>::iterator::operator--(): out of range!\n");
	}

	iterator old(*this);
	curr = curr->prev;	
	return old; 
}

//-----------------------------------------------------------------------------

template<class Elem>
Elem& List<Elem>::iterator::operator*() 
{ 
	return curr->val; 
}	

//-----------------------------------------------------------------------------

template<class Elem>
const Elem& List<Elem>::iterator::operator*() const
{ 
	return curr->val;
}

//-----------------------------------------------------------------------------

template<class Elem>
bool List<Elem>::iterator::operator== (const iterator& b) const
{ 
	return curr == b.curr; 
} 

//-----------------------------------------------------------------------------

template<class Elem>
bool List<Elem>::iterator::operator!= (const iterator& b) const
{ 
	return curr != b.curr; 
}

//-----------------------------------------------------------------------------

template<class Elem>
void List<Elem>::iterator::swap(iterator& src)
{
	std::swap(curr, src.curr); 
	std::swap(begin, src.begin);
	std::swap(end, src.end);
}

//-----------------------------------------------------------------------------

template<class Elem>
void swap(typename List<Elem>::iterator& lhs, typename List<Elem>::iterator& rhs)
{
	lhs.swap(rhs);
}
 