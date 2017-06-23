/*
	TITLE		   Draw a class diagram			  Chapter13Exercise6.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Draw a class diagram. 
		           Define a Box class that is
				   a rectangle with a Text label.
		   Output: 
		   Author: 17.09.2015
		     Date: Chris B. Kirov
*/


namespace Graph_lib
{
// class RoundedBox
/*
	This class creates
	a rectangle with rounded
	corners. The first parameter
	represents the top left point
	of the smallest encirling 
	rectangle, i.e. outside the 
	RoundedBox object.
*/
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
	int roundWidth;
	int roundHeight;
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

//========================================================================================================
// Class Connection Points
/*
	This classes member functions
	find the geometric center,
	north, south, east, west,
	ne, nw, se, sw of the passed
	object.
	*/
class ConnectionPoints
{
public:
	// constructors
	ConnectionPoints(const Graph_lib::Rectangle& r);
	ConnectionPoints(const Graph_lib::Circle& c);
	ConnectionPoints(const Graph_lib::Ellipse& e);
	ConnectionPoints(const Point& ul, const Point& dr);
	ConnectionPoints(const Point& ul, int w, int h);

	// non-modyfing member function
	Point n();
	Point s();
	Point e();
	Point w();
	Point center();
	Point ne();
	Point se();
	Point sw();
	Point nw();

protected:
	ConnectionPoints();
    
private:
	Point topLeft;
	int width;
	int height;	
};

// Class Connectionpoints member implementation
// constructors
ConnectionPoints::ConnectionPoints(const Graph_lib::Rectangle& r)
	: topLeft(r.point(0)), width(r.width()), height(r.height())
{ }
ConnectionPoints::ConnectionPoints(const Graph_lib::Circle& c)
	: topLeft(c.center().x - c.radius(), c.center().y - c.radius()), width(2 * c.radius()), height(2 * c.radius())
{ }

ConnectionPoints::ConnectionPoints(const Graph_lib::Ellipse& e)
	: topLeft(e.center().x - e.major(), e.center().y - e.minor() ), width(2 * e.major()), height(2 * e.minor())
{ }

ConnectionPoints::ConnectionPoints(const Point& ul, const Point& dr)
	: topLeft(ul), width(abs(ul.x - dr.x)), height(abs(ul.y - dr.y))
{ }

ConnectionPoints::ConnectionPoints(const Point& ul, int w, int h)
	: topLeft(ul), width(w), height(h)
{ }
//========================================================================================================
// // non-modyfing member function

/*
	Function: n()
	Use: Point p = n(Rect_obj);
	It returns the middle point
	of the top side of the passed rectangle.
	Internally, it retrieves the zero-th
	point from the base class Shape,i.e.
	the upper left point and increases
	the x-coordinate by half the width.
*/
Point ConnectionPoints::n()
{
	return Point(topLeft.x + width / 2., topLeft.y);
}

/*
	Function: s()
*/
Point ConnectionPoints::s()
{
	return Point(topLeft.x + width / 2., topLeft.y + height);
}

/*
	Function: e()
*/
Point ConnectionPoints::e( )
{
	return Point(topLeft.x + width, topLeft.y + height / 2.);
}

/*
	Function: w()
*/
Point ConnectionPoints::w( )
{
	return Point(topLeft.x, topLeft.y + height / 2.);
}

/*
	Function: center()
*/
Point ConnectionPoints::center( )
{
	return Point(topLeft.x + width / 2., topLeft.y + height / 2.);
}

/*
	Function: ne()
*/
Point ConnectionPoints::ne( )
{
	return Point(topLeft.x + width, topLeft.y);
}

/*
	Function: se()
*/
Point ConnectionPoints::se( )
{
	return Point(topLeft.x + width, topLeft.y + height);
}

/*
	Function: sw()
*/
Point ConnectionPoints::sw( )
{
	return Point(topLeft.x, topLeft.y  + height);
}

/*
	Function: nw()
	
*/
Point ConnectionPoints::nw( )
{
	return Point(topLeft.x, topLeft.y);
}
//========================================================================================================

#define PI 3.14159265359
// class Arrow
/*
	This class uses two points
	to instantiate an object
	resembling a line starting
	from the first parameter 
	and ending with and appropriatelly
	directed arrow at the second end.
*/
class Arrow: public Lines
{
public:
	Arrow(Point p1, Point p2, int arr);

private:
	Point rotate_point(Point pivot, float angle, Point p); 
	int arrowSize;
};

Arrow::Arrow(Point p1, Point p2, int arr)
	: arrowSize(arr)
{
	Shape::add(p1);
	Shape::add(p2);
	// The arrow head is generated by rotating a point on the line around the second(end) point
	// of the line at the same angle in both directions, then using these points to generate arrow lines
	// norm of the vector p1p2
	int x = abs(p2.x - p1.x);
	int y = abs(p2.y - p1.y);
	double norm = sqrt(double(x*x + y*y));
	// unit vector along the vector p1p2; 
	// multiplied by the wanted size of the arrow so that the divisin by the norm is > 1
	Point unitVector(double(x*arrowSize)/double(norm), double(y*arrowSize)/double(norm));
	// rotate a point on the line located just before p2, 30 degrees in both directions around p2
	Point arrow1;
	Point arrow2;
	// cover all the possible slopes
	if (double(p2.y - p1.y) >= 0 && double(p2.x - p1.x) >= 0){
		arrow1 = rotate_point(p2, 30, Point(p2.x - unitVector.x, p2.y - unitVector.y));
		arrow2 = rotate_point(p2, 330, Point(p2.x - unitVector.x, p2.y - unitVector.y));
	}else if(double(p2.y - p1.y) >= 0 && double(p2.x - p1.x) < 0){
		arrow1 = rotate_point(p2, 30, Point(p2.x + unitVector.x, p2.y - unitVector.y));
		arrow2 = rotate_point(p2, 330, Point(p2.x + unitVector.x, p2.y - unitVector.y));
	}else if(double(p2.y - p1.y) < 0 && double(p2.x - p1.x) < 0){
		arrow1 = rotate_point(p2, 30, Point(p2.x + unitVector.x, p2.y + unitVector.y));
		arrow2 = rotate_point(p2, 330, Point(p2.x + unitVector.x, p2.y + unitVector.y));
	}else if(double(p2.y - p1.y) < 0 && double(p2.x - p1.x) >= 0){
		arrow1 = rotate_point(p2, 30, Point(p2.x - unitVector.x, p2.y + unitVector.y));
		arrow2 = rotate_point(p2, 330, Point(p2.x - unitVector.x, p2.y + unitVector.y));
	}
	// generate first part of the arrow
	Shape::add(p2);
	Shape::add(arrow1);
	// generate second part of the arrow
	Shape::add(p2); 
	Shape::add(arrow2); 
}

Point Arrow::rotate_point(Point pivot, float angle, Point p){
	 float angleRad = angle * PI / 180.;
     return Point(cos(angleRad ) * (p.x - pivot.x) - sin(angleRad ) * (p.y - pivot.y) + pivot.x,
                  sin(angleRad ) * (p.x - pivot.x) + cos(angleRad ) * (p.y - pivot.y) + pivot.y);
}

//========================================================================================================
// class LabeledBox
/*
	This class creates a rounded box
	with a text in it. The first 
	parameter is the top left point
	of the box and the second is the
	text to be printed in the box.
*/
class LabeledRoundBox: public RoundedBox
{
public:
	LabeledRoundBox(Point ul, string t);
	Text* add_text() const ;
	     
private:
	 Point topLeft;
	 int width;
	 int height;
	 string text;
};

LabeledRoundBox::LabeledRoundBox(Point ul, string t)
	: RoundedBox(ul, t.size() * 15, 20), topLeft(ul), width(t.size() * 15), height(20), text(t)
{ 
 
}

Text* LabeledRoundBox::add_text() const
{
	// find the right middle point of the box
	ConnectionPoints cp(topLeft, width, height);
	// and insert the text
	Text* t = new Text(Point(cp.w().x + 20, cp.w().y + 5) , text);
	// specify text parameters (optional)
	t->set_font(Font::courier);
	t->set_font_size(15);
	t->set_color(Color::black);
	return t;
}

} // end of namespace Graph_lib