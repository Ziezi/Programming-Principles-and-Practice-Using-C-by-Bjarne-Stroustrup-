/*
	TITLE		   Array_ref      					   Chapter25Exercise17.cpp
	COMMENT
		Objective: Proof that Array_ref handles inheritance correctly by trying
				   to get a Rectangle* into std::vector<Circle*> using
				   Array_ref<Shape*>, without using casts or other operations
				   involving undefined behaviour.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 27.05.2017
*/
#include <iostream>
#include <vector>
#include "Simple_window.h"

template <class T>
class Array_ref
{
	T* p;
	int sz;

public:
	Array_ref(T* pp, int s )
		: p(pp), sz(s)
	{
	
	}

	T& operator[] (int i) { return p[i]; }

	const T& operator[] (int i) const { return p[i]; }

	bool assign(Array_ref a)
	{
		if (a.sz != a)
		{
			return false;
		}

		for (int i = 0; i < sz; ++i)
		{
			p[i] = a.p[i];
		}
	}

	void reset(Array_ref a) { reset(a.p, a.sz); }

	void rest(T* pp, int s) { p = pp; sz = s; }

	int size() const { return sz; }
};

//-----------------------------------------------------------------------------------

template <class T>
Array_ref<T> make_ref(T* pp, int s)
{
	return (pp) ? Array_ref<T>(pp, s) : Array_ref<T>(0, 0);
}

//-----------------------------------------------------------------------------------

template <class T>
Array_ref<T> make_ref(std::vector<T>& v)
{
	return (v.size()) ? Array_ref<T>(&v[0], v.size()) : Array_ref<T>(0, 0);
}

//-----------------------------------------------------------------------------------

template <class T, int s>
Array_ref<T> make_ref(T (&pp)[s])
{
	return Array_ref<T>(pp, s);
}

//-----------------------------------------------------------------------------------

void test_inheritance_protection(Graph_lib::Shape* s, std::vector<Graph_lib::Circle>& c)
{
	std::size_t size = 1;
	c.emplace_back(make_ref(s, size));
}

//-----------------------------------------------------------------------------------

int main()
{
	try
	{
		Graph_lib::Rectangle* rectangle = new Graph_lib::Rectangle(Point(50, 50), 50, 100);

		std::vector<Graph_lib::Circle> circles;

		test_inheritance_protection(rectangle, circles);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}