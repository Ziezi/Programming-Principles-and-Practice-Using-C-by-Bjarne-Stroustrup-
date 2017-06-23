/*
	TITLE		    Containers comparison      Chapter20TryThis8.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Redo the previous Try This using containers of
					type int, initialized to { 1, 2, 3, 4, 5 }
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
	int c[ ] = { 1, 2, 3, 4, 5 };
	int* beg_b = c;
	int* end_b = (c  + 5);

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
		 int c[ ] = { 1, 2, 3, 4, 5 };
		 std::vector<int> v(c, (c + 5));
		 std::list<int> l(v.begin(), v.end());

		 // test size
		 std::cout <<"Size: \n";
		 std::cout << size(c, (c + 5)) <<'\n';
		 std::cout << size(v.begin(), v.end()) <<'\n';
		 std::cout << size(l.begin(), l.end()) <<'\n';

		 // test compare
		 std::cout <<"\nComparison: \n";
		 if ( compare(c, (c + 5)) && 
			  compare(v.begin(), v.end()) &&
			  compare(l.begin(), l.end())) 
		 {
			std::cout <<"same\n";
		 }
		 else
		 {
			std::cout <<"different\n";
		 }

		  // test copy
		 std::cout <<"\nCopy: \n";
		 int c_copy[5];
		 copy(c, (c + 5), c_copy);
		 print(c_copy, c_copy + 5);

		 std::vector<int> v_copy(5);
		 copy(v.begin(), v.end(), v_copy.begin());
		 print(v_copy.begin(), v_copy.end());

		 std::list<int> l_copy(5);
		 copy(l.begin(), l.end(), l_copy.begin());
		 print(l_copy.begin(), l_copy.end());
	} 
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}