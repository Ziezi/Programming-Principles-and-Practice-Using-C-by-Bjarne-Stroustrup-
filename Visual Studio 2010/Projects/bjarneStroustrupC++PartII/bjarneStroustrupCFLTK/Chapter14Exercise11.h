/*
	TITLE		   Group container                Chapter14Exercise11.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define Binary_Tree class derived from Shape.
		           Give Number of levels as parameter:
				   0 - no nodes;
				   1 - one done;
				   2 - top node with two subnodes, etc.
				   Let a node be a circle; connect nodes
				   by lines.
		    Input: - 
		   Output: -
		   Author: 16.10.2015
		     Date: Chris B. Kirov
*/

#ifndef _Chapter14Exercise11_h
#define _Chapter14Exercise11_h

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

	void draw_lines() const;

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

#endif