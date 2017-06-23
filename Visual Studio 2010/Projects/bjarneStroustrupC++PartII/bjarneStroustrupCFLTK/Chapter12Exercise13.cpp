/*
	TITLE			   Colored Starlike patterns 	Chapter12Exercise13.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Draw starline patterns by connecting
					   points on a superellipse.
					   Add color.
			    Input: -
			   Output: Graph on screen.
			   Author: Chris B. Kirov
			     Date: 17. 08. 2015
*/
#define PI 3.14159265359

//------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include "Simple_window.h"
#include "Chapter12Exercise13.h"

//------------------------------------------------------------------------------------------------------------------------------
int main()
{
	// Superellipse parameters

	// exponents
	double n = 2/3.;
	double m = 2/3.;

	// coefficient 
	double A = 200.0;
	double B = 200.0;

	// center point of the graph
	const int centX = x_max() / 2.;
	const int centY = y_max() / 2.;

	// incrementation step
	double di = 0.01;

	try
	{
		SuperEllipse se(A, B, n, m, centX, centY, di);

		se.drawSuperEllipse();

		se.drawStar();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(...)
	{
		std::cerr <<"Default exception!"<< std::endl;
	}
}
 
 