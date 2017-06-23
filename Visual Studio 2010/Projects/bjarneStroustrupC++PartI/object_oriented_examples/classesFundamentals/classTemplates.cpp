/*
   TITLE	           Class templates			classTemplates.cpp
   COMMENT
			Objective: Define a class, 
			           class members using template type parameters.
				Input: -
			   Output: Prints the greater of the two initialized values.
			   Author: Chris B. Kirov
			     Date: 1.15.2015
*/

#include "stdafx.h"
using namespace std;

// template declaration
template <class T>
// class definition
class mypair {
	T a, b;
public:
	mypair(T val1, T val2) {a = val1; b = val2; }
	// member function of returning type T
	T getmax ();
};

// definition of the member function: getmax
template <class T>
T mypair<T>::getmax(){
	T retval;
	retval = a > b? a : b;
	return retval;
}

int main(){
	// the object has member data of type int
	mypair<int> myobject (100,50);
	cout << myobject.getmax() << endl;
	return 0;
}

