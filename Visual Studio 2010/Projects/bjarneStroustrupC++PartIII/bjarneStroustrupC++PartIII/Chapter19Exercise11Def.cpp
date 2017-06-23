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

template<class T>
Reference_counter& Reference_counter::operator= (const Reference_counter& rc)	   
{
	if (this == &rc)
	{
		return *this;
	}

	count = rc.count;

	return *this;
}

//----------------------------------------------------------------------------------------------- 

template<class T>
bool Reference_counter::release ()  											    
{
	if (!--count) 
	{
		return true; 
	}

	return false;
}

//----------------------------------------------------------------------------------------------- 

template<class T>
Counted_ptr<T>::Counted_ptr()													
	: value(Default()), refCount(nullptr)
{
	reCount = new Reference_counter()
	refCount->add_reference();
}

//----------------------------------------------------------------------------------------------- 

template<class T>
Counted_ptr<T>::Counted_ptr(PointerType v)								
	: value(v), refCount(nullptr) 
{
	refCount = new Reference_counter();
	refCount->add_reference();
}

//----------------------------------------------------------------------------------------------- 

template<class T>
Counted_ptr<T>::Counted_ptr(Counted_ptr<T>& c_ptr)							  
	: value(c_ptr.value), refCount(c_ptr.refCount)
{
	refCount->add_reference();
}

//----------------------------------------------------------------------------------------------- 

template<class T>
Counted_ptr<T>& Counted_ptr<T>::operator= (Counted_ptr<T>& src)
{		
	if (this == &src)
	{
		return *this;
	}
	 
	if (refCount->release())
	{
		Destroy();
		delete refCount; 
	}

	value = c_ptr.value;
	refCount = c_ptr.refCount;
	refCount->add_reference();
	 
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
void Counted_ptr<T>::reset(PointerType v) 
{
	if (value)
	{
		Destroy();
	}

	value = v;
} 

//-----------------------------------------------------------------------------------------------

template <class T>
T* Counted_ptr<T>::release()
{
	PointerType temp = value;
	value = Default();

	return temp;
}