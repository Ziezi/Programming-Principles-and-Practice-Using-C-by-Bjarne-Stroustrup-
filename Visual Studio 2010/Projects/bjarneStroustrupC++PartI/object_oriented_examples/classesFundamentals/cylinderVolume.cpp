/*
   TITLE	           Find cylinder volume		cylinderVolume.cpp
   COMMENT
 			Objective: Uses classes to find volume of a cylinder.
			           (Introduction to member initialization methods)
 				Input: -
 			   Output: It prints the volume of a cylinder
 			   Author: Chris B. Kirov
				 Date: 1.10.2015
*/
#include "stdafx.h"
using namespace std;

// defining used constants
#define PI 3.14159265

// class definition
class Circle{
	double radius;
public:
	Circle(double r): radius(r) { }
	double area() { return (radius*radius*PI); }
};

class Cylinder{
	double height;
	Circle base;
public:
	Cylinder(double r, double h): base(r), height(h) { }
	double volume() { return(base.area()*height); }
};

// execution
int main(){
	Cylinder c1(5,10);
	cout << "Volume of Cylinder with R=5, H=10: "<< c1.volume() << endl;
	return 0;
}

// Result
// Volume of Cylinder with R=5, H=10: 785.398



