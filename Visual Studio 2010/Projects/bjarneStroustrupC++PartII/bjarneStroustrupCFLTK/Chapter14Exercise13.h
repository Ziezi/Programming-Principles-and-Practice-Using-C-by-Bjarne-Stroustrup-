 /*
	TITLE		   Binary tree	                    Chapter14Exercise13.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define Binary_Tree class derived from Shape.
		           Modify it to include a parameter indicating 
				   whether the connection between two nodes is:
				   - arrow pointing down
				   - red arrow pointing up.
		    Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#ifndef _Chapter14Exercise13_h_
#define _Chapter14Exercise13_h_

//-----------------------------------------------------------------------------------------------------------------------------------------
// class Arrow representing an Binary_tree edge 
class Arrow: public Line
{
public:
	Arrow(Point start, Point end)
		: Line(start, end)
	{
	
	}
	
	void draw_lines() const;
};

 void Arrow::draw_lines() const
 {
	// draw line of arrow
	Line::draw_lines();

	// construct arrow head

	// length of arrow, to be used as standard unit of length
	double length = sqrt(double(pow(point(1).x - point(0).x, 2.) + pow(point(1).y - point(0).y, 2.)));
	
	// distance from the end of arrow
	int base_distance = 6;

	// base perpendicular to arrow line
	double baseX = (base_distance / length) * point(0).x + (1 - base_distance / length) * point(1).x;
	double baseY = (base_distance / length) * point(0).y + (1 - base_distance / length) * point(1).y;

	// base length 
	int base_length = 6;

	// left vertex coordinates 
	double lvX = baseX + (base_length / (2 * length)) * (point(1).y - point(0).y);
	double lvY = baseY + (base_length / (2 * length)) * (point(0).x - point(1).x);

	// right vertex coordinates 
	double rvX = baseX + (base_length / (2 * length)) * (point(0).y - point(1).y);
	double rvY = baseY + (base_length / (2 * length)) * (point(1).x - point(0).x);

	// draw head
	if (color().visibility())
	{
		fl_begin_complex_polygon();
        fl_vertex(point(1).x, point(1).y);
        fl_vertex(lvX, lvY);
        fl_vertex(rvX, rvY);
        fl_end_complex_polygon();
	}
 }
 //-----------------------------------------------------------------------------------------------------------------------------------------

 enum ConnectionType { line, down_arrow, up_red_arrow };

//-----------------------------------------------------------------------------------------------------------------------------------------
// class Binary_tree graphically represents a binary tree
class Binary_tree: public Shape
{
public:	 
	Binary_tree(Point c, int l, ConnectionType t)
		: root(c), levels(l) 
	{
			if(l < 0) 
			{
				throw std::invalid_argument("Tree levels must be >= 0 !");
			}

			generate_coordinates();
			create_connections(t);
	}

	void draw_lines() const;

protected:
	int levels; // depth of binary tree
	Point root; // root coordinates

	std::vector<Shape*> connections; // lines

private:
	void generate_coordinates();
	void create_connections(ConnectionType t);
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
	int scaleX = 5;
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

void Binary_tree::create_connections(ConnectionType t)
{
	const int radius = 10; // arrows start/end out of the nodes (circles)

	// if a parent node has an index: i, left child has 2i + 1 and right 2i + 2
	for (int i = 0; i < number_of_points() / 2; ++i)
	{
		if (t == ConnectionType::line)
		{
			connections.emplace_back(new Line(point(i), point(2 * i + 1)));
			connections.emplace_back(new Line(point(i), point(2 * i + 2)));
		}
		else if (t == ConnectionType::down_arrow)
		{
			connections.emplace_back(new Arrow(point(i), Point(point(2 * i + 1).x, point(2 * i + 1).y - radius)));
			connections.emplace_back(new Arrow(point(i), Point(point(2 * i + 2).x, point(2 * i + 2).y - radius)));
		}
		else if (t == ConnectionType::up_red_arrow)
		{
			Arrow* la = new Arrow(Point(point(2 * i + 1).x, point(2 * i + 1).y - radius), point(i));
			la->set_color(Color::red);

			Arrow* ra = new Arrow(Point(point(2 * i + 2).x, point(2 * i + 2).y - radius), point(i));
			ra->set_color(Color::red);

			connections.emplace_back(la);
			connections.emplace_back(ra);
		}
	}
}

#endif

 