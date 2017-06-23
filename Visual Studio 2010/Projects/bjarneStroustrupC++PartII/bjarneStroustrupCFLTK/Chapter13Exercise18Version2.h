/*
	TITLE		   Regular Polygon		        Chapter13Exercise18Veraion2.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Create a class RegularPolygon that
				   instantiates an objects using as
				   paremeters: the points of the
				   corners of the polygon.
				    
		   Output: 
		   Author: 20.09.2015
		     Date: Chris B. Kirov
*/
#ifndef _Chapter13Exercise18Verions2_H_
#define _Chapter13Exercise18Version2_H_

#define PI 3.14159265359

namespace Graph_lib
{
// class RegularPolygon	
class RegularPolygon: public Closed_polyline
{
public:
	RegularPolygon(Point c, int r, int n);
	RegularPolygon(vector<Point>& vertices);
	double getSide() { return  2 * radius * sin(PI * 6.); }
private:
	Point center;
	int radius;
	int sidesNumber;

	void generatePoly();
	void rotateCoordinate(Point& axisOfRotation, Point& initial, double angRads, int numberOfRotations);
};

// class Helper functions
double sideLength(vector<Point>& v);
double angle(vector<Point>& v);
Point polygonCenter(vector<Point>& v);
bool validityCheck (vector<Point>& v);

// Non-member functions 
void rotateCoordinate(vector<Point>& v, Point& axisOfRotation, Point& initial, double angRads, int numberOfRotations);
void generateRegularPolygon(vector<Point>& v, Point& center, int sidesNumber, int radius);

//----------------------------------------------------------------------------------------------------------------------
// class Vector2D
// includes basic vector arithmetic to reduce excessive amount repetitive simple calculations in the above functions
class Vector2D
{
public:
	explicit Vector2D(const int& x = 0, const int& y = 0)
		: x(x), y(y)
	{
	
	}

	Vector2D(const Vector2D& src)
		: x(src.x), y(src.y) 
	{
	
	}

	virtual ~Vector2D()
	{

	}

	// accessors
	inline int X() const { return x; }
	inline int Y() const { return y; }
	inline int X (const int& x) { this->x = x; }
	inline int Y (const int& y) { this->y = y; }

	// vector arithmetic
	inline Vector2D operator-() const { return Vector2D(-x,-y); }
	inline Vector2D operator+(Vector2D& v) const { return Vector2D(x + v.x, y + v.y); }
	inline Vector2D operator-(Vector2D& v) const { return Vector2D(x - v.x, y - v.y); }

	// scalling
	inline Vector2D operator*(const int& s) const { return Vector2D(x * s, y * s); }
	// dot product
	inline double operator*(const Vector2D& v) const { return x * v.x + y * v.y; }
	// l-2 norm
	inline double norm() const { return sqrt(double(x * x + y * y)); }
	// inner angle
	static double angle(const Vector2D& v1, const Vector2D& v2) { return acos((double) (v1 * v2) / (v1.norm() * v2.norm()) ); }

private:
	int x;
	int y;
};

#include "Chapter13Exercise18Version2Def.cpp"
} // end of namespace Graph_lib

#endif 