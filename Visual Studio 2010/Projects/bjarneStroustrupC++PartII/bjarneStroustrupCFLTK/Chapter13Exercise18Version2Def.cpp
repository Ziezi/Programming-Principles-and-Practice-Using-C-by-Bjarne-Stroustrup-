/*
	TITLE		   Regular Polygon		        Chapter13Exercise18Version2Def.cpp
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
 
// Class Members implementation
// consructors
RegularPolygon::RegularPolygon(std::vector<Point>& vertices)
	: sidesNumber(vertices.size()), center(polygonCenter(vertices)), radius(sideLength(vertices))
{
	if(!validityCheck(vertices))
	{
		std::cerr <<"Not coordinates of a regular polygon!";
	}
	for(auto it = vertices.begin(); it != vertices.end(); ++it)		Closed_polyline::add(*it);
}

RegularPolygon::RegularPolygon(Point c, int r, int n)
	: center(c), radius(r), sidesNumber(n) 
{ 
	generatePoly();
}

// class member function
void RegularPolygon::generatePoly()
{ 
	 double angRads = (PI / 180.) * (360. / sidesNumber);

	 // first point of the Hexagon in above the center at distance: radius
	 Point initial(center.x, center.y - radius);

	 // initialize the first point of the hexagon
	 // Closed_polyline::add(initial);
	 rotateCoordinate(center, initial, angRads, sidesNumber);
}

void RegularPolygon::rotateCoordinate(Point& axisOfRotation, Point& initial, double angRads, int numberOfRotations)
{
	// base case: when all rotations performed return vector holding the rotated points
	if (numberOfRotations <= 0)
	{
		return;
	}
	else
	{
		// apply transformation on the initial point
		double x = cos(angRads) * (initial.x - axisOfRotation.x) - sin(angRads) * (initial.y - axisOfRotation.y) + axisOfRotation.x;
		double y = sin(angRads) * (initial.x - axisOfRotation.x) + cos(angRads) * (initial.y - axisOfRotation.y) + axisOfRotation.y;

		// save the rest of the five points of the hexagon
		Closed_polyline::add(Point(x, y));

		// call the same function this time on the rotated point and decremented number of rotations
		rotateCoordinate(axisOfRotation, Point(x,y), angRads, --numberOfRotations);
	}
}

//-----------------------------------------------------------------------------------------------------------------------------------
// Class Helper functions
double sideLength(std::vector<Point>& v)
{
	double epsilon = 10;
	int refX = v[0].x - v[v.size()-1].x;
	int refY = v[0].y - v[v.size()-1].y;

	Vector2D vref(refX,refY);
	double sumSide = vref.norm();

	for(size_t i = 1; i < v.size(); ++i)
	{
		int X = v[i-1].x - v[i].x;
	    int Y = v[i-1].y - v[i].y;

		Vector2D vec(X,Y);
		sumSide += vec.norm();

		// test if each pair of verteces forms line with same lenght
		if(vec.norm() < vref.norm() - epsilon || vec.norm() > vref.norm() + epsilon) 
		{
			throw std::invalid_argument("Different side length!");
		}
	}	

	// average lenght
	return ceil(sumSide / v.size());
}

double angle(std::vector<Point>& v)
{
	double epsilon = 0.1;
	double angle = 2 * PI  / v.size();
	double sumAngle = 0;

	for (size_t i = 0; i < v.size() - 3; ++i)
	{
		Vector2D v1(v[i+1].x - v[i].x, v[i+1].y - v[i].y);
		Vector2D v2(v[i+2].x - v[i+1].x, v[i+2].y - v[i+1].y);

		double pairAngle = Vector2D::angle(v1,v2);
		sumAngle +=pairAngle;

		// test if each pair line formed by a pair of vertices are at
		// relative angle of the respective polygon inner angle
		if (pairAngle < angle - epsilon || pairAngle > angle + epsilon)
		{
			throw std::invalid_argument("Different relative angle!");
		}
	}
	return 2 * sumAngle / v.size();
};
 
Point polygonCenter(std::vector<Point>& v)
{
	double sumX = 0;
	double sumY = 0;

	for(size_t i = 0; i < v.size(); ++i)
	{
		sumX +=v[i].x;
		sumY +=v[i].y;
	}

	int x = ceil(sumX / v.size());
	int y = ceil(sumY / v.size());

	return Point(x,y);
}

bool validityCheck (std::vector<Point>& v)
{
	double epsilon = 20;
	Point cent = polygonCenter(v);

	Vector2D refVec(cent.x - v[0].x, cent.y - v[0].y);
	cout <<"reVec: "<< refVec.norm() << '\n';

	for(size_t i = 1; i < v.size(); ++i)
	{
		Vector2D vec(cent.x - v[i].x, cent.y - v[i].y);
		cout <<"vec: "<< vec.norm() << '\n';

		if(vec.norm() < refVec.norm() - epsilon || vec.norm() > refVec.norm() + epsilon) 
		{
			return false;
		}
	}
	return true;
}

//-----------------------------------------------------------------------------------------------------------------------------------
// Non-member functions 
void rotateCoordinate(std::vector<Point>& v, Point& axisOfRotation, Point& initial, double angRads, int numberOfRotations)
{
	if(numberOfRotations <= 0)
	{
		return;
	}
	else
	{
		double x = cos(angRads) * (initial.x - axisOfRotation.x) - sin(angRads) * (initial.y - axisOfRotation.y) + axisOfRotation.x;
		double y = sin(angRads) * (initial.x - axisOfRotation.x) + cos(angRads) * (initial.y - axisOfRotation.y) + axisOfRotation.y;

		v.push_back(Point(x, y));

		rotateCoordinate(v, axisOfRotation, Point(x,y), angRads, --numberOfRotations);
	}
}

void generateRegularPolygon(std::vector<Point>& v, Point& center, int sidesNumber, int radius)
{
	 // converted to radians
	 double angRads = 2 * PI / double(sidesNumber);

	 Point initial(center.x, center.y - radius);

	 rotateCoordinate(v, center, initial, angRads, sidesNumber);
}

 