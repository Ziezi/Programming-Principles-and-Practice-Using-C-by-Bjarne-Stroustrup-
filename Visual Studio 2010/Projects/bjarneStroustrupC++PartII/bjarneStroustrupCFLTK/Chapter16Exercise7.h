/*
	TITLE		   Airplane animation			    Chapter16Exercise7.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Make an image of an airplane "fly around" in a window.
				   Have a "start" and "stop" button.   
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/

#ifndef _Chapter16Exercise7_h_
#define _Chapter16Exercise7_h_

class Airplane: Window
{
public:
	Airplane()
		: Window(Point(300, 300), 500, 500, "Chapter 16 Exercise 7"),
		location(x_max() / 2, y_max() / 2),
		x_step(1), y_step(1),
		start(Point(5, 0), 70, 20, "Start", cb_start),
		stop(Point(x_max() - 75, 0), 70, 20, "Stop", cb_stop)
	{
		background = new Graph_lib::Image(Point(0, 20), "Chapter16Exercise7sky.jpg", Graph_lib::Suffix::Encoding::jpg);
		superman = new Graph_lib::Image(Point(x_max() / 2, y_max() / 2), "Chapter16Exercise7man.jpg", Graph_lib::Suffix::Encoding::jpg);
		attach(*background);
		attach(*superman);

		attach(start);
		attach(stop);
	}

private:
	// data members
	Graph_lib::Image* background;
	Graph_lib::Image* superman;
	Point location;
	int x_step;
	int y_step; 

	// controls
	Button start, stop;


	// callback
	static void cb_timer(Address pw) 
	{ 
		reinterpret_cast<Airplane*>(pw)->change_location();
		Fl::repeat_timeout(0.01, cb_timer, pw);
	}

	static void cb_start(Address, Address pw) { reference_to<Airplane>(pw).start_flight(); }
	static void cb_stop(Address, Address pw) { reference_to<Airplane>(pw).stop_flight(); }

	// action
	void change_location();
	void start_flight() { Fl::add_timeout(0.01, cb_timer, this); } // add bool "pushed" value to prevent mutliple "starts"
	void stop_flight() { Fl::remove_timeout(cb_timer); }
};

void Airplane::change_location()
{
	detach(*superman);
	delete superman;

	// picture size 107 x 167
	const int pic_x = 107;
	const int pic_y= 167;

	// changle horizontal direction
	if (location.x == x_max() - pic_x || location.x == 0)
	{
		x_step = -x_step;
	}

	// changle vertical direction
	if (location.y == y_max() - pic_y || location.y == 30)
	{
		y_step = -y_step;
	}

	location.x += x_step;
	location.y += y_step;

	superman = new Graph_lib::Image(location, "Chapter16Exercise7man.jpg", Graph_lib::Suffix::Encoding::jpg);
	attach(*superman);

	redraw();
}


#endif