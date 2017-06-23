/*
	TITLE		   Regular Polygon		        Chapter13Exercise18.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Create a class RegularPolygon that
				   instantiates an objects using as
				   paremeters: the points of the
				   corners of the polygon.
		    Input: -   
		   Output: The algorithm to find the center is valid. 
		           The non-member function implementation needs revision.
		   Author: 20.09.2015
		     Date: Chris B. Kirov
*/

#include "GUI.h"
#include "Simple_window.h"
#include <iostream>
#include "Chapter13Exercise18.h"

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
		 int sidesNumber = 6;
		 int radius = 200;

		 // generate coordinates using the original member function used for that purpose
		 std::vector<Point> polygonCoord;
		 Graph_lib::generateHex(polygonCoord, center, sidesNumber, radius);

		 // instantiate a polygon using valid points
		 RegularPolygon p(polygonCoord);
		 siw->attach(p);

		 // check the reference points generated py the validity function
		 // it calculates the center from each pair of vertex coordinates
		 // and compares them to see if the match(within error range)
		 std::vector<Marks* >m;
		 for (size_t i = 1; i < polygonCoord.size(); ++i)
		 {
			 Point c = Graph_lib::polygonCenter(polygonCoord[i - 1], polygonCoord[i], sidesNumber);

			 // depict the calculated centers
			 m.push_back(new Mark(c,'0'+ i));

			 siw->attach(*m[m.size() - 1]);
		 }
		
		 siw->wait_for_button();

		 // free heap memory
		 for(auto it = m.begin(); it != m.end(); ++it) delete *it;
	 }
	 catch(std::exception& e)
	 {
		std::cerr << e.what() << std::endl;
	 }
	 catch(...)
	 {
		std::cerr <<"Defaul exception!"<< std::endl;
	 }
}