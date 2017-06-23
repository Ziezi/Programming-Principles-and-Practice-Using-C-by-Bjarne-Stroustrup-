/*
	TITLE			Auto_ptr               Chapter19Exercise10.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Implement a simple auto_ptr supporting:
					constructor, destructor, ->, *, and release();
		     Input: -
			Output: - 
			Author: Chris B. Kirov
			  Date: 24.1.2016
*/

#ifndef CHAPTER19EXERCISE10_H
#define CHAPTER19EXERCISE10_H

/*
	Class: Auto_ptr

	A generic smart pointer that doesn't need to be deleted explicitly, providing garbage collection.
*/
template<class T>
class Auto_ptr
{
private:
	Auto_ptr(Auto_ptr<T> const&);						    // prevent copy and assignment instantiation
	Auto_ptr& operator= (Auto_ptr<T> const&);
protected:
	typedef T* PointerType;									// pointer type defined by the implementation
	typedef T& ReferenceType;								// the type returned by: operator*
public:
	Auto_ptr()												// default contructor
		: value(Default()) 
	{
	
	}

	Auto_ptr(std::nullptr_t)								// nullptr to smart pointer conversion
		: value(Default()) 
	{
	
	}

	Auto_ptr& operator= (std::nullptr_t)					// nullptr to smart pointer conversion
	{
		reset();
		return *this;
	}

    explicit Auto_ptr(PointerType v)						// constructor
		: value(v) 
	{
	
	}				

	Auto_ptr(Auto_ptr&& src)								// move constructor
	{
		src.swap(*this);
	}	

	Auto_ptr& operator= (Auto_ptr&& src)					// move assignment
	{
		src.swap(*this);
		return *this;
	}

	~Auto_ptr() { Destroy(); }								// destructor

	template <class U>										// allow Auto_ptr usage with types derived from T
	Auto_ptr (Auto_ptr<U>&& src)							
	{
		Auto_ptr<T> tmp(src.release());
		tmp.swap(*this);
	}

	template <class U>										// allow Auto_ptr usage with types derived from T
	Auto_ptr& operator= (Auto_ptr<U>&& src)					
	{
		Auto_ptr<T> tmp(src.release());
		tmp.swap(*this);

		return *this;
	}

	// access operators
	ReferenceType operator* () const { return *value; }		// unary dereference operator
	PointerType operator-> () const { return value; }		// indirect class member access (arrow) operator

	// non-modifying members
	PointerType get() const { return value; }				// getter method

	void reset()											// reassign new value (default value: nullptr)
	{
		PointerType tmp = release();
		delete tmp;
	}	

	PointerType release()									// transfers the object to another pointer
	{
		PointerType temp = Default();
		std::swap(temp, value);
		return temp;
	}

	operator bool() { return value; }				// evaluate object in boolean context; prevent == comparison via convertion
	void swap(Auto_ptr& src) { std::swap(value, src.value); }

protected:
	void Destroy() { delete value; }						// destroys the object pointer by: value
	static PointerType Default() { return nullptr; }		// default value: nullptr
private:
	// data member
	PointerType value;
};

//--------------------------------------------------------------------------------------------------------------------------

template <class T>
void swap (Auto_ptr<T>& lhs, Auto_ptr<T>& rhs)
{
	lhs.swap(rhs);
}

#endif