 /*
	TITLE			   Class Money				      Chapter9Exercise15.h
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Add data member currency and supporting functions.

					Data members:	Member functions:	Overloaded operators:	Helper functions:
									get_dollars()		copy assignment			round_and_convert()
								    set_dollars()		operator=				 
																				 
					cents			get_all_in_cents()	relational:				 
									set_all_in_cents()	operator<				convert_to_dollars_and_cents()
														operator>				convert_to_cents()
					Invalid			Money()  			operator==
									Money(all_cents)	operator!=
								 	Money(dollars)		
														algebracaic:
					currency		get_currency()		operator+				valid_currency()
									set_currency()		operator-				initialize_currency_table()
														
														insertion/extraction:   initialize_conversion_table()
														operator<<				currency_convertor()
														operator>>
														
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 31.03.2015
*/
#ifndef CHAPTER9EXERCISE15_H
#define CHAPTER9EXERCISE15_H

/*
	Namespace Mycurrency

	Encompasses the code
	related to class Money.
*/
namespace Mycurrency
{

/*
	Class Money

	Data structure representing
	a meduim of exchange. 
*/ 
class Money
{
public:
	// default constructor
	Money();

	// constructors
	Money(long long c, std::string& currency);
	Money(double d, std::string& currency);

	// copy assignment 
	Money& operator= (const Money& a); 

	/*
		Class Invalid

		Thrown as exception.
	*/ 
	class Invalid{};

	double get_dollars();
	long long get_all_in_cents() const { return cents; }
	std::string get_currency() const { return currency; }

	void set_dollars(double d);
	void set_all_in_cents(long long c) { cents = c; } 
	void set_currency(std::string& currency);

private:
	// private function members
	long long convert_to_cents(double d);
	double convert_to_dollars_and_cents(long long c);

	// data members
	long long cents;
	std::string currency;
};
//==============================================================================================

// forward declarations
long long round_and_convert(double d);
bool valid_currency(std::string& currency);
void initialize_currency_table(std::vector<std::string>& v);
void initialize_conversion_table(std::map<std::string, double>& m);
long long currency_convertor(long long input_ammount, std::string& input_currency, std::string& output_currency);

//==============================================================================================


// Class Money member implementations
/*
	Class Money

	Default constructor.
*/ 
Money::Money()
	: cents(0), currency("")
{

}
//----------------------------------------------------------------------------------------------

/*
	Class Money

	Constructor: initialize from amount expressed in terms of cents.
*/ 
Money::Money(long long all_cents, std::string& c)
	: cents(all_cents), currency(c)
{
	if (!valid_currency(c))
	{
		throw Invalid();
	}
}
//----------------------------------------------------------------------------------------------

/*
	Class Money

	Constructor: initialize 
	from  dollars and cents
	as a floating point number.
*/ 
Money::Money(double d, std::string& c)
	: cents(round_and_convert(d)), currency(c)
{
	if (!valid_currency(c))
	{
		throw Invalid();
	}
}
//----------------------------------------------------------------------------------------------

/*
	operator=

*/
Money& Money::operator= (const Money& a)
{ 
	cents = a.get_all_in_cents();
	currency = a.get_currency();

	return *this;
}
//----------------------------------------------------------------------------------------------

/*
	Function: get_dollars()

*/ 
double Money::get_dollars()
{
	return convert_to_dollars_and_cents(cents);
}
//----------------------------------------------------------------------------------------------
	
/*
	Function: set_dollars()

*/ 
void Money::set_dollars(double d)
{
	cents = round_and_convert(d);
}
//----------------------------------------------------------------------------------------------

/*
	Function: set_currency()

*/
void Money::set_currency(std::string& c)
{
	if (!valid_currency(c))
	{
		throw Invalid();
	}

	currency = c;
}
//----------------------------------------------------------------------------------------------

/*
	Function: convert_to_cents(double dollars);
	 
	Converts an input amount of money from
	dollars and cents to cents,
	for the class data member.
*/
long long Money::convert_to_cents(double d) 
{
	 return round_and_convert(d);
}
//----------------------------------------------------------------------------------------------

/*
	Function: convert_to_dollars_and_cents(long long c);
	 
	Converts the value of the class data member from cents
	to dollars and cents, as floating point number.
*/
double Money::convert_to_dollars_and_cents(long long c)
{
	if (c >= -100 || c <= 100)
	{
		double fraction_part = static_cast<double>(c);

		return (fraction_part / 100.0);
	}

	long long dollars = c / 100;
	long long cents = c % (dollars * 100);
	 
	double fraction_part = static_cast<double>(cents) / 100.0;
	double decimal_part = static_cast<double>(dollars);

	return decimal_part + fraction_part;
}
//==============================================================================================

// Helper functions
/*
	Function: round_and_convert()

	It converts a double to unsigned long long
	and rounds to the second digit, 
	using 4/5 rule.
*/
long long round_and_convert(double d)
{
	 return static_cast<long long>((d + 0.005) * 100);
}
//----------------------------------------------------------------------------------------------

/*
	Function: initialize_currency_table();

	Initializes the vector storing the
	supported currencies.
*/
static void initialize_currency_table(std::vector<std::string>& v)
{
	v.push_back("BGN");
	v.push_back("EUR");
	v.push_back("GBP");
	v.push_back("USD");
}
//----------------------------------------------------------------------------------------------

/*
	Function: valid_currency();

	It checs whether the input 
	parameter reprsents a valid
	currency abbreviation.
*/
bool valid_currency(std::string& currency)
{
	if (currency.size() != 3)
	{
		std::cerr <<"Invalid currency!\n";
		return false;
	}

	std::vector<std::string> supported_currencies;
	initialize_currency_table(supported_currencies);

	std::vector<std::string>::iterator it;
	it = std::find(supported_currencies.begin(), supported_currencies.end(), currency);

	if (it != supported_currencies.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}
//----------------------------------------------------------------------------------------------


/*
	Function: initialize_conversion_table(std::vector<Currency_Rate>& v);

*/
static void initialize_conversion_table(std::map<std::string, double>& m)
{
	m["BGN"] = 1.00000;
    m["USD"] = 1.79549;   
    m["EUR"] = 1.95583, 
    m["GBP"] = 2.53405;  
}
//----------------------------------------------------------------------------------------------

/*
	Function: currency_convertor(long long input_ammount, std::string input_currency, std::string output_currency);

	It returns the "input_amount" of "input_currency" 
	to amount of "output_currency".
*/
long long currency_convertor(long long input_ammount, std::string& input_currency, std::string& output_currency)
{
	if(!valid_currency(input_currency) || !valid_currency(output_currency))
	{
		throw Money::Invalid();
	}

	std::map<std::string, double> exchange_rate_table;
	initialize_conversion_table(exchange_rate_table);

	return static_cast<long long>(input_ammount * exchange_rate_table[input_currency] / exchange_rate_table[output_currency]);
}
//==============================================================================================

// Overloaded operators
/*
	operator+
	 
*/
Money operator+ (const Money& a, const Money& b)
{
	long long cents_in_same_currency_as_a = b.get_all_in_cents();

	// check if same currency
	if (a.get_currency() != b.get_currency())
	{
		cents_in_same_currency_as_a = currency_convertor(b.get_all_in_cents(), 
														 b.get_currency(),
														 a.get_currency());
	}

	long long sum = a.get_all_in_cents() + cents_in_same_currency_as_a;

	// check for overflow
	if (sum < a.get_all_in_cents() || sum < cents_in_same_currency_as_a)
	{
		std::cerr <<"Addition overflow!\n";
		throw Money::Invalid();
	}

	return Money(sum, a.get_currency());
}
//----------------------------------------------------------------------------------------------

/*
	operator-
	 
*/
Money operator- (const Money& a, const Money& b)
{
	long long cents_in_same_currency_as_a = b.get_all_in_cents();

	// check if same currency
	if (a.get_currency() != b.get_currency())
	{
		cents_in_same_currency_as_a = currency_convertor(b.get_all_in_cents(), 
														 b.get_currency(),
														 a.get_currency());
	}

	long long difference = a.get_all_in_cents() - cents_in_same_currency_as_a;

	// check underflow
	if (difference > a.get_all_in_cents())
	{
		std::cerr <<"Subtraction underflow!\n";
		throw Money::Invalid();
	}

	return Money(difference, a.get_currency());
}
//----------------------------------------------------------------------------------------------

/*
	operator== 
	 
*/
bool operator== (const Money& a, const Money& b)
{
	return a.get_all_in_cents() == b.get_all_in_cents() &&
		   a.get_currency() == b.get_currency();
}
//----------------------------------------------------------------------------------------------

/*
	operator!= 
	 
*/
bool operator!= (const Money& a, const Money& b)
{
	return !(a == b);
}
//----------------------------------------------------------------------------------------------

/*
	operator<

*/
bool operator< (const Money& a, const Money& b)
{
	long long cents_in_same_currency_as_a = b.get_all_in_cents();

	// check if same currency
	if (a.get_currency() != b.get_currency())
	{
		cents_in_same_currency_as_a = currency_convertor(b.get_all_in_cents(), 
														 b.get_currency(),
														 a.get_currency());
	}

	return a.get_all_in_cents() < cents_in_same_currency_as_a;
}
//----------------------------------------------------------------------------------------------

/*
	operator>

*/
bool operator> (const  Money& a, const  Money& b)
{
	long long cents_in_same_currency_as_a = b.get_all_in_cents();

	// check if same currency
	if (a.get_currency() != b.get_currency())
	{
		cents_in_same_currency_as_a = currency_convertor(b.get_all_in_cents(), 
														 b.get_currency(),
														 a.get_currency());
	}

	return a.get_all_in_cents() > cents_in_same_currency_as_a;
}
//----------------------------------------------------------------------------------------------

/*
	operator>>
	
*/
std::istream& operator>> (std::istream& is, Money& r)
{
	// define input variables
	double dollars; 
	std::string currency;

	// extract input
	is >> dollars >> currency;
	
	// check stream status
	if (!is) return is;

	// check input format validity
	if (!valid_currency(currency))
	{
		is.clear(std::ios_base::failbit);
		return is;
	}

	// initialize object in argument
	r = Money(dollars, currency);

	return is;
}
//----------------------------------------------------------------------------------------------

/*
	operator<<
	
*/
std::ostream& operator<< (std::ostream& os, Money& r)
{
	return os << std::setprecision(2) // display two digits after the decimal point
			  << std::fixed			  // display even zeroes after the decimal point
		      << r.get_dollars() 
			  <<" "<< r.get_currency(); 
}

} // end of namespace Mycurrency

#endif
