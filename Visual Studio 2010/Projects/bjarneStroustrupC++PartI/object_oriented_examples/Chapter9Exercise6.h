/*
	TITLE			   Class Book						Chapter9Exercise6.h
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: 
					   Data members:					Function members:	      Overloaded operators:
					   ISBN								set_bookAvailability();   operator<<
					   title							borrowBook();			  operator==
					   author							returnBook();			  operator!=
					   copyrightDate					get_ISBN();
					   bookAvailability					get_title();
														get_author();
														get_copyrightDate();
														get_bookAvailability();

				Input: -
			   Output: -
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

	// overlodoaded operators
	friend std::ostream& operator<< (std::ostream& os, const Book& a);
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

//--------------------------------------------------------------------------------------------------------------

/*
	Class Book Friend overloaded exrtaction operator<<

*/
std::ostream& operator<<(std::ostream& os, const Book& a)
{
	 return os << a.get_title()  <<"\n"
			   << a.get_author() <<"\n"
			   << a.get_ISBN()   << std::endl;
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
//--------------------------------------------------------------------------------------------------------------

// Overloaded operators
/*
	Operator: ==
	Use: assertion(object_nameA == object_nameB)

	This binary operator asserts equality between 
	the ISBN's of two objects of type Book and
	returns true if they are equal.
*/
bool operator==(Book& a, Book& b)
{
	return a.get_ISBN() == b.get_ISBN();
}
//--------------------------------------------------------------------------------------------------------------

/*
	Operator: !=
	Use: assertion(object_nameA == object_nameB)

	This binary operator asserts inequality between 
	the ISBN's of two objects of type Book and
	returns true if they are unequal.
*/
bool operator!=(Book& a, Book& b)
{
	return !(a.get_ISBN() == b.get_ISBN());
}





 