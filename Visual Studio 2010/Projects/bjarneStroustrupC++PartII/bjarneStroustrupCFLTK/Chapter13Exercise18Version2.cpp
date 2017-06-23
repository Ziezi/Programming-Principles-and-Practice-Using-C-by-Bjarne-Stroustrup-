/*
	TITLE		   Regular Polygon		        Chapter13Exercise18Version2.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Create a class RegularPolygon that
				   instantiates an objects using as
				   paremeters: the points of the
				   corners of the polygon.
				    
		   Output: Task done! constuctor provided vith adequate validity check 
		           Side Note: radius, sideLenght and relative angle of the edges
				              calculations deviate for particular polygons.
		   Author: 20.09.2015
		     Date: Chris B. Kirov
*/
#include "GUI.h"
#include "Simple_window.h"
#include <iostream>
#include "Chapter13Exercise18Version2.h"

int main()
{
	 // window parameters
	 int winWidth = 800;
	 int winHeight = 600;
	 Point centerPoint((x_max() - winWidth) / 2, (y_max() - winHeight) / 2);

	 Simple_window* siw = new Simple_window(centerPoint, winWidth, winHeight, "Chapter 13 Exercise 10");

	 try
	 {
		 Point center(siw->x_max()/2., siw->y_max()/2.);
		 int sidesNumber = 10;
		 int radius = 200;

		 // generate coordinates using the original member function used for that purpose
		 vector<Point> polygonCoord;
		 generateRegularPolygon(polygonCoord, center, sidesNumber, radius);

		 // instantiate a polygon using valid points
		 RegularPolygon p(polygonCoord);
		 siw->attach(p);

		 siw->wait_for_button();
	 }
	 catch(std::exception& e)
	 {
		std::cerr << e.what() << std::endl;
	 }
	 catch(const std::invalid_argument& e)
	 { 
		 std::cerr << e.what() << std::endl;
	 }catch(...)
	 {
		std::cerr <<"Defaul exception!"<< std::endl;
	 }
}