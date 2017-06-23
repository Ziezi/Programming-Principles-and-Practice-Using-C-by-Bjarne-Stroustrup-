/*
   TITLE	       Properties of constant objects		constantMemberObjects.cpp
   COMMENT
 		Objective: Initialize a constant class object 
		           and show that its members are immutable.
				   (Read-only property).
			Input: -
		   Output: It prints value of constant object 
		   Author: Chris B. Kirov
		     Date: 1.10.2015
*/

#include "stdafx.h"
using namespace std;

// class definition
class MyClass {
public:
	int x;
	MyClass(int val): x(val) { }
	int get() { return x; }
};

int main() {
	// only the constructor can modify (initialize) const type
	const MyClass foo(10);

	// Error: modification of const type
	//foo.x = 20;
	// Error: the member function: get(), should be itself const, to be called
	//int y = foo.get();
	//cout <<  y << endl;

	cout << foo.x << endl;
	return 0;
}