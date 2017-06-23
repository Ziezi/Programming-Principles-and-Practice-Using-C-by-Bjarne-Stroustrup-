/* 
	TITLE	       Change the Representation of DList		    Chapter27Exercise6Def.cpp
	COMMENT
		Objective: Change the representation of Link and List from §27.9 without changing
				   the user interface provided by the functions. 
				   Allocate Links in an array of Links and have the members:
				   first, last, prev, and next be ints (indices into the array).  
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 13.06.2017
*/

template <typename T>
int DList<T>::get_index()
{
	for (int i = 0; i < list_size; ++i)
	{
		if (available[i] == true) 
		{
			available[i] = false;
			return i;
		}
	}
	throw std::out_of_range("DList::get_index()::DList Overflow!\n");
}

//--------------------------------------------------------------------------

template <typename T>
void DList<T>::return_index(int i)
{
	if (available[i])
	{
		throw std::invalid_argument("Dlist::return_index()::Memory already free!\n");
	}

	available[i] = true;

	delete head[i];
}

//--------------------------------------------------------------------------

template <typename T>
void DList<T>::create()
{
	list_size = 30;
	head = new T* [list_size];
	available = new bool [list_size];

	if (!head)
	{
		throw std::bad_alloc("List::create::bad_alloc!\n");
	}
	 
	init();
}

//--------------------------------------------------------------------------

template <typename T>
void DList<T>::init()
{
	first = -1;
	last = -1;

	for (int i = 0; i < list_size; ++i)
	{
		available[i] = true;
	}
}

//--------------------------------------------------------------------------

template <typename T>
void DList<T>::clear()
{
	if (head)
	{
		first = -1;
		last = -1;

		for (int i = 0; i < list_size; ++i)
		{
			if(available[i] == false)
			{
				return_index(i);
			}
		}
	}
}

//--------------------------------------------------------------------------

template <typename T>
void DList<T>::destroy()
{
	if (head)
	{
		clear();

		delete[] head;
		delete available;
	}
}

//--------------------------------------------------------------------------

template <typename T>
DList<T>::DList()
{
	create();
}

//--------------------------------------------------------------------------

template <typename T>
DList<T>::~DList()
{
	destroy();
}

//--------------------------------------------------------------------------

template <typename T>
T* DList<T>::erase(T* l)
{
	if (!l) 
	{
		return nullptr;
	}

	if (l == front())					// if link is the first
	{
		if (l->next)			 
		{
			first = l->next;
			head[l->next]->prev = -1;

			return head[l->next];
		}	
		else							 
		{
			first = -1;
			last = -1;

			return nullptr;
		}
	}
	else if (l == back())				// if the link is the last
	{
		if (l->prev)			 
		{
			last = l->prev;
			head[l->prev]->next = -1;

			return head[l->prev];
		}	
		else							 
		{
			last = -1;
			first = -1;

			return nullptr;
		}
	}
	else								// link is somewhere inbetween
	{
		head[l->next]->prev = l->prev;
		head[l->prev]->next = l->next;

		return head[l->next];
	}
}

//--------------------------------------------------------------------------

template <typename T>
void DList<T>::push_back(T* l)
{
	if (l == nullptr)
	{
		throw std::invalid_argument("Dlist::push_back()::Null pointer as argument!\n");
	}

	int index = get_index();
	head[index] = l;

	if (last != -1)
	{
		head[last]->next = index;
		head[index]->prev = last;
	}
	else
	{
		first = index;
		head[index]->prev = -1;
	}

	last = index;
	head[index]->next = -1;
}

//--------------------------------------------------------------------------

template <typename T>
void DList<T>::push_front(T* l)
{
	if (l == nullptr)
	{
		throw std::invalid_argument("Dlist::push_front()::Null pointer as argument!\n");
	}

	int index = get_index();
	head[index] = l;

	if (first != -1)
	{
		head[first]->prev = index;
		head[index]->next = first;
	}
	else
	{
		last = index;
		head[index]->next = -1;
	}

	first = index;
	head[index]->prev = -1;
}

//--------------------------------------------------------------------------

template <typename T>
void DList<T>::insert(T*& ref, T* l)
{
	if (ref == nullptr || l == nullptr)
	{
		throw std::invalid_argument("Dlist::insert()::Null pointer as argument!\n");
	}

	int index = get_index();
	head[index] = l;

	head[index]->next = link_index(ref);

	if (ref == front())
	{
		head[index]->prev = -1;
		
		first = index;
	}
	else if (ref == back())
	{
		if (ref->prev != -1)
		{
			head[index]->prev = ref->prev;

			head[ref->prev]->next = index;
		}
		else
		{
			head[index]->prev = -1;
		}
	}
	else
	{ 
		 head[index]->prev = ref->prev;

		 head[ref->prev]->next = index;
	} 

	ref->prev = index;
}

//--------------------------------------------------------------------------

template <typename T>
T* DList<T>::advance(T* l, int n)
{
	if (l == nullptr || (l < head[0] || l > head[list_size - 1]))
	{
		throw std::invalid_argument("Dlist::advance()::Null pointer as argument!\n");
	}
	
	int index = link_index(l);

	if (n > 0)
	{
		while (n--)
		{
			index = head[index]->next;
		}
	}
	else
	{
		while (n++)
		{
			index = head[index]->prev;
		}
	}

	return head[index];
}

//--------------------------------------------------------------------------

template <typename T>
std::size_t DList<T>::size() const
{
	std::size_t s = 0;

	int index = first;

	if (index != -1)
	{
		++s;
		while (head[index]->next != -1)
		{		 
			index = head[index]->next;
			++s;
		}
	}

	return s;
}

//--------------------------------------------------------------------------

template <typename T>
void DList<T>::print() const
{
	int index = first;

	if (index != -1)
	{
		while (head[index]->next != -1)
		{
			std::cout << reinterpret_cast<Name*>(head[index])->s <<'\n';
			index = head[index]->next;
		}
	}
}

//--------------------------------------------------------------------------
 
template <typename T>
T* DList<T>::find(const std::string& name) const
{
	int index = first;

	if (index != -1)
	{
		while (head[index]->next != -1)
		{
			std::string s = reinterpret_cast<Name*>(head[index])->s;

			if (s == name)
			{
				return head[index];
			}

			index = head[index]->next;
		}
	}

	return back();
}

//--------------------------------------------------------------------------
 
