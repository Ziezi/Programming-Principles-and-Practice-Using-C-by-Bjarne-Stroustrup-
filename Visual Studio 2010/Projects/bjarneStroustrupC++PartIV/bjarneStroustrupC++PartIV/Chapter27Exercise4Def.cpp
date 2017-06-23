/* 
	TITLE	       Intrusive Doubly Linked List in C++ Chapter27Exercise4Def.cpp
	COMMENT
		Objective: If you didn't already, write a C++ version of the intrusive
				   list example in §27.9 and test it using every function. 
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 13.06.2017
*/

void DList::create()
{
	head = new List;

	if (!head)
	{
		throw std::bad_alloc("List::create::bad_alloc!\n");
	}
	 
	init();
}

//--------------------------------------------------------------------------

void DList::init()
{
	head->first = nullptr;
	head->last = nullptr;
}

//--------------------------------------------------------------------------

void DList::clear()
{
	if (!head)
	{
		Link* curr = head->first;
		
		while (curr)
		{
			Link* succ = curr->next;

			delete curr;

			curr = succ;
		}

		head->first = nullptr;
		head->last = nullptr;
	}
}

//--------------------------------------------------------------------------

void DList::destroy()
{
	if (head)
	{
		clear();

		delete head;
	}
}

//--------------------------------------------------------------------------

DList::DList()
{
	create();
}

//--------------------------------------------------------------------------

DList::~DList()
{
	destroy();
}

//--------------------------------------------------------------------------

Link* DList::erase(Link* l)
{
	if (!l) 
	{
		return nullptr;
	}

	if (l == front())					// if link is the first
	{
		if (l->next)			 
		{
			head->first = l->next;
			l->next->prev = nullptr;

			return l->next;
		}	
		else							 
		{
			head->first = nullptr;
			head->last = nullptr;

			return nullptr;
		}
	}
	else if (l == back())				// if the link is the last
	{
		if (l->prev)			 
		{
			head->last = l->prev;
			l->prev->next = nullptr;

			return l->prev;
		}	
		else							 
		{
			head->last = nullptr;
			head->first = nullptr;

			return nullptr;
		}
	}
	else								// link is somewhere inbetween
	{
		l->next->prev = l->prev;
		l->prev->next = l->next;

		return l->next;
	}
}

//--------------------------------------------------------------------------

void DList::push_back(Link* l)
{
	if (l == nullptr)
	{
		throw std::invalid_argument("Dlist::push_back()::Null pointer as argument!\n");
	}

	if (back() != nullptr)
	{
		head->last->next = l;
		l->prev = back();
	}
	else
	{
		head->first = l;
		l->prev = nullptr;
	}

	head->last = l;
	l->next = nullptr;
}

//--------------------------------------------------------------------------

void DList::push_front(Link* l)
{
	if (l == nullptr)
	{
		throw std::invalid_argument("Dlist::push_front()::Null pointer as argument!\n");
	}

	if (front() != nullptr)
	{
		head->first->prev = l;
		l->next = front();
	}
	else
	{
		head->last = l;
		l->next = nullptr;
	}

	head->first = l;
	l->prev = nullptr;
}

//--------------------------------------------------------------------------

void DList::insert(Link* ref, Link* l)
{
	if (ref == nullptr || l == nullptr)
	{
		throw std::invalid_argument("Dlist::insert()::Null pointer as argument!\n");
	}

	l->next = ref;

	if (ref == front())
	{
		l->prev = nullptr;
		
		head->first = l;
	}
	else if (ref == back())
	{
		if (ref->prev != nullptr)
		{
			l->prev = ref->prev;

			ref->prev->next = l;
		}
		else
		{
			l->prev = nullptr;
		}
	}
	else
	{ 
		 l->prev = ref->prev;

		 ref->prev->next = l;
	} 

	ref->prev = l;
}

//--------------------------------------------------------------------------

Link* DList::advance(Link* l, int n)
{
	if (l == nullptr)
	{
		throw std::invalid_argument("Dlist::advance()::Null pointer as argument!\n");
	}

	Link* curr = l;

	if (n > 0)
	{
		while (n--)
		{
			curr = curr->next;
		}
	}
	else
	{
		while (n++)
		{
			curr = curr->prev;
		}
	}

	return curr;
}

//--------------------------------------------------------------------------

std::size_t DList::size() const
{
	std::size_t s = 0;

	Link* curr = front();

	while (curr != nullptr)
	{		 
		curr = curr->next;
		++s;
	}

	return s;
}

//--------------------------------------------------------------------------

void DList::print() const
{
	Link* curr = front();

	while (curr)
	{
		std::cout << reinterpret_cast<Name*>(curr)->s <<'\n';
		curr = curr->next;
	}
}

//--------------------------------------------------------------------------

Link* DList::find(const std::string& name) const
{
	Link* curr = front();

	while (curr)
	{
		std::string s = reinterpret_cast<Name*>(curr)->s;

		if (s == name)
		{
			return curr;
		}

		curr = curr->next;
	}

	return back();
}

//--------------------------------------------------------------------------

 
