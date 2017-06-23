/*
	TITLE		  Stripped_Closed_Polyline	        Chapter14Exercise7.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a class where the closed polyline is
		           "filled" by drawing varying-pixel-wide-spaced
				   horizontal lines across the inside 
				   area. (Consider line width and spacing.)
		    Input: - 
		   Output:  
		   Author: 28.09.2015
		     Date: Chris B. Kirov
*/

// Helper functions
static void generatePoints(vector<Point>& p)
{
	p.push_back(Point(50,50));
	p.push_back(Point(200,50));
	p.push_back(Point(250,100));
	p.push_back(Point(200,200));
	p.push_back(Point(100,225));
	p.push_back(Point(50,200));
	p.push_back(Point(25,100));
}

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

//---------------------------------------------------------------------------------------
// class Edge: representing lines segments of the poly-line
struct Edge
{
	Edge(Point p0, Point p1)
		: start(p0), end(p1)
	{ 
		// check if not same point
		if (p0.x == p1.x && p0.y == p1.y)
		{
			throw std::invalid_argument("Edge: Identical points!");
		}

		// chech if same direction
		if (p0.y > p1.y)
		{
			std::swap(start, end);
		}

		// assign min and max ordinate
		yMin = start.y;
		yMax = end.y;
	} 

	// operator< defined for the sorting by increasing max ordinate 
	bool operator< (const Edge& e) { return (yMax < e.yMax); }

	// data members 
Point start;
Point end;

int yMin;
int yMax;
};
//---------------------------------------------------------------------------------------

// intesection between two lines (8 coordinates)
Point intersectPoint(float p0_x, float p0_y, float p1_x, float p1_y, float p2_x, float p2_y, float p3_x, float p3_y)
{
    float s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;

    float s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
	{
        // return intersection 
        int x = p0_x + (t * s1_x); 
        int y = p0_y + (t * s1_y);

        return Point(x, y);
    }

	int noIntersection = -1;

    return Point(noIntersection, noIntersection);  
}

// overloaded for Points (4 points)
Point  intersectPoint (Point p0, Point p1, Point p2, Point p3)
{
	return  intersectPoint(p0.x, p0.y, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
}

// overloaded for Edges (2 edges)
Point intersectPoint (Edge& e1, Edge& e2)
{
	return intersectPoint(e1.start, e1.end, e2.start, e2.end);
}
//---------------------------------------------------------------------------------------

// Class Striped_closed_polyline
class Striped_closed_polyline: public Closed_polyline
{
public:
	void draw_lines() const;
};

// member function
void Striped_closed_polyline::draw_lines() const
{
	Closed_polyline::draw_lines(); 
	// add horizontal lines...
}