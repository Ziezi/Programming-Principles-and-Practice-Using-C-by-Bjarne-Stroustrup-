/*
	TITLE		    Linked List			     Chapter20Exercise12.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Complete the definition of list from §20.4.1 - 2
					and get high() example to run. Allocate a List to
					represent one past the end.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 21. 02. 2017
*/

#ifndef Chapter20Exercise12_h
#define Chapter20Exercise12_h


template <class Elem>
struct Link
{
	Link()
		: succ(nullptr), prev(nullptr), val(Elem())
	{
	
	}

	Link (Link<Elem>* s, Link<Elem>* p, const Elem& v = Elem())
		: succ(s), prev(p), val(v)
	{
	
	}

	Link (const Link<Elem>& src)
		: succ(src.succ), prev(src.prev), val(src.val)
	{
	
	}

	Link<Elem>& operator= (const Link<Elem>& src)
	{
		Link<Elem> temp(src);
		swap(temp);
		return *this;
	}

	void swap(Link<Elem>& src)
	{
		Link<Elem> temp(src);

		src.succ = succ;
		src.prev = prev;
		src.val  = val;

		src = temp.src;
		prev = temp.prev;
		val = temp.val;
	}

	Link* succ;
	Link* prev;
	Elem val;
};

//-----------------------------------------------------------------------------

template<class Elem>
void swap(Link<Elem>& lhs, Link<Elem>& rhs)
{
	lhs.swap(rhs);
}

//-----------------------------------------------------------------------------

template <class Elem>
class List
{
public:
	class iterator;

	List()
		: first(new Link<Elem>()), last(first)
	{

	}

	iterator begin() { return iterator(first); }
	iterator end() { return iterator(last); }

	iterator insert(iterator p, const Elem& v); 				// insert before specified position; return it	
	iterator erase(iterator p);									// erase at specified position; return next
	 
	void push_back(const Elem& v);
	void push_front(const Elem& v) { first = new Link<Elem>(first, nullptr, v); }

	void pop_front();
	void pop_back();

	Elem& front() { return first->val; }
	Elem& back();

	size_t size() 
	{
		size_t count = 0;
		for (iterator p = begin(); p != end(); ++p)
		{
			++count;	 
		}
		return count;
	}

	void print()
	{
		for (iterator p = begin(); p != end(); ++p)
		{
			std::cout << *p <<' ';	 
		}
	}

private:
	Link<Elem> *first;
	Link<Elem> *last;
};

//-----------------------------------------------------------------------------

template <class Elem>
class List<Elem>::iterator
{
public:
	iterator(Link<Elem>* p)
		: curr(p)
	{
	
	}

	iterator& operator= (iterator& p)
	{
		curr = p.get_link();
		return *this;
	}

	iterator& operator++()
	{
		curr = curr->succ;
		
		return *this; 
	}

	iterator& operator--()
	{ 
		curr = curr->prev;
		
		return *this; 
	}

	Elem& operator*() { return curr->val; } 

	bool operator== (const iterator& b) const { return curr == b.curr; }
	bool operator!= (const iterator& b) const { return curr != b.curr; }

	Link<Elem>* get_link() { return curr; }

private:
	Link<Elem>* curr;
};

//-----------------------------------------------------------------------------

template <class Iterator>
Iterator high (Iterator first, Iterator last)
{
	Iterator high = first;
	for (Iterator p = first; p != last; ++p)
	{
		if (*high < *p)
		{
			high = p;
		}
	}
	return high;
}

#endif 