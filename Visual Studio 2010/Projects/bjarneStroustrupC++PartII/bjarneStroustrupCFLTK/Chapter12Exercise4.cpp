/*
	TITLE			   Checkers Board	        Chapter12Exercise4.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Draw a checkers board 8-by-8
					   alternating white and red.
				Input: -
			   Output: Graph on screen.
			   Author: Chris B. Kirov
			     Date: 17. 08. 2015
*/
#include <iostream>
#include "Simple_window.h"
#include "Chapter12Exercise4.h"

int main()
{
	try
	{
		// instantiate via default constuctor
		checkersBoard defaultCheckersBoard;

		// checkers board parameters
		int numberOfColumns = 8;
		int numberOfRows = 8;
		int sideSize = 80;

		// instantiate an object
		checkersBoard cs(numberOfColumns, numberOfRows, sideSize, Color::black, Color::white);
		// draw a checkers board
		cs.drawBoard();
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
