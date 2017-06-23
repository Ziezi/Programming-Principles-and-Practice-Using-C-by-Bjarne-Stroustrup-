/*
	TITLE		   Find credit card numbers in file				   Chapter23Exercise7.h
	COMMENT
		Objective: Write a program that finds redit card numbers in a file and displays
				   the line containing the date and its number.
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 27.04.2017
*/

#ifndef Chapter23Exercise7_h
#define Chapter23Exercise7_h

// NOT COMPLETED !!!!
//--------------------------------------------------------------------

template <class T, class U>
U my_cast(T src)
{
	std::stringstream interpreter;

	if (!(interpreter << src))
	{
		throw std::runtime_error("lexical_cast::no operator>> for this type!\n");
	}

	U dest;

	if (!(interpreter >> dest))
	{
		throw std::runtime_error("lexical_cast::no operator<< for this type!\n");
	}

	return dest;
}

//--------------------------------------------------------------------

int luhn_checksum(const std::vector<int>& card_number)
{
	int sum = 0;
	for(size_t i = 0; i < card_number.size(); ++i)
	{
		if (i % 2 == 0 && i != 0) // add odd digits
		{
			sum += card_number[i];
		}
		else // add the doubled even digits
		{
			sum += (2 * card_number[i]);
		}
	}
	return sum % 10;
}

//--------------------------------------------------------------------

/*
	https://en.wikipedia.org/wiki/Luhn_algorithm

	Checks whether card number is valid.
*/
bool is_valid_number(const std::string& n)
{
	std::vector<int> card_number(n.size());
	for (size_t i = 0; i < n.size(); ++i)
	{
		card_number[i] = my_cast<char, int>(n[i]);
	}
	 
	int remainder = luhn_checksum(card_number);

	return remainder == 0;
}

//--------------------------------------------------------------------

#endif