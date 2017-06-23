/*
	TITLE			Templatized Linked List    Chapter19Exercise4.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Modify class Link from Chapter 17.9.3 to be a 
		            template with the type of a value  as the 
					template argument.
					Redo Exercise 13 Chapter 17 with Link<God>.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 21.1.2016
*/

#ifndef CHAPTER18EXERCISE_H
#define CHAPTER18EXERCISE_H

// data structure used as  a node, i.e.: data member: value,  in the Linked list
struct God 
{
	// public members of God
	std::string name;
	std::string mythology;
	std::string vehicle;
	std::string weapon;

	// constructor
	God (std::string n = " ", std::string m = " ", std::string v = " ", std::string w = " ")
		: name(n), mythology(m), vehicle(v), weapon(w) 
	{ 
	
	}

	// copy constuctor
	God (const God& src)
		: name(src.name), mythology(src.mythology), vehicle(src.vehicle), weapon(src.weapon) 
	{
	
	}

	// assingment operator
	God& operator= (const God& src)
	{
		if (this == &src) 
		{
			return *this;
		}

		name = src.name;
		mythology = src.mythology;
		vehicle = src.vehicle;
		weapon = src.weapon;

		return *this;
	}

	// friend member operators
	friend std::ostream& operator<< (std::ostream& os, const God& g);
	friend bool operator< (const God& lhs, const God& rhs);
	friend bool operator> (const God& lhs, const God& rhs);
};

//---------------------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const God& g) 
{
	os <<"{"<< g.name<<", "<< g.mythology <<", "<< g.vehicle <<", "<< g.weapon <<"}";
	return os;
}

//---------------------------------------------------------------------------------------------

// order by name
bool operator< (const God& lhs, const God& rhs)
{
	return lhs.name < rhs.name;
}

//---------------------------------------------------------------------------------------------

bool operator> (const God& lhs, const God& rhs) 
{
	return lhs.name > rhs.name;
}

//---------------------------------------------------------------------------------------------

class Node 
{
	std::string value;

	friend std::ostream& operator<< (std::ostream& os, const Node& g);
	friend bool operator< (const Node& lhs, const Node& rhs);
	friend bool operator> (const Node& lhs, const Node& rhs);
};

//---------------------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const Node& g)
{
	os << g.value ;
	return os;
}

//---------------------------------------------------------------------------------------------

bool operator< (const Node& lhs, const Node& rhs)
{
	return lhs.value < rhs.value;
}

//---------------------------------------------------------------------------------------------

bool operator> (const Node& lhs, const Node& rhs) 
{
	return lhs.value > rhs.value;
}

//---------------------------------------------------------------------------------------------
// doubly linkes list accepting any object type as its data member (value)
template<class T>
class Link 
{
public:
	// public data member
	T value;

	// conatructor
	Link<T> (T v, Link<T>* p = 0, Link<T>* s = 0)
		: value(v), prev(p), succ(s) 
	{
	
	}

	// copy constructor
	// value must have copu constructor implemented
	Link<T> (const Link<T>& l) 
		: value(l.value), prev(l.next()), succ(l.previous()) 
	{
	
	}

	// non-modifying members
	Link<T>* next () const { return succ; }
	Link<T>* previous () const { return prev; }
	Link<T>* advance (int n) const;

	// modifying members
	Link<T>* insert (Link<T>* n);
	Link<T>* add (Link<T>* n);
	Link<T>* add_ordered (Link<T>* n);
	Link<T>* erase(void);
private:
	// private data members
	Link<T>* prev;
	Link<T>* succ;
};

//---------------------------------------------------------------------------------------------

// class Link member implementations

// non-modifying members
/*
	Function: advance()
	Use: link_object.advance(signed_int);

	It advances to the "signed_int" node
	in both directions of the linkes list;
	otherwise it returns failure, to indicate
	no such node, in the form of "0".
*/
template<class T>
Link<T>* Link<T>::advance (int n) const 
{
	if (!this) 
	{
		return 0;
	}

	Link<T>* p = this;
	if (n > 0)
	{
		while(n--)
		{
			if (!succ) 
			{
				return 0;
			}
			p = succ;
		}
	}

	if (n < 0)
	{
		while (n++)
		{
			if (!prev)
			{
				return 0;
			}
			p = prev;
		}
	}
	return p;
}

//---------------------------------------------------------------------------------------------

// modifying members
/*
	Function: insert()
	Use: link_object.insert(new_link_node);

	It inserts the node passed as a parameter
	before the node currently pointed to.
*/
template<class T>
Link<T>* Link<T>::insert (Link<T>* n) 
{
	if (!n) 
	{
		return this;
	}

	if (!this) 
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

//---------------------------------------------------------------------------------------------

/*
	Function: add()
	Use: link_object.add(new_link_node);

	It inserts the node passed as a parameter
	after the node currently pointer to.
*/
template<class T>
Link<T>* Link<T>::add (Link<T>* n) 
{
	if (!n)
	{
		return this;
	}

	if (!this) 
	{
		return n;
	}

	// n->succ = nullptr;
	n->succ = succ;
	n->prev = this;
	succ = n;

	if (n->succ) 
	{
		n->succ->prev = n;
	}

	return n;
}

//---------------------------------------------------------------------------------------------

/*
	Function: add_ordered()
	Use: link_object.add_ordered();

	It inserts the new node such that 
	current node and new node in
	lexicographical order; returns 
	pointer to first node. 
   
	First node in ordered list contains the 
	lexicographically smaller value.

	It assumes argument is the head.
*/
template<class T>
Link<T>* Link<T>::add_ordered (Link<T>* n) 
{
    if (!n)
	{
		return this;
	}

	if (!this) 
	{
		return n;
	}

	Link<T>* head = this; 
	if (n->value > head->value) 
	{
		return insert(n); // add before current (last) node
	}
	
	Link<T>* current_node = this; 
	while (current_node)
	{
		if (n->value > current_node->value) 
		{
			add(n); // splice node
			return this;
		}
		current_node = current_node->previous();
	} 

    add(n); // insert after current (first) node
    return this;
}

//---------------------------------------------------------------------------------------------

/*
	Function: erase()
	Use: link_object.erase(void);

	It erases the currently
	pointer to node.
*/
template<class T>
Link<T>* Link<T>::erase (void)
{
	if (!this) 
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

//---------------------------------------------------------------------------------------------

// Non-member functions
/*
	Function: print();
	Use: print(link_object);

	It assumes that link_object
	is eihter head or tail pointer;
	It traverses and prints all the
	data members of the nodes, given
	that nodes have operator<< overloaded.
*/
template<class T>
void print(Link<T>* n) 
{
	Link<T>* tail = n;
	if (tail->next())
	{
		std::cout <<"[";
		while (tail) 
		{
			std::cout << tail->value;

			if (tail = tail->next()) 
			{
				std::cout <<"\n";
			}
		}
		std::cout <<"]";
	} 
	else if (tail->previous()) 
	{
		std::cout <<"[";
		while (tail) 
		{
			std::cout << tail->value;
			if (tail = tail->previous())
			{
				std::cout <<"\n";
			}
		}
		std::cout <<"]";
	}
}

//---------------------------------------------------------------------------------------------

/*
	Function: order_list ()
	Use: order_list (src_list, dest_list);

	It traverses src_list and builds
	ordered dest_list, assuming that 
	Link nodes have copy constructor
	implemented.
*/
template<class T>
void order_list (Link<T>* src, Link<T>*& dest) 
{
	while (src)
	{	
		Link<T> l(src->value, nullptr, nullptr);
		dest = dest->add_ordered(new Link<T>(l));
		src = src->next();
	}  
}

#endif