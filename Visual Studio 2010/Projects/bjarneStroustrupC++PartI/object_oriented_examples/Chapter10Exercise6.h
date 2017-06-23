/*
	TITLE			   Class Roman_int                Chapter10Exercise6.h
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Implement a class that represents a number as Roman.
			class Roman_int					Helper Functions:					Overloaded operators:

			Roman_int()			            to_arab(std::string& n)				operator>>
			Roman_int(int n)			    to_roman(int n)				        operator<<
			Roman_int(std::string& n)		is_roman_number(std::string& n)
									        is_roman_digit(char& c)
			as_int()						initialize_arab_to_roman()
			as_roman()						initialize_roman_to_arab()
											initialize_digits()
			value
				Input: - 
			   Output: -
			   Author: Chris B. Kirov
			     Date: 24.04.2015
*/

/*
	class Roman

	Representing Roman numeral.
*/ 
class Roman_int
{
public:
	// contsctructors
	Roman_int()
		: value(0)
	{ 

	}

	Roman_int(int n)
		: value(n) 
	{

	}

	Roman_int(std::string& r)
	{
		if (!is_roman_number(r))
		{
			throw std::invalid_argument("Invalid initialization value!\n");
		}

		value = to_arab(r);
	}

	// function members
	int as_int() const { return value; }
	std::string as_roman() { return to_roman(value); }

private:
	int to_arab(std::string&);
	std::string to_roman(int);
	bool is_roman_number(std::string&);
	bool is_roman_digit(char&);

	int value;
};
//================================================================================================

// Class Roman_int member implementations
/*
	Function: initialize_roman_to_arab();

*/
static void initialize_roman_to_arab(std::map<char, int>& roman)
{
	 roman['M'] = 1000;
	 roman['D'] = 500;
	 roman['C'] = 100;
	 roman['L'] = 50;
	 roman['X'] = 10;
	 roman['V'] = 5;
	 roman['I'] = 1;
}
//------------------------------------------------------------------------------------------------

/*
	Function: to_arab();
	 
	It changes a number representation 
	from Roman (numbers < 4000) to Arab. 

	Applies the rules for calculating 
	the value of a Roman numeral.
*/
int Roman_int::to_arab(std::string& s)
{ 
	 std::map<char, int> roman;
	 //initialize_roman_to_arab(roman);

	 roman['M'] = 1000;
	 roman['D'] = 500;
	 roman['C'] = 100;
	 roman['L'] = 50;
	 roman['X'] = 10;
	 roman['V'] = 5;
	 roman['I'] = 1;

	 int result = 0;
	 for(size_t i = 0; i < s.size() - 1; ++i)
	 {
		if(roman[s[i]] < roman[s[i + 1]])
		{
			result -= roman[s[i + 1]];
		}
		else 
		{
			result += roman[s[i]];
		}
	 }

	 result += roman[s[s.size() - 1]];

	 return result;
}
//------------------------------------------------------------------------------------------------

/*
	Function: initialize_arab_to_roman();

*/
static void initialize_arab_to_roman(std::forward_list< std::pair<int, std::string> >& roman)
{
	roman.emplace_front(std::pair<int, std::string>(0, " "));
	roman.emplace_front(std::pair<int, std::string>(1, "I"));
	roman.emplace_front(std::pair<int, std::string>(4, "IV"));
	roman.emplace_front(std::pair<int, std::string>(5, "V"));
	roman.emplace_front(std::pair<int, std::string>(9, "IX"));
	roman.emplace_front(std::pair<int, std::string>(10, "X"));
	roman.emplace_front(std::pair<int, std::string>(40, "XL"));
	roman.emplace_front(std::pair<int, std::string>(50, "L"));
	roman.emplace_front(std::pair<int, std::string>(90, "XC"));
	roman.emplace_front(std::pair<int, std::string>(100, "C"));
	roman.emplace_front(std::pair<int, std::string>(400, "CD"));
	roman.emplace_front(std::pair<int, std::string>(500, "D"));
	roman.emplace_front(std::pair<int, std::string>(900, "CM"));
	roman.emplace_front(std::pair<int, std::string>(1000, "M"));
}

//------------------------------------------------------------------------------------------------

/*
	Function: to_roman();
	
	It changes a number representation 
	from  Arab(numbers < 4000) to Roman. 
*/
std::string Roman_int::to_roman(int value)
{
	if (value == 0)
	{
		return " ";
	}

	std::forward_list< std::pair<int, std::string> > roman;
	// initialize_arab_to_roman(roman);

	roman.emplace_front(std::pair<int, std::string>(1, "I"));
	roman.emplace_front(std::pair<int, std::string>(4, "IV"));
	roman.emplace_front(std::pair<int, std::string>(5, "V"));
	roman.emplace_front(std::pair<int, std::string>(9, "IX"));
	roman.emplace_front(std::pair<int, std::string>(10, "X"));
	roman.emplace_front(std::pair<int, std::string>(40, "XL"));
	roman.emplace_front(std::pair<int, std::string>(50, "L"));
	roman.emplace_front(std::pair<int, std::string>(90, "XC"));
	roman.emplace_front(std::pair<int, std::string>(100, "C"));
	roman.emplace_front(std::pair<int, std::string>(400, "CD"));
	roman.emplace_front(std::pair<int, std::string>(500, "D"));
	roman.emplace_front(std::pair<int, std::string>(900, "CM"));
	roman.emplace_front(std::pair<int, std::string>(1000, "M"));

	std::string roman_number;
	for(auto it = roman.begin(); it != roman.end(); ++it)
	{
		while (value >= it->first)
		{
			roman_number += it->second;

			value -= it->first;
		}
	}
	return roman_number;
}
//------------------------------------------------------------------------------------------------

/*
	Function: initialize_digits()


*/
static void initialize_digits(std::vector<char>& romans)
{
	 romans.push_back('I');
	 romans.push_back('V');
	 romans.push_back('X');
	 romans.push_back('L');
	 romans.push_back('C');
	 romans.push_back('D');
	 romans.push_back('M');
}
//------------------------------------------------------------------------------------------------

// Helper Functions

/*
	Function: is_roman_digit();
	 
	It checks if a token is 
	a valid Roman numeral.
*/
bool Roman_int::is_roman_digit(char& r)
{
	 std::vector<char> roman_digits;
	 // initialize_digits(roman_digits);
	
	 roman_digits.push_back('I');
	 roman_digits.push_back('V');
	 roman_digits.push_back('X');
	 roman_digits.push_back('L');
	 roman_digits.push_back('C');
	 roman_digits.push_back('D');
	 roman_digits.push_back('M');

	 for(size_t i = 0; i < roman_digits.size(); ++i)
	 {
		 if(roman_digits[i] == r)
		 {
			 return true;
		 }
	 }
	 return false;
}
//------------------------------------------------------------------------------------------------

/*
	Function: is_roman_number();
	 
	It checks for the validity of a Roman.
	
	Asserts that each MSD is either larger
	or equal to the adjusent LSD or 5/10 
	times smaller than it (IV, IX; XL, XC, CD, CM). 
*/
bool Roman_int::is_roman_number(std::string& roman)
{
	if (roman.size() == 1 && is_roman_digit(roman[0]))
	{
		return true;
	}

	// check if all digits are valid roman digits
	for (size_t i = 0; i < roman.size(); ++i)
	{
		if (!is_roman_digit(roman[i]))
		{
			return false;
		}
	}

	// check for correspondence between digits value and position
	for (size_t i = 0; i < roman.size() - 1; i++)
	{
		if(to_arab(std::string(1, roman[i])) >= to_arab(std::string(1, roman[i + 1])) ||
		      5 * to_arab(std::string(1, roman[i])) == to_arab(std::string(1, roman[i + 1])) ||
		      10 * to_arab(std::string(1, roman[i])) == to_arab(std::string(1, roman[i + 1])) 
		  )
		{
			
		}
		else
		{
			return false;
		}
	}
	return true;
}
//------------------------------------------------------------------------------------------------

// Overloaded Operators
/*
	operator>>
	 
*/
std::istream& operator>> (std::istream& is, Roman_int& r)
{
	// extract input
	std::string roman;
	is >> roman;

	// check stream status
	if (!is)
	{
		std::cerr <<"bad input!\n";
		return is;
	}

	r = Roman_int(roman);

	return is;
}
//------------------------------------------------------------------------------------------------

/*
	operator<< 
	 
*/
std::ostream& operator<< (std::ostream& os, Roman_int& r)
{
	return os << r.as_roman();
}

 