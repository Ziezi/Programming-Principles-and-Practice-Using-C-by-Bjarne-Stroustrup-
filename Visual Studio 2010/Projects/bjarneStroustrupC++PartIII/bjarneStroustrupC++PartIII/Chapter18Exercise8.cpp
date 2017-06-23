/*
	TITLE		    Palindromes  		     Chapter18Exercise8.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Rewrite all the functions from chapter §18.6
					to check for palindrome be making a backward copy 
					of the string and then comparing to the original.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 25.12.2015
*/
#include <iostream>
#include <string>

bool is_palindrome (const std::string& s);
bool is_palindrome (const char s[], size_t size);
bool is_palindrome (const char* first_elem, const char* last_elem);

//--------------------------------------------------------------------
int main ()
{
	try
	{
		// bool is_palindrome (std::string& s);
		std::string s = "heeh";

		std::cout << s <<" is ";
		if (!is_palindrome(s))
		{
			std::cout << " not";
		}
		std::cout <<"a palindrome.\n";


		// bool is_palindrome (const char s[], size_t size); 
		char s1[] = {"aba"};		// zero terminated array

		std::cout << s1 <<" is ";
		if (!is_palindrome(s1, 3)) 
		{
			std::cout << " not";
		}
		std::cout <<" a palindrome.\n";


		char sep[] = {'a', 'b'};    // non -zero terminated array

		std::cout << sep[0] << sep[1] <<" is ";
		if (!is_palindrome(sep, 2)) 
		{
			std::cout << " not";
		}
		std::cout <<" a palindrome.\n";


		char *p1 = new char[4];		// dynamic array
		for (size_t i = 0; i < 4; ++i) p1[i] = 'a' + i;

		std::cout << *p1 <<" is ";
		if (!is_palindrome(p1, 4))
		{
			std::cout << " not";
		}
		std::cout <<" a palindrome.\n";


		char *p2 = new char('a');    // dynamic array

		std::cout << *p2 <<" is ";
		if (!is_palindrome(p2, 1))
		{
			std::cout << " not";
		}
		std::cout <<" a palindrome.\n";


		// bool is_palindrome (const char* first_elem, const char* last_elem);
		char s3[] = {'a', 'b', 'a'};
		char* pb = &s3[0];
		char* pe = &s3[2];

		if(!is_palindrome(pb, pe))
		{
			std::cout << " not";
		}
		std::cout <<" a palindrome.\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	catch (...)
	{
		std::cerr <<"Unhandled exception!\n";
	}
	getchar();
}
//--------------------------------------------------------------------

/*
	Function: is_palindrome()
*/
bool is_palindrome (const std::string& s)
{
	std::string reversed (s);

	std::reverse(reversed.begin(), reversed.end());

	if (reversed == s)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

//--------------------------------------------------------------------

/*
	Function: is_palindrome()
*/
bool is_palindrome (const char s[], size_t size)
{
	if (!s)
	{
		throw std::invalid_argument("is_palinrome: null pointe argument!");
	}

	char *p = new char[size];

	if (!p)
	{
		throw std::invalid_argument("is_palinrome: bad allocation!");
	}
	 
	for (size_t i = 0; i < size; ++i)
	{
		p[i] = s[size - 1 - i];
	}

	// compare reversed and original 
	for (size_t i = 0; i < size; ++i) 
	{
		if (p[i] != s[i])
		{
			delete[] p;
			return false;
		}
	}

	delete []p;
	return true;
}

//--------------------------------------------------------------------

/*
	Function: is_palindrome()
*/
bool is_palindrome (const char* first_elem, const char* last_elem) 
{
	if (!first_elem || !last_elem)
	{
		throw std::invalid_argument("is_palinrome: null pointe argument!");
	}

	size_t len = last_elem - first_elem + 1;
 
	char *p = new char[len];

	if (!p)
	{
		throw std::invalid_argument("is_palinrome: bad allocation!");
	}

	size_t ind = 0;
	for (auto i = last_elem; i != first_elem - 1; --i)
	{
		p[ind++] = *i;
	}

	for (auto i = 0; i < ind; ++i) 
	{
		if (p[i] != *(first_elem + i))
		{
			delete[] p;
			return false;
		}
	}

	delete[] p;
	return true;
}