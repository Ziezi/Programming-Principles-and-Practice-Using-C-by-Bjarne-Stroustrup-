/*
	TITLE		   Pseudo window                  Chapter14Exercise10.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define a Pseudo_window with:
				   rounded corners, lable,
				   control icons and fake
				   contents (image, etc.). 
		    Input: - 
		   Output: -
		   Author: 14.10.2015
		     Date: Chris B. Kirov
*/
#ifndef CHAPTER14EXERCISE10_H
#define CHAPTER14EXERCISE10_H

//--------------------------------------------------------------------------------
// from Chapter 13 Exercise 2 Rounded Box
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
//--------------------------------------------------------------------------------------------------

class Pseudo_window: public RoundedBox
{
public:
	Pseudo_window(Point ul, int width, int height, string& title)
		: RoundedBox(Point(ul.x, ul.y), width, height), 
		  im(Point(ul.x - width, ul.y - height), "Chapter14Exercise10.jpg"),
		  t(Point(ul.x - width, ul.y - height), title),
		  r(Point(ul.x - width + 45, ul.y - height + 15), Point(ul.x - 45, ul.y - 25))
	{
		im.set_mask(Point(700, 450), 300, 350);
		im.move(50, 20);

		t.move(110, 20);
		t.set_color(Color::blue);
		t.set_font_size(30);

		r.set_color(Color::invisible);
		r.set_fill_color(Color::red);
	}
		  
	void draw_lines() const;

private:
	Image im; 
	Text t;
	Rectangle r;
};

// Member implementations
void Pseudo_window::draw_lines() const
{
	RoundedBox::draw_lines();
	r.draw();
	im.draw();
	t.draw();
}

} // end of namespace Graph_lib
#endif