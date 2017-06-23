/*
	TITLE		   std::exception class hierarchy Chapter14Exercise17.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Draw a class hierarchy for the std::exception C++ standard library.
		           It's consisted of a set of labeled boxes located on different lines.
		    Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/

#ifndef _Chapter14Exercise17_h_
#define _Chapter14Exercise17_h_

class Arrow: public Line
{
public:
	Arrow(Point& start, Point& end)
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
//---------------------------------------------------------------------------------------------------------------

class Hierchy_Diagram: public Shape
{
public:
	Hierchy_Diagram(Point c)
		: center(c)
	{
		generate_coordinates();
		create_connections();
		create_labels();
	}

	void draw_lines() const;

protected:

	Point center;

	std::vector<Shape*> connections; // arrows
	std::vector<Text*> labels;       // name of classes

private:
	void generate_coordinates();
	void create_connections();
	void create_labels();
};

void Hierchy_Diagram::draw_lines() const
{
	int width = 160;
	int height = 30;

	for (int i = 0; i < number_of_points(); ++i)
	{
		// draw rectangles
		fl_rect(point(i).x, point(i).y, width, height);

		// draw labels
		labels[i]->draw();	
	}

	// draw connections
	for (int i = 0; i < connections.size(); ++i)
	{
		connections[i]->draw();
	}
}
 
void Hierchy_Diagram::generate_coordinates()
{
	// base class
	add(center);

	// first row of upper left coordinate of labeled rectangular boxes
    int adjustX = 150;
	int adjustY = 70;
	for (int i = 1; i <= 6; ++i)
	{
		add(Point(center.x - adjustX , center.y + adjustY * i));
	}

	// second row
	for (int i = 1; i <= 7; ++i)
	{
		add(Point(center.x + adjustX , center.y + adjustY * i));
	}
}

void Hierchy_Diagram::create_connections()
{
	Point v1Start, v1End, v2Start, v2End, v3Start, v3End;

	int adjustY = 15;
	int length = 20;

	for (int i = 1; i < number_of_points(); ++i)
	{
		if (i >= 1 && i <= 6) // horizontal lines for the first row
		{
			if (i == 1) v1Start = Point(point(i).x - length, point(i).y + adjustY);
			if (i == 6) v1End = Point(point(i).x - length, point(i).y + adjustY);

			connections.push_back(new Graph_lib::Line(Point(point(i).x - length, point(i).y + adjustY), Point(point(i).x, point(i).y + adjustY)));
		}
		else // horizontal lines for the second row
		{
			if (i == 7) v2Start = Point(point(i).x - length, point(i).y + adjustY);
			if (i == 10) v2End = Point(point(i).x - length, point(i).y + adjustY);

			if (i == 11) v3Start = Point(point(i).x - length, point(i).y + adjustY);
			if (i == number_of_points() - 1) v3End = Point(point(i).x - length, point(i).y + adjustY);

			connections.push_back(new Graph_lib::Line(Point(point(i).x - length, point(i).y + adjustY), Point(point(i).x, point(i).y + adjustY)));
		}
	}

	// vertical line for first row 
	connections.push_back(new Graph_lib::Line(Point(v1Start.x, v1Start.y - 20), v1End));
	
	// upper vertical for the second row
	connections.push_back(new Graph_lib::Line(v2Start, v2End));

	// lower vertical for the second row
	connections.push_back(new Graph_lib::Line(v3Start, v3End));

	// arrows
	connections.push_back(new Arrow(Point(v1Start.x, v1Start.y - 20), Point(point(0).x, point(0).y + adjustY)));
	connections.push_back(new Arrow(v2End, Point(point(5).x + 160, point(5).y + 15)));
	connections.push_back(new Arrow(v3End, Point(point(6).x + 160, point(6).y + 15)));
}

void Hierchy_Diagram::create_labels()
{
	std::string names[] = { "std::exception", 
		                    "std::bad_alloc", "std::bad_cast", "std::bad_typeid", "std::bad_exception", "std::logic_failure", "std::runtime_error", 
						    "std::domain_error", "std::invalid_argument", "std::length_error", "std::out_of_range", 
						    "std::overflow_error", "std::range_error", "std::underflow_error" };
	int adjustX = 5;
	int adjustY = 20;

	for (int i = 0; i < number_of_points(); ++i)
	{
		labels.push_back(new Text(Point(point(i).x + adjustX, point(i).y + adjustY), names[i]));
	}
}

#endif