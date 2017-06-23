/* 
	TITLE	       C-style look up table					           Chapter27Exercise12.c 
	COMMENT
		Objective: Implement a (C-style string, int) lookup table with operations such as
				   find (struct table*, const char*), insert (struct table*, const char*, int),
			       and remove (struct table*, const char*). 
				   The representation of the table could be an array of a struct pair or a pair
				   of arrays (const char* [] and int*); you choose. 
				   Also choose return types for your functions. Document your design decisions.   
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 16.06.2017
*/
#include <stdio.h>
#include <stdlib.h>		// qsort(); bsearch()
#include <string.h>
#include <assert.h>
#include <stddef.h>		// size_t
#include "Chapter27Exercise12.h"

int main()
{
	char* names [ ] = { "Epictetus", "Aurelius", "Epicurus", "Jesus", "Smith", "Marx", "Chomsky", "Jijek", "Varoufakis", "Corbin" };
	int numbers [ ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	size_t s = 10;
	size_t i = 0;
	Pair* f = 0;

	table = create_table(s);

	for (i; i < s; ++i)
	{
		m_insert(table, names[i], numbers[i]);	
	}

	print_table();
	printf("\nCapacity -> %d, Size -> %d\n", get_capacity(), get_size());

	f = m_find(table, names[4]);
	if (f != 0)
	{
		printf("\nElement found: %s -> %d.\n", f->name, f->number);
	}
	else
	{
		printf("\nElement not found!\n");
	}

	m_remove(table, names[1]);		// remove beginning
	m_remove(table, names[8]);		// remove end
	m_remove(table, names[4]);		// remove in middle

	print_table();
	printf("\nCapacity -> %d, Size -> %d\n", get_capacity(), get_size());

	printf("\nInsert 10 additional Pairs\n");
	i = 0;
	for (i; i < s; ++i)
	{
		m_insert(table, names[i], numbers[i]);	
	}

	print_table();
	printf("\nCapacity -> %d, Size -> %d\n", get_capacity(), get_size());

	clear_table(table);

	getchar();
	return 0;
}
