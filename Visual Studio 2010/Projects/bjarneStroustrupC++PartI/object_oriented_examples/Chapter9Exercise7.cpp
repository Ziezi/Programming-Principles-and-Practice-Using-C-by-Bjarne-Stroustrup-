/*
	TITLE			   Class Book			          Chapter9Exercise7.cpp
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: 
					   Data members:					Function members:	      Overloaded operators:
					   ISBN								set_bookAvailability();   operator<<
					   title							borrowBook();			  operator==
					   author							returnBook();			  operator!=
					   copyrightDate					get_ISBN();
					   bookAvailability					get_title();
					   genre							get_author();
														get_copyrightDate();
														get_bookAvailability();
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 16.03.2015
*/
#include <iostream>
#include <string>
#include <vector>
#include "Chapter9Exercise7.h"
 
void test_function();

//===========================================================================================================
int main()
{
	try
	{
		test_function();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
//===========================================================================================================

void test_function()
{
	Book a("111a", "The Builders of Modern Bulgaria", "S. Radev", 1900, Book::biography, true);
	Book b("123a", "Macroeconomics", "Mankiw", 2012, Book::fiction, true);
	Book c("000a", "Writings of the Bulgarian Revolutions", "Z. Stoianov", 1900, Book::biography, true);

	std::vector<Book> library;
	library.push_back(a);
	library.push_back(b);
	library.push_back(c);

	std::cout << "Welcome to our simple library.\n";
	for (size_t i = 0; i < library.size(); ++i)
	{
		std::cout << library[i] <<'\n';
	}

	if (b.get_bookAvailability())
	{
		std::cout << "Book available.\n";
	}
	else 
	{
		std::cout << "Book not available.\n";
	}

	if (library[0] == library[0])
	{
		std::cout <<"Books identical\n";
	}

	if (library[1] != library[0])
	{
		std::cout <<"Books not identical\n";
	}
}