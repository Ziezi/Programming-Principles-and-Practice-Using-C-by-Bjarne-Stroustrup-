/*
	TITLE		    To lower C-string        Chapter17Exercise3.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Write a function void to_lower(char *s).
		            That converts C-style string to lower case.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 02.12.2015
*/
#include <iostream>

void to_lower (char *s);

//-------------------------------------------------------

int main ()
{
	try 
	{
		/*
			char a = 'a';
			char z = 'z';
			char A = 'A';
			char Z = 'Z';
			
			// to get the ASCII value, just use a simple cast
			std::cout <<"a "<< std::hex << int(a) <<'\n';
			std::cout <<"z "<< std::hex << int(z) <<'\n';
			std::cout <<"A "<< std::hex << int(A) <<'\n';
			std::cout <<"Z "<< std::hex << int(Z) <<'\n';

			std::cout <<"character distance in ASCII code: "<< 'a' - 'A' << '\n'; 
		*/
			// c -style string
			char c_str[] = "ABCDEFG0";
		    char* c_style = c_str;

			to_lower(c_style);
			for (size_t i = 0; i < strlen(c_style); ++i) std::cout << c_style[i];
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	getchar();
}

//-------------------------------------------------------

/*
	Function: void to_lower ()
	 
	It assumes the passed argument is a
	pointer (or a reference )to C-style
	('0' terminated) string.
	
	It converts all the uppercase characters
	to lowercase until it reaches '0', by adding
	the value of abs('A' - 'a') to character's ASCII value.

	(upper case and lower case characters code 
	representation are at a distance of ('A' - 'a')).
*/
void to_lower (char *s) 
{
	// read till end, '0' is reached
	while (*s != '0')
	{
		if (*s > 'A' || *s < 'Z')
		{
			*s += abs('a' - 'A'); // if true convert to lower case by translating
		}
		++s;
	}
}