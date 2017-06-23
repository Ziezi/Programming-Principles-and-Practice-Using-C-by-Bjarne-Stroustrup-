/*
	TITLE			   Class Book			          Chapter9Exercise8.h
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: 
			Data members:		Function members:	    Overloaded operators:    Helper Functions:
			userName			get_user_name();		operator<<			     valid_input();
			libraryCardNumber   get_library_number();
			libraryFees		    get_library_fees();
								fee_exists();
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 16.03.2015
*/
#ifndef CHAPTER9EXERCISE8_H
#define CHAPTER9EXERCISE8_H  
/*
	Class Patrorn

	Data structure representing 
	Library member profile.
*/ 
class Patron
{
public:
	Patron();
	Patron(std::string name, std::string card, double fees);

	// non-modifying member functions
	std::string get_user_name() const { return userName; }
	std::string get_library_number() const { return libraryCardNumber; }
	double get_library_fee() const { return libraryFees; }
	bool fee_exists() const { return libraryFees != 0; }

	// modifying member functions
	void set_library_fee(double fee) { libraryFees = fee; }

	// oveloaded operators
	friend std::ostream& operator<< (std::ostream& os, Patron& p);

private:

	// data members
	std::string userName;
	std::string libraryCardNumber;
	double libraryFees;
};

// forward declarations
bool valid_input(std::string card, double fees);

//------------------------------------------------------------------------------------------------------- 

// Class member implementations
/*
	Class Patron default constructor

*/ 
Patron::Patron()
	: userName(" "), libraryCardNumber(" "), libraryFees(0)
{

}
//-------------------------------------------------------------------------------------------------------

/*
	Class Patron constructor

*/ 
Patron::Patron(std::string name, std::string card, double fees)
	: userName(name), libraryCardNumber(card), libraryFees(fees)
{
	if (!valid_input(card, fees))
	{
		std::cerr <<"Wrong constructor initialization value!\n";
	}
}

//=======================================================================================================

// Overloaded operators
/*
	Overloaded Extraction operator<<

	It extracts data members of the 
	passed Patron object. 
*/
std::ostream& operator<< (std::ostream& os, Patron& p)
{
	return os << p.get_user_name() <<'\n'
		      << p.get_library_number() << std::endl;
}

/*
	Overloaded comparison operator==
*/
bool operator== (Patron& a, Patron& b)
{
	return a.get_library_number() == b.get_library_number();
}

//-------------------------------------------------------------------------------------------------------

// Helper functions
/*
	Function: valid_input()

	It checks the validity of 
	constructor's initialization
	values.
*/
bool valid_input(std::string card, double fees)
{
	if (fees < 0)
	{
		std::cerr <<"Wrong fee value!\n";
		return false;
	}

	if (card.size() < 8)
	{
		std::cerr <<"Wrong card number length!\n";
		return false;
	}

	for (size_t i = 0; i < card.size(); ++i)
	{
		if (!isdigit(card[i]))
		{
			std::cerr <<"Wrong card number format!\n";
			return false;
		}
	}

	return true;
}

#endif
