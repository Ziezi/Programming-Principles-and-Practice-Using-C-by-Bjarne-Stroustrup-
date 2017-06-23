/*
	TITLE		   Dysfunctional inteface	Chapter25TryThis2.cpp
	COMMENT
		Objective: Before reading further, try to see how many 
				   errors you can find in f() in §25.4.3. Specifically, which 
				   of the calls of poor() could cause the program 
				   to crash?   
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 09.05.2017
*/
#include <iostream>
#include <vector>
#include "Graph.h"

using namespace Graph_lib;

void poor(Shape* p, int sz)
{
	for (int i = 0; i < sz; ++i)
	{
		p[i].draw();
	}
}

//---------------------------------------------------------------------------

void f(Shape* q, std::vector<Circle>& s0)
{
	Graph_lib::Polygon s1[10];
	Graph_lib::Shape s2[10]; // no default constructor

	// initialize
	Shape* p1 = new Graph_lib::Rectangle(Point(0, 0), Point(10, 20));

	poor(&s0[0], s0.size()); // Circle - Shape memory layout mismatch
	poor(s1, 10);
	poor(s2, 20);		// index out of range
	poor(p1, 1);
	
	delete p1;

	p1 = 0;

	poor(p1, 1);		// dereferencing deleted / nullptr
	poor(q, max);		// max undefined
}

//---------------------------------------------------------------------------

int main()
{
	try
	{
		Shape* q = new Graph_lib::Rectangle(Point(0, 0), Point(10, 20));
		std::vector<Circle> s0;

		f(q, s0);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}