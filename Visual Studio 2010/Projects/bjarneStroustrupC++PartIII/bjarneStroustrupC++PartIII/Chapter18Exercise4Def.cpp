/*
	TITLE		    Compare strings				 Chapter18Exercise4Def.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective:- Test the functions for non-zero
					terminated strings. 
					- Modify the functions to handle 
					  non-zero terminated strings.

			        The modification to handle non-zero 
					terminated strings is reflects in the
					strlen() function where there is a limit
					for the string lenght.

		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 25.12.2015
*/

/*
	Function: strlen()
*/
size_t my_strlen (const char* c) 
{
	if (!c) 
	{
		return 0;
	}

	size_t len = 0;

	while (*c++)
	{
		++len;
	}

	return len;
}

//----------------------------------------------------------------------------

/*
	Function: strcmp ()
	 
	It compares lexicographically two C-style
	strings and returns: 0 if strings equal,
	-1 if c_style < c_style2 and
	1 if c_style > c_style2. 
*/
int strcmp (const char* s1, const char* s2) 
{
	// check strings validity
	if (!s1 || !s2)
	{
		throw std::invalid_argument("strcmp: null pointer argument!");
	}

    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;

    while (*p1 != '\0')
	{
        if (*p2 == '\0')
		{
			return  1;
		}

        if (*p2 > *p1)
		{
			return -1;
		}

        if (*p1 > *p2)   
		{
			return  1;
		}

        p1++;
        p2++;
    }

    if (*p2 != '\0') 
	{
		return -1;
	}

    return 0;
}

//-------------------------------------------------------------------------------

/*
	Function: strdup()
	 
	It copies a C-style string on heap allocated
	memory and returns a pointer to it.
*/
char* m_strdup (const char* c, size_t size) 
{
	// check if c is the null pointer
	if (!c) 
	{
		throw std::invalid_argument("m_strdup: null pointer argument!");
	}

	// allocate dynamic memory, accounting for the termination char '\0'
	char * heap_p = new char[size + 1];

	// check if allocation successful
	if (!heap_p) 
	{
		throw std::bad_alloc("m_strdup: bad allocation.");
	}

	// copy C-string on heap
	for (size_t i = 0; i < size; ++i) 
	{
		*(heap_p + i) = *(c + i);
	}

	// C- style strings
	*(heap_p + size) = '\0';

	// return pointer to the free storage
	return heap_p;
}

//--------------------------------------------------------------------------------

/*
	Function: findx_0 ()

	Returns the beginning
	substring of s matching x;
	or nulllptr.
*/
char* findx (char* s, char* x)
{
	if (!s || !x) // check for null pointers
	{
		throw std::invalid_argument("findx: null pointer argument!");
	}

	if (my_strlen(s) < my_strlen(x)) // is success possible 
	{
		return 0;
	}

	while (*s != '\0') // traverse s 
	{
		char* beg = 0;
		beg = find_char(s, x); // search first matching char

		if (beg)
		{
			char *s_ptr = beg, *x_ptr = x;

			if (my_strlen(s_ptr) < my_strlen(x_ptr)) // is success possible 
			{
				return 0;
			}

			while (*x_ptr != '\0') 
			{
				if (*s_ptr != *x_ptr) // search all matching chars
				{
					break;
				}

				++s_ptr;
				++x_ptr;
			}

			return beg;
		}

		++s;
	}

	return 0;
}

//--------------------------------------------------------------------------------

/*
	Function: find_char()
	 
	Returns a pointer to the first char from
	source that matches: target, where source
	is C-style string.
*/
char* find_char(char* s, char* c) 
{
	if (!s || !c) 
	{
		throw std::invalid_argument("find_char: null pointer argument!");
	}

	// traverse the source string till the end
	while (*s != '\0')
	{
		// return true at the first occurence of: c
		if (*s == *c)
		{
			return s;
		}

		// if there is no match, increment s to the next character
		++s;
	}
	return 0;
}

//--------------------------------------------------------------------------------

/*
	Test functions with stack fake C-style strings (non-zero terminated).
*/
void test1()
{
	std::cout <<"Test 1\n";

	// non - zero terminated strings on the stack
	char c_str1 [] = {'a', 'b', 'c'};
	char c_str2 [] = {'a', 'b', 'c'};

	// test strcmp
	int cmp = 2;
	cmp = strcmp (c_str1, c_str2);

	if (cmp == -1)
	{
		 	std::cout << c_str1 << " smaller than " << c_str2 <<"\n"; 
	} 
	else if (cmp == 0)
	{
			std::cout << c_str1 << " equal to " << c_str2 <<"\n";
	} 
	else if (cmp == 1)
	{
			std::cout << c_str1 << " larger than " << c_str2 <<"\n";
	}
	else 
	{
		std::cout << "Function error!\n";
	}

	// test findx
	char* found = findx(c_str1, c_str2);

	if (found)
	{
		std::cout <<"string found!\n";
	}
	else
	{
		std::cout <<"string not found!\n";
	}

	// test strdup
	char* heap_str = m_strdup(c_str1, my_strlen(c_str1));

	if (heap_str)
	{
		std::cout <<"string on heap!\n";
	}
	else
	{
		std::cout <<"alocation failed!\n";
	}
}

//--------------------------------------------------------------------------------

/*
	Test functions with free store fake C-style strings (non-zero terminated).
*/
void test2()
{
	std::cout <<"Test 2\n";

	// non - zero terminated strings on the heap
	char* c_str1 = new char[4];
	char* c_str2 = new char[4];

	for (auto i = 0; i < 4; ++i)
	{
		*(c_str1 + i) = 'a' + i;
		*(c_str2 + i) = 'a' + i;
	}

	int cmp = 2;
	cmp = strcmp (c_str1, c_str2);

	if (cmp == -1)
	{
		 	std::cout << c_str1 << " smaller than " << c_str2 <<"\n"; 
	} 
	else if (cmp == 0)
	{
			std::cout << c_str1 << " equal to " << c_str2 <<"\n";
	} 
	else if (cmp == 1)
	{
			std::cout << c_str1 << " larger than " << c_str2 <<"\n";
	}
	else 
	{
		std::cout << "Function error!\n";
	}

	// test findx
	char* found = findx(c_str1, c_str2);

	if (found)
	{
		std::cout <<"string found!\n";
	}
	else
	{
		std::cout <<"string not found!\n";
	}
}

//--------------------------------------------------------------------------------

size_t my_strlen (const char* c, size_t max)
{
	if (!c) 
	{
		return 0;
	}

	// handle non-zero terminated strings
	size_t max_string_length = max;
	size_t len = 0;

	while (*c++)
	{
		// limit the lenght of a string 
		if (len > max_string_length) 
		{
			return ++len;
		}

		++len;
	}

	return len;
}

//--------------------------------------------------------------------------------

/*
	Define what "valid char" means,
	i.e. expected input.
*/
bool valid_char(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||(c >= '0' && c <= '9'))
	{
		return true;
	}
	else 
	{
		return false;
	}
}

//--------------------------------------------------------------------------------

/*
	Convert an input string up to "max" chars
	to null (c-style) string.
*/
char* to_C_style_string(char* src, size_t max)
{
	if (!src)
	{
		throw std::invalid_argument("to_C_style_string: nullptr argument!\n");
	}

	size_t size = 2, index = 0;

	char* dest = (char*) malloc(sizeof(char) * size);

	if (!dest)
	{
		throw std::bad_alloc("to_C_style_string: bad allocation!\n");
	}

	while (valid_char(*(src + index)) && index < max)
	{
		*(dest + index) = *(src + index);

		++index;

		if (index == size)
		{
			dest = (char*) realloc(dest, sizeof(char) * (size + 1));
			size = size + 1;
		}
	}

	*(dest + index) = '0';

	return dest;
}

//--------------------------------------------------------------------------------

/*
	Test reinplemented functions. 
*/
void test3()
{
	std::cout <<"Test 3\n";

	// non - zero terminated strings on the stack
	char c_str1 [] = {'a', 'b', 'c'};
	char c_str2 [] = {'a', 'b', 'c'};

	int cmp = 2;
	cmp = strcmp (to_C_style_string(c_str1, 20), to_C_style_string(c_str2, 20));

	if (cmp == -1)
	{
		 	std::cout << "first smaller than second\n"; 
	} 
	else if (cmp == 0)
	{
			std::cout << "first equal to second\n";
	} 
	else if (cmp == 1)
	{
			std::cout <<"first larger than second\n";
	}
	else 
	{
		std::cout << "Function error!\n";
	}


	// non - zero terminated strings on the heap
	char* c_str11 = new char[4];
	char* c_str22 = new char[4];

	for (auto i = 0; i < 4; ++i)
	{
		*(c_str11 + i) = 'a' + i;
		*(c_str22 + i) = 'a' + i;
	}

	cmp = 2;
	cmp = strcmp (to_C_style_string(c_str11, 20), to_C_style_string(c_str22, 20));

	if (cmp == -1)
	{
		 	std::cout << "first smaller than second\n"; 
	} 
	else if (cmp == 0)
	{
			std::cout << "first equal to second\n";
	} 
	else if (cmp == 1)
	{
			std::cout <<"first larger than second\n";
	}
	else 
	{
		std::cout << "Function error!\n";
	}
}

