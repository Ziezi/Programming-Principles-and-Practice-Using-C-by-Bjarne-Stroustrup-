/*
	TITLE		    Linked list             Chapter17Exercise11.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Complete and run the example from 17.10.1.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 07.12.2015
*/
 
/*
	Member function: insert()
	 
	It inserts new link object
	before the n-th instant and
	after the (n-1)-th Link.
*/
Link* Link::insert(Link* n) 
{
	// check if these links are null pointers
	if (n == 0)
	{
		return this;
	}

	if (this == 0) 
	{
		return n;
	}

	// rewire (n-1), n and (n+1)-th Link to account for the new n-th
	n->succ = this; // this object is following the newly inserted

	if (prev) 
	{
		prev->succ = n; // if there is a previous link, its successor is n
	}

	n->prev = prev; // n points to prev
	prev = n; // this object previous is n

	return n;
}

//---------------------------------------------------------------------------------
/*
	Member function: add()
	 
	It inserts new link object
	after the n-th instant. 
*/
Link* Link::add(Link *n)
{
	// check if this or n are null pointers
	if (n == 0)
	{
		return this;
	}

	if (this == 0)
	{
		return n;
	}

	// rewire n-th and new (n+1)-th Link
	succ = n; // this points to n, which is the new last element
	n->prev = this; 
	n->succ = nullptr;

	return this;
}  

//---------------------------------------------------------------------------------
/*
	Member function: erase()
	 
	It erases the n-th instant. 
*/
Link* Link::erase()
{
	// check if this is already a null Link
	if (this == 0) 
	{
		return 0;
	}

	// connect the predecessor with successor, to skip the deleted, if any
	if (prev) 
	{
		prev->succ = succ;
	}

	if (succ) 
	{
		succ->prev = prev;
	}

	return succ;
}  

//---------------------------------------------------------------------------------
/*
	Member function: find()
	 
	It returns the first successor link containing
	string value. Read and write permissions.
*/
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
	string value. Read permission only.
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
/*
	Member function: advance()
	 
	It returns the link found after 
	"n" links, in any direction: positive or negative.
*/
Link* Link::advance (int n)
{
	// check if current object nullptr
	if (this == 0) 
	{
		return 0;
	}

    Link* p = this;

	// traversal is in "positive" direction, toward successors
	if (n > 0) 
	{
		while (n--) // loop till: n != 0
		{
			if (succ == 0) 
			{
				return 0;
			}
			
			p = succ;
		}
	}

	// traversal is in "negative" direction, towards predecessors
	if (n < 0)
	{
		while (n++) 
		{
			if (prev == 0)
			{
				return 0;
			}

			p = prev;
		}
	}
	 
	return p;
}

//---------------------------------------------------------------------------------
/*
	Function: print_all()
*/
void print_all (Link* p)
{
	std::cout << "{";
	while (p) 
	{
		std::cout << p->value;
		if (p = p->next())
		{
			std::cout <<",";
		}
	}
	std::cout << "}";
}

 