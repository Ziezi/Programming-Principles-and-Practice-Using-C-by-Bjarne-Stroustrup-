/*
	TITLE		    Linked list             Chapter18TryThis.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Construction and destruction of objects.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 21.12.2015
*/
#include <iostream>
#include <string>
#include <vector>

struct X 
{
	// data member
	int val;

	// non - modifying member function
	void out (const std::string& s) 
	{ 
		std::cerr << this <<"->"<< s <<": "<< val <<'\n';
	}

	// constructors and assignment

	// default constuctor
	X() 
	{ 
		val = 0;
		out("X()");
	}

	// constructor
	X(int v)
	{ 
		val = v;
		out("X(int)"); 
	}

	// copy constructor
	X(const X& x)
	{ 
		val = x.val; 
		out("X(X&)"); 
	}

	// copy assignment
	X& operator= (const X& x) 
	{ 
		val = x.val; 
		out("X::operator=()"); 
		return *this; 
	}

	// destructor
	~X() 
	{ 
		out("~X()");
	}
};

//------------------------------------------------------------------------------------------

X glob(2);					// default constructor called
							// throughout the whole program there is a brake due to:
							// Access violation reading location 0xfeeefef6.
			
							// caused by this line

//------------------------------------------------------------------------------------------

X copy(X a)
{ 
	return a; 
}

//------------------------------------------------------------------------------------------

X copy2(X a)
{ 
	X aa  = a;
	return aa; 
}

//------------------------------------------------------------------------------------------

X& ref_to(X& a)
{ 
	return a; 
}

//------------------------------------------------------------------------------------------

X* make(int i) 
{ 
	X a(i); 
	return new X(a); 
}

//------------------------------------------------------------------------------------------

struct XX 
{
	X a;
	X b; 
};

//------------------------------------------------------------------------------------------

int main ()
{
	try 
	{
		std::cout <<"1\n";
		X loc(4);				 

		std::cout <<"2\n";
		X loc2 = loc;			// copy constructor called

		std::cout <<"3\n"; 
		loc = X(5);				// constructor, copy assignment and destructor called for anonymous object

		std::cout <<"4\n"; 
		loc2 = copy(loc);		// copy constructor and destructor called twice: 
								// (parameter by value, local variable to return value (by value)), and copy assignment   

		std::cout <<"5\n";		// copy consructor and destructor called three times and copy assignmet
		loc2 = copy2(loc);

		std::cout <<"6\n";
		X loc3(6);				// constructor called 

		std::cout <<"7\n";
		X& r = ref_to(loc);		// nothing called

		std::cout <<"8\n";
		delete make(7);			// constructor and copy consructor called, destructor called twice

		std::cout <<"9\n";
		delete make(8);			// constructor and copy consructor called, destructor called twice

		std::cout <<"10\n";
		std::vector<X> v(4);	// default constructor, copy constructor and destructor
								// called 4 times + another 4 times for the destructor at the end

		std::cout <<"11\n";
		XX loc4;				// default constructor and destructor called twice

		std::cout <<"12\n";
		X* p = new X(9);		// constructor called once
		delete p;				// destructor called

		std::cout <<"13\n";		// default constructor called 5 times
		X* pp = new X[5];
		//delete pp;			// aborted due to assertion failure: delete[]pp should be used instead of delete pp

		std::cout <<"end\n";	// destructors called 5 times + for the rest leaked resources
	} 
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	getchar();
}