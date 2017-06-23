/*
	TITLE		    Containers comparison      Chapter20TryThis7.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: For each array of char, vector<char>, list<char>,
				    and string, define one with the value "Hello", 
					pass it to a function as an argument, write out
					the number of characters in the string passed,
					try to compare it to "Hello", copy the argument
					into another variable of the same type.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 17. 02. 2017
*/
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>

//-----------------------------------------------------------------

template <class Iterator>
size_t size(Iterator beg, Iterator end)
{
	size_t s = 0;
	while (beg != end)
	{
		++s;
		++beg;
	}
	return s;
}

//-----------------------------------------------------------------

template <class Iterator>
bool compare(Iterator beg_a, Iterator end_a)
{
	char c[ ] = { 'H', 'e', 'l', 'l', 'o' };
	char* beg_b = c;
	char* end_b = (c  + 5);

	while (beg_a != end_a || beg_b != end_b)
	{
		if (*beg_a != *beg_b)
		{
			return false;
		}

		++beg_a;
		++beg_b;
	}

	return true;
}

//-----------------------------------------------------------------

template <class Iterator>
void copy (Iterator src_b, Iterator src_e, Iterator dest_b)
{
	while (src_b != src_e)
	{
		*dest_b = * src_b;

		++src_b;
		++dest_b;
	}
}

//-----------------------------------------------------------------

template <class Iterator>
void print (Iterator beg, Iterator end)
{
	while (beg != end)
	{
		std::cout << *beg;
		++beg;
	}
	std::cout <<'\n';
}

//-----------------------------------------------------------------

int main()
{
	try 
	{
		 char c[ ] = { 'H', 'e', 'l', 'l', 'o' };
		 char* b = c;
		 char* e = (c + 5); 

		 std::string s(b, e);
		 std::vector<char> v(s.begin(), s.end());
		 std::list<char> l(v.begin(), v.end());

		 // test size
		 std::cout <<"Size: \n";
		 std::cout << size(b, e) <<'\n';
		 std::cout << size(s.begin(), s.end()) <<'\n';
		 std::cout << size(v.begin(), v.end()) <<'\n';
		 std::cout << size(l.begin(), l.end()) <<'\n';

		 std::cout <<"\nComparison: \n";
		 // test compare
		 if ( compare(b, e) && 
			  compare(s.begin(), s.end()) &&
			  compare(v.begin(), v.end()) &&
			  compare(l.begin(), l.end())) 
		 {
			std::cout <<"same\n";
		 }
		 else
		 {
			std::cout <<"different\n";
		 }

		 std::cout <<"\nCopy: \n";
		 // test copy
		 char c_copy[5];
		 copy(c, (c + 5), c_copy);
		 print(c_copy, c_copy + 5);

		 std::string s_copy(5, ' ');
		 copy(s.begin(), s.end(), s_copy.begin());
		 print(s_copy.begin(), s_copy.end());

		 std::vector<char> v_copy(5);
		 copy(v.begin(), v.end(), v_copy.begin());
		 print(v_copy.begin(), v_copy.end());

		 std::list<char> l_copy(5);
		 copy(l.begin(), l.end(), l_copy.begin());
		 print(l_copy.begin(), l_copy.end());
	} 
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}