/*
	TITLE			Ownership management through reference counting    Chapter19Exercise11.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Design and implement a counted_ptr<T> that is 
					a type that holds a pointer to an object of 
					type T and a pointer to a "use count" (an int)
					shared by all counted pointers to the same object
					of type T.

					The use count should hold the number of counted 
					pointers pointing to a given T.
		     Input: -
			Output: - 
			Author: Chris B. Kirov
			  Date: 27.1.2016
*/

#ifndef CHAPTER19EXERCISE11_H
#define CHAPTER19EXERCISE11_H

/*
	Keeps track of the number of instantiated pointers  
*/
class Reference_counter
{
private:
	Reference_counter (const Reference_counter& rc);               // prevent copy constructor
	Reference_counter& operator= (const Reference_counter& rc);	   // prevent copy assignment
protected:
	typedef unsigned int ValueType;
public:
	Reference_counter () : count(0) { }							   // default constructor ONLY									
	~Reference_counter () { }									   // destructor

	void add_reference () { ++count; }							   // increments counter, reflecting new pointer creation
	bool release () { --count; return !count; }  				   // decrements counter and check if any pointers left
private:
	ValueType count;											   // counts the number of pointers  
};

//----------------------------------------------------------------------------------------------- 

/* 
	 The ownership of the pointer is shared across multiple instances of Counted_ptr and
	 the pointer is only released (deleted) when all Counted_ptr instances have been destroyed.
*/
template <class T>
class Counted_ptr 
{
protected:
	typedef T* PointerType;
	typedef T& ReferenceType;
public:
	Counted_ptr();												   // default constructor
	Counted_ptr(std::nullptr_t);								   // null to smart pointer conversion			
	explicit Counted_ptr (PointerType v);						   // constructor
	Counted_ptr (Counted_ptr<T> const& c_ptr);					   // copy constructor	 
	Counted_ptr (Counted_ptr<T>&& c_ptr);						   // move constructor

	Counted_ptr<T>& operator= (std::nullptr_t);					   // null to smart pointer conversion		
	Counted_ptr<T>& operator= (Counted_ptr<T>  const& c_ptr);  	   // copy assignment
	Counted_ptr<T>& operator= (Counted_ptr<T>&& c_ptr);			   // move assignment	
	~Counted_ptr ();											   // destructor
	 
	PointerType get() const { return value; }					   // pointee object value access 
	ReferenceType operator* () const { return *value; }			   // dereference	    
	PointerType operator-> () const { return value; }

	operator bool() const { return value; }							// evaluate object in boolean context 
	void swap(Counted_ptr& src);

protected:
	void Destroy() { delete value; }							    // destroy pointee object and free its memory
	static PointerType Default() { return nullptr; }				// default value for the class StoredType
private:
	PointerType value;
	Reference_counter* refCount;									// If counter = 0; the pointee object is deleted.
};

//-----------------------------------------------------------------------------------------------

template<typename T>
void swap(Counted_ptr<T>& lhs, Counted_ptr<T>& rhs) { lhs.swap(rhs); }

#include "Chapter19Exercise11Defv2.cpp"
#endif