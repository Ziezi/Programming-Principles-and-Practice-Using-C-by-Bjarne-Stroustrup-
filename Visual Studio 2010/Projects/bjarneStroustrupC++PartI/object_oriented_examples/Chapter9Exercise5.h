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

/*
	Class Book

	Data structure 
	representing a Book
*/ 
class Book
{
private:
	// data members
	std::string ISBN;
	std::string title;
	std::string author;
	int copyrightDate;
	bool bookAvailability;

	void set_bookAvailability(bool availability) { bookAvailability = availability; }
public:
	
	// default constructor
	Book();

	// constructor
	Book(std::string isbn, std::string title, std::string author, int copyrigthDate, bool availability);

	// modifying member functions 
	void borrowBook() { set_bookAvailability(false); }
	void returnBook() { set_bookAvailability(true); }

	// non - modifying member function 
	std::string get_ISBN() const { return ISBN; }
	std::string get_title() const { return title; }
	std::string get_author() const { return author; }
	int get_copyrightDate() const { return copyrightDate; }
	bool get_bookAvailability() const { return bookAvailability; }
};

// forward declarations
bool validInput(std::string isbn);

//--------------------------------------------------------------------------------------------------------------

// Class Book member implementations
/*
	Class Book

	Default constructor.
*/ 
Book::Book()
	: ISBN("none"), title("none"), author("none"), copyrightDate(0), bookAvailability(0)
{

}
//--------------------------------------------------------------------------------------------------------------

/*
	Class Book

	Contructor.
*/ 
Book::Book(std::string isbn, std::string t, std::string a, int cp, bool avail)
	: ISBN(isbn), title(t), author(a), copyrightDate(cp), bookAvailability(avail)
{
	if(!validInput(isbn)) 
	{
		std::cerr <<"Invalid input!\n"; 
	}
}
//==============================================================================================================

// Helper Function
/*
	Function: validInput();
	Use: bool valIn = validInput(isbn);

	This function checks whether each of the input arguments
	are in the right order and format before they are used
	to create, borrow or return an object Book. 
*/
bool validInput(std::string isbn)
{
	const int ISBNlen = 4;
	if(isbn.length() != ISBNlen)
	{
		std::cerr <<"ISBN must be 4 symbols long!\n";
		return false;
	}

	for (size_t i = 0; i < isbn.size() - 1; ++i)
	{
		if (!isdigit(isbn[i]))
		{
			std::cerr <<"ISBN first 3 symbols must be digits!\n";
			return false;
		}
	}

	if (!isalpha(isbn[isbn.size() - 1]))
	{
		std::cerr <<"ISBN last symbol must be character!\n";
		return false;
	}

	return true;
}
 