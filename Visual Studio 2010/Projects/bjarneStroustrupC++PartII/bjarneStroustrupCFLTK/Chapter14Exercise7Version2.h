/*
	TITLE		  Stripped_Closed_Polyline	        Chapter14Exercise7.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a class where the closed polyline is
		           "filled" by drawing varying-pixel-wide-spaced
				   horizontal lines across the inside 
				   area. (Consider line width and spacing.)
		    Input: - 
		   Output: -
		   Author: 13.10.2015
		     Date: Chris B. Kirov
*/
// Helper functions

// compare function for sorting by the x-coordinates of a Point
struct XLessThan
{
	inline bool operator() (Point& p1, Point& p2) { return (p1.x < p2.x); }
};  

// compare function for sorting by the y-coordinates of a Point
struct YLessThan
{
	inline bool operator() (Point& p1, Point& p2) { return (p1.y < p2.y); }
};  

//-------------------------------------------------------------------------------------------------------
// class Edge: representing lines segments of the poly-line
struct Edge
{
	// constructor
	Edge(Point p0, Point p1) 
		: start(p0), end(p1)
	{ 
		if (p0.x == p1.x && p0.y == p1.y) 
		{
			throw std::invalid_argument("Edge: Identical points!");
		}

		if (p0.y > p1.y) 
		{
			std::swap(start, end);
		}

		yMin = start.y;
		yMax = end.y;
	} 

	// overloaded operator used for sort comparison
	bool operator< (const Edge& e) { return (yMax < e.yMax); }

	// data members 
	Point start;
	Point end;
    
	int yMin;
	int yMax;
};

// does two lines (p1,p2) and (p3,p4) intersect?
// if se return the distance of the intersect point as distances from p1
inline pair<double, double> line_intersect (Point p1, Point p2, Point p3, Point p4, bool& parallel)
{
    double x1 = p1.x;
    double x2 = p2.x;
    double x3 = p3.x;
    double x4 = p4.x;
    double y1 = p1.y;
    double y2 = p2.y;
    double y3 = p3.y;
    double y4 = p4.y;

    double denom = ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

    if (denom == 0)
	{
        parallel= true;
        return pair<double,double>(0, 0);
    }

    parallel = false;
    return pair<double,double>( ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denom,
                                ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom);
}

// intersection between two line segments
// returns true if the two segments intersect,
// in which case intersection is set to the point of intersection
bool line_segment_intersect (Point p1, Point p2, Point p3, Point p4, Point& intersection)
{
   bool parallel;
   pair<double,double> u = line_intersect(p1, p2, p3 ,p4, parallel);

   if (parallel || u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1)
   {
	   return false;
   }

   intersection.x = p1.x + u.first * (p2.x - p1.x);
   intersection.y = p1.y + u.first * (p2.y - p1.y);

   return true;
}

// overloaded for edge
bool edge_intersect(Edge e1, Edge e2, Point& intersection)
{
	return line_segment_intersect(e1.start, e1.end, e2.start, e2.end, intersection);
}

// ------------------------------------------------------------------------------------------------------------------
// Class Striped_closed_polyline
class Striped_closed_polyline: public Closed_polyline
{
public:
	// constructors
	Striped_closed_polyline()
		: spacing(10) 
	{
	
	}

	Striped_closed_polyline(int s)
		: spacing(s)
	{ 
		if(s <= 0) 
		{
			throw std::invalid_argument("Spacing must be positive!"); 
		}
	}

	// member functions
	void set_spacing(int s) { spacing = s; }
	void draw_lines() const;	

private:

	int spacing;
};

// class member function
void Striped_closed_polyline::draw_lines() const
{
	Closed_polyline::draw_lines();

	// create edges using the points stored in the base class 
	vector<Edge> polyEdges;

	Point first = point(0);
	Point last = point(number_of_points() - 1);

	polyEdges.push_back(Edge(last, first));

	for (size_t i = 1; i < number_of_points(); ++i)
	{
		polyEdges.push_back(Edge(point(i - 1), point(i)));
	}

	// sort by increasing yMax (ordinate of the end point)
	std::sort(polyEdges.begin(), polyEdges.end());

	// find Xmin and Xmax of the poly-line (end coordinates of the horizontal scan-line)
	int polyXmin =  1000;
	int polyXmax =  -1;

	for (size_t i = 0; i < number_of_points(); ++i)
	{
		if(point(i).x < polyXmin)
		{
			polyXmin = point(i).x; 
		}

		if(point(i).x > polyXmax) 
		{
			polyXmax = point(i).x; 
		}
	}

	// find intersection points between the horizontal line and the poly-line
	// int spacing = 10;
	vector<Point> intersections;

	for (size_t i = 0; i < polyEdges.size(); ++i)
	{
		for (size_t j = polyEdges[i].yMin; j < polyEdges[i].yMax; j += spacing)
		{
			Edge horizontal(Point(polyXmin, j), Point(polyXmax, j));

			// check if polyEdge not horizontal
			if (polyEdges[i].start.y != polyEdges[i].end.y)
			{
				Point s;
				if(edge_intersect(polyEdges[i], horizontal, s))
				{
					intersections.emplace_back(s);
				}
			}
		}
	}

	// sort intersection points by their y-coordinate (form a sequence of pair-points making horizontal lines)
	std::sort(intersections.begin(), intersections.end(), YLessThan());

	// draw scan-lines
	if (color().visibility())
	{ 
		for (size_t i = 1; i < intersections.size(); i += 2)
		{
			// draw scan lines
			fl_line(intersections[i-1].x, intersections[i-1].y, intersections[i].x, intersections[i].y);	
		}
	}	
}

//----------------------------------------------------------------------------------------------------------------------

// Helper function 
static void generatePoints(Striped_closed_polyline* s)
{
	s->add(Point(50,50));
	s->add(Point(200,50));
	s->add(Point(250,100));
	s->add(Point(200,200));
	s->add(Point(100,225));
	s->add(Point(50,200));
	s->add(Point(25,100));
}