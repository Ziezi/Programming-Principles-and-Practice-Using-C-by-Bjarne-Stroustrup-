/*
	TITLE			Ownership management through reference counting    Chapter19Exercise11Defv2.cpp
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


template<class T>
Counted_ptr<T>::Counted_ptr()													
	: value(Default()), refCount(new (std::nothrow) Reference_counter())
{
	if (!refCount) 
	{
		Destroy();
		throw std::bad_alloc("Counted_ptr::default constructor::Referene_counter(): can't allocate refCount");
	}
}

//----------------------------------------------------------------------------------------------- 

template<class T>
Counted_ptr<T>::Counted_ptr(std::nullptr_t)
	: value(Default()), refCount(new (std::nothrow) Reference_counter())
{
	if (!refCount) 
	{
		Destroy();
		throw std::bad_alloc("Counted_ptr::default constructor::Referene_counter(): can't allocate refCount");
	}
}

//----------------------------------------------------------------------------------------------- 

template<class T>
Counted_ptr<T>::Counted_ptr(PointerType v)								
	: value(v), refCount(new (std::nothrow) Reference_counter()) 
{
	if (!refCount)
	{
		Destroy();
		throw std::bad_alloc("Counted_ptr::constructor::Referene_counter(): can't allocate refCount");
	}

	refCount->add_reference();
}

//----------------------------------------------------------------------------------------------- 

template<class T>
Counted_ptr<T>::Counted_ptr(Counted_ptr<T> const& src)							  
	: value(src.value), refCount(src.refCount)
{
	refCount->add_reference();
}

//-----------------------------------------------------------------------------------------------

template<class T>
Counted_ptr<T>::Counted_ptr(Counted_ptr<T>&& src)
{
	src.swap(*this);
}

//----------------------------------------------------------------------------------------------- 

template<class T>
Counted_ptr<T>& Counted_ptr<T>::operator= (std::nullptr_t)
{
	Counted_ptr<T> temp = nullptr;
	swap(*this, temp);

	return *this;
}

//----------------------------------------------------------------------------------------------- 


template<class T>
Counted_ptr<T>& Counted_ptr<T>::operator= (Counted_ptr<T> const& src)
{		
	Counted_ptr<T> tmp(src);

	std::swap(value, tmp.value);
	std::swap(refCount, tmp.refCount);

	return *this;
}

//-----------------------------------------------------------------------------------------------

template<class T>
Counted_ptr<T>& Counted_ptr<T>::operator= (Counted_ptr<T>&& src)
{
	src.swap(*this); 
	return *this;
}

//-----------------------------------------------------------------------------------------------

template <class T>
Counted_ptr<T>::~Counted_ptr() 
{
	if (refCount->release())
	{
		Destroy();
		delete refCount;
	}
}

//-----------------------------------------------------------------------------------------------

template <class T>
void Counted_ptr<T>::swap(Counted_ptr& src)
{
	std::swap(value, src.value);
	std::swap(refCount, src.refCount);
}


 