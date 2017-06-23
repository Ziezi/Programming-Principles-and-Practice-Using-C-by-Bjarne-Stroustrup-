/*
	TITLE		   Star		                    Chapter13Exercise19.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Create class Star. 
		           One parameter should be number of point.
				   Draw stars with differently colored line
				   and different filling colors.
		   Output: 
		   Author: 24.09.2015
		     Date: Chris B. Kirov
*/

#ifndef _Chapter13Exercise19_H_
#define _Chapter13Exercise19_H_

#define PI 3.14159265359

namespace Graph_lib
{
// it should be checked why mulitple number of vertexes result if nonsencical results
class Star: public Lines
{
public:
	Star(Point c, int r, int n);

private:
	int vertexNumber;
	Point center;
	int radius;

	vector<Point>starCoordinates;

	void rotateCoordinate(Point& axisOfRotation, Point& initial, double angRads, int numberOfRotations);
	void generatePoly();
	void makeStar();
};

#include "Chapter13Exercise19Def.cpp"
} // end of namespace Graph_lib
#endif 