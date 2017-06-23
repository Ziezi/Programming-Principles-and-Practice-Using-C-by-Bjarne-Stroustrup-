/* 
   TITLE	           Class Constructor initialization		classConstructorInheritance.cpp
   COMMENT
			Objective: Initialize a constructor of a base class, calling it 
			           from within the derived class constructor member initialization list.
				Input: -
		       Output: It prints the statement of the invoked constructor.
			   Author: Chris B. Kirov
			     Date: 1.10.2015
*/
#include "stdafx.h"
using namespace std;

// definition of the base class
class Mother{
public:
	Mother() {cout << "Mother: default constructor. ";}
	Mother(int a) { cout << "Mother: parameter constructor."; }
};

class Daughter: public Mother{
public: 
	Daughter(int a) {cout<<"Daughter: parameter constructor.";}		// nothing specified: call default constructor
};

class Son: public Mother{
public:
	Son(int a): Mother(a) {cout<< "Son: parameter constructor.";}// constructor specified: call this specific constructor (line:15)
};

int main(){

	Daughter Jully(0);		 
	Son Chris(0);

	return 0;
}