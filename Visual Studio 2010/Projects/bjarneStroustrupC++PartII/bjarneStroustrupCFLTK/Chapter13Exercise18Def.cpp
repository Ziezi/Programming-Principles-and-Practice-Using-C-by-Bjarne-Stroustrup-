/*
	TITLE		   Regular Polygon		        Chapter13Exercise18def.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Create a class RegularPolygon that
				   instantiates an objects using as
				   paremeters: the points of the
				   corners of the polygon.
				    
		   Output: NOT WORKING !!!
		   Author: 20.09.2015
		     Date: Chris B. Kirov
*/
 
// Class Members implementation
// consructors
RegularPolygon::RegularPolygon(vector<Point>& vertices)
	: sidesNumber(vertices.size())
{
	if(!validityCheck(vertices))
	{
		std::cerr <<"Not coordinates of a regular polygon!";
	}

	for(auto it = vertices.begin(); it != vertices.end(); ++it) 
	{
		Closed_polyline::add(*it);
	}
}

RegularPolygon::RegularPolygon(Point c, int r, int n)
	: center(c), radius(r), sidesNumber(n) 
{ 
	generateHex();
}

// class member function
void RegularPolygon::generateHex()
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
int sideLength(Point& p0, Point& p1)
{
	int x = abs(p1.x - p0.x);
	int y = abs(p1.y - p0.y);

	return sqrt(double(x * x + y * y));
}

int apothemLength(int side, int sideNumber)
{
	return side / 2. * atan(PI/double(sideNumber));
}

Point scaledUnitVector(Point& p0, Point& p1, int norm, int scale)
{
	// unit vector along p0p1 scaled by the apothem
	int x = abs(p1.x - p0.x);
	int y = abs(p1.y - p0.y);

	return Point(x * scale /double(norm), y * scale /double(norm));
}

Point rotate(Point& axisOfRotation, Point& initial, int sideNumber)
{
	// the apothem is a bisector, so the angle of rotations is half the angle of the polygon
	double angRads = (360. / 2* sideNumber) * (PI / 180.);

	int x = cos(angRads) * (initial.x - axisOfRotation.x) - sin(angRads) * (initial.y - axisOfRotation.y) + axisOfRotation.x;
	int y = sin(angRads) * (initial.x - axisOfRotation.x) + cos(angRads) * (initial.y - axisOfRotation.y) + axisOfRotation.y;

	return Point(x, y);
}

Point polygonCenter(Point& p0, Point& p1, int sideNumber)
{
	int side = sideLength(p0, p1);
	int apoth = apothemLength(side, sideNumber);

	Point initial = scaledUnitVector(p0, p1, side, apoth);
	Point vertex = rotate(p0, initial, sideNumber);

	return vertex;
}

bool validityCheck(vector<Point>& v)
{
	int roundingError = 5;
	int sideNumber = v.size();
	Point refCenter = polygonCenter(v[v.size() - 1], v[0], sideNumber);

	for(size_t i = 1; i < sideNumber; ++i) 
	{
		Point current = polygonCenter(v[i-1],v[i], sideNumber);
		if((current .x  < refCenter.x - roundingError || 
			current .x  > refCenter.x + roundingError) &&
		   (current .y  < refCenter.y - roundingError || 
			current .y  > refCenter.y + roundingError))  /*return false*/;
	}
	return true;
}

//-----------------------------------------------------------------------------------------------------------------------------------
// Non-member functions 
void rotateCoordinate(vector<Point>& v, Point& axisOfRotation, Point& initial, double angRads, int numberOfRotations)
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

void generateRegularPolygon(vector<Point>& v, Point& center, int sidesNumber, int radius)
{
	 // converted to radians
	 double angRads = 2 * PI / double(sidesNumber);

	 Point initial(center.x, center.y - radius);

	 rotateCoordinate(v, center, initial, angRads, sidesNumber);
}

 