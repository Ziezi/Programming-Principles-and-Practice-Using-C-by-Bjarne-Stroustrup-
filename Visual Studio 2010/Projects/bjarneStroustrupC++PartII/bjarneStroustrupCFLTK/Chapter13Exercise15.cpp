/*
	TITLE		   Right triangle Tile		     Chapter13Exercise15.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Tile a window with right triangles.
			Input: -
		   Output:  
		   Author: 20.09.2015
		     Date: Chris B. Kirov
*/
#include "GUI.h"
#include "Simple_window.h"
#include <iostream>

#define PI 3.14159

namespace Graph_lib
{

class RightTriangle: public Closed_polyline
{
public:
	RightTriangle(Point dl, Point dr, Point ul);
	RightTriangle(Point dl, int b, int h);

	int getArea() const { return base * height / 2; }

	Point getDownLeft() const { return downLeft; }
	Point getDownRight() const { return downRight; }
	Point getUpLeft() const { return upLeft; }
private:
	Point downLeft;
	Point downRight;
	Point upLeft;

	int base;
	int height;
};

RightTriangle::RightTriangle(Point dl, int b, int h)
	: downLeft(dl), base(b), height(h), downRight(dl.x + b, dl.y), upLeft(dl.x , dl.y -h)
{
	if(b < 0 || h < 0)
	{
		std::cerr <<"Negative lenght!";
	}

	Closed_polyline::add(dl);
	Closed_polyline::add(Point(dl.x + b, dl.y));
	Closed_polyline::add(Point(dl.x, dl.y - h));
}

RightTriangle::RightTriangle(Point dl, Point dr, Point ul)
	: downLeft(dl), downRight(dr), upLeft(ul)
{
	// check if points form a right triangle 
	//if(pow(double(dr.x - dl.x),2) + pow(double(ul.y - dl.y),2) !=  
	//sqrt(pow(double(ul.y - dr.y),2) + pow(double(ul.x - dr.x),2))) error("Not Pythagorean triplets!");
	Closed_polyline::add(dl);
	Closed_polyline::add(dr);
	Closed_polyline::add(ul);
}

Point rotatePoint(Point axisOfRotation, Point initial, double angle)
{
	double angRads = angle * PI / 180.;
	return Point(cos(angRads) * (initial.x - axisOfRotation.x) - sin(angRads) * (initial.y - axisOfRotation.y) + axisOfRotation.x,
		         sin(angRads) * (initial.x - axisOfRotation.x) + cos(angRads) * (initial.y - axisOfRotation.y) + axisOfRotation.y);
}
} // end of Graph_lib

//------------------------------------------------------------------------------------------------------------------------------------
int main()
{
	 // window parameters
	 int winWidth = 800;
	 int winHeight = 600;
	 Point centerPoint((x_max() - winWidth) / 2, (y_max() - winHeight) / 2);

	 Simple_window* siw = new Simple_window(centerPoint, winWidth, winHeight, "Chapter 13 Exercise 12");

	 try
	 {
		 // right triangle parameters
		 Point downLeft(0,100);
		 int base = 50;
		 int height = 100;

		 // window tile 
		  vector<Graph_lib::RightTriangle* > windowTile;

		 int columns = 20;
		 int rows = 6;

		 for (size_t i = 0; i < columns; ++i)
		 {
			for (size_t j = 0; j < rows; ++j)
			{
				// instantiate a rotated around the uppeLeft point triangle
				windowTile.push_back(new Graph_lib::RightTriangle(Point(downLeft.x + i * base, downLeft.y + j * height), base, height));

				windowTile[windowTile.size() - 1]->set_fill_color(rand() % 256 + 1);

				siw->attach(*windowTile[windowTile.size() - 1]);
			}
		 }

		 siw->wait_for_button();

		 // free heap memory
		 for (auto it= windowTile.begin(); it != windowTile.end(); ++it) delete *it;
	 }
	 catch(std::exception& e)
	 {
		std::cerr << e.what() << std::endl;
		getchar();
	 }
	 catch(...)
	 {
		std::cerr <<"Defaul exception!"<< std::endl;
	 }
}