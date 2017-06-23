/*
	TITLE			   Confocal Polygons  	   Chapter12Exercise11.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Draw regular confocal polygons.
					   The innermost should be an equalateral triangle,
					   enclosed by a square, enclosed by a pentagon, etc.

					   Touching sides not implemented.
			    Input: -
			   Output: Graph on screen.
			   Author: Chris B. Kirov
			     Date: 17. 08. 2015
*/
#define PI 3.14159265359
//-----------------------------------------------------------------------------------------------------------------------

#include <cmath>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
#include "Simple_window.h"
#include "Chapter12Exercise11.h"

//-----------------------------------------------------------------------------------------------------------------------

int main()
{
	try
	{
		int confocalPolygons = 10;
		int sideLength = 20;
		ConfocalRegularPolygons crp(confocalPolygons, sideLength);
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
