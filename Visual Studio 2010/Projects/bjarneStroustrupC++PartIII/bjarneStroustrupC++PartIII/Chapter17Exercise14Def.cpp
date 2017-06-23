/*
	TITLE		    Singly Linked list   Chapter17Exercise14Def.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Reimplement the example from Chapter 17.10.1
		            and modify it to a sinlgly-linked list.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 21.12.2015
*/

 
// non-modifying members
/*
	It adds a new node after this object, 
	and before next, if it exists.
*/
Singly_linked_list* Singly_linked_list::add(Singly_linked_list* n) 
{
	if (!n)
	{
		return this;
	}

	if (!this) 
	{
		return n;
	}

	if (succ)
	{ 
		n->succ = succ;
	}
	else
	{
		n->succ = nullptr;
	}

	succ = n;

	return n;
}

//-----------------------------------------------------------------------
/*
	It inserts a node before current.

*/
Singly_linked_list* Singly_linked_list::insert(Singly_linked_list* n) 
{
	if (!this) 
	{
		return n;
	}

	if (!n)
	{
		return this;
	}

	n->succ = this;

	// return last node
	return n;
}

//-----------------------------------------------------------------------

/*
	Erase next object and return current.
*/
Singly_linked_list* Singly_linked_list::erase() 
{
	if (!this) 
	{
		return 0;
	}

	if (!succ) 
	{
		return this;
	}

	if (succ->succ) 
	{
		succ = succ->succ ;
		succ->succ = nullptr;
	}
	else 
	{
		succ = nullptr;
	}

	return this;
}

//-----------------------------------------------------------------------
/*
	Find element containing value identical with the argument.
	Assumes traversing starts from last node in the list.
*/
const Singly_linked_list* Singly_linked_list::find(const std::string& v) const 
{
	const Singly_linked_list* p = this;

	while (p) 
	{
		if (v == p->value)
		{
			return p;
		}

		p = p->succ;
	}

	return 0;
}

//-----------------------------------------------------------------------
/*
	It advance forward n times, if there are n elements in front.
*/
Singly_linked_list* Singly_linked_list::advance (unsigned int n) 
{
	if (!this) 
	{
		return 0;
	}

	Singly_linked_list* p = this;

	while (n--)
	{
		if (!p->succ) 
		{
			return 0;
		}

		p = p->succ;
	}

	return p;
}

//-----------------------------------------------------------------------
// non-member functions
void print_all (Singly_linked_list* src)
{
	std::cout <<"{";
	while (src) 
	{
		std::cout << src->value;

		if (src = src->next()) 
		{
			std::cout <<", ";
		}
	}
	std::cout <<"}";
}
