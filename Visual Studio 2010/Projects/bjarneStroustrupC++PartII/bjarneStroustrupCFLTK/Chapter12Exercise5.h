/*
	TITLE			   Frame around rectangle	 Chapter12Exercise5.h
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Draw a 1/4-inch frame around a rectangle
					   with size 3/4 the height of the screen
					   and 2/3 the width.
				Input: -
			   Output: Graph on screen.
			   Author: Chris B. Kirov
			     Date: 17. 08. 2015
*/

/*
	Class: framedBox  

	An object instantiation of 
	this class creates a colored 
	box with colored frame.
*/
class framedBox
{
public:
	// default constructor
	framedBox();

	// constuctor
	framedBox(Point& uL, int width, int height, int frWidth, Color inner, Color frame);

	// member functions
	void drawFramedBox();

private:
	// data members
	Point upperLeft;

	int boxWidth;
	int boxHeight;
	int frameWidth;

	Color innerColor;
	Color frameColor;
};
//-----------------------------------------------------------------------------------------------------------------
// Class framedBox member implementations

// default constructor
framedBox::framedBox()
	: upperLeft(Point(x_max()/2., y_max()/2.)), 
	  boxWidth(200), boxHeight(200), frameWidth(20), 
	  innerColor(Graph_lib::Color::blue), frameColor(Graph_lib::Color::red)
{
	drawFramedBox();
}

//-----------------------------------------------------------------------------------------------------------------
// constructor
framedBox::framedBox(Point& uL, int width, int height, int frWidth, Color inner, Color frame)
	: upperLeft(uL), boxWidth(width), boxHeight(height), frameWidth(frWidth), innerColor(inner), frameColor(frame)
{ 
	
}
//-----------------------------------------------------------------------------------------------------------------

/*
	Function: drawFramedBox();

	It draws a colored box with colored frame.
*/
void framedBox::drawFramedBox()
{
	// position the window in the middle
	Point tl(x_max() / 2. - x_max() / 2., y_max() / 2. - y_max() / 2.);
	Simple_window sw(tl, x_max(), y_max(), "Chapter 12 Exercise 5");

	// outer rectangle: size is larger with + 2 * frameSize on each dimension
	Graph_lib::Rectangle outerRect(Point(sw.x_max() / 2. - (boxWidth) / 2., 
			                             sw.y_max() / 2. - (boxHeight) / 2.),
										 boxWidth  + 2 * frameWidth,
										 boxHeight  + 2 * frameWidth);

	outerRect.set_fill_color(frameColor);
	sw.attach(outerRect);

	// inner rectangle: initial coordinate is: translated + framesize in each axis
	Graph_lib::Rectangle innerRect(Point(sw.x_max() / 2. - (boxWidth) / 2. + frameWidth, 
			                             sw.y_max() / 2. - (boxHeight) / 2. + frameWidth),
										 boxWidth,
										 boxHeight);

	innerRect.set_fill_color(innerColor);

	sw.attach(innerRect);
	sw.wait_for_button();
}
