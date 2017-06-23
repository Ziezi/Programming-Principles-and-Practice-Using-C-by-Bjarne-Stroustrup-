/* 
	TITLE		   Intrusive Linked List   Chapter27Exercise2Def.c
	COMMENT
		Objective: Complete the intrusive list example in §27.9
				   and test it using every function.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 12.06.2017
*/

//--------------------------------------------------------------------------

void init(List* lst)
{
	assert(lst);

	lst->first = 0;
	lst->last = 0;
}

//--------------------------------------------------------------------------

List* create()
{
	List* lst = (List*) malloc(sizeof(List));

	init(lst);

	return lst;
}

//--------------------------------------------------------------------------

void push_back(List* lst, Link* l)
{
	assert(l);
	assert(lst);
	{
		Link* last = lst->last;

		if (last)
		{
			last->next = l;
			l->prev = last;
		}
		else
		{
			lst->first = l;
			l->prev = 0;
		}

		lst->last = l;
		l->next = 0;
	}
}

//--------------------------------------------------------------------------

void push_front(List* lst, Link* l)
{
	assert(lst);
	assert(l);
	{
		Link* first = lst->first;

		if (first)
		{
			first->prev = l;
			l->next = first;
		}
		else
		{
			lst->last = l;
			l->next = 0;
		}

		lst->first = l;
		l->prev = 0;
	}
}

//--------------------------------------------------------------------------

// insert l before ref
void insert(List* lst, Link* ref, Link* l)
{
	assert(lst);
	assert(ref);
	assert(l);
	{
		l->next = ref;

		if (ref == lst->first)			// ref is first
		{
			l->prev = 0;
			
			lst->first = l;
		}
		else if (ref == lst->last)		// ref is last
		{
			if (ref->prev)
			{
				l->prev = ref->prev;

				ref->prev->next = l;
			}
			else
			{
				l->prev = 0;
			}
		}
		else							// ref is in between
		{
			l->prev = ref->prev;

			ref->prev->next = l;
		}

		ref->prev = l;
	}
}

//--------------------------------------------------------------------------

Link* erase(List* lst, Link* l)
{
	assert(lst);
	if (l == 0) return 0;

	if (l == lst->first)
	{
		if (l->next)
		{
			lst->first = l->next;
			l->next->prev = 0;

			return l->next;
		}
		else
		{
			lst->first = 0;
			lst->last = 0;

			return 0;
		}
	}
	else if (l == lst->last)
	{
		if (l->prev)
		{
			lst->last = l->prev;
			l->prev->next = 0;

			return l->prev;
		}
		else
		{
			lst->first = 0;
			lst->last = 0;
			
			return 0;
		}
	}
	else
	{
		l->next->prev = l->prev;
		l->prev->next = l->next;

		return l->next;
	}
}

//--------------------------------------------------------------------------

Link* advance(Link* l, int n)
{
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

void clear (List* lst)
{
	assert(lst);
	{
		Link* curr = lst->first;
		Link* succ = 0;

		while (curr)
		{
			succ = curr->next;

			free(curr);

			curr = succ;
		}

		lst->first = 0;
		lst->last = 0;
	}
}

//--------------------------------------------------------------------------

void destroy (List* lst)
{
	assert(lst);

	clear(lst);
	
	free(lst);
}

//--------------------------------------------------------------------------

size_t list_size(List* lst)
{
	assert(lst);
	{
		Link* curr = lst->first;
		size_t size = 0;

		while (curr)
		{
			++size;
			curr = curr->next;
		}

		return size;
	}
}

//--------------------------------------------------------------------------

Name* make_name(char* str)
{
	Name* n = (Name*) malloc(sizeof(Name));

	assert(str);
	assert(n);
	{
		n->s = str;
	}

	return n;
}

//--------------------------------------------------------------------------

void print_names(List* lst)
{
	assert(lst);
	{
		Link* curr = lst->first;
		char* n = 0;

		while (curr)
		{
			n = ((Name*)(curr))->s;
			printf("Name: %s\n", n);

			curr = curr->next;
		}
	}
}

//--------------------------------------------------------------------------

// Complexity O(n)
Link* find(List* lst, char* n)
{
	assert(lst);
	assert(n);
	{
		Link* curr = lst->first;
		char* name = 0;

		while (curr)
		{
			name = ((Name*)(curr))->s;

			if (strcmp(name, n) == 0)
			{
				return curr;
			}

			curr = curr->next;
		}

		return 0;
	}
}

//--------------------------------------------------------------------------