/*
	TITLE		    pvector		    		  Chapter20Exercise15.h
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define a `pvector` to be like `vector` of pointers
					except that it contains pointer to objects
					and its destructor deletes each object. 
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 22. 02. 2017
*/

#ifndef Chapter20Exercise15_h
#define Chapter20Exercise15_h

 template<class T> 
 struct Vector : public std::vector<T> 
 {
	typedef typename std::vector<T>::size_type size_type;

	Vector() 
	{
	
	}

	explicit Vector(size_type n) 
		: std::vector<T>(n) 
	{
	
	}

	Vector(size_type n, const T& v) 
		: std::vector<T>(n,v)
	{
	
	}

	template <class I>
	Vector(I first, I last) 
		: std::vector<T>(first, last) 
	{
	
	}

	T& operator[](unsigned int i) 
	{
		if (i < 0 || this->size() <= i)
		{
			throw std::out_of_range("Vector::operator[]: index out of range");
		}

		return std::vector<T>::operator[](i);
	}

	const T& operator[](unsigned int i) const
	{
		if (i < 0 || this->size() <= i)
		{
			throw std::out_of_range("Vector::operator[]: index out of range");
		}
		return std::vector<T>::operator[](i);
	}
};

//----------------------------------------------------------------------

template <class T>
class Pvector
{
public:
	typedef typename Vector<T*>::size_type size_type;
	typedef typename Vector<T*>::iterator iterator;
	typedef typename Vector<T*>::const_iterator const_iterator;

	Pvector()
		: elements()
	{
	
	}

	Pvector(size_t n)
		: elements(Vector<Elem>(n))
	{
	
	}

	~Pvector()
	{
		for (size_t i = 0; i < elements.size(); ++i)
		{
			delete elements[i];
		}
	} 

	iterator begin() { return elements.begin(); }
	iterator end() { return elements.end(); }
	
	void push_back(T* e) { elements.push_back(e); }
	T* operator[] (size_type i) { return elements[i]; }
	const T* operator[] (size_type i) const { return elements[i]; }

	size_type size() { return elements.size(); }
	size_type capacity() { return elements.capacity(); }

private:
	Vector<T*> elements;
};


#endif