/*
	TITLE		    Singly Linked List		  Chapter20Exercise14.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define a singly-linked list, `slist`, 
				    in the style of `std::list`.
					Which operations from `List` should be kept?   
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 22. 02. 2017
*/

#ifndef Chapter20Exercise14_h
#define Chapter20Exercise14_h

template <class Elem>
struct Link
{
	Link()
		: succ(nullptr), val(Elem())
	{
	
	}

	Link (Link<Elem>* s, const Elem& v = Elem())
		: succ(s), val(v)
	{
	
	}

	Link (const Link<Elem>& src)
		: succ(src.succ), val(src.val)
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
		src.val  = val;

		src = temp.src;
		val = temp.val;
	}

	Link* succ;
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
class SList
{
public:
	class iterator;

	SList()
		: first(0)
	{

	}

	iterator begin() { return iterator(first); }
	iterator end() { return iterator(0); }

	iterator insert(iterator p, const Elem& v)  				// insert after specified position; return it	
	{
		Link<Elem>* curr = p.get_link();
		Link<Elem>* new_next = new Link<Elem>(curr->succ, v);
		curr->succ = new_next;
		
		return iterator(new_next);
	}

	iterator erase(iterator p)									// erase next to specified position; return next
	{
		Link<Elem>* curr = p.get_link();
		Link<Elem>* next = curr->succ;

		if (next->succ) // skip next
		{
			curr->succ = next->succ;
		}
		else			// current becomes back()
		{
			curr->succ = nullptr;
		}

		delete next;	// free next

		return p;
	}

	void push_back(const Elem& v)
	{
		iterator b = tail();
		Link<Elem>* bb = b.get_link();
		insert(bb, v);
	}

	void push_front(const Elem& v) { first = new Link<Elem>(first, v); }

	void pop_front()
	{
		Link<Elem>* next = first->succ;
		delete first;
		first = next;
	}

	void pop_back()
	{
		if (begin() == end())			 // empty list
		{
			return; 
		}

		iterator tail_iter = tail();	 // return back()

		iterator tail_prev = begin();	 // back() - 1
		iterator p = begin();
		while (p != tail_iter)
		{
			tail_prev = p;
			++p;
		}

		if (tail_prev == begin())		// single element
		{
			tail_prev = tail_iter;
		}

		erase(tail_prev);
	}

	Elem& front() { return first->val; }
	Elem& back() 
	{
		iterator b = tail();
		Link<Elem>* bb = b.get_link();
		return bb->val;
	}

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

	 
	iterator tail()												// returns an iterator to the last link
	{
		iterator last_to_end = begin();
		iterator p = begin();
		while (p != end())
		{
			last_to_end = p;
			++p;
		}
		return last_to_end;
	}

private:
	Link<Elem> *first;
};

//-----------------------------------------------------------------------------

template <class Elem>
class SList<Elem>::iterator
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