/* 
   TITLE			   Number of instantiated objects		staticMembers.cpp
   COMMENT
 			Objective: Implement object counter using static members.
 				Input: -
 			   Output: Print the number of instantiated objects.
			   Author: Chris B. Kirov
			     Date: 01.10.2014
*/
#include "stdafx.h"
using namespace std;

// class definition
class Dummy {
public: 
	static int n;
	Dummy() { n++;}
	~Dummy() { n--;}
};

// static member initialization must be done outside the class
int Dummy::n = 0;

// execution
int main() { 
	Dummy a;
	Dummy b[5];
	Dummy * c = new Dummy;

	cout << "Number of objects: " << a.n << endl;
	delete c;
	cout << "Number of objects: " << Dummy::n << endl;

	return 0;
}

// Result:
// Number of objects: 7
// Number of objects: 6 