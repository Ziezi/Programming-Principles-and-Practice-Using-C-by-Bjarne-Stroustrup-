/*
	TITLE		    Linked list             Chapter17Exercise13.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Modify Link to include struct God,
				    containing members of type string:
					name, mythology, vehicle, weapon.
					Write: print_all(), add_ordered() functions.  
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 07.12.2015
*/

// modifying member functions

/*
	Member function: insert()
	 
	It inserts the new link 
	in before this object.
*/
Link* Link::insert (Link* n) 
{
	if (n == 0)
	{
		return this;
	}

	if (this == 0)
	{
		return n;
	}

	n->succ = this;
	n->prev = prev;
	
	if (prev) 
	{
		prev->succ = n;
	}

	prev = n;

	return n;
}

//------------------------------------------------------------------------
/*
	Member function: add()
	 
	It adds new link after this object.
*/
Link* Link::add (Link* n)
{

	if (n == 0 )
	{
		return this;
	}

	if (this == 0)
	{
		return n;
	}

	n->prev = this;

	if (succ) 
	{
		succ->prev = n;
	}

	n->succ = succ;
	succ = n;
	
	return n;
}

//------------------------------------------------------------------------
/*
	Member function: add_ordered()

	It inserts new link taking into
	consideration the God's name of 
	the current last Link such that 
	the name of the last and the
	new are in lexicographically 
	(increasing) order.
*/
Link* Link::add_ordered (Link* n) 
{
    if (n == 0) 
	{
		return this;
	}

	// new list: first node
    if (this == 0)
	{
		n->succ = 0;
        n->prev = 0;
		return n;
	}

    if (n->god < god)
	{
		Link* p = insert(n);   // first element has changed
		return p;
    }

    Link* p = this;

    while (!(n->god < p->god)) // >= not defined for God
	{
        if (p->succ==0) // last element reached
		{					
            p->add(n);      // attach to end of list
            return this;    // first element has not changed
        }

        p = p->succ;
    }

    p->insert(n);
    return this;
}

//------------------------------------------------------------------------
/*
	Member function: erase()
	 
	It erases the current object
	and connects its successor to
	its predecessor; returns successor.
*/
Link* Link::erase (void)
{
	if (this == 0)
	{
		return 0;
	}

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

//------------------------------------------------------------------------
/*
	Member function: find()
	 
	It returns the first successor link containing
	string name. Read and write permissions.
*/
Link* Link::find (const std::string& n)
{
	Link* p = this;

	while (p)
	{
		if (p->god.name == n) 
		{
			return p;
		}

		p = p->succ;
	}

	return 0;
}

//------------------------------------------------------------------------
// non - modifying member functions

/*
	Member function: find()
	 
	It returns the first successor link containing
	string value. Read permission only.
*/
const Link* Link::find(const std::string &n) const 
{
	const Link* p = this;
	
	while (p)
	{
		if (p->god.name == n)
		{
			return p;
		}

		p = p->succ;
	}

	return 0;	
}

//------------------------------------------------------------------------
/*
	Member function: advance()
	 
	It returns the link 
	found after n links, where
	n could be either positive or
	negative.
*/
Link* Link::advance (int n) 
{
	if (this == 0)
	{
		return 0;
	}

	Link* p = this;

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

	if (n > 0) 
	{
		while (n--) 
		{
			if (succ == 0) 
			{
				return 0;
			}

			p = succ;
		}
	}

	return p;
}

//------------------------------------------------------------------------
// non - member functions
/*
	Function: print_all_back_to_front();
	 
	It prints all nodes of the doubly linked
	list starting from the last and advancing
	to first node.
*/
void print_all_back_to_front(Link* n) 
{
	std::cout <<"{";
	while (n) 
	{
		std::cout << n->god;

		if (n = n->next()) 
		{
			std::cout <<'\n';
		}
	}
	std::cout <<"}";
}

//------------------------------------------------------------------------
/*
	Function: print_all_front_to_back();
 
	It prints all nodes of the doubly linked
	list starting from the last and advancing
	to first node.
*/
void print_all_front_to_back(Link* n) 
{
	std::cout <<"{";
	while (n) 
	{
		std::cout << n->god;

		if (n = n->previous()) 
		{
			std::cout <<'\n';
		}
	}
	std::cout <<"}";
}

//------------------------------------------------------------------------
/*
	Function: order_list ();
	 
	It uses src link ptr to create a 
	lexicograhically ordered list:
	dest link ptr, in terms of God's name.  
*/
void order_list (Link* src, Link*& dest) 
{
	// traverse src from back to front
	while (src)
	{
		// use src's God element to create a new Link as an element of an ordered List
		dest = dest->add_ordered(new Link(God(src->god.name,
			                                  src->god.mythology,
											  src->god.vehicle,
											  src->god.weapon)));

		src = src->next();
	}  
}