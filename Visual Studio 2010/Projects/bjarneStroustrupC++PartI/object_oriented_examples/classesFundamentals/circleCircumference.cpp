/* 
   TITILE	           Circumference of a circle		circleCircumference.cpp
   COMMENT
			Objective: Find circumference of a circle.
			           Introduction to ways of object initialization:
					   assignment, function, uniform.
				Input: -
			   Output: Prints the circumference of a circle.
			   Author: Chris B. Kirov
			     Date: 1.10.2015					
*/
#include "StdAfx.h"
using namespace std;

// constant definition
#define PI 3.14159265

// class definition
class Circle{
	double radius;
public:
	Circle();
	Circle(double r){ radius = r;}
	double circum() {return 2*radius*PI;}
};

// default constructor definition
Circle::Circle(){
	radius = 1;
}

// execution
int main(){
	Circle c1 = 5.0;		// assignment initialization; Only with single parameter constructors
	Circle c2(10.0);		// function initialization
/*
	Circle c3 {15.0};		// uniform initializatation
	Circle c4 = {20.0};		// uniform for constructor with one argument
*/
	cout << "Circumference of c1: "<< c1.circum() << endl;
	cout << "Circumference of c2: "<< c2.circum() << endl;
	system("pause");
	return 0;
}

// Result
// Circumference of c1: 31.4159
// Circumference of c2:	62.8319