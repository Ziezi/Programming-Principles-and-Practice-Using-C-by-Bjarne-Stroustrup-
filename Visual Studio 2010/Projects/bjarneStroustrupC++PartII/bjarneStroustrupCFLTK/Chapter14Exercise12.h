 /*
	TITLE		   Group container                Chapter14Exercise12.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define Binary_Tree class derived from Shape.
		           Modify the draw function to be virtual and
				   derive a new class that overrides it and
				   lets each node be triangle.
		    Input: - 
		   Output: !!! Done by deriving Binary_tree_triangle from Shape !!!
		   Author: 17.10.2015
		     Date: Chris B. Kirov
*/

#ifndef _Chapter14Exercise12_h
#define _Chapter14Exercise12_h

// class used to represent a triangle node
class RegularPolygon: public Closed_polyline
{
public:
	RegularPolygon(Point c, int r, int n);

	double getSide() { return  2 * radius * sin(PI * 1 / 6.); }
	Point get_center() const { return center; }

private:
	Point center;
	int radius;
	int sidesNumber;

	void generatePoly();
	void rotateCoordinate(Point& axisOfRotation, Point& initial, double angRads, int numberOfRotations);
};

RegularPolygon::RegularPolygon(Point c, int r, int n)
	: center(c), radius(r), sidesNumber(n) 
{ 
	generatePoly(); 
}

void RegularPolygon::generatePoly()
{
	 double angRads = PI / 180. * (360. / double(sidesNumber));

	 // first point of the Hexagon in above the center at distance: radius
	 Point initial(center.x, center.y - radius);

	 // initialize the first point of the hexagon
	 rotateCoordinate(center, initial, angRads, sidesNumber);
}

void RegularPolygon::rotateCoordinate(Point& axisOfRotation, Point& initial, double angRads, int numberOfRotations)
{
	// base case: when all rotations performed return vector holding the rotated points
	if(numberOfRotations <= 0)
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

//-----------------------------------------------------------------------------------------------------------------------------------------
// class Binary_tree graphically represents a binary tree
class Binary_tree: public Shape
{
public:	 
	Binary_tree(Point c, int l)
		: root(c), levels(l) 
	{
			if(l < 0) 
			{
				throw std::invalid_argument("Tree levels must be >= 0 !");
			}

			generate_coordinates();
			create_connections();
	}

	virtual void draw_lines() const;

protected:
	int levels; // depth of binary tree
	Point root; // root coordinates

	std::vector<Shape*> connections; // lines

private:
	void generate_coordinates();
	void create_connections();
};

// Class Binary_tree member methods
void Binary_tree::draw_lines() const
{
		if (color().visibility())
		{
			// draw node connections
			for (size_t i = 0; i < connections.size(); ++i)
			{
				connections[i]->draw();
			}

			// draw nodes
			for (int i = 0; i < number_of_points(); ++i)
			{
				const int radius = 10; // nodes are circles
				fl_arc(point(i).x - radius, point(i).y - radius, 2 * radius, 2 * radius, 0, 360);
			}
		}
}

// Class Binary_tree helper methods
void Binary_tree::generate_coordinates()
{
	// level sanity check
	if (levels < 0)
	{
		std::cerr <<"Binary_tree::levels must be >= 0!";
	}

	// empty tree
	if (levels == 0)
	{
		return;
	}

	// add the root
	add(root);

	// define distance between nodes
	int scaleX = 15;
	int scaleY = 50;

	// generate nodes' coordinates
	for (int i = 2; i <= levels; ++i)
	{
		int nodesPerLevel = pow(2.0, i - 1);
		for (int j = 0; j < nodesPerLevel; ++j)
		{
			float horizontalAdjust = ((pow(2.0, i - 1) - 1) / 2 - j) * pow(2.0, levels - 1) * scaleX;
			int nodeX = root.x - horizontalAdjust;

			float verticalAdjust = (i - 1) * scaleY;
			int nodeY = root.y + verticalAdjust;

			add(Point(nodeX, nodeY));
		}
	}
}

void Binary_tree::create_connections()
{
	// if a parent node has an index: i
	for (int i = 0; i < number_of_points() / 2; ++i)
	{
		// every left child node has index 2i + 1
		connections.emplace_back(new Line(point(i), point(2 * i + 1)));

		// every right child node has index 2i + 2
		connections.emplace_back(new Line(point(i), point(2 * i + 2)));
	}
}


//-----------------------------------------------------------------------------------------
class Binary_tree_triangle: public Binary_tree
{
public:
	Binary_tree_triangle(Point c, int l)
		: Binary_tree(c, l)
	{ 

	}

	void draw_lines() const;
};

void Binary_tree_triangle::draw_lines() const
{
	 if (color().visibility())
		{
			// draw node connections
			for (size_t i = 0; i < connections.size(); ++i)
			{
				connections[i]->draw();
			}

			// draw nodes
			for (int i = 0; i < number_of_points(); ++i)
			{
				const int side = 10; // nodes are equilateral triangles
				fl_polygon(point(i).x, point(i).y,
						   point(i).x - side / 2, point(i).y + side, 
						   point(i).x + side / 2, point(i).y + side);
			}
		}
}

#endif