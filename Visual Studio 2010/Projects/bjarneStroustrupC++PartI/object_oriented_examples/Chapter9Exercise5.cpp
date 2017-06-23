/*
	TITLE			   Class Book			          Chapter9Exercise5.cpp
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Create class Book containing:

					   Data members:					Function members:
					   ISBN								set_bookAvailability();
					   title							borrowBook();
					   author							returnBook();
					   copyrightDate					get_ISBN();
					   bookAvailability					get_title();
														get_author();
														get_copyrightDate();
														get_bookAvailability();
				Input: -
			   Output: Prints the created book object. 
			   Author: Chris B. Kirov
			     Date: 16.03.2015
*/
#include <iostream>
#include <string>
#include <vector>
#include "Chapter9Exercise5.h"

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
	Book a("111a", "The Builders of Modern Bulgaria", "S. Radev", 1900, true);
	Book b("123a", "Macroeconomics", "Mankiw", 2012, true);
	Book c("000a", "Writings of the Bulgarian Revolutions", "Z. Stoianov", 1900, true);

	std::vector<Book> library;
	library.push_back(a);
	library.push_back(b);
	library.push_back(c);

	std::cout << "Welcome to our simple library.\n";
	for (size_t i = 0; i < library.size(); ++i)
	{
		std::cout << "ISBN: "<< library[i].get_ISBN() <<'\n';
		std::cout << "Title:"<< library[i].get_title() <<'\n';
		std::cout << "Author: "<< library[i].get_author() <<'\n';
		std::cout << "Copyright date: "<< library[i].get_copyrightDate()<<'\n';

		std::cout <<"\n";
	}

	if (b.get_bookAvailability())
	{
		std::cout << "Book available.\n";
	}
	else 
	{
		std::cout << "Book not available.\n";
	}
}