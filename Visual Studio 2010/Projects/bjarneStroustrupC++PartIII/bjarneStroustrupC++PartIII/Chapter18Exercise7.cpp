/*
	TITLE		    C-style string concatenation Chapter18Exercise7.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Rewrite cat_dot() for c-style strings as input parameters;
					let it return a c-string on the heap.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 25.12.2015
*/
#include <iostream>
#include <assert.h>

char* cat_dot (const char* s1, const char* s2, const char* sep);

//---------------------------------------------------------------------

int main ()
{
	try
	{
		char s1[] = {"Hristo"};
		char s2[] = {"Botev"};
		char sep[] = {"."};

		char* conc = nullptr; 

		conc = cat_dot(s1, s2, sep);

		if (conc) 
		{
			 std::cout <<"Result: "<< conc << "\n"; 

		}
		else 
		{
			std::cout << "Concatenation falied!\n";
		}

		delete conc;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	catch (...)
	{
		std::cerr << "Unhadled exception!\n";
	}
	getchar();
}

//---------------------------------------------------------------------

size_t m_strlen (const char* s)
{
	if (!s)
	{
		throw std::invalid_argument("m_strlen: null pointer argument!\n");
	}

	size_t len = 0;

	while (*s++)
	{
		++len;
	}

	return len;
}

//---------------------------------------------------------------------

/*
	Function: cat_dot()
	 
	It concatenates the C-style strings passed
	via first two arguments, adding the
	third string as a separator in between them.
*/
char* cat_dot (const char* s1, const char* s2, const char* sep)
{
	if (!s1 || !s2 || !sep)
	{
		throw std::invalid_argument("cat_dot: null pointer argument!\n");
	}

	size_t len_s1 = m_strlen(s1);
	size_t len_sep = m_strlen(sep);
	size_t len_s2 = m_strlen(s2);
	size_t total_len = len_s1 + len_sep + len_s2  + 1;

	char *p = new char[total_len];

	for (size_t i = 0; i < total_len; ++i)
	{
		if (i < len_s1) 
		{
			*(p + i) = *(s1++); 
		}
		else if ((i >= len_s1) && (i < len_s1 + len_sep))
		{
			*(p + i) = *(sep++);
		}
		else if ((i >= len_s1 + len_sep) && (i < len_s1 + len_s2 + len_sep))
		{
			*(p + i) = *(s2++);
		}
		else 
		{
			*(p + i) = '\0';	 
		}
	}

	return p;
}

 