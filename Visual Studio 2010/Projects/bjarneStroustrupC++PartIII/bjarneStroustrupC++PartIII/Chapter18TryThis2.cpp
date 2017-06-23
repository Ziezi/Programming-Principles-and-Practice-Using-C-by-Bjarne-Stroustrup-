/*
	TITLE		    Custom vector             Chapter18TryThis2.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Implement the vector example from Chapter 18,
					compile, run and check error messages when use
					operator[] to assign new values to elements.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 22.12.2015
*/
#include <iostream>
#include <string>

class My_vector 
{
public:
	// default constructor
	My_vector() 
		: size(1), elem(new double[1]) 
	{
		elem[0] = 0.0;
	}  

	// explicit constructor, disallows implicit conversions from int to vector object
	explicit My_vector(int s)
		: size(s), elem(new double[s]) 
	{
		for (auto i = 0; i < s; ++s)
		{
			elem[i] = 0.0;
		}
	}

	// copy constructor
	My_vector(const My_vector& mv)
		: size(mv.get_size()), elem(new double[mv.get_size()]) 
	{
		for (auto i = 0; i < size; ++i)
		{
			elem[i] = mv.elem[i];
		}
	}

	// copy assignment
	My_vector& operator= (const My_vector& mv)
	{
		// allocate new space
		double* p = new double[mv.get_size()];

		// copy elemets of source to target vector
		for (auto i = 0; i < mv.get_size(); ++i)
		{
			p[i] = mv.elem[i];
		}

		// delete old target elements
		delete[] elem;

		// reassign the new elements
		elem = p;
		size = mv.get_size();

		// assure chaining by returning self-reference
		return *this;
	}

	// destructor 
	~My_vector()
	{ 
		delete[] elem; 
	}

	// member functions
	int get_size() const { return size; }
	double get (int i) { return elem[i]; }
	void set (int i, double v) { elem[i]  = v; }

	// index access operator, returning by value doesn't allow writing new values to the accessed element
	double operator[] (int i) { return elem[i]; } 

	// returning by reference allows reassigning of new values 
	// double& operator[] (int i) { return elem[i]; } 
private:
	int size;
	double *elem;
};
 
//-----------------------------------------------------------------------------------------------------------

int main () 
{
	try
	{
		std::cout <<"My_vector\n";

		My_vector v(10);
	 
		v.set(0, 2.5);

		// std::cout <<"v[0]: "<< v.get(0) <<" operator[]: "<< v[0] <<"\n";

		// trying to assign new value to an element accessed using operator[]
		v[1] = 5.0; // error C2106: '=' : left operand must be l-value
	}
	catch (std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	getchar();
}