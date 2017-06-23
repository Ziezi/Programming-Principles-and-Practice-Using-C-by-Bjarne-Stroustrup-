/*
	TITLE		   Star		                 Chapter13Exercise19Def.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Create class Star. 
		           One parameter should be number of point.
				   Draw stars with differently colored Lines
				   and different filling colors.
		   Output: 
		   Author: 24.09.2015
		     Date: Chris B. Kirov
*/
 
// Class Members implementation
Star::Star(Point c, int r, int n)
	: vertexNumber(n), center(c), radius(r)
{ 
	if(n < 5) 
	{
		throw std::invalid_argument("Not enough vertices!");
	}

	generatePoly(); 
	makeStar();
}
 
void Star::rotateCoordinate(Point& axisOfRotation, Point& initial, double angRads, int numberOfRotations)
{
	if(numberOfRotations <= 0) 
	{
		return;
	}
	else
	{
		double x = cos(angRads) * (initial.x - axisOfRotation.x)
			     - sin(angRads) * (initial.y - axisOfRotation.y) + axisOfRotation.x;
		double y = sin(angRads) * (initial.x - axisOfRotation.x) 
			     + cos(angRads) * (initial.y - axisOfRotation.y) + axisOfRotation.y;

		starCoordinates.push_back(Point(x, y));
		rotateCoordinate(axisOfRotation, Point(x,y), angRads, --numberOfRotations);
	}
}

void Star::generatePoly()
{ 
	 double angRads = (PI / 180.) * (360. / vertexNumber);

	 Point initial(center.x, center.y - radius);
	 rotateCoordinate(center, initial, angRads, vertexNumber);
}

void Star::makeStar()
{
	// every if statement covers Star with n and multiples of n vertexes
	// the inner for loops execute one iteration for the fundamental stars
	// and n iterations for the multiples (rotational symmetry)
	if (vertexNumber % 5 == 0)
	{
		size_t polygons = starCoordinates.size() / 5;

		for (size_t it = 0; it < starCoordinates.size() / 5; ++it)
		{
			Lines::add(starCoordinates[it + 3 * polygons], starCoordinates[it]);
			Lines::add(starCoordinates[it], starCoordinates[it + 2 * polygons]);
			Lines::add(starCoordinates[it + 2 * polygons], starCoordinates[it + 4 * polygons]);
			Lines::add(starCoordinates[it + 4 * polygons], starCoordinates[it + 1 * polygons]);
			Lines::add(starCoordinates[it + 1 * polygons], starCoordinates[it + 3 * polygons]);
		}
		
	}
	else if (vertexNumber % 6 == 0)
	{
		size_t polygons = starCoordinates.size() / 6;
		for (size_t it = 0; it < starCoordinates.size() / 3; ++it)
		{
			Lines::add(starCoordinates[it], starCoordinates[it + 2 * polygons]);
			Lines::add(starCoordinates[it + 2 * polygons], starCoordinates[it + 4 * polygons]);
			Lines::add(starCoordinates[it + 4 * polygons], starCoordinates[it]);
		}
	}
	else if (vertexNumber % 7 == 0)
	{
		size_t polygons = starCoordinates.size() / 7;
		for (size_t it = 0; it < starCoordinates.size() / 7; ++it)
		{
			Lines::add(starCoordinates[it], starCoordinates[it + 3 * polygons]);
			Lines::add(starCoordinates[it + 3 * polygons], starCoordinates[it + 6 * polygons]);
			Lines::add(starCoordinates[it + 6 * polygons], starCoordinates[it + 2 * polygons]);
			Lines::add(starCoordinates[it + 2 * polygons], starCoordinates[it + 5 *polygons]);
			Lines::add(starCoordinates[it + 5 * polygons], starCoordinates[it + 1 * polygons]);
			Lines::add(starCoordinates[it + 1 * polygons], starCoordinates[it + 4]);
			Lines::add(starCoordinates[it + 4 * polygons], starCoordinates[it]);
		}
	}
	else if (vertexNumber % 8 == 0)
	{
		size_t polygons = starCoordinates.size() / 8;
		for (size_t it = 0; it < starCoordinates.size() / 8; ++it)
		{
			Lines::add(starCoordinates[it], starCoordinates[it + 5 * polygons]);
			Lines::add(starCoordinates[it + 5 * polygons], starCoordinates[it + 2 * polygons]);
			Lines::add(starCoordinates[it + 2 * polygons], starCoordinates[it + 7 * polygons]);
			Lines::add(starCoordinates[it + 7 * polygons], starCoordinates[it + 4 * polygons]);
			Lines::add(starCoordinates[it + 4 * polygons], starCoordinates[it + 1 * polygons]);
			Lines::add(starCoordinates[it + 1 * polygons], starCoordinates[it + 6 * polygons]);
			Lines::add(starCoordinates[it + 6 * polygons], starCoordinates[it + 3 * polygons]);
			Lines::add(starCoordinates[it + 3 * polygons], starCoordinates[it]);
		}
	}
	else
	{
		throw std::invalid_argument("Star vertices number not supported!");
	}
}





 

 