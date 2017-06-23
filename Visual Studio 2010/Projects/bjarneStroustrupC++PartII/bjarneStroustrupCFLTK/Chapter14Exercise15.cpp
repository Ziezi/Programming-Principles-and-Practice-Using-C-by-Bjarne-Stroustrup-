/*
	TITLE		   Iterator						 Chapter14Exercise15.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a class Iterator with pure virtual function next()
				   that returns a pointer to double. 
				   Now derive Vector_iterator and List_iterator from
				   Iterator so that next() for the first yields a pointer
				   to the next element of a vector<double> and
				   the latter one to list<double>. 
				   You initialize a Vector_iterator with vector<double> 
				   and the first call to next() yields a pointer to the first element, if any.
				   If there is no next element, return 0. 
				   Test both by using a function void print (Iterator&)
				   to print the elements of vector and list of doubles.
		    Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include <iostream>
#include <vector>
#include <list>

class Iterator
{
public:
	virtual double* next() = 0;
};
//----------------------------------------------------------------------------

class Vector_iterator: public Iterator
{
public: 
	Vector_iterator(const std::vector<double>& vv)
		: v(vv), index(0)
	{

	}

	double* next();

private:
	std::vector<double> v;
	size_t index;
};

double* Vector_iterator::next()
{
	if (v.size() && index < v.size())
	{
		return &v[index++];
	}
	else 
	{
		return 0;
	}
}

//----------------------------------------------------------------------------

class List_iterator: public Iterator
{
public:
	List_iterator(const std::list<double>& ll)
		: l(ll), itr(l.begin())
	{
	
	}

	double* next();

private:
	std::list<double> l;
	std::list<double>::iterator itr;
};

double* List_iterator::next()
{
	double* ptr;

	if (distance(itr, l.end()) > 0)
	{
		ptr = &*itr;
		++itr;
		return ptr;
	}
	else
	{
		return 0;
	}
}

//----------------------------------------------------------------------------

void print (Iterator& it)
{
	double* ptr = nullptr;

	while ((ptr = it.next()) != 0)
	{
		std::cout << *ptr << std::endl;
	}
}

//----------------------------------------------------------------------------

int main() 
{
	try
	{
		std::vector<double> v;
		for (int i = 0; i < 10; ++i)
		{
			v.push_back(i);
		}

		Vector_iterator itv(v);
		print(itv);
		 
		std::list<double> l;
		for (int i = 0; i < 10; ++i)
		{
			l.push_back(i);
		}

		List_iterator itl(l);
		print(itl);

		getchar();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	catch (...)
	{
		std::cerr <<"Default exception caugth!"<< std::endl;
		getchar();
	}
}
