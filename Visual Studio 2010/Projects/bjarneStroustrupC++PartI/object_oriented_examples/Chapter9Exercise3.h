/*
	TITLE			   Class name-age pairs		 Chapter9Exercise3.h
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Implement a class Name_pairs: 

					   Data members:					Member functions:		Overloaded operator:
					   string name, double age;			read_names();           operator<<
					   vector<string> name;				read_ages();            operator==
					   vector<double> age;				sort();	                operator!=
													    size();
				Input: Prompts user to type name-age pairs.
			   Output: Prints all the above / sorted.
			   Author: Chris B. Kirov
			     Date: 14.03.2015
*/

namespace NamePairs
{
/*
	Class Name_pairs

	Declaration of data structure 
	representing a name-age pairs.
*/ 
class Name_pairs
{
public:
	// default constructor
	Name_pairs();

	// modifying member functions
	void read_names(int n);
	void read_ages();
	void sort();

	// non-modifying member functions
	void print() const;
	std::string get_name() const { return name; }
	double get_age() const { return age; }
	size_t size() const { return names.size(); }

	// qualified as friend: non-member functions have access to the private members of the class
	friend std::ostream& operator<< (std::ostream& os, const Name_pairs& a);
	friend bool operator== (const Name_pairs& a, const Name_pairs& b);
	friend bool operator!= (const Name_pairs& a, const Name_pairs& b);

private:
	// data members 
	std::string name;
	double age;

	// vectors holding the values of each input pair
	std::vector<std::string> names;
	std::vector<double> ages;
};

//-----------------------------------------------------------------------------------------

// class Name_pairs member implementations
/*
	Class Name_pairs default constructor

*/ 
Name_pairs::Name_pairs()
	: name(" "), age(0)
{
	 
}
//-----------------------------------------------------------------------------------------

/*
	Function: sortPairs();
	Use: sortPairs(name,age);

	It sorts the vector of names 
	and matches the ages.
*/
void sortPairs(std::vector<std::string>& n, std::vector<double>& a)
{
	std::vector<std::string> sortedNames;	        
 	sortedNames.assign(n.begin(), n.end());			 
	sort(sortedNames.begin(), sortedNames.end());	 

	std::vector<int> indexHolder;	
	unsigned int i = 0;

	for(i; i < sortedNames.size(); ++i)
	{
		for(unsigned int j = 0; j < n.size(); ++j)
		{
			if(sortedNames[i] == n[j])
			{
				indexHolder.push_back(j);
				break;
			}
		}
	}

	std::vector<double> sortedAges;
	for (unsigned int i = 0; i < indexHolder.size(); ++i)
	{
		sortedAges.push_back(a[indexHolder[i]]);
	}

	sort(n.begin(), n.end());						 
	a.assign(sortedAges.begin(), sortedAges.end()); 
}
//-----------------------------------------------------------------------------------------

/*
	Function: print();
	Use: print(Name_pairs& np);

	Prints name age pair, each
	on a newline.
*/
void Name_pairs::print() const
{
	if (names.size() != ages.size()) 
	{
		std::cerr <<"Incompatible number of names and ages!\n";
	}

	for (unsigned int i = 0; i < names.size(); ++i)
	{
		std::cout << "("<< names[i] << ", " << ages[i] << ")\n"; 
	}
}
//-----------------------------------------------------------------------------------------

/*
	Function: read_names()
	Use: object_intatiation.read_names(n)

	Prompts the user to type 
	the number of names passed as 
	argument.
*/
void Name_pairs::read_names(int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << "Please type a name:\n>>";
		std::string name;
		std::cin >> name;
		names.push_back(name);
	}
}
//-----------------------------------------------------------------------------------------

/*
	Function: read_ages()
	Use: object_intatiation.read_ages()

	Prompts the user to type number
	of ages that match the number of
	names.
*/
void Name_pairs::read_ages()
{
	for (size_t i = 0; i < names.size(); ++i)
	{
		std::cout << "Please type an age:\n>>";
		double a;
		std::cin >> a;
		ages.push_back(a);
	}
}
//-----------------------------------------------------------------------------------------

/*
	Function: sort()
	Use: object_intatiation.sort()

	Wrapping function calling helper
	function sortPairs().
*/
void Name_pairs::sort()
{
	sortPairs(names, ages);
}
//-----------------------------------------------------------------------------------------

// Overloaded operators 
/*
	Operator: << 
	Use: ouput_stream_object << Name_pairs_object;

	It prints the name-age pairs on a newline
	in the format:
	(name, age)
*/
std::ostream& operator<<(std::ostream& os, const Name_pairs& a)
{
	for (unsigned int i=0; i< a.size(); ++i)
	{
		os <<"("<< a.names[i]<<", "<< a.ages[i] <<")\n";
	}
	return os;
}
//-----------------------------------------------------------------------------------------

/*
	Operator: ==
	Use: object_a == object_b;

    It returns true if every pair of the 
	two objects have the same values.
*/
bool operator==(const Name_pairs& a, const Name_pairs& b)
{
	for (unsigned int i = 0; i < a.size(); ++i)
	{
		if(a.names[i] != b.names[i] || a.ages[i] != b.ages[i])
		{
			return false; 
		}
	}
	return true;
}
//-----------------------------------------------------------------------------------------

/*
	Operator: !=
	Use: object_a != object_b;

	It returns false if at least one pair of the 
	two objects have different values.
*/
bool operator!=(const Name_pairs& a, const Name_pairs& b)
{
	return !(a == b);
}

} // end namespace NamePairs 


 