/*
	TITLE		   Regular Polygon		        Chapter13Exercise18.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Create a class RegularPolygon that
				   instantiates an objects using as
				   paremeters: the points of the
				   corners of the polygon.
				    
		   Output: // NOT WORKING !!!! 
		   Author: 20.09.2015
		     Date: Chris B. Kirov
*/

#ifndef _Chapter13Exercise18_H_
#define _Chapter13Exercise18_H_

#define PI 3.14159265359

namespace Graph_lib
{
// class RegularPolygon	
class RegularPolygon: public Closed_polyline
{
public:
	RegularPolygon(Point c, int r, int n);
	RegularPolygon(vector<Point>& vertices);
	double getSide() { return  2 * radius * sin(PI * 1 / 6.); }

private:
	Point center;
	int radius;
	int sidesNumber;

	void generateHex();
	void rotateCoordinate(Point& axisOfRotation, Point& initial, double angRads, int numberOfRotations);
};

// class Helper functions
int sideLength(Point& p0, Point& p1);
int apothemLength(int side, int sideNumber);
Point scaledUnitVector(Point& p0, Point& p1, int norm, int scale);
Point rotate(Point& axisOfRotation, Point& initial, int sideNumber);
Point polygonCenter(Point& p0, Point& p1, int sideNumber);
bool validityCheck (vector<Point>& v);

// Non-member functions 
void rotateCoordinate(vector<Point>& v, Point& axisOfRotation, Point& initial, double angRads, int numberOfRotations);
void generateHex(vector<Point>& v, Point& center, int sidesNumber, int radius);

#include "Chapter13Exercise18Def.cpp"
} // end of namespace Graph_lib

#endif 