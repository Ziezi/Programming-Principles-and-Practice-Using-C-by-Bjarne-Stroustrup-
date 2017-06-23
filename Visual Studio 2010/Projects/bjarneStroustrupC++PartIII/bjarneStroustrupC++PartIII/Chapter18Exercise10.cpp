/*
	TITLE		    Buffer Length		     Chapter18Exercise10.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Reimplement the function from Chapter 18.6.2
		            to handle non-zero terminated C-style strings
					or very long strings, by
		     Input: -
			Output: - 
			Author: Chris B. Kirov
			  Date: 26.12.2015
*/
#include <iostream>
#include <limits>

bool is_palindrome (const char s[], size_t n);
std::istream& read_word (std::istream& is, char* buffer, size_t max);

//--------------------------------------------------------------------------------------------------------------------------

int main ()
{
	try
	{
		int max = 3;
		char* buffer = new char[max];

		read_word(std::cin, buffer, max);

		std::cout << "The input word is ";
		if (!is_palindrome(buffer, strlen(buffer)))
		{
			std::cout <<"not ";
		}
		std::cout <<"a palindrome.";
		getchar();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	catch(...)
	{
		std::cerr << "Unhandled exception!\n";
	}
	getchar();
}

//--------------------------------------------------------------------------------------------------------------------------

bool is_palindrome(const char s[], size_t n) 
{
	if (!s)
	{
		throw std::invalid_argument("is_palindrome: null pointer argument!\n");
	}

	if (n == 1)
	{
		return true;
	}

	int first = 0;
	int last = n - 1;

	while (first < last) 
	{
		if (s[first++] != s[last--])
		{
			return false;
		}
	}

	return true;
}

//--------------------------------------------------------------------------------------------------------------------------

char* resize(char* src, size_t size)
{
	char* p = new char[size * 2];

	if (!p)
	{
		throw std::bad_alloc("read_word: bas allocation!\n");
	}
			
	for (size_t i = 0; i < size; ++i)
	{
		p[i] = src[i];
	}

	delete [] src;

	return p;
}

//--------------------------------------------------------------------------------------------------------------------------

std::istream& read_word (std::istream& is, char* buffer, size_t max)
{
	if (!buffer)
	{
		throw std::invalid_argument("read_word: null pointer argument!\n");
	}

	size_t index = 0, current_max = max;
	char c;

	while (is.get(c))
	{
		buffer[index++] = c;

		if (index == current_max)
		{
			buffer = resize (buffer, current_max);

			current_max *= 2;
		}
	}

	return is;
}
	
	 

 