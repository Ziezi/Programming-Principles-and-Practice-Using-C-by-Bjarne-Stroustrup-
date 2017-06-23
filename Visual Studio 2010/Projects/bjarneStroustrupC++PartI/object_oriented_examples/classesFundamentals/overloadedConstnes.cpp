/* 
   TITLE	Constant and non-constant member functions		overloadedConstnes.cpp
   COMMENT
 			Objective: Call the overloaded function from const and non-const objects.
 				Input: -
 			   Output: It calls a function according the callee.
			   Author: Chris B. Kirov
			     Date: 10.10.2014
*/		   
#include "stdafx.h"
using namespace std;

// class definition
class MyClass {
	int x;
public:
	MyClass(int val): x(val) { }
	int& get() { return x; }
	const int& get() const { return x; }
};

int main() {
	MyClass foo(5);
	const MyClass binky(10);

	foo.get() = 15;
	// binky.get() = 20; // Error const member are immutable 

	// it calls the member function at line#: 14 
	cout << foo.get() << '\n';
	// it calls the constant type member function at line#: 15
	cout << binky.get() << '\n';

	return 0;
}