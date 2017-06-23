/*
	TITLE		   Class inheritane/overrloading      Chapter14Drill.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: 1. Define class B1 with virtual function vf() and
				      non-virtual f(), within B, with access specifier
				      public and implement them to print their name.
				      Make object B1 and call each fucntion.
				   2. Derive a class D1 from B1 and override vf().
				      Make object D1 and call vf( ) and f() for it .
				   3. Define a reference to B1 (B1&) and initialize 
				      it to the above D1 object. Call f(), vf() for that reference.
		    Input: -
		   Output: Prints the invoked function and members.
		   Author: 26.09.2015
		     Date: Chris B. Kirov
*/
#include <iostream>
#include <string>

// 1. 
class B1
{
public:
	virtual void vf() const { std::cout <<"B1::vf()"; }
	void f() const { std::cout <<"B1::f()"; }

	// 5.
	virtual void pvf() const { std::cout <<"B1::pvf()"; }
};

// 2.
class D1: public B1
{
public:
	void vf() const { std::cout <<"D1::vf()"; }
	void pvf() const { std::cout <<"D1::pvf()"; }

	// 4.
	void f() { std::cout <<"D1::f()"; }
};


// 6.
class D2: public D1
{
public:
	void pvf() const { std::cout <<"D2::pvf()"; }
};

//--------------------------------------------------------------------------------------
// 7.
class B2
{
public:
	virtual void pvf() const = 0;
};

class D21: public B2
{
public:
	D21() : d21s("default") { } 

	void pvf() const { std::cout << d21s; }
private:

	std::string d21s;
};

class D22: public B2
{
public:
	D22() : d22s(100) { } 
	
	void pvf() const { std::cout << d22s; }
private:

	int d22s;
};

void f(B2& b)
{
	b.pvf();
}

//--------------------------------------------------------------------------------------
int main()
{
	// 1.
	std::cout <<"1.\n";
	B1 b1;
	b1.vf();  // virtual function is called normally
	b1.f();
	std::cout <<'\n'; 

	// 2.
	std::cout <<"2.\n";
	D1 d1;
	d1.vf(); // late binding; dynamic dispatch; run-time polymorhism
	d1.f();   
	std::cout <<'\n'; 

	// 3.
	std::cout <<"3.\n";
	B1& bref = d1;
	bref.vf();  // interface inheritance
	bref.f();
	std::cout <<'\n'; 

	// 4.
	std::cout <<"4.\n";
	D1 dd1;
	dd1.vf(); // late binding; dynamic dispatch; run-time polymorhism
	dd1.f();  // not overriden
	std::cout <<'\n';  

	bref.vf();  // interface inheritance
	bref.f();   // not overriden
	std::cout <<'\n';

	// 5.
	std::cout <<"5.\n";
	b1.vf();
	b1.f();
	b1.pvf();

    std::cout <<'\n'; 
	d1.vf();
	d1.f();
	d1.pvf();

	std::cout <<'\n'; 
	bref.vf();
	bref.f();
	bref.pvf();
	std::cout <<'\n'; 

	// 6.
	std::cout <<"6.\n";
	D2 d2;
	d2.f();    // last override in D1  
	d2.vf();   // last override in D1 
	d2.pvf();  // overriden 
	std::cout <<'\n'; 

	// 7.
	// all data members need to be initialized first; default constructors defined
	std::cout <<"7.\n";
	D21 d21;
	D22 d22;

	f(d21); // interface inheritance (call f with d21) & run-time polymorhism (print d21 data member)

	std::cout <<'\n'; 
	f(d22); // interface inheritance & run-time polymorhism

	getchar();
}