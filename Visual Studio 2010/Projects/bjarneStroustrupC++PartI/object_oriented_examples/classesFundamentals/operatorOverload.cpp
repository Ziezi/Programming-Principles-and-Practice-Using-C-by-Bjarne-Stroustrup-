/*
   TITLE	           Operator Overloading in classes		     operatorOverload.cpp
   COMMENT
 			Objective: Add two (algebraic)vectors using classes and operator overload.
 				Input: -
 			   Output: Prints the resultant vector.
			   Author: Chris B. Kirov
			     Date: 10.10.2014
*/
#include "StdAfx.h"
using namespace std;

// class definition
class CVector {
public:
	int x, y;
	CVector() {}
	CVector(int a, int b): x(a),y(b) { }
};

// definition of the overloaded operator '+'
CVector operator+ (const CVector& lhs, const CVector& rhs){
	CVector temp;
	temp.x = lhs.x + rhs.x;
	temp.y = lhs.y + rhs.y;
	return temp;
} 

// definition of overloaded operator '='; returns objects by reference, using 'this'
CVector& CVector::operator= (const CVector& param){
	x = param.x;
	y = param.y;
	return *this;
}

// execution
int main(){
	CVector vect1(1,5);
	CVector vect2(3,5);
	CVector result;

	result = vect1 + vect2;
	cout <<'('<< result.x << ',' << result.y << ')'<< endl;
	return 0;
}

// Result
// It prints: (4,10)

