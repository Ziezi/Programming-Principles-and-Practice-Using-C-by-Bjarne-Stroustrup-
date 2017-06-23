/*
	TITLE		    Try This 2		           Chapter17TryThis2.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Analyze the behavior of class constructors and destructors.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 26.11.2015
*/
#include <iostream>
#include <string>

class A 
{
public:

	A () 
		: aint(1), astring("a"), aptr(new double[10]) 
	{ 
		std::cout << "A constructor called!\n"; 
	}

	~A()
	{ 
		delete[] aptr;
		std::cout << "A destructor called!\n";
	}

private:

	int aint;
	std::string astring;
	double* aptr;
}; 
//--------------------------------------------------------------

class B: public A 
{

public:
	B ()
		: bchar(new char[10])
	{ 
		std::cout << "B constuctor called!\n";
		for (size_t i = 0; i < 10; ++i) bchar[i] = 'a';
	}

	~B ()
	{ 
		delete[] bchar; 
		std::cout <<"B destructor called!\n"; 
	}

private:
	char *bchar;
};

//--------------------------------------------------------------

int main () 
{
	try 
	{
		std::cout <<"class A:\n";
		A a;

		std::cout <<"class B:\n";
		B b;
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	getchar();
}
