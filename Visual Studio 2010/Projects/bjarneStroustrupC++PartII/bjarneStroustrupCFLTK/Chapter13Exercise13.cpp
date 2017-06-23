/*
	TITLE		   RGB matrix		        Chapter13Exercise13.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Draw the color matrix from 13.10,
				   without the lines around each color
			Input: -
		   Output:  
		   Author: 20.09.2015
		     Date: Chris B. Kirov
*/
#include "GUI.h"
#include "Simple_window.h"
#include <iostream>

#define PI 3.14159

int main()
{
	 // window parameters
	 int winWidth = 800;
	 int winHeight = 600;
	 Point centerPoint((x_max() - winWidth) / 2, (y_max() - winHeight) / 2);

	 Simple_window* siw = new Simple_window(centerPoint, winWidth, winHeight, "Chapter 13 Exercise 12");

	 try
	 {
		 // garbage container
		 vector<Graph_lib::Rectangle*> RGBmatrix;

		 int colour = 0;

		 // generate color matrix
		 for(size_t i = 0; i < 16; ++i)
		 {
			for(size_t j = 0; j < 16; ++j)
			{
				RGBmatrix.push_back(new Graph_lib::Rectangle(Point(i * 20, j * 20), 20, 20));

				RGBmatrix[RGBmatrix.size()-1]->set_fill_color(colour++);
				RGBmatrix[RGBmatrix.size()-1]->set_color(Color::invisible);

				siw->attach(*RGBmatrix[RGBmatrix.size() - 1]);
			}
		 }

		 siw->wait_for_button();

		 // free heap memory
		 for(auto it = RGBmatrix.begin(); it != RGBmatrix.end(); ++it) delete *it;
	 }
	 catch(std::exception& e)
	 {
		std::cerr << e.what() << std::endl;
	 }
	 catch(...)
	 {
		std::cerr <<"Defaul exception!"<< endl;
	 }
}