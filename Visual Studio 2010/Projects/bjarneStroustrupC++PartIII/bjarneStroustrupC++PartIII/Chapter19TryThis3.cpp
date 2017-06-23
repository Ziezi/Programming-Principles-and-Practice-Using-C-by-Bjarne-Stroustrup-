/*
	TITLE		    RAII & auto_ptr            Chapter19TryThis3.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Modify the function reserve() to use auto_ptr.
					Can't access allocated memory - no pointer arithmetic.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 19.1.2016
*/
#include <iostream>
#include <vector>
#include <memory>

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

	// allocate needed space and return it to p
	//std::auto_ptr <T> p(alloc.allocate(newalloc)); 
	T* new_mem_ptr = alloc.allocate(newalloc);

	// copy old elements to new memory
	for (int i = 0; i < sz; ++i)
	{
		//alloc.construct(&p[i] , elem[i]);
		alloc.construct(&new_mem_ptr[i] , elem[i]);
	}

	// destroy old data
	for (int i = 0; i < sz; ++i) 
	{
		alloc.destroy(&elem[i]);
	}

	alloc.deallocate(elem, space);

	// elem = p.release();
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

int main ()
{
	try
	{
		// default
		Vector<int> v1;
		v1.push_back(2);
		std::cout <<"v1::size: " << v1.size();
		std::cout <<"\nv1::capacity: " << v1.capacity();
		std::cout <<"\nv1::operator[]: " << v1[0];

		//
		Vector<double> v2(10);
		std::cout <<"v2::size: " << v2.size();
		std::cout <<"\nv2::capacity: " << v2.capacity();
		std::cout <<"\nv2::operator[]: " << v2[9];

		//
		Vector<char> v3(20, 'a');
		std::cout <<"\nv3::size: " << v3.size();
		std::cout <<"\nv3::capacity: " << v3.capacity() <<'\n';
		v3[9] = 'b';

		for (int i = 8; i < v3.size(); ++i)
		{
			std::cout << v3[i] <<' ';
		}
		 
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}