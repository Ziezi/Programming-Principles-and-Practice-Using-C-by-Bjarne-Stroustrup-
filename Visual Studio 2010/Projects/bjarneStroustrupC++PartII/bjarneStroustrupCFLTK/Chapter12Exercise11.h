/*
	TITLE			   Confocal Polygons  	   Chapter12Exercise11.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Draw regular confocal polygons.
					   The innermost should be an equalateral triangle,
					   enclosed by a square,
					   encodef by a pentagon.
			    Input: -
			   Output: Graph on screen.
			   Author: Chris B. Kirov
			     Date: 17. 08. 2015
*/

/*
	Class regularPolygon

	It creates an object representing
	a regular polygon drawn on the screen.
*/
class regularPolygon
{
public:
	// constructor
	regularPolygon(Point centerOfPolygon, int numbOfSides, int size);

    // destructor  
	~regularPolygon();

	// member function returning a polygon object drawn using the vector: coordinates 
	Graph_lib::Polygon* drawPolygon();

private:
	// data members
	Point axisOfRotation;
	Point initial;
	int numberOfRotations;
	int sizeOfSides;
	float angRads;

	void rotateCoordinate(vector<Point>& rotated, Point& axisOfRotation, Point initial, 
	                      float angRads, int numberOfRotations);

	// wrapper function (if it's declared as static the definition gets underlined in red)
	void generateCoordinatesForPolygon();

	// container holding the generated coordinates
	vector<Point> coordinates;

	// container holding the generated polygons used to free the dynamically alocated memory
	// common to all instantiated objects
	vector<Graph_lib::Polygon *> generatedPolygons;
};
//-----------------------------------------------------------------------------------------------------------------------
// Class regularPolygon member implementations

// constructor
regularPolygon::regularPolygon(Point centerOfPolygon, int numbOfSides, int size)
	: axisOfRotation(centerOfPolygon), numberOfRotations(numbOfSides), sizeOfSides(size)
{ 
	generateCoordinatesForPolygon(); 
}

//-----------------------------------------------------------------------------------------------------------------------
// destructor  
regularPolygon::~regularPolygon()
{ 
	for(auto it = generatedPolygons.begin(); it != generatedPolygons.end(); it++) 
	{
		delete *it; 
	}
}
//-----------------------------------------------------------------------------------------------------------------------

/*
	Member Function: rotateCoordinate()
	 
	It performs the same rotation on
	a consequtively generated points, through recursion.
	These points are saved in a vector, passed
	by reference.
*/
void regularPolygon::rotateCoordinate (vector<Point>& rotated, 
								       Point& axisOfRotation, Point initial, 
									   float angRads, int numberOfRotations)
{
	// base case: when all rotations performed return vector holding the rotated points
	if(numberOfRotations <= 0)
	{
		return;
	}
	else
	{
		// apply transformation on the initial point
		int x = cos(angRads) * (initial.x - axisOfRotation.x) - sin(angRads) * (initial.y - axisOfRotation.y) + axisOfRotation.x;
		int y = sin(angRads) * (initial.x - axisOfRotation.x) + cos(angRads) * (initial.y - axisOfRotation.y) + axisOfRotation.y;

		// save the result
		// the vector could be replaced with Closed_polyline::add(Point(x,y))
		rotated.push_back(Point(x, y));

		// call the same function this time on the rotated point and decremented number of rotations
		rotateCoordinate(rotated, axisOfRotation, Point(x,y), angRads, numberOfRotations -1);
	}
}
//-----------------------------------------------------------------------------------------------------------------------

/*
	Member Function: generatePolygon()
	 
	It generates coordinates for the polygon.
*/
void regularPolygon::generateCoordinatesForPolygon()
{
		if(axisOfRotation.x < 0 || axisOfRotation.y < 0)
		{
			std::cerr <<"Pivot point coordinates out of lower bound!\n";
		}
		if(numberOfRotations < 3)
		{
			std::cerr <<"Not enough polygon sides!\n";;
		}
		if(sizeOfSides < 0) 
		{
			std::cerr <<"Negative side lenght!\n";
		}

	    coordinates.reserve(numberOfRotations);

		// calculate the angles of rotations
		angRads = PI / 180. * (360. / numberOfRotations);

		// corrections to the initial point by subtracting the bysector (in function of the side) 
		// so that the polygone is centered around the center of rotations !!! to be done 
		initial.x = axisOfRotation.x - sizeOfSides;
		initial.y = axisOfRotation.y - sizeOfSides;	

		// generate the coordinates of the polygon 
		rotateCoordinate(coordinates, axisOfRotation, initial, angRads, numberOfRotations);
}
//-----------------------------------------------------------------------------------------------------------------------

/*
	Member Function: makePolygon();
	 
	It creates (returns) a pointer to a polygon
	object created from the generated coordinates.

	The returned result needs to be attached to 
	a window.
*/
Graph_lib::Polygon* regularPolygon::drawPolygon()
{
	Graph_lib::Polygon* poly = new Graph_lib::Polygon;

	for(size_t i = 0; i < coordinates.size(); ++i)
	{
		poly->add(coordinates[i]);
	}

	// collected in the container to be deleted at the end
	generatedPolygons.push_back(poly);

	return poly;
}


//=======================================================================================================================
/*
	Class: ConfocalRegularPolygons

	It draws a number of confocal
	regular polygons with specifiable
	side length, where the innermost 
	is an equilateral triangle.
*/
class ConfocalRegularPolygons
{
public:
	ConfocalRegularPolygons(int n, int sideLength);

	~ConfocalRegularPolygons();

private:
	size_t numberOfConfocalGeometricalObjects;
	const int sideLength;

	// create all confocal regaular polygons and store in vector
	std::vector<regularPolygon*> confocalGeometricalObjects;
};

//-----------------------------------------------------------------------------------------------------------------------
// Class ConfocalRegularPolygons member implementations

// constuctor
ConfocalRegularPolygons::ConfocalRegularPolygons(int n, int l)
	: numberOfConfocalGeometricalObjects(n), sideLength(l)
{
	const int swWidth = 800;
	const int swHeight = 800;
	Simple_window sw(Point((x_max()- swWidth) / 2. , (y_max() - swHeight) / 2.), 
			            swWidth, swHeight, "Chapter 12 Exercise 11");

	// center (pivot) point 
	Point center(sw.x_max() / 2., sw.y_max() / 2.);

	for (size_t i = 0; i < numberOfConfocalGeometricalObjects; ++i)
	{
		// make each n+1 polygon's side larger than its inscribed
		confocalGeometricalObjects.emplace_back(new regularPolygon(center, 3 + i, sideLength * (i + 1)));
		sw.attach(*confocalGeometricalObjects[i]->drawPolygon());
	}

	sw.wait_for_button();
}

//-----------------------------------------------------------------------------------------------------------------------
// destructor
ConfocalRegularPolygons::~ConfocalRegularPolygons()
{
	// free dynamic memory
	for (size_t i = 0; i < confocalGeometricalObjects.size(); ++i)
	{
		delete confocalGeometricalObjects[i];
	}
}