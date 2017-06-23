/*
	TITLE		   Ellipse drawing		        Chapter13Exercise11.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Draw an ellipse 300 x 200
		           400 x-axis and 300 y-axis through the center of the
				   ellipse.
				   Mark the foci.
				   Mark a point on the ellipse, not on the axes and
				   connect it with the foci.
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

	 Simple_window* siw = new Simple_window(centerPoint, winWidth, winHeight, "Chapter 13 Exercise 11");

	 try
	 {
		 // ellipse parameters
		 int majorSemiAxis = 150;
		 int minorSemiAxis = 100;
		 int x = (siw->x_max()- majorSemiAxis) / 2;
		 int y = (siw->y_max() - minorSemiAxis) / 2;

		 Graph_lib::Ellipse el(Point(x,y), majorSemiAxis, minorSemiAxis);
		 siw->attach(el);

		 // axes
		 int xLenght = 400;
		 Graph_lib::Axis xAxis(Axis::x, Point(x - xLenght/2, y), xLenght, 10, "x axis");
		 siw->attach(xAxis);

		 int yLenght = 300;
		 Graph_lib::Axis yAxis(Axis::y, Point(x, y + yLenght/2), yLenght, 10, "y axis");
		 siw->attach(yAxis);

		 // foci
		 int linearEccentricity = sqrt(double((majorSemiAxis * majorSemiAxis) - (minorSemiAxis * minorSemiAxis)));
		 Graph_lib::Mark f1(Point(x - linearEccentricity/2,y),'1');
		 siw->attach(f1);

		 Graph_lib::Mark f2(Point(x + linearEccentricity/2,y),'2');
		 siw->attach(f2);

		 // point on the ellipse
		 double angle = 45 * PI / 180.;
		 int px = majorSemiAxis * cos(angle) + x;
		 int py = minorSemiAxis * sin(angle) + y;

		 Graph_lib::Mark p(Point(px, py), 'p');
		 siw->attach(p);

		 // lines from foci to point
		 Graph_lib::Open_polyline op;
		 op.add(Point(x - linearEccentricity/2,y));
		 op.add(Point(px, py));
		 op.add(Point(x + linearEccentricity/2,y));

		 siw->attach(op);

		 siw->wait_for_button();
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