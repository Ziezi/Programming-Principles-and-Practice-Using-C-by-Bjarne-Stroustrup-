/*
	TITLE		    Range-checked iterator  Chapter20Exercise18Def.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define a range-checked iterator for Vector.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 22. 02. 2017
*/

//----------------------------------------------------------------------

template <class T, class A>
Vector<T,A>::Vector()
	: sz(0), elem(nullptr), space(0)
{
	
}

//----------------------------------------------------------------------

template <class T, class A>
Vector <T,A>::Vector(size_type s)
	: sz(s), elem(nullptr), space(s)
{
	elem = alloc.allocate(s);

	T init = T();
	for (int i = 0; i < sz; ++i)
	{
		alloc.construct(&elem[i], init);
	}
}

//----------------------------------------------------------------------

template <class T, class A>
Vector <T,A>::Vector(size_type s, value_type val)
	: sz(s), elem(nullptr), space(s)
{
	elem = alloc.allocate(s);

	for (int i = 0; i < sz; ++i)
	{
		alloc.construct(&elem[i], val);
	}
}

//----------------------------------------------------------------------

template <class T, class A>
void Vector <T,A>::reserve(size_type newalloc)
{
	if (newalloc <= space) 
	{
		return;
	}

	T* new_mem_ptr = alloc.allocate(newalloc);

	for (size_type i = 0; i < sz; ++i)
	{
		alloc.construct(&new_mem_ptr[i] , elem[i]);
	}

	for (size_type i = 0; i < sz; ++i) 
	{
		alloc.destroy(&elem[i]);
	}

	alloc.deallocate(elem, space);

	elem = new_mem_ptr;

	space = newalloc;
}

//----------------------------------------------------------------------

template <class T, class A>
void Vector<T, A>::resize(size_type newsize, value_type val = T())
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
void Vector<T, A>::push_back(const_reference_type val)
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
Vector<T, A>::iterator::iterator()
	: iter(nullptr), begin(nullptr), end(nullptr)
{

}

//----------------------------------------------------------------------

template <class T, class A>
Vector<T, A>::iterator::iterator(pointer_type p, pointer_type b, pointer_type e)
	: iter(p), begin(b), end(e)
{

}

//----------------------------------------------------------------------

template <class T, class A>
Vector<T, A>::iterator::iterator(const iterator& p)
	: iter(p.iter), begin(p.begin), end(p.end)
{

}

//----------------------------------------------------------------------

template <class T, class A>
typename Vector<T, A>::iterator& Vector<T, A>::iterator::operator= (const iterator& p)
{
	iterator temp(p);
	swap(*this, temp);
	return *this;
}

//----------------------------------------------------------------------

template <class T, class A>
typename Vector<T, A>::iterator Vector<T, A>::iterator::operator++() 
{ 
	if (iter + 1 > end)
	{ 
		throw std::out_of_range("iterator::operator++: out of range");
	} 
	++iter;
	return *this; 
}

//----------------------------------------------------------------------

template <class T, class A>
typename Vector<T, A>::iterator Vector<T, A>::iterator::operator++(int)
{
	Vector<T, A>::iterator old(*this);
	if (iter + 1 > end)
	{ 
		throw std::out_of_range("iterator::operator++: out of range");
	} 
	++iter;
	return old;
}

//----------------------------------------------------------------------

template <class T, class A>
typename Vector<T, A>::iterator Vector<T, A>::iterator::operator--()
{
	if (iter == begin)
	{ 
		throw std::out_of_range("iterator::operator--: out of range");
	} 
	--iter;
	return *this;
}

//----------------------------------------------------------------------

template <class T, class A>
typename Vector<T, A>::iterator Vector<T, A>::iterator::operator--(int)
{
	iterator old(*this);

	if (iter == begin)
	{ 
		throw std::out_of_range("iterator::operator--: out of range");
	} 
	--iter;

	return old;
}

//----------------------------------------------------------------------

template <class T, class A>
bool Vector<T, A>::iterator::operator== (const iterator& i)
{
	return iter == i.iter;
}

//----------------------------------------------------------------------

template <class T, class A>
bool Vector<T, A>::iterator::operator!= (const iterator& i)
{
	return !(*this == i);
}

//----------------------------------------------------------------------

template <class T, class A>
bool Vector<T, A>::iterator::operator< (const iterator& i)
{
	return iter < i.iter;
}

//----------------------------------------------------------------------

template <class T, class A>
bool Vector<T, A>::iterator::operator>= (const iterator& i)
{
	return !(*this < i);
}

//----------------------------------------------------------------------

template <class T, class A>
bool Vector<T, A>::iterator::operator> (const iterator& i)
{
	return iter > i.iter;
}

//----------------------------------------------------------------------

template <class T, class A>
bool Vector<T, A>::iterator::operator<= (const iterator& i)
{
	return !(*this > i);
}

//----------------------------------------------------------------------

template <class T, class A>
typename Vector<T, A>::const_reference_type Vector<T, A>::iterator::operator*() const
{ 
	if (iter == end)
	{
		throw std::out_of_range("iterator::operator* const: can't dereference end()");
	}
	return *iter; 
}	

//----------------------------------------------------------------------

template <class T, class A>
typename Vector<T, A>::reference_type Vector<T, A>::iterator::operator*()
{ 
	if (iter == end)
	{
		throw std::out_of_range("iterator::operator*: can't dereference end()");
	}
	return *iter; 
}	

//----------------------------------------------------------------------

template <class T, class A>
typename Vector<T, A>::iterator Vector<T, A>::iterator::operator+ (int n)
{
	if (iter + n > end)
	{ 
		throw std::out_of_range("iterator::operator+: out of range");
	} 
	iter += n;
	return *this;
}

//----------------------------------------------------------------------

template <class T, class A>
typename Vector<T, A>::iterator Vector<T, A>::iterator::operator- (int n)
{
	if (iter - n < begin)
	{ 
		throw std::out_of_range("iterator::operator-: out of range");
	} 
	iter -= n;
	return *this;
}

//----------------------------------------------------------------------

template <class T, class A>
typename Vector<T, A>::iterator Vector<T, A>::iterator::operator+= (int n)
{
	if (iter + n > end)
	{ 
		throw std::out_of_range("iterator::operator+=: out of range");
	} 
	iter += n;
	return *this;
}

//----------------------------------------------------------------------

template <class T, class A>
typename Vector<T, A>::iterator Vector<T, A>::iterator::operator-= (int n)
{
	if (iter - n < begin)
	{ 
		throw std::out_of_range("iterator::operator-=: out of range");
	} 
	iter -= n;
	return *this;
}

//----------------------------------------------------------------------

template <class T, class A>
typename Vector<T, A>::reference_type Vector<T, A>::iterator::operator[] (size_type n)
{
	if (begin + n > end)
	{
		throw std::out_of_range("iterator::operator[]: out of range");
	}
	return *(iter + n);
}

//----------------------------------------------------------------------

template <class T, class A>
void Vector<T, A>::iterator::swap(iterator& i)										
{
	iterator temp(i);

	i.iter = iter;
	i.begin = begin;
	i.end = end;

	iter = temp.iter;
	begin = temp.begin;
	end = temp.end;
}

//----------------------------------------------------------------------

template <class T, class A>
void Vector<T, A>::iterator::swap(iterator& lhs, iterator& rhs)						 
{
	lhs.swap(rhs);
}