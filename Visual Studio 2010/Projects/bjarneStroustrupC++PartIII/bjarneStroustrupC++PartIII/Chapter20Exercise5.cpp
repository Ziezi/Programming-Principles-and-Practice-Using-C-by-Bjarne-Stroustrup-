/*
	TITLE		     >>operator for vector   Chapter20Exercise5.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define <<operator and >>operator for vector. 
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 19. 02. 2017
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <class T>
std::ostream& operator<< (std::ostream& os, std::vector<T>& v)
{
	if (!v.empty())
	{
		os <<"{ ";
		std::copy(v.begin(), v.end(), std::ostream_iterator<T>(os, " "));
		os <<"}";
	}
	
	return os;
}

//-----------------------------------------------------------------------------------

/* Expected input format: { val val val val } */ 
template <class T>
std::istream& operator>> (std::istream& is, std::vector<T>& v)
{
	char c;
	is >> c;

	if (c != '{')  
	{
		is.setf(std::ios_base::failbit);
		return is;
	}
	
	while (is >> c)
	{
		if (c == '}')
		{
			return is;
		}
		is.unget();
		
		T val;
		if (is >> val)
		{
			v.push_back(val);
		}
		else
		{
			is.setf(std::ios_base::failbit);
			return is;
		}
	}

	is.setf(std::ios_base::failbit);
	return is;
}

//-----------------------------------------------------------------------------------

int main()
{
	try 
	{
		 std::vector<double> v;

		 std::cin >> v;

		 std::cout << v;

		 getchar();
	}
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}