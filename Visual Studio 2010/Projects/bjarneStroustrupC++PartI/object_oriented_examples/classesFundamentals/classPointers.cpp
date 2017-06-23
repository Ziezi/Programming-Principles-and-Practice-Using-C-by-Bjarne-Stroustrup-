/* TITLE			   Class pointers		   classPointers.cpp
   COMMENT
			Objective: Introduce class pointers and expressions.
				Input: -
			   Output: Prints area of a class.	
			   Author: Chris B. Kirov
                 Date: 1.10.2015
*/			   
#include "stdafx.h"
using namespace std;

// class definition
class Rectangle{
	int width, height;
public:
	Rectangle(int x, int y): width(x), height(y) { }
	int area() { return (width*height); }
};

// execution
int main(){
	Rectangle rect1(4,5);
	Rectangle * pointer1, * pointer2, *pointer3;
	pointer3 = NULL;
	// object pointer initialization
	pointer1 = &rect1;
	pointer2 = new Rectangle(5,6);
//	pointer3 = new Rectangle[2] { {2,3},{3,4} };

	cout << "*point1 area: " << pointer1->area() << endl;
	cout << "*point2 area: "<< pointer2->area() << endl;
	return 0;
}