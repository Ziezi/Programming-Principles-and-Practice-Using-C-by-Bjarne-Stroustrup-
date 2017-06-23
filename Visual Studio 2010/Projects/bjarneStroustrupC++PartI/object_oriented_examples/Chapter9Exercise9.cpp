/*
	TITLE			   Implement software for a Library	 Chapter9Exercise9.cpp
		Bjarne Stroustrup "Programming: Principles and Practice Using C++""
	COMMENT
			Objective: Implement a class Library.
				Data Members:						Function Members:

				vector<Book> books					find_book()
												    add_new_book()
													remove_book()
													in_library()
													number_of_library_books()
													check_out_book()
													return_book_back()

			   vector<Patron> members				find_member()
											        add_new_member()
													remove_member()
													is_member()
													number_of_library_members()

													owes_fee()
													is_fee()
													members_owing_fees()
													
				vector<Transaction> transactions	find_transaction()
													number_of_transactions()
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 19.03.2015
*/
#include <iostream>
#include <string>
#include <vector>
#include "Chapter9Exercise9.h"

void test_function();

//==============================================================================================================
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

//==============================================================================================================
void test_function()
{
	// create books
	Book book1 = Book("000a", "Programming Princples", "Bjarne Stroustroup", 2009, Book::nonfiction, true);
	Book book2 = Book("001b", "Jobs", "Walter Isaacson", 2011, Book::biography, true);

	// create partons
	Patron member1 = Patron("Chris Kirov","20090319",0);
	Patron member2 = Patron("Julia Lozancheva","20090320",0);

	// create a Library
	Library my_library;

	// create a Library Book list
	my_library.add_new_book(book1);
	my_library.add_new_book(book2);
	std::cout << "Number of Books in library list: " << my_library.number_of_library_books()<< std::endl;

	// create a Library Member List
	my_library.add_new_member(member1);
	my_library.add_new_member(member2);
	std::cout << "Number of library members: " << my_library.number_of_library_members()<< std::endl;

	// test class Library member function
	std::vector<Patron> fee_owners;
	my_library.members_owing_fees(fee_owners);
	std::cout << "People owing fees: " << fee_owners.size() << std::endl;

	// realize a transaction
	my_library.check_out_book(book1, member1, Date(2016, Date::mar, 29));
	std::cout << "Number of library transactions: " << my_library.number_of_transactions()<< std::endl; 

	my_library.members_owing_fees(fee_owners);
	std::cout << "People owing fees: " << fee_owners.size() << std::endl;
}