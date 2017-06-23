/*
	TITLE			   Starlike patterns 	   Chapter12Exercise12.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Draw starline patterns by connecting
					   points on a superellipse.
			    Input: -
			   Output: Graph on screen.
			   Author: Chris B. Kirov
			     Date: 17. 08. 2015
*/

/*
	Class: SuperEllipse

	It generates a superellipse using the parameters of the constructor. 
	The two member functions draw the generated points.
*/
class SuperEllipse
{
public:
	SuperEllipse(double CoeffA, double CoeffB, double expN, double expM, int centX, int centY, double precision);
	 
	~SuperEllipse();

	// member functions
	void drawStar();
    void drawSuperEllipse();

private: 
	// data members
	// generated coordinates
	std::vector<Point> coordinates;

	// coordinates connected with lines to form superellipse
	std::vector<Graph_lib::Line*> generatedLines;
};

//------------------------------------------------------------------------------------------------------------------------------
// Helper functions

/*
	Function: sgn()
	 
	Returns either -1, 0 or 1 if the input
	value is < 0 , == 0 or > =, respectivelly.
*/
template <typename T> 
int sgn(T val)
{
    return (T(0) < val) - (val < T(0));
}
//------------------------------------------------------------------------------------------------------------------------------

/*
	Function: generateSuperEllipse()
	Use: vector<Point> generateSuperEllipse(double coeffA, double coeffB, double expN, double expM, 
										    int centX, int centY, double precision)

	It generates a set of superellipse coordinates based on the following parametric equations:

	x(theta) = coeffA * pow(abs(cos(theta)), 2 / n) * sgn(cos(theta)) + centX;
	y(theta) = coeffB * pow(abs(sin(theta)), 2 / m) * sgn(sin(theta)) + centY;

	and returns a vector containing them.
*/
std::vector<Point> generateSuperEllipse(double coeffA, double coeffB, double expN, double expM, int centX, int centY, double precision = 0.01)
{
	if(precision < 0.01 || precision > 1)
	{
		std::cerr <<"Precision out of range!\n";
	}

	vector<Point> superEllipseCoordinates;
	Point temp, sEllipseCoordinate;

	for(double d = -1; d < 1; d += precision)
	{
		double theta = d * PI; 
		int x = coeffA * pow(abs((double)cos(theta)), (double)2.0 / expM) * sgn(cos(theta));
		int y = coeffB * pow(abs((double)sin(theta)), (double)2.0 / expN) * sgn(sin(theta));
		sEllipseCoordinate = Point(x + centX/2. , y + centY);
		// check for duplicate points
		if(sEllipseCoordinate != temp)
		{
			superEllipseCoordinates.push_back(sEllipseCoordinate);
		}
		temp = sEllipseCoordinate;	
	}

	return superEllipseCoordinates;
}

//------------------------------------------------------------------------------------------------------------------------------
// Class Superellipse members implementation

// constructor
SuperEllipse::SuperEllipse(double CoeffA, double CoeffB, double expN, double expM, int centX, int centY, double precision)
{
	// generate ellipse points
	coordinates = generateSuperEllipse(CoeffA, CoeffB, expN, expM, centX, centY, precision);
}

//------------------------------------------------------------------------------------------------------------------------------

// desctuctor
SuperEllipse::~SuperEllipse()
{
	for(auto it = generatedLines.begin(); it != generatedLines.end(); ++it) 
	{
		delete *it;
	}
}
//------------------------------------------------------------------------------------------------------------------------------

/*
	Member Function: drawStar()
	Use: SuperEllipse sEobject.drawStar();

	It generates a Simple_window object and draws a 
	star-like pattern by connecting a single one of 
	the, already generated superellipse points to 
	the equally spaced remaining point.

	Finally it attaches the drawing	to the window object.
*/
void SuperEllipse::drawStar()
{
	const int swWidth = 800;
	const int swHeight = 800;

	Simple_window sw(Point((x_max()- swWidth) / 2. , (y_max() - swHeight) / 2.), 
			         swWidth, swHeight, "Chapter 12 Exercise 12");

	// If the initial value of the i counter is not divided by a number (100) it connects 
	// a lot of points and results in filling the superellipse 
	for(size_t i = coordinates.size() / 100; i < coordinates.size(); ++i)
	{
			for(size_t j = i + 1; j < coordinates.size(); ++j)
			{
				generatedLines.push_back(new Line(Point(coordinates[0]),Point(coordinates[j])));
				sw.attach(*generatedLines[generatedLines.size() - 1]);
			}
	}

	sw.wait_for_button();
}

//------------------------------------------------------------------------------------------------------------------------------
/*
	Member Function: drawSuperEllipse();
	Use: SuperEllipse sEobject.drawSuperEllipse();

	Generates a Simple_window object and draws an 
	open polyline of the coordinates passsed as parameter 
	(in the case superellipse). 
	
	Finally it attaches the drawing to the window object.
*/
void SuperEllipse::drawSuperEllipse()
{
	const int swWidth = 800;
	const int swHeight = 800;

	Simple_window sw(Point((x_max()- swWidth) / 2. , (y_max() - swHeight) / 2.), 
			         swWidth, swHeight, "Chapter 12 Exercise 12");

	Graph_lib::Open_polyline superEllipse;
	for(size_t i = 0; i < coordinates.size(); ++i)
	{
		superEllipse.add(coordinates[i]); 
	}

	sw.attach(superEllipse);

	sw.wait_for_button();
}