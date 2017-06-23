/*
	TITLE		    Vector size of int       Chapter19Exercise16.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define a vector so sizeof(vector<int>) == sizeof(int*),
					that is, the vector itself consists only of a pointer
					to a representation consisting of the elements, 
					the number of elements, and the space pointer. 
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 06. 2. 2016
*/
#include <iostream>

template <class T>
class Vector
{
public:
	Vector()
		: sz(0), elem(nullptr), space(0)
	{
	
	}

	Vector(int s)
		: sz(s), elem(new (std::nothrow) T[s]), space(s)
	{
		if (!elem)
		{
			delete[] elem;
			throw std::bad_alloc("Vector::constructor: bad allocation!\n");
		}

		T init = T();
		for (int i = 0; i < sz; ++i)
		{
			elem[i] = init;
		}
	}

	
	T* elem;
	int sz;
	int space;
};

//----------------------------------------------------------------------

template<class T>
class Vector_int
{
public:
	Vector_int()
		: v(new (std::nothrow) Vector<T>())
	{
		if (!v)
		{
			delete v;
			throw std::bad_alloc("Vector_int::constructor: bad allocation!\n");
		}

	}

	Vector_int(int s)
		: v(new (std::nothrow) Vector<T>(s))
	{
		if (!v)
		{
			delete v;
			throw std::bad_alloc("Vector_int::constructor: bad allocation!\n");
		}

	}

	Vector_int(int s, T val)
		: v(new (std::nothrow) Vector<T>(s))
	{
		if (!v)
		{
			delete[] v;
			throw std::bad_alloc("Vector_int::constructor: bad allocation!\n");
		}

		for (int i = 0; i < v->sz; ++i)
		{
			v->elem[i] = val;
		}
	}

	~Vector_int() { delete v; }

	void reserve(int newalloc);
	void resize(int newsize);
	void push_back(const T& val);

	T& operator[] (int index) { return v->elem[index]; }
	int size() const { return v->sz; }
	int capacity() const { return v->space; }
private:
	Vector<T>* v;
};

//----------------------------------------------------------------------

template <class T>
void Vector_int<T>::reserve(int newalloc)
{
	if (newalloc <= v->space) 
	{
		return;
	}

	Vector<T>* new_mem_ptr = new (std::nothrow) Vector<T>[newalloc];

	if (!new_mem_ptr)
	{
		delete new_mem_ptr;
		throw std::bad_alloc("Vector::reserve: bad allocation!\n");
	}

	for (int i = 0; i < v->sz; ++i)
	{
		new_mem_ptr->elem[i] = v->elem[i];
	}

	delete v;
	  
	v = new_mem_ptr;
	v->space = newalloc;
}

//----------------------------------------------------------------------

template <class T>
void Vector_int<T>::resize(int newsize)
{
	reserve(newsize);

	T def_val = T();
	for (size_t i = newsize; i < v->sz; ++i)
	{
		v->elem[i] = def_val;
	}

	v->sz = newsize;
}

//----------------------------------------------------------------------

template <class T>
void Vector_int<T>::push_back(const T& val)
{
	if (v->space == 0)
	{
		reserve(8);
	}
	else if (v->sz == v->space)
	{
		reserve(2 * v->space);
	}

	v->elem[v->sz] = val;
	++v->sz;
}

//----------------------------------------------------------------------

int main()
{
	try 
	{
		Vector_int<int> v(1);

		std::cout <<"size: "<< sizeof(v) <<'\n';
		std::cout <<"size int: "<< sizeof(int) <<'\n';

		std::cout <<"v.size(): "<< v.size() <<'\n';
		std::cout <<"v.capacity(): "<< v.capacity() <<'\n';

		v[0] = 5;
		std::cout <<"v[0]"<< v[0];
	} 
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}