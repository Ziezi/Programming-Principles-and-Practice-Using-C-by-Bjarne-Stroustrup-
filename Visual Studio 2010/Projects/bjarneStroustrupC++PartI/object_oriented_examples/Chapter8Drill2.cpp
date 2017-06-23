/* 
	TITLE			   Swap functions               Chapter8Drill2.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Parameter passing and paramater type. 
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Data: 01.03.2015
*/
#include <iostream>

void swap_v(int, int);
void swap_r(int&, int&);
void swap_cr(const int&, const int&);

//==========================================================================

int main()
{
	// x and y should be the same
	int x = 7;
	int y = 9;
	swap_v(x,y);
	std::cout << "x= " << x << " y= " << y << std::endl;

	// x and y swapped
	swap_r(x,y);
	std::cout << "x= " << x << " y= " << y << std::endl;

	swap_v(7,9);
	// no possibility of printing literals in parameter list
	// Error : initial value of reference to non-const must be lvalue (non-literal, defined variable)
	// inability to initialize an argument passed-by-reference with literal (entity non existing in memory, only in opcode)
	// swap_r(7,9);
	 
	const int cx = 7;
	const int cy = 9;
	swap_v(cx,cy);
	// // x and y should be the same ; compilation error possible
	std::cout << "cx= " << cx << " cy= " << cy << std::endl;
	// qualifiers dropped in binding reference of type"int&" to initialize to type "const int&"
	// no possibility of conversion of the input variables to match the input arguments
	// swap_r(cx,cy);

	swap_v(7.7,9.9);
	// possibly truncated to integers 
	// Error: initial value of reference to non-const must be lvalue
	// inability to initialize an argument passed-by-refernce with literal (entity non existing in memory, only in opcode)
	// swap_r(9.9,7.7);

	double dx = 7;
	double dy = 9;
	swap_v(dx,dy);
	std::cout << "dx= " << cx << " dy= " << cy << std::endl;
	// reference of type "int&" can not be initialized with variable of type double
	// swap_r(dx,dy);
	 
	getchar();
}

//==========================================================================

// passed-by-value parameters
void swap_v(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

// passed-by-reference parameters
void swap_r(int& a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}

// passed-by-const-reference parameters
void swap_cr(const int& a, const int& b)
{
	int temp = a;
	//a = b;
	//b = temp;
}
