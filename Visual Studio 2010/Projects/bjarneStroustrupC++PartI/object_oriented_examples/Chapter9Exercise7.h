/*
	TITLE			   Class Book			          Chapter9Exercise7.h
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
#ifndef CHAPTER9EXERCISE7_H
#define CHAPTER9EXERCISE7_H
/*
	Class Book

	Data structure 
	representing a Book
*/ 
class Book
{
public:
	enum Genre { fiction = 0, nonfiction, periodical, biography, children, none };  

	// default constructor
	Book();

	// constructor
	Book(std::string isbn, std::string title, std::string author, int copyrigthDate, Genre g, bool availability);

	// modifying member functions 
	void borrowBook() { set_bookAvailability(false); }
	void returnBook() { set_bookAvailability(true); }

	// non - modifying member function 
	std::string get_ISBN() const { return ISBN; }
	std::string get_title() const { return title; }
	std::string get_author() const { return author; }
	int get_copyrightDate() const { return copyrightDate; }
	std::string get_genre();
	bool get_bookAvailability() const { return bookAvailability; }

	// overlodoaded operators
	friend std::ostream& operator<< (std::ostream& os, Book& a);

private:
	// data members
	std::string ISBN;
	std::string title;
	std::string author;
	int copyrightDate;
	Genre genre;
	bool bookAvailability;

	void set_bookAvailability(bool availability) { bookAvailability = availability; }
};

// forward declarations
bool validInput(std::string isbn);
static void initialize_vector(std::vector<std::string>& genre);

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
Book::Book(std::string isbn, std::string t, std::string a, int cp, Genre g, bool avail)
	: ISBN(isbn), title(t), author(a), copyrightDate(cp), genre(g), bookAvailability(avail)
{
	if(!validInput(isbn)) 
	{
		std::cerr <<"Invalid input!\n"; 
	}
}

/*
	Function: get_genre();
	Use: string genre = get_genre();

	It returns a string holding the 
	genre of the book
*/
std::string Book::get_genre()
{
	std::vector<std::string> genre_names;
	initialize_vector(genre_names);

	return genre_names[genre];
}
//--------------------------------------------------------------------------------------------------------------

/*
	Class Book Friend overloaded exrtaction operator<<

*/
std::ostream& operator<<(std::ostream& os, Book& a)
{
	 return os << a.get_title()  <<"\n"
			   << a.get_author() <<"\n"
			   << a.get_genre() << "\n"
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

//--------------------------------------------------------------------------------------------------------------

/*
	Function: initialize_vector()
	Use: initialize_vector(vect);

	It initializes the vector.
	It gets called only once.
*/
static void initialize_vector(std::vector<std::string>& genre)
{
	genre.push_back("Fiction");
	genre.push_back("Non - Fiction");
	genre.push_back("Periodical");
	genre.push_back("Biography");
	genre.push_back("Children");
	genre.push_back("None");
}

#endif