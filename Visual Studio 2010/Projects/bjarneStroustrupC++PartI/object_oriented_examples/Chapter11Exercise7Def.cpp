/*
	TITLE		   Create a dictionary			  Chapter11Exercise7Def.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Create a dictionary from a multipage text.
		           Code from Chapter 11.7 used instead of the trivial code 
				   from the previous exercise.
			Input: -
		   Output: -
		     Date: 03.07.2015
		   Author: Chris B. Kirov
*/

// Class PunctStream member functions 

/*
	Function : isWhiteaspace()
	 
	It checks whether the passed 
	argument is whitespace characters, 
	part of string: "white".
*/
bool PunctStream::isWhitespace(char c)
{
	for(size_t i = 0; i < white.size(); i++)
	{
		if (c == white[i])
		{
			return true;
		}
	}
	return false;
}
//----------------------------------------------------------------------------------

// Overloaded operators 
/*
	operator>>

*/
PunctStream& PunctStream::operator>> (std::string& s)
{
	while(!(buffer >> s))
	{
		// if buffer bad() or source not good => return PunctStream object
		// this is a pointer to the object in context, i.e.: PunctStream.
		if(buffer.bad() || !source.good())
		{
			return *this;
		}

		buffer.clear();

		std::string line;

		// get a line from source
		getline(source, line);

		// replace "white" characters in "line"
		for(size_t i = 0; i < line.size(); ++i)
		{
			if(isWhitespace(line[i]))
			{
				line[i] = ' ';
			}
			// if case sensitivity is set => convert to lowercase
			else if (!sensitive) 
			{
				line[i] = tolower(line[i]);
			}
		}

		// initialize the stringstream buffer to "line"
		buffer.str(line);
	}
	return *this;
}
//----------------------------------------------------------------------------------

/*
	operator bool()
	 
	This operator returnes a true
	representing the good state 
	of the stream object.
*/
PunctStream::operator bool()
{
	// to return true: fail() and bad() should be unset, good()-set
	return !(source.fail() || source.bad()) && source.good();
}
//----------------------------------------------------------------------------------

// Non-member functions
/*
	Function: create_dictionary()
	 
	It extracts the stream object
	passed as parameter, edits words 
	according to the predefined specifications,
	stores them into a vector in alphabetical order.
*/
void create_dictionary(PunctStream& ps, std::vector<std::string>& d)
{
	std::string word;
	while(ps >> word) 
	{
		d.push_back(word);
	}

	sort(d.begin(), d.end());
}
//----------------------------------------------------------------------------------

/*
	Funtion: print_dictionary()

*/
void print_dictionary(std::vector<std::string>& d)
{
	for(size_t i = 0; i < d.size(); ++i)
	{
		if (i + 1 < d.size() && d[i] != d[i +1])
		{
			std::cout << std::setw(20) << std::left << d[i];
		}

		if (i % 4 == 0)
		{
			std::cout <<"\n";
		}
	}
}