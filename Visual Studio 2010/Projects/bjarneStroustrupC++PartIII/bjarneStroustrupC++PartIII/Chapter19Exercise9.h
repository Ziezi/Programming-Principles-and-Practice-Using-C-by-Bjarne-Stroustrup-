/*
	TITLE			Allocator				   Chapter19Exercise9.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Re-implement vector::operator() (§19.2.5)
					using an allocator §19.3.6 for memory management.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 24.1.2016
*/
#ifndef CHAPTER19EXERCISE9_H
#define CHAPTER19EXERCISE9_H
 
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

	Vector<T, A>& operator= (const Vector<T, A>& src)
	{
		if (this == &src)							// self assignment
		{
			return *this;
		}

		if (sz >= src.size())						// already enough memory - overwrite
		{
			for (int i =0; i < sz; ++i)
			{
				alloc.construct(&elem[i], src.elem[i]);
			}

			sz = src.size();

			return *this;
		}

		T* new_ptr = alloc.allocate(src.size());	// make new copy

		for (int i =0; i < src.size(); ++i)
		{
			alloc.construct(&new_ptr[i], src.elem[i]);
		}
		
		for (int i =0; i < sz; ++i)
		{
			alloc.destory(&elem[i]);
		}

		alloc.deallocate(elem);

		space = sz = src.size();
		elem = new_ptr;
		
		return *this;
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




