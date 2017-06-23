/* 
	TITLE	       C-style look up table					              Chapter27Exercise12.h
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
#ifndef Chapter27Exercise12_h
#define Chapter27Exercise12_h

typedef struct Pair
{
	const char* name;
	int number;
} Pair;

//--------------------------------------------------------------------------------------------

size_t table_capacity;											// global variable: capacity
size_t table_size;												// global variable: current size
Pair* table;													// global variable: table array

//--------------------------------------------------------------------------------------------

size_t get_capacity()
{
	return table_capacity;
}

//--------------------------------------------------------------------------------------------

void set_capacity(size_t new_capacity)
{
	table_capacity = new_capacity;
}

//--------------------------------------------------------------------------------------------

size_t get_size()
{
	return table_size;
}

//--------------------------------------------------------------------------------------------

void set_size(size_t new_size)
{
	table_size = new_size;
}

//--------------------------------------------------------------------------------------------
 
Pair* create_table(size_t capacity)
{
	Pair* p = 0;
	p = (Pair*) calloc(sizeof(Pair), capacity);

	if (p == NULL && capacity > 0)
	{
		perror("create::bad allocation!\n");
		exit(-1);
	}

	set_capacity(capacity);

	return p;
}

//--------------------------------------------------------------------------------------------
 
void clear_table(Pair t[])
{
	free(t);
}

//--------------------------------------------------------------------------------------------
 
Pair* resize_table(Pair src[], size_t old_size)
{
	Pair* p = (Pair*) realloc(src, sizeof(*p) * (old_size * 2));

	set_capacity(old_size * 2);

	src = p;

	return src;
}

//--------------------------------------------------------------------------------------------

void print_table()
{
	size_t i = 0;
	size_t size = get_size();

	for (i; i < size; ++i)
	{
		printf("%s -> %d\n", table[i].name, table[i].number);
	}
}

//--------------------------------------------------------------------------------------------
 
int qsort_comp(const void* lhs, const void* rhs)
{
	Pair* lp = (Pair*)lhs;
	Pair* rp = (Pair*)rhs;

	const char* ln = lp->name;
	const char* rn = rp->name;

	return strcmp(ln, rn);
}

//--------------------------------------------------------------------------------------------
 
int bsearch_comp(const void* lhs, const void* rhs)
{
	Pair* rp = (Pair*)rhs;

	const char* ln = (const char*) lhs;
	const char* rn = rp->name;

	return strcmp(ln, rn);
}

//--------------------------------------------------------------------------------------------

Pair* m_find (Pair* table, const char* name)
{
	return (Pair*) bsearch(name, table, get_size(), sizeof(Pair), bsearch_comp);
}

//--------------------------------------------------------------------------------------------

void m_insert (Pair* table, const char* name, int number)
{
	size_t index = get_size();
	size_t c = get_capacity();

	if (index >= c)
	{
		table = resize_table(table, c);
	}

	table[index].name = name;
	table[index].number = number;

	set_size(index + 1);

	qsort(table, get_size(), sizeof(Pair), qsort_comp);
}

//--------------------------------------------------------------------------------------------

void m_remove (Pair* table, const char* name)
{
	Pair* r = m_find(table, name);
	size_t i = -1;

	if (r != NULL)
	{
		i = (r - table);					// get index of element to be removed
											// start iteration from that index
		for (i; i < table_size - 1; ++i)	// shift back elements after the removed: overwrite 
		{
			table[i] = table[i + 1];
		}

		set_size(get_size() - 1);			// decrement table size
	}
	else
	{
		perror("remove()::no such name in the table!\n");
	}
}

//--------------------------------------------------------------------------------------------

#endif