/*
	TITLE		   Star					         Chapter13Exercise19.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Create class Star. 
		           One parameter should be number of point.
				   Draw stars with differently colored line
				   and different filling colors.
		   Output: // No filling color implemented.
		   Author: 24.09.2015
		     Date: Chris B. Kirov
*/

#include "GUI.h"
#include "Simple_window.h"
#include <iostream>
#include "Chapter13Exercise19.h"

int main()
{
	 int winWidth = 800;
	 int winHeight = 600;
	 Point centerPoint((x_max() - winWidth) / 2, (y_max() - winHeight) / 2);

	 Simple_window* siw = new Simple_window(centerPoint, winWidth, winHeight, "Chapter 13 Exercise 19");

	 try
	 {

		 Point c(siw->x_max()/2, siw->y_max()/2);
		 int radius = 150;

		 // Currenly: sides > 5, sides =! 13, 17, 19 and multiples
		 int sides = 13;

		 Graph_lib::Star st(c, radius, sides);

		 st.set_color(Color::blue);

		 siw->attach(st);

		 siw->wait_for_button();
	 }
	 catch(std::exception& e)
	 {
		std::cerr << e.what() << std::endl;
	 }
	 catch(const std::invalid_argument& e)
	 { 
		 std::cerr << e.what() << std::endl;
	 }
	 catch(...)
	 {
		std::cerr <<"Defaul exception!"<< std::endl;
	 }
}