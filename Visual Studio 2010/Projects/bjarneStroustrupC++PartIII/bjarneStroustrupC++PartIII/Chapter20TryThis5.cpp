/*
	TITLE		    Vector: push_front()      Chapter20TryThis5.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Implement push_front() for vector and 
					compare it to push_back(). 
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 17. 02. 2017
*/
#include <iostream>

template <class T>
class Allocator
{
public:
	Allocator()
	{
	
	}

	~Allocator()
	{

	}

	T* allocate (size_t n) { return reinterpret_cast<T*>(::operator new(n * sizeof(T))); }
	void deallocate (T* ptr, size_t n) { ::operator delete(ptr); }

	void construct (T* ptr, const T& v) {  new(ptr) T(v); }
	void destroy (T* ptr) { ptr->~T(); }
};

//----------------------------------------------------------------------

template <class T, class A = Allocator<T> >
class Vector
{
public:
	Vector()
		: sz(0), elem(nullptr), space(0)
	{
	
	}

	Vector(int s)
		: sz(s), elem(nullptr), space(s)
	{
		elem = alloc.allocate(s);

		T init = T();
		for (int i = 0; i < sz; ++i)
		{
			alloc.construct(&elem[i], init);
		}
	}

	Vector(int s, T val)
		: sz(s), elem(nullptr), space(s)
	{
		elem = alloc.allocate(s);

		for (int i = 0; i < sz; ++i)
		{
			alloc.construct(&elem[i], val);
		}
	}

	void reserve(int newalloc);
	void resize(int newsize, T val = T());
	void push_back(const T& val);
	void push_front(const T& val);

	T& operator[] (int index) { return elem[index]; }

	int size() const { return sz; }
	int capacity() const { return space; }

private:
	A alloc;
	T* elem;
	int sz;
	int space;
};

//----------------------------------------------------------------------

template <class T, class A>
void Vector <T,A>::reserve(int newalloc)
{
	if (newalloc <= space) 
	{
		return;
	}

	T* new_mem_ptr = alloc.allocate(newalloc);

	for (int i = 0; i < sz; ++i)
	{
		alloc.construct(&new_mem_ptr[i] , elem[i]);
	}

	for (int i = 0; i < sz; ++i) 
	{
		alloc.destroy(&elem[i]);
	}

	alloc.deallocate(elem, space);

	elem = new_mem_ptr;
	space = newalloc;
}

//----------------------------------------------------------------------

template <class T, class A>
void Vector<T, A>::resize(int newsize, T val = T())
{
	reserve(newsize);

	for (size_t i = 0; i < newsize; ++i)
	{
		alloc.construct(elem[i], val);
	}

	for (size_t i = newsize; i < sz; ++i)
	{
		alloc.destroy(&elem[i]);
	}

	sz = newsize;
}

//----------------------------------------------------------------------

template <class T, class A>
void Vector<T, A>::push_back(const T& val)
{
	if (space == 0)
	{
		reserve(8);
	}
	else if (sz == space)
	{
		reserve(2 * space);
	}

	alloc.construct(&elem[sz], val);
	++sz;
}

//----------------------------------------------------------------------

template <class T, class A>
void Vector<T, A>::push_front(const T& val)
{
	if (space == 0)
	{
		reserve(8);
	}
	else if (sz == space)
	{
		reserve(2 * space);
	}

	T* new_mem_ptr = alloc.allocate(sz + 1);

	// put in front 
	alloc.construct(&new_mem_ptr[0], val);

	// translate old elements one to the right
	for (int i = 0; i < sz; ++i)
	{
		alloc.construct(&new_mem_ptr[i + 1] , elem[i]);
	}

	for (int i = 0; i < sz; ++i) 
	{
		alloc.destroy(&elem[i]);
	}
	alloc.deallocate(elem, space);

	elem = new_mem_ptr;
	++sz;
}

//----------------------------------------------------------------------

int main()
{
	try 
	{
		// Every insertion needs new dynamic memory allocation and copy of all existing elements to a place with index = index+1
		// If the allocated chunck of space with length: n is being populated starting from n/2 then push_front() could be faster
		// the overhead would be an index measuring the left space in front and / or "front" capacity() 

		Vector<int> v;
		v.push_front(5);
		v.push_front(1);

		std::cout <<"First element: "<< v[0];
	} 
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}