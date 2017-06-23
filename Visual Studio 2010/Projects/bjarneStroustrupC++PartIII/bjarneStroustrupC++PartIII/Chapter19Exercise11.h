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
protected:
	typedef unsigned int ValueType;
public:
	Reference_counter () : count(0) { }							   // default constructor										
	explicit Reference_counter (ValueType c)	: count(c) { }	   // constructor
	Reference_counter (const Reference_counter& rc);               // copy constructor
	Reference_counter& operator= (const Reference_counter& rc);	   // copy assignment
	~Reference_counter () { }									   // destructor

	// modifying member functions
	void add_reference () { ++count; }							   // increments counter, reflecting new pointer creation
	bool release ();  											   // decrements counter and check if any pointers left
private:
	ValueType count;											   // counts the number of pointers  
};

//----------------------------------------------------------------------------------------------- 

/* 
	Allows multiple pointers to single object. If number of pointers pointing to the same object zero, object deleted.
*/
template <class T>
class Counted_ptr 
{
protected:
	typedef T* PointerType;
	typedef T& ReferenceType;
public:
	Counted_ptr();												   // default constructor
	explicit Counted_ptr(PointerType v);						   // constructor
	Counted_ptr(Counted_ptr<T>& c_ptr);							   // copy constructor	 
	Counted_ptr<T>& operator= (Counted_ptr<T>& c_ptr);  		   // copy assignment	
	~Counted_ptr();												   // destructor
	 
	// modifying member functions
	PointerType get() { return value; }							   // pointee object value access 
	void reset(PointerType v);									   // pointer reassignment
	PointerType release();										   // pointer resources transfer

	// access operators
	ReferenceType operator* () const { return *value; }			    
	PointerType operator-> () const { return value; }

protected:
	void Destroy() { delete value; }							    // destroy pointee object and free its memory
	static PointerType Default() { return nullptr; }				// default value for the class StoredType
private:
	PointerType value;
	Reference_counter* refCount;									// If counter = 0; the pointee object is deleted.
};

#include "Chapter19Exercise11Def.cpp"
#endif