/*
	TITLE		    Range-checked iterator    Chapter20Exercise18.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define a range-checked iterator for Vector.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 22. 02. 2017
*/

#ifndef Chapter20Exercise18_h
#define Chapter20Exercise18_h

template <class T>
class Allocator
{
public:
	Allocator() { }

	~Allocator() { }

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
	typedef A allocator_type;
	typedef size_t size_type;
	typedef T value_type;
	typedef T* pointer_type;
	typedef T& reference_type;
	typedef const T& const_reference_type;

	class iterator;

	Vector();
	Vector(size_type s);
	Vector(size_type s, value_type val);

	void reserve(size_type newalloc);
	void resize(size_type newsize, value_type val = T());
	void push_back(const const_reference_type val);

	reference_type operator[] (size_type index) { return elem[index]; }

	size_type size() const { return sz; }
	size_type capacity() const { return space; }

	iterator begin() { return iterator(elem, elem, elem + sz); }
	iterator end() { return iterator(elem + sz, elem, elem + sz); }

private:
	allocator_type alloc;
	pointer_type elem;
	size_type sz;
	size_type space;
};

//----------------------------------------------------------------------

/* random access iterator */

template <class T, class A>
class Vector<T, A>::iterator
{
public:
	iterator();													// default constructor
	iterator(pointer_type p, pointer_type b, pointer_type e);
	
	iterator(const iterator& p);								// copy constructor
	iterator& operator= (const iterator& p);					// copy assignment 
		
	iterator operator++();										// incrementations
	iterator operator++(int);									// postfix
	iterator operator--();										// decrementations
	iterator operator--(int);									// postfix
	
	bool operator== (const iterator& i);						// equality comparisons
	bool operator!= (const iterator& i);

	bool operator< (const iterator& i);							// inequality comparisons
	bool operator<= (const iterator& i);
	bool operator> (const iterator& i);
	bool operator>= (const iterator& i);
	
	// multi-pass (maintains dereferenceability)
	const_reference_type operator*() const;						// dererenceable read rvalue
	reference_type operator*();									// dererenceable write lvalue

	iterator operator+ (int n);									// arithmetic operations
	iterator operator- (int n);
	
	iterator operator+= (int n);								// supports compound assignment += -=
	iterator operator-= (int n);
	
	reference_type operator[] (size_type n);					// supports offset dereference operator []

	void swap(iterator& i);										// swap data member helper
	void swap(iterator& lhs, iterator& rhs);					// swap iterator helper

private:
	pointer_type iter;
	pointer_type begin;
	pointer_type end;
};

//----------------------------------------------------------------------
 

#include "Chapter20Exercise18Def.cpp"

#endif