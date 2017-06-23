/*
	TITLE			Allocator    Chapter19Exercise8.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Implement an allocator (19.3.6) using malloc() and free() (B.10.4).
					Get vector as defined by the end of 19.4 to work for few simple cases.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 24.1.2016
*/
#ifndef CHAPTER19EXERCISE8_H
#define CHAPTER19EXERCISE8_H
 
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

	T* allocate (size_t n) { return reinterpret_cast<T*>(malloc(n * sizeof(T))); }
	void deallocate (T* ptr, size_t n) { free(ptr); }

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
	T& at (int index)
	{
		if (index < 0 || index > sz)
		{
			throw std::out_of_range("Vector::at: out of range access!");
		}
		return elem[index];
	}

	const T& at (int index) const
	{
		if (index < 0 || index > sz)
		{
			throw std::out_of_range("Vector::at: out of range access!");
		}
		return elem[index];
	}

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

#endif




