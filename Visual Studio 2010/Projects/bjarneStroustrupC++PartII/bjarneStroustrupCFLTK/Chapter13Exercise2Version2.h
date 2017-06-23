/*
	TITLE		   Rounded box			    Chapter13Exercise2Version2.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a class Box which draws four lines and four arcs.
		           Draw a rounded box.
				   Superellipse could be used as well!
		    Input: -
		   Output: -
		   Author: 18.09.2015
		     Date: Chris B. Kirov
*/
namespace Graph_lib
{

class RoundedBox: public Shape
{
public:
	RoundedBox(Point ul, Point dr);
	RoundedBox(Point ul, int w, int h);

	void draw_lines() const;

private:
	Point upperLeft;
	int width;
	int height;
	// roundedness of the box 
	// should be changed together with Arc center, major and minor axes
	int roundWidth; // hard coded
	int roundHeight;// hard coded
};

// Class member implementations
RoundedBox::RoundedBox(Point ul, Point dr)
	: upperLeft(ul), width(abs(ul.x - dr.x)), height(abs(ul.y - dr.y)), 
	  roundWidth(abs(ul.x - dr.x) / 4), roundHeight(abs(ul.y - dr.y) / 4)  
{
	add(ul);
}

RoundedBox::RoundedBox(Point ul, int w, int h)
	: upperLeft(ul), width(w), height(h), roundWidth(w / 4), roundHeight(h / 4) 
{
	add(ul);
}

void RoundedBox::draw_lines() const
{
	
	if(color().visibility())
	{ 
		// Arcs
		// upper left arc
		fl_arc(point(0).x , point(0).y, width/2, height/2, 90, 180);
		// upper right arc
		fl_arc(point(0).x + width/2, point(0).y, width/2, height/2, 0, 90);
		// down right arc
		fl_arc(point(0).x + width/2, point(0).y + height/2, width/2, height/2, 270, 0); 
		// down left arc
		fl_arc(point(0).x, point(0).y + height/2, width/2, height/2, 180, 270); 

		// Lines
		// top horizontal
		fl_xyline(point(0).x + roundWidth, point(0).y, point(0).x + width - roundWidth);
		// right vertical
		fl_yxline(point(0).x + width, point(0).y + roundHeight, point(0).y + height - roundHeight);
		// bottom horizontal
		fl_xyline(point(0).x + roundWidth, point(0).y + height, point(0).x + width - roundWidth);
		// left vertical
		fl_yxline(point(0).x, point(0).y + roundHeight, point(0).y + height - roundHeight);
	}
}

} // end of namespace Graph_lib


