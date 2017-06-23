/*
	TITLE		    ownership_vector		Chapter20Exercise17.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define an `ownership_vector` that holds 
					pointers to objects like `pvector`, 
					but provides a mechanism for the user to 
					decide which objects are owned by the vector
					(i.e., which objects are `delete`d by the destructor).
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 22. 02. 2017
*/

#ifndef Chapter20Exercise17_h
#define Chapter20Exercise17_h

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

/* 
	Class similar to smart pointers that substitudes standard class
	std::auto_ptr which can not be used with the class std::vector. 
*/
template <class T>
class Ownership_vector 
{
public:
	Ownership_vector()
	{
	
	}

	~Ownership_vector()
	{
		for (size_t i = 0; i < owned.size(); ++i)
		{
			delete owned[i];
		}
	}

	void push_back(T& s) { v.push_back(&s); }
    void push_back(T* p) { v.push_back(p); owned.push_back(p); }

	T& operator[](int i) { return *v[i]; }
	const T& operator[](int i) const { return *v[i]; }

	size_t number_of_stored() { return v.size(); }
	size_t number_of_owned() { return owned.size(); }

private:
	Vector<T*> v;
	Vector<T*> owned;
};

#endif