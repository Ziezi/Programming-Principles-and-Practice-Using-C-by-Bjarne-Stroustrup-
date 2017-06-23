/*
	TITLE		   Controller					 Chapter14Exercise16.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Define class Controller with four virtual functions
				   on(), off(), set_level(int) and show(). 
				   Dervive at least two classes from Controller. 
				   One should be a simple test class where show()
				   prints out whether the class is set on or off
				   and what the current level is. 
				   The second class should control the line color of Shape;
				   the exact meaning of of "level" is up to you.  
		    Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/
#include "Graph.h"
#include "Simple_window.h"
#include "Point.h"
#include <iostream>
#include <map>

class Controller
{
public:
	virtual void on() = 0;
	virtual void off() = 0;
	virtual void set_level(int l) = 0;
	virtual void show() const = 0;
};
//------------------------------------------------------------------------------------------

enum Status { off, on };
//------------------------------------------------------------------------------------------

class Test: public Controller
{
public:
	Test(int l, Status p)
		: level(l), power(p)
	{
		if (l < 0 || (p < Status::off || p > Status::on))
		{
			std::cerr <<"Class Test::Constructor: Invalid initialization arguments!\n"; 
		}
	}

	void on() { power = Status::on; }
	void off() { power = Status::off; }
	void set_level(int l) { level = l; }
	void show() const { std::cout <<"Level: " << level <<" Power: "<< power <<'\n'; }

private:
	int level;
	Status power;
};
//------------------------------------------------------------------------------------------

class Shape_Controller: public Controller
{
public:
	Shape_Controller(Graph_lib::Shape* sh)
		: shape(sh), visible(true)
	{
		
	}

	// turns on and off color, i.e. off: black & white 
	void on() { shape->set_color(Graph_lib::Color::visible); visible = true; }
	void off() { shape->set_color(Graph_lib::Color::invisible); visible = false; }

	// sets colour
	void set_level(int as_int);
	void show () const;
	
private:
	bool visible;
	Graph_lib::Shape* shape;
};

void Shape_Controller::set_level(int as_int) 
{ 
	if (as_int < Graph_lib::Color::red || as_int > Graph_lib::Color::dark_cyan)
	{
		std::cerr <<"Shape_Controller::set_level: Invalid color value!\n";	
	}

	// implicit convertion from int to enum Color
	shape->set_color(as_int);
}

void Shape_Controller::show() const
{
	static std::map<int, std::string> color_names;
	color_names.emplace(pair<int, std::string>(88 ,"red"));
	color_names.emplace(pair<int, std::string>(216, "blue"));
	color_names.emplace(pair<int, std::string>(63, "green"));
	color_names.emplace(pair<int, std::string>(95, "yellow"));
	color_names.emplace(pair<int, std::string>(255, "white"));
	color_names.emplace(pair<int, std::string>(56, "black"));
	color_names.emplace(pair<int, std::string>(248, "magenta")); 
	color_names.emplace(pair<int, std::string>(223, "cyan")); 
	color_names.emplace(pair<int, std::string>(72, "dark red"));
	color_names.emplace(pair<int, std::string>(60, "dark green")); 
	color_names.emplace(pair<int, std::string>(76, "dark yellow"));
	color_names.emplace(pair<int, std::string>(136, "dark blue" ));
	color_names.emplace(pair<int, std::string>(152, "dark magenta")); 
	color_names.emplace(pair<int, std::string>(140, "dark cyan"));

	int index = shape->color().as_int();

	if (shape->color().visibility())
	{
		std::cout <<"Invisible\n";
	}

	std::string no_colour = "none";
	std::cout <<"Color: "<< (visible ? color_names[index] : no_colour) <<", Visibility: " << std::noboolalpha << visible << std::endl;
}

int main()
{
	int level = 5;
	Status power = Status::on;

	Test t(level, power);

	t.show();

	t.off();
	t.set_level(0);
	t.show();

	//----------------------------------------------------------------------------------------------------------------------
	Point ul(50, 50);
	Simple_window sw(ul, 500, 500, "Chapter 14 Exercise 16");
	

	Point center(sw.x_max() / 2, sw.y_max() / 2);
	int radius = 50;

	Graph_lib::Circle c(center, radius);
	 
	Shape_Controller sc(&c);

	sc.on();
	int color_as_int = 88;
	sc.set_level(color_as_int);

	sc.show();
	 
	sw.attach(c);

	sw.wait_for_button();
	getchar(); 
}