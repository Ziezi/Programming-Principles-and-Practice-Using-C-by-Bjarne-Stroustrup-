/* 
	TITLE		   C Doubly Linked List					 Chapter27TryThis3.c
	COMMENT
		Objective: Rewrite the intrusive list example in C++, showing how to 
				   make it shorter and easier to use without making the code 
				   slower or the objects bigger. 
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 09.06.2017
*/
#include <stdlib.h>		// malloc
#include <stdio.h>		// printf
#include <assert.h>		// assert

//--------------------------------------------------------------------------

typedef struct Link
{
	struct Link* next;
	struct Link* prev;
} Link;

//--------------------------------------------------------------------------

typedef struct List
{
	Link* first;
	Link* last;
} List;

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

typedef struct Name
{
	Link l;
	char* s;
} Name;

//--------------------------------------------------------------------------

Name* make_name(char* str)
{
	Name* n = (Name*) malloc(sizeof(Name));
	n->s = str;

	return n;
}

//--------------------------------------------------------------------------

#ifdef __cplusplus	


#else  // compiling in C(89?). 

int main ()
{
	List* lst = create();

	char* names[ ] = { "Giorikas", "Kostikas", "Foo", "Bar", "Gosho", "Pesho" };
	char* name;

	int i = 0;
	int size = 6;

	for (i; i < size; ++i)
	{
		push_back(lst, (Link*)(make_name(names[i])));

		name = ((Name*)(lst->last))->s;
		printf("Name: %s \n", name);
	}

	destroy(lst);

	getchar();

	return 0;
}

#endif
 