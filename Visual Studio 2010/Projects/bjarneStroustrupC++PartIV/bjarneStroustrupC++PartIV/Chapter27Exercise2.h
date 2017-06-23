/* 
	TITLE		   Intrusive Linked List   Chapter27Exercise2.h
	COMMENT
		Objective: Complete the intrusive list example in §27.9
				   and test it using every function.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 12.06.2017
*/
#ifndef Chapter27Exercise2_h
#define Chapter27Exercise2_h

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

void init(List* lst);
List* create();

void push_back(List* lst, Link* l);
void push_front(List* lst, Link* l);
void insert(List* lst, Link* ref, Link* l);		// insert l before ref
Link* erase(List* lst, Link* l);				// erase l and return next/(prev if ref == last)
Link* advance(Link* l, int n);

void clear (List* lst);
void destroy (List* lst);

size_t list_size(List* lst);

//--------------------------------------------------------------------------

typedef struct Name
{
	Link l;
	char* s;
} Name;

//--------------------------------------------------------------------------

Name* make_name(char* str);
void print_names(List* lst);
Link* find(List* lst, char* name);				// search "name" in lst; return 0 if not found

//--------------------------------------------------------------------------

#include "Chapter27Exercise2Def.c"

#endif