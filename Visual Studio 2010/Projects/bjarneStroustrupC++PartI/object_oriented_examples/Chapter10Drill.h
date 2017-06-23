/*
	TITLE			   Implement Class Point         	  Chapter10Drill.h
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: 1. Write a class Point representing a point in 2D plane.
					      Data members: coordinate x, coordinate y
					   2. Input 7 points.
				Input: - 
			   Output: - 
			   Author: Chris B. Kirov
			     Date: 03.04.2015
*/
 
// 1. Write a class Point representing a point in 2D plane.
namespace MyPoint
{
/*
	Class Point
	Data structure representing
	a point in the 2D plane.
*/ 
class Point
{
public:
	// default contructors
	Point() 
		: x(0), y(0)
	{
	
	}

	// constructor
	Point(double xx, double yy)	
		: x(xx), y(yy)
	{
	
	}

	// non-modifying methods
	inline double get_x() const { return x; }
	inline double get_y() const { return y; }

	// modifying methods
	inline double set_x(double xx) { x = xx; }
	inline double set_y(double yy) { y = yy; }

private:
	double x;
	double y;
};
//============================================================================
// Overloaded operators
/*
	operator:>>
	 
	Input format: (x,y)
*/

std::istream& operator>> (std::istream& is, Point& p)
{
	char par1, comma, par2;
	double x,y;
	is >> par1 >> x >> comma >> y >> par2;

	// check stream state
	if(!is)
	{
		return is;
	}

	// check input format validity
	if (par1 != '(' || comma != ',' || par2 != ')')
	{
		is.clear(std::ios_base::failbit);
		return is;
	}
	 	 
	p = Point(x,y);

	return is;
}
//----------------------------------------------------------------------------

/*
	operator<<
	 
	Output format: (x,y)
*/
std::ostream& operator<< (std::ostream& os, Point& p)
{
	return os << '(' << p.get_x() 
		      << ',' << p.get_y()
			  << ')';
}

/*
	operator==
	 
*/
bool operator== (const Point& p1, const Point& p2)
{
	return p1.get_x() == p2.get_x() && 
		   p1.get_y() == p2.get_y();
} 

/*
	operator!=
	 
*/
bool operator!= (const Point& p1, const Point& p2)
{
	return !(p1.get_x() == p2.get_x() && 
		     p1.get_y() == p2.get_y());
} 

} // end of namespace MyPoint