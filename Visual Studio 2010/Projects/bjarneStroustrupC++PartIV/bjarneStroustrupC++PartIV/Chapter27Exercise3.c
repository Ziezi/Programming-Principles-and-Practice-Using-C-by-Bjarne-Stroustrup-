/* 
	TITLE		   Expand the Linked List				 Chapter27Exercise3.c
	COMMENT
		Objective: "Pretty up" the intrusive list example in §27.9 as best you
				   can to make it convenient to use. 
				   Do catch / handle as many error's as you can. 
				   It is fair game to change the details of the struct 
				   definitions, to use macros, whatever.

						- find_name(List* lst, char* name);
						- assert() statements checks every input parameter and dynamic allocation.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 13.06.2017
*/
#include <stdio.h>		// printf
#include <stdlib.h>		// malloc
#include <assert.h>		// assert
#include <string.h>		// strcmp
#include <time.h>		// clock_t; CLOCKS_PER_SEC
#include "Chapter27Exercise2.h"

#ifdef __cplusplus

#else	// compiling in C.

int main()
{
	clock_t t = clock();

	List* lst = create();
	Link* curr = 0;

	char* names1 [ ] = { "Epictetus", "Aurelius", "Epicurus", "Jesus", "Smith", "Marx", "Chomsky", "Jijek", "Varoufakis", "Corbin" };
	char* names2 [ ] = { "Copernikus", "Galilei", "Newton", "Hertz", "Maxwell", "Lorenz", "Minkowski", "Planck", "Einstein", "Musk" };
	char* name = 0;

	int size = 10;
	int i = 0;

	for (i; i < size; ++i)
	{
		push_front(lst, (Link*)(make_name(names1[i])));
	}

	i = 0;
	for (i; i < size; ++i)
	{
		push_back(lst, (Link*)(make_name(names2[i])));
	}

	print_names(lst);

	erase(lst, lst->first);
	printf("List Size: %d\n", list_size(lst));
	print_names(lst);
	 
	insert(lst, lst->first, (Link*)(make_name(names1[9])));
	printf("List Size: %d\n", list_size(lst));
	print_names(lst);
	 
	erase(lst, lst->last);
	printf("List Size: %d\n", list_size(lst));
	print_names(lst);
 
	push_back(lst, (Link*)(make_name(names2[9])));
	printf("List Size: %d\n", list_size(lst));
	print_names(lst);

	curr = advance(lst->last, -19);
	printf("\nName = %s\n", ((Name*)(curr))->s);
	 
	curr = advance(lst->first, 19);
	printf("Name = %s\n", ((Name*)(curr))->s);
	 
	curr = find(lst, names1[0]);
	if (curr != 0)
	{
		printf("\nName found = %s\n", ((Name*)(curr))->s);
	}
	
	destroy(lst);

	t = clock() - t;

	printf ("It took %d clicks (%f seconds).\n",t , ((float)t) / CLOCKS_PER_SEC);

	getchar();
}

#endif