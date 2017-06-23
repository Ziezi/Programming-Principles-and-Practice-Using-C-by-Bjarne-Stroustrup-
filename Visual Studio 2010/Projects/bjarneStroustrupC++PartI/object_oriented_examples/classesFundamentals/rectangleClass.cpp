/* 
   TITLE	           Area of rectangle	rectangleClass.cpp
   COMMENT
 			Objective: Set parameters of an rectangle and find its area.
					   (Introduction to classes)
 				Input: -
 			   Output: It prints the area of an rectangle.
			   Author: Chris B. Kirov
			     Date: 10.10.2014
*/					
#include "StdAfx.h"
using namespace std;

// class definition
// member declaration and definition
class Rectangle{
		int width, height;
	public:
		void set_values(int,int);
		int area(void){return (width*height);};
};

// definition of class member function
void Rectangle::set_values(int x, int y){
	width = x;
	height = y;
}

// execution using the class object: rect
int main(){

	Rectangle rect;
	rect.set_values(6,6);
	cout << "Area: " << rect.area()<< endl;
	return 0;
}
