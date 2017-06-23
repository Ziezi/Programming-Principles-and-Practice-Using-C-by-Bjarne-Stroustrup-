/*
	TITLE			   Implement software for a Library	 Chapter9Exercise9.h
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
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
			     Date: 17.03.2015
*/
#ifndef CHAPTER9EXERCISE9_H
#define CHAPTER9EXERCISE9_H

#include "Chapter9Exercise8.h" // Patron
#include "Chapter9Exercise7.h" // Book
#include "Chapter9Drill5.h"    // Date

/*
	Class Library
	
	Data structure representing
	a library.
*/
class Library 
{
public:
	void add_new_book(Book& book);
	void remove_book(Book& book);
	bool in_library(Book& book);
	int number_of_library_books() const { return books.size(); }
	void check_out_book(Book& book, Patron& member, Date& date);
	void return_book_back(Book& book, Patron& member, Date& date);

	void add_new_member(Patron& member);
	void remove_member(Patron& member);
	bool is_member(Patron& member);
	int number_of_library_members() const { return members.size(); }

	void members_owing_fees(std::vector<Patron>& members_with_fees);
	void owes_fee(Patron& member);
	bool is_fee(Patron& member);
	
	int number_of_transactions() const { return transactions.size(); }

private:
	struct Transaction
	{
		Book book;
		Patron patron;
		Date date;

		Transaction()
			: book(), patron(), date()
		{
		
		}

		Transaction(Book& b, Patron& p, Date& d)
			: book(b), patron(p), date(d)
		{
		
		}
	};

	std::vector<Book> books;
	std::vector<Patron> members;
	std::vector<Transaction> transactions; 
	
	Book find_book(std::string& isbn);  
	Patron find_member(std::string& card_number);  
	Transaction find_transaction(Date& d, Patron& p, Book& b);  
};
//-----------------------------------------------------------------------------------------------------------------

// Class Library member implementations
/*
	Function : add_new_book(Book& book);
	 
*/
void Library::add_new_book(Book& book)
{
	books.push_back(book);
}
//-----------------------------------------------------------------------------------------------------------------

/*
	Function : remove_book(Book& book);
	 
*/
void Library::remove_book(Book& book)
{
	for (std::vector<Book>::iterator it = books.begin() ; it != books.end(); ++it)
	{
		if (*it == book)
		{
			books.erase(it);
		}
	}
	std::cerr <<"Book not removed!\n";
}
//-----------------------------------------------------------------------------------------------------------------

/*
	Function : in_library(Book& book);

	It returns whether the book passed
	as parameter is available for borrowing.
*/
bool Library::in_library(Book& book) 
{
	// check if exist
	Book in_library_list = find_book(book.get_ISBN());

	// check if borrowed
	if (in_library_list.get_bookAvailability())
	{
		return true;
	}
	return false;
}
//-----------------------------------------------------------------------------------------------------------------

/*
	Function: add_new_member(Patron& member);
	 
*/
void Library::add_new_member(Patron& member)
{
	members.push_back(member);
}
//-----------------------------------------------------------------------------------------------------------------

/*
	Function : remove_book(Book& book);
	 
*/
void Library::remove_member(Patron& member)
{
	for (std::vector<Patron>::iterator it = members.begin() ; it != members.end(); ++it)
	{
		if (*it == member)
		{
			members.erase(it);
		}
	}
	std::cerr <<"Member not removed!\n";
}
//-----------------------------------------------------------------------------------------------------------------

/*
	Function: is_member(Patron& member);

	It returns whether the paremeter
	is a library member.
*/
bool Library::is_member(Patron& member)  
{
	if (find_member(member.get_library_number()) == Patron())
	{
		return false;
	}
	return true;
}

//-----------------------------------------------------------------------------------------------------------------

/*
	Function owes_fees(Patron& member);
	
	It returns whether the member passed
	as parameter owes any fees.
*/
bool Library::is_fee(Patron& member) 
{
	// get the members owing fees
	std::vector<Patron> members_with_fees;
	members_owing_fees(members_with_fees);

	// check if targert member contained in the list
	for (size_t i = 0; i < members_with_fees.size(); ++i)
	{
		if (member == members_with_fees[i])
		{
			return true;
		}
	}
	return false;
}
//-----------------------------------------------------------------------------------------------------------------

/*
	Function: owes_fee(Patron& member);

	It marks the member as fee owner.
*/
void Library::owes_fee(Patron& member)
{
	int initial_fee = 10;
	for (size_t i = 0; i < members.size(); ++i)
	{
		if (member == members[i])
		{
			members[i].set_library_fee(initial_fee);
		}
	}
}

//-----------------------------------------------------------------------------------------------------------------

/*
	Function: check_out_book(Book& book, Patron& borrower, Date& date);

	It checks whether the borrower is a member and owes fees and
	the book is in the library.
	It marks the book as unavailable and it creates a new transaction.
*/
void Library::check_out_book(Book& book, Patron& borrower, Date& date)
{
	if (!is_member(borrower))
	{
		std::cerr <<"Borrower not a member!\n";
		return;
	}
	 
	if (!in_library(book))
	{
		std::cerr <<"Book not in the library!\n";
		return;
	}

	if (is_fee(borrower))
	{
		std::cerr <<"Borrower owes fees!\n";
		return;
	}

	// find the book
	for (size_t i = 0; i < books.size(); ++i)
	{
		if (book == books[i])
		{
			// add new transaction
			transactions.emplace_back(Transaction(book, borrower, date));

			// mark member as fee owner  
			owes_fee(borrower);

			// mark the book as unavailable
			books[i].borrowBook();
		}
	}
}
//-----------------------------------------------------------------------------------------------------------------

/*
	Function: return_book_back(Book& book, Patron& member, Date& date);

 
*/
void Library::return_book_back(Book& book, Patron& borrower, Date& date)
{
	// find the book
	for (size_t i = 0; i < books.size(); ++i)
	{
		if (book == books[i])
		{
			// mark the book as unavailable
			books[i].returnBook();
			
			// add new transaction
			transactions.emplace_back(Transaction(book, borrower, date));
		}
	}
}
//-----------------------------------------------------------------------------------------------------------------

/*
	Function: find_book(std::string& isbn);

	It returns the book matching the isbn.
	Otherwise returns an "empty book".
*/
Book Library::find_book(std::string& isbn)
{
	for (size_t i = 0; i< books.size(); ++i)
	{
		if(books[i].get_ISBN() == isbn) 
		{
			return books[i];
		}
	}
	return Book();
}
//-----------------------------------------------------------------------------------------------------------------

/*
	Function: find_member(std::string& card_number)
 
	It returns the member that matches the card_number.
	Otherwise returns an "empty member".
*/
Patron Library::find_member(std::string& card_number)
{
	for (size_t i = 0; i < members.size(); ++i)
	{
		if(members[i].get_library_number() == card_number)
		{
			return members[i];
		}
	}
	return Patron();
}
//-----------------------------------------------------------------------------------------------------------------

/*
	Function: find_transaction(Date& date, Patron& member, Book& book);
	 
	It returns the transaction matching the paramter values.
	Otherwise it returns the "empty transaction".
*/
Library::Transaction Library::find_transaction(Date& date, Patron& member, Book& book)
{
	for (size_t i = 0; i < transactions.size(); ++i)
	{
		if((transactions[i].date == date) ||
		   (transactions[i].patron == member)||
		   (transactions[i].book.get_ISBN() == book.get_ISBN())
		   ) 
		{
		   return transactions[i];
		}
	}
	return Transaction();
}
//-----------------------------------------------------------------------------------------------------------------

/*
	Function: members_owing_fees(std::vector<Patron>& members_owing_fees);

	It populates the vector passed by reference with the members
	owing fees.
*/
void Library::members_owing_fees(std::vector<Patron>& members_owing_fees)
{
	for (size_t i = 0; i < members.size(); ++i)
	{
		if(members[i].get_library_fee() != 0)
		{
			members_owing_fees.push_back(members[i]);
		}
	}
}

#endif