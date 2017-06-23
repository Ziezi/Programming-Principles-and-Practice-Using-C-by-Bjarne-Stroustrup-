/*
	TITLE		   Analog clock    			        Chapter16Exercise6.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Make an "Analog Clock", that is, a clock with hands that move;
				   get the time from OS library; find functions that wait for short
				   period of time.
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/

#ifndef _Chapter16Exercise6_h_
#define _Chapter16Exercise6_h_

class Analog_clock: Window
{
public:
	Analog_clock(Point o, std::string& t);

	// function members
	void set_time(int h, int m, int s);

private:
	// data members
	int sec, min, hour;
	Graph_lib::Image clock_dial;
	Graph_lib::Line* hour_indicator;
	Graph_lib::Line* minute_indicator;
	Graph_lib::Line* second_indicator;

	// callback
	static void cb_timer(Address pw);

	// action
	void increment_time();

	// helper
	void get_time();
	void run_clock();
	void set_indicators();
	Point rotate(Point initial, Point pivot, double angle);
};

#include "Chapter16Exercise6Def.cpp"

#endif
