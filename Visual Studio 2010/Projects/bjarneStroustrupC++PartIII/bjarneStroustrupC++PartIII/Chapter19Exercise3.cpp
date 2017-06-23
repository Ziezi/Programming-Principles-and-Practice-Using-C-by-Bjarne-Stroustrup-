/*
	TITLE			Class Pair   		      Chapter19Exercise3.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: A class Pair that holds a pair of any type.
		            Use it to implement a simple symbol table,
					like the one in Chapter 7.8.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 21.1.2016
*/
#include <iostream>
#include <vector>

template <typename T, typename U>
class Pair
{
public:
	Pair(T l, U r) 
		: left(l), right(r)
	{ 
	
	}

	T get_left () const { return left; }
	U get_right () const { return right; }

	void set_left (T l) { left = l; }
	void set_right (U r) { right = r; }
 
private:
	T left;
	U right;
};

//-----------------------------------------------------------------------

template<typename T, typename U>
std::ostream& operator<< (std::ostream& os, const Pair<T,U>& p)
{
	os << p.get_left() <<", "<< p.get_right() <<"\n";
	return os;
} 

//-----------------------------------------------------------------------

int main ()
{
	// symbol table using class Pair
	std::vector<Pair<char, int>> symbol_table;

	char left_value = 'a';
	int right_value = 1;
	Pair<char, int> p(left_value ,right_value);

	symbol_table.push_back(p);
	
	std::cout <<"Symbol table element: "<< symbol_table[0];
	
	getchar();
}