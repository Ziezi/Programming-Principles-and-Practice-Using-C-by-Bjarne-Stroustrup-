/* 
	TITLE		   Intrusive Linked List   Chapter27Exercise2.c
	COMMENT
		Objective: Complete the intrusive list example in §27.9
				   and test it using every function.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 12.06.2017
*/
#include <stdio.h>		// printf
#include <stdlib.h>		// malloc
#include <assert.h>		// assert
#include <string.h>		// strcmp
#include "Chapter27Exercise2.h"

#ifdef __cplusplus

#else	// compiling in C.

int main()
{
	// test create() and init()
	List* lst = create();
	Link* curr = 0;

	char* names1 [ ] = { "Epictetus", "Aurelius", "Epicurus", "Jesus", "Smith", "Marx", "Chomsky", "Jijek", "Varoufakis", "Corbin" };
	char* names2 [ ] = { "Copernikus", "Galilei", "Newton", "Hertz", "Maxwell", "Lorenz", "Minkowski", "Planck", "Einstein", "Musk" };
	char* name = 0;

	int size = 10;
	int i = 0;

	// test push_front()
	for (i; i < size; ++i)
	{
		push_front(lst, (Link*)(make_name(names1[i])));
	}
	assert(list_size(lst) == size);

	// test list_size()
	printf("List Size: %d\n", list_size(lst));

	// test push_back()
	i = 0;
	for (i; i < size; ++i)
	{
		push_back(lst, (Link*)(make_name(names2[i])));
	}
	assert(list_size(lst) == (2 * size));

	// test print_names()
	print_names(lst);

	printf("Second Part\n\n\n");
	// test erase()  
	erase(lst, lst->first);
	assert(list_size(lst) == ((2 * size) - 1));

	printf("List Size: %d\n", list_size(lst));
	print_names(lst);
	getchar();

	// test insert()
	insert(lst, lst->first, (Link*)(make_name(names1[9])));
	assert(list_size(lst) == (2 * size));

	printf("List Size: %d\n", list_size(lst));
	print_names(lst);
	getchar();

	// test erase()  
	erase(lst, lst->last);
	assert(list_size(lst) == ((2 * size) - 1));

	printf("List Size: %d\n", list_size(lst));
	print_names(lst);
	getchar();

	// list back to normal
	push_back(lst, (Link*)(make_name(names2[9])));
	assert(list_size(lst) == (2 * size));

	printf("List Size: %d\n", list_size(lst));
	print_names(lst);

	// test advance()
	curr = advance(lst->last, -19);
	printf("\nName = %s\n", ((Name*)(curr))->s);
	getchar();
	 
	curr = advance(lst->first, 19);
	printf("Name = %s\n", ((Name*)(curr))->s);
	getchar();

	destroy(lst);
}

#endif