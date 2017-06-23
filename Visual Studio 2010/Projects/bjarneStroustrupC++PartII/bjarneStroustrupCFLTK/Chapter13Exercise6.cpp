/*
	TITLE		   Draw a class diagram			  Chapter13Exercise6.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Draw a class diagram. 
		           Define a Box class that is
				   a rectangle with a Text label.
		   Output: 
		   Author: 17.09.2015
		     Date: Chris B. Kirov
*/
#include "GUI.h"
#include "Simple_window.h"
#include <iostream>
#include "Chapter13Exercise6.h"

static void initText(vector<string>& v)
{
	// line 1
	v.push_back("Line");
	v.push_back("Lines");
	v.push_back("Polygon");
	v.push_back("Axis");
	v.push_back("Rectangle");
	v.push_back("Text");
	v.push_back("Image");
	// line 2
	v.push_back("Simple_window");
	v.push_back("Shape");
	v.push_back("Point");
	// line 3
	v.push_back("Window");
	v.push_back("Line_style");
	v.push_back("Color");
}

static void initCoordinates(vector<Point>& c)
{
	// line1
	c.push_back(Point(5,500));
	c.push_back(Point(70,500));
	c.push_back(Point(150,500));
	c.push_back(Point(300,500));
	c.push_back(Point(400,500));
	c.push_back(Point(600,500)); 
	c.push_back(Point(700,500));
	// line 2
	c.push_back(Point(5,350));
	c.push_back(Point(400,300));
	c.push_back(Point(700,350));
	// line 3
	c.push_back(Point(40,100));
	c.push_back(Point(400,100));
	c.push_back(Point(700,100));
}

//--------------------------------------------------------------------------------------------------
int main()
{
	 // window parameters
	 int winWidth = 800;
	 int winHeight = 600;
	 Point centerPoint((x_max() - winWidth) / 2., (y_max() - winHeight) / 2.);
	 Simple_window* siw = new Simple_window(centerPoint, winWidth, winHeight, "Chapter 13 Exercise 6");

	 try
	 {
		 // Create labeled boxes
		 // vector holding the labels
		 vector<string> labels;
		 initText(labels);
		 // vectro holdig the coordinate of te boxes
		 vector<Point> boxCoordinates;
		 initCoordinates(boxCoordinates);
		 // boxes garbage collector 
		 vector<Graph_lib::LabeledRoundBox*> boxes;

		 for (size_t i = 0; i < labels.size(); ++i)
		 {
			Graph_lib::LabeledRoundBox* lb = new LabeledRoundBox(boxCoordinates[i], labels[i]);
			boxes.push_back(lb);
			siw->attach(*lb->add_text());
			siw->attach(*lb);
		 }
		 // Connect with arrows
		 // arrows garbage collector
		 vector<Graph_lib::Arrow*> arrows;
		 int firstRow=7;
		 int arrowSize = 10;
		 for (size_t i = 0; i < firstRow; ++i)
		 {
			 Graph_lib::Arrow* ar = new Arrow(Point(boxCoordinates[i].x + 25, boxCoordinates[i].y), 
				                              Point(boxCoordinates[8].x + 25 + i*4, boxCoordinates[8].y + 20), arrowSize);
			 arrows.push_back(ar);
			 siw->attach(*ar);
		 }
		 Graph_lib::Arrow* ar = new Arrow(Point(boxCoordinates[7].x + 70, boxCoordinates[7].y), 
			                              Point(boxCoordinates[10].x + 35, boxCoordinates[10].y + 20), arrowSize);
		 arrows.push_back(ar);
	     siw->attach(*ar);
		  
		 siw->wait_for_button();
		 // free memory
		 for (auto it = boxes.begin(); it != boxes.end(); ++it) delete *it;
		 for (auto it = arrows.begin(); it != arrows.end(); ++it) delete *it;
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


//--------------------------------------------------------------------------------------------------