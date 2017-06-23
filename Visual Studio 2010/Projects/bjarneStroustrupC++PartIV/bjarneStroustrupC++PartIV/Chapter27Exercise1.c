/* 
	TITLE		   C-style string-manipulator functions	 Chapter27Exercise1.c
	COMMENT
		Objective: Implement versions of strlen(), strcmp(), and strcpy().  
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 12.06.2017
*/
#include <stdio.h>		// printf
#include <stdlib.h>		// malloc
#include <assert.h>		// assert

//-------------------------------------------------------------------

size_t m_strlen(const char* str)
{
	size_t length = 0;

	assert(str);
	{
		while (*str++) 
		{
			++length;
		}
	}
	return length;
}
 
//-------------------------------------------------------------------

int m_strcmp(const char* lhs, const char* rhs)
{
	 const unsigned char* ptr_l = (const unsigned char*) lhs;
	 const unsigned char* ptr_r = (const unsigned char*) rhs;

	 assert(lhs);
	 assert(rhs);
	 {
		 while (*ptr_l && *ptr_l == *ptr_r)
		 {
			ptr_l++;
			ptr_r++;
		 }
	 }
	 return (*ptr_l > *ptr_r) - (*ptr_r > *ptr_l);
}

//-------------------------------------------------------------------

char* m_strcpy(char* dest, const char* src)
{
	char* begin = dest;

	assert(dest);
	assert(src);
	{
		while (*dest++ = *src++);
	}
	return begin;
}

//-------------------------------------------------------------------

#ifdef __cplusplus

#else	// compiling in C.

int main()
{
	const char* p = { "1234" };
	const char* p2 = "12345";
	size_t length = m_strlen(p2) + 1;
	char* p3 = (char*) malloc(sizeof(char) * length);

	printf("Length p = %d\n", m_strlen(p));
	printf("Length p2 = %d\n", m_strlen(p2));


	if (m_strcmp(p, p) == 0)
	{
		printf("Strings identical\n");
	}

	if (m_strcmp(p, p2) < 0)
	{
		printf("p = %s < p2 = %s\n", p , p2);
	}

	if (m_strcmp(p2, p) > 0)
	{
		printf("p2 = %s > p = %s\n", p2 , p);
	}


	m_strcpy(p3, p2);

	printf("Destination = %s", p3);

	free(p3);
	 
	getchar();
}

#endif