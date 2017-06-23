/* 
  TITLE	            Area of rectangle	       rectangleClassbeta.cpp
  COMMENT
 			Object: Set parameters and find the area of an rectangle.
                    (Introdcution to classes)
 			 Input: -
 			Output: It prints the area of an rectangle.
			Author: Chris B. Kirov
			  Date: 10.10.2014
*/					
#include "StdAfx.h"
using namespace std;

// class definition
class Rectangle{
		int width, height;
	public:
		Rectangle();
		Rectangle(int,int);
		int area(void) {return (width*height);}
};

// class constructor definitions
// default constructor
Rectangle::Rectangle(){
	width = 5;
	height = 5;
}

// constructor
Rectangle::Rectangle(int a, int b){
	width = a;
	height = b;
}

// execution
int main(){
	// consrtuctor call
	Rectangle recta(3,4);

	// default constructor call; No parameters and NO parenthesses
	Rectangle rectb;

	cout << "recta: " << recta.area() << endl;
	cout << "rectb: " << rectb.area() << endl;
	return 0;
}

// Result:
// recta: 12
// rectb: 25


