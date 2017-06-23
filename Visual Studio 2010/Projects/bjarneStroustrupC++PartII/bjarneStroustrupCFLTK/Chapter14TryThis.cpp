/*
	TITLE		   Class inheritane/overriding      Chapter14TryThis.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define three classes and 
		           overload virtual function
				   of a base class in a derived
				   class and analyse its behavior
				   when invoked. 
		    Input: -
		   Output: -
		   Author: 26.09.2015
		     Date: Chris B. Kirov
*/
#include <iostream>

// base class including virtual function
struct B
{
	virtual void f() const { std::cout <<"B::f";}
	void g() const { std::cout <<"B::g";}
};

// derived class overriding the virtual function f() of B
struct D: B
{
	void f() const { std::cout <<"D::f"; }
	void g() { std::cout <<"D::g"; }         
};

// derived class 
struct DD: D
{
	void f() { std::cout <<"DD::f"; }         
	void g() const { std::cout << "DD::g"; }  
};

void call(const B&  b)
{
	b.f();
	b.g();
};

//--------------------------------------------------------
int main(){
 
	B b;
	D d;
	DD dd;

	std::cout <<"Function invokations:\n";
	call(b); // 
	std::cout << '\n';

	call(d); // 
	std::cout << '\n';

	call(dd); // 
	std::cout << '\n';
	 
	std::cout <<"Member invokations:\n";
	b.f();   
	b.g();  
	std::cout << '\n';

	d.f();   
	d.g();   
	std::cout << '\n';

	dd.f();   
	dd.g();  
	std::cout << '\n';
}