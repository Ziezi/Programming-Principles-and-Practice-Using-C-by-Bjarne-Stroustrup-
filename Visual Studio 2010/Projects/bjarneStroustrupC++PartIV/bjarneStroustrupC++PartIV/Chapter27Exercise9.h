/* 
	TITLE	       Ordered Linked List								     Chapter27Exercise9.h
	COMMENT
		Objective: Using only C facilities, including lhe C standard library, read a sequence 
				   of words from stdin and write them to stdout in lexicographical order.
				   Hint: The C sort function is called qsort(); look it up somewhere.

				   Alternatively, insert the words into an ordered list as you read them. 
				   Theere is no C standard library list.  
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 15.06.2017
*/
#ifndef Chapter27Exercise9_h
#define Chapter27Exercise9_h

/*
	Insert Link: l in lexicographical order. 
*/
void insert_ordered (List* lst, Name* l)
{
	assert(lst);
	assert(l);
	{
		Name* curr = (Name*)(lst->first);
		char* curr_name = 0;
		char* l_name = l->s;

		if (curr == 0)						   // list empty
		{
			push_front(lst, (Link*)l);
			return;
		}

		while (curr != 0)
		{
			curr_name = curr->s;

			if (strcmp(curr_name, l_name) <= 0)// current name > new link name
			{
				insert(lst, (Link*)curr, (Link*)l);
				break;
			}

			if ((Link*)(curr) == lst->last)	   // end reached
			{
				push_back(lst, (Link*)l);
				break;
			}
			
			curr = (Name*)(curr->l.next);
		}
	}
}

//----------------------------------------------------------------------------------------------

void via_building_ordered_list()
{
	List* lst = create();
	Link* curr = 0;

	char* names1 [ ] = { "Epictetus", "Aurelius", "Epicurus", "Jesus", "Smith", "Marx", "Chomsky", "Jijek", "Varoufakis", "Corbin" };
	char* names2 [ ] = { "Copernikus", "Galilei", "Newton", "Hertz", "Maxwell", "Lorenz", "Minkowski", "Planck", "Einstein", "Musk" };
	char* name = 0;

	int size = 10;
	int i = 0;

	for (i; i < size; ++i)
	{
		insert_ordered(lst, make_name(names1[i]));
	}
	printf("List Size: %d\n", list_size(lst));
	print_names(lst);
	getchar();

	i = 0;
	for (i; i < size; ++i)
	{
		insert_ordered(lst, make_name(names2[i]));
	}
	printf("List Size: %d\n", list_size(lst));
	print_names(lst);
	getchar();

	printf("Second Part\n\n\n");	 
	erase(lst, lst->first);

	printf("List Size: %d\n", list_size(lst));
	print_names(lst);

	insert(lst, lst->first, (Link*)(make_name(names1[9])));
	assert(list_size(lst) == (2 * size));

	printf("List Size: %d\n", list_size(lst));
	print_names(lst);

	erase(lst, lst->last);
	printf("List Size: %d\n", list_size(lst));
	print_names(lst);
 
	push_back(lst, (Link*)(make_name(names1[1])));
	assert(list_size(lst) == (2 * size));

	printf("List Size: %d\n", list_size(lst));
	print_names(lst);
	 
	curr = advance(lst->last, -19);
	printf("\nName = %s\n", ((Name*)(curr))->s);
	 
	curr = advance(lst->first, 19);
	printf("Name = %s\n", ((Name*)(curr))->s);
	getchar();

	destroy(lst);
}

//----------------------------------------------------------------------------------------------

int cmpstr (const void* lhs, const void* rhs)
{
	const char** clhs = (const char**)lhs;
	const char** crhs = (const char**)rhs;

	return strcmp(*clhs, *crhs);
}

//----------------------------------------------------------------------------------------------

void print_str_array(char* arr[ ], size_t size)
{
	assert(arr);
	{
		size_t i = 0;
		printf("{\n");
		for (i; i < size; ++i)
		{
			printf("%s", arr[i]);

			if (i < size - 1)
			{
				printf(", ");
			}
		}
		printf("\n}\n");
	}
}

//----------------------------------------------------------------------------------------------

void populate_array(char* arr[], size_t size) 
{
	char line[15];
	size_t i = 0;

	printf("Type %d names, press carriage return after each name:\n", size);

	for (i; i < size; ++i)
	{
		printf("Type %d - th name: ", i);	// prompt
		scanf("%15s", line);				// read max 15 chars

		arr[i] = (char*) malloc(sizeof(char) * (strlen(line) + 1));	// allocate memory for current read string

		strcpy(arr[i], line);				// copy current read string into the array
	}
}

//----------------------------------------------------------------------------------------------

void clear_array(char* arr[], size_t size)
{
	size_t i = 0;

	for (i; i < size; ++i)
	{
		free(arr[i]);
	}
}

//----------------------------------------------------------------------------------------------

void via_array_qsort()
{
	 char* names [ ] = { "Epictetus", "Aurelius", "Epicurus", "Jesus", "Smith", "Marx", "Chomsky", "Jijek", "Varoufakis", "Corbin" };
	 size_t size = 10;

	 print_str_array(names, size);
	
	 qsort(names, size, sizeof(char*), cmpstr);

	 print_str_array(names, size);
}

#endif