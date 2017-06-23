/*
	TITLE		   Rounded box     Chapter13Exercise2.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a class Box which draws four lines and four arcs.
		           Draw a rounded box.
				   Superellipse could be used as well!
		    Input: -
		   Output: 
		   Author: 10.09.2015
		     Date: Chris B. Kirov
*/

namespace Graph_lib
{
// Class RoundedBox
class RoundedBox: public Shape
{
public:
	// constructors
	RoundedBox(Point p, int w, int h);
	RoundedBox(Point ul, Point dr);

    // function to incorporate arc within the class
    void draw_lines() const;

private:
	int width;
	int height; 
};

//--------------------------------------------------------------------------------------------------
// Function Implementation
// Helper function
bool validInput(int w, int h)
{
	if (w < 0 || h < 0) 
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool validInput(Point ul, Point dr)
{
	if(ul.x - dr.x < 0 || ul.y - dr.y < 0)
	{
		return false;
	}
	return true;
}

//--------------------------------------------------------------------------------------------------
// Class Constructors
RoundedBox::RoundedBox(Point p, int w, int h)
		: width(w), height(h)
	{ 
		if (!validInput(w,h)) 
		{
			std::cerr << "Invalid input Box";
		}

		add(Point(p.x - w, p.y - h));
	}

RoundedBox::RoundedBox(Point ul,Point dr) 
		:  width(dr.x - ul.x), height(dr.y - ul.y)
	{ 
		if(!validInput(ul, dr))
		{
			std::cerr << "Invalid input Box";
		}

		add(Point(ul.x - width, ul.y - height));
	}

//--------------------------------------------------------------------------------------------------
// Member function
void RoundedBox::draw_lines() const
{
	// draw lines with reduced length to adapt for the arcs
	if (color().visibility())
	{
		// upper horizontal
		fl_line(point(0).x + width/4, point(0).y, point(0).x + (3./4.) * width, point(0).y);
		// lower horizontal
		fl_line(point(0).x + width/4, point(0).y + height, point(0).x + (3./4.) * width, point(0).y + height);
		// left vertical 
		fl_line(point(0).x, point(0).y + height/4, point(0).x, point(0).y + (3./4.)*height);
		// right vertical 
		fl_line(point(0).x + width, point(0).y + height/4, point(0).x + width, point(0).y + (3./4.) * height);
	}
	 
	// draw arcs
	if(color().visibility())
	{
	    fl_color(fill_color().as_int());
		// upper left arc
		fl_arc(point(0).x, point(0).y, width/2, height/2, 90, 180); 
		// upper right arc
		fl_arc(point(0).x + width/2, point(0).y, width/2, height/2, 0, 90);
		// down right arc
		fl_arc(point(0).x + width/2, point(0).y + height/2, width/2, height/2, 270, 0); 
		// down left arc
		fl_arc(point(0).x , point(0).y + height/2, width/2, height/2, 180, 270); 
	}
}

} // end of namespace Graph_lib