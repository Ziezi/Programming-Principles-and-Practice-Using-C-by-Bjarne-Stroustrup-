/*
	TITLE		   Implement code from 16.5§		  Chapter16DrillDef.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Write line - drawing program with GUI.
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/

// constructor initialization
Lines_window::Lines_window(Point o, int w, int h, const std::string& t)
	: Window(o, w, h, t),
	next_button(Point(x_max() - 150, 0), 70, 20, "Next point", cb_next),
	quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit),

	next_x(Point(x_max() - 310, 0), 50, 20, "next x: "),
	next_y(Point(x_max() - 210, 0), 50, 20, "next y: "),
	xy_out(Point(100, 0), 100, 20, "current (x,y): "),

	color_menu(Point(x_max() - 70, 40), 70, 20, Menu::vertical, "color"),
	menu_button(Point(x_max() - 80, 30), 80, 20, "Color menu", cb_menu),

	style_menu(Point(x_max()- 70, 180), 70, 20, Menu::vertical, "style"),
	style_button(Point(x_max()- 80, 170), 80, 20, "Style menu", cb_style)
{
	attach(lines);

	attach(next_button);
    attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	xy_out.put("no point");
	
	color_menu.attach(new Button(Point(0, 0), 0, 0, "red", cb_red));
	color_menu.attach(new Button(Point(0, 0), 0, 0, "blue", cb_blue));
	color_menu.attach(new Button(Point(0, 0), 0, 0, "black", cb_black));
	attach(color_menu);
	color_menu.hide();
	attach(menu_button);

	style_menu.attach(new Button(Point(0, 0), 0, 0, "solid", cb_solid));
	style_menu.attach(new Button(Point(0, 0), 0, 0, "dash", cb_dash));
	style_menu.attach(new Button(Point(0, 0), 0, 0, "dot", cb_dot));
	attach(style_menu);
	style_menu.hide();
	attach(style_button);
}

// callback from OS - reverse control to function next()
void Lines_window::cb_next(Address, Address pw)
{
	reference_to<Lines_window>(pw).next();
}

// callback from OS - reverse control to function quit()
void Lines_window::cb_quit(Address, Address pw)
{
	reference_to<Lines_window>(pw).quit();
}

void Lines_window::cb_red(Address, Address pw)
{
	reference_to<Lines_window>(pw).red_pressed();
}

void Lines_window::cb_blue(Address, Address pw)
{
	reference_to<Lines_window>(pw).blue_pressed();
}

void Lines_window::cb_black(Address, Address pw)
{
	reference_to<Lines_window>(pw).black_pressed();
}

void Lines_window::cb_menu(Address, Address pw)
{
	reference_to<Lines_window>(pw).menu_pressed();
}

void Lines_window::cb_solid(Address, Address pw)
{
	reference_to<Lines_window>(pw).solid_pressed();
}

void Lines_window::cb_dash(Address, Address pw)
{
	reference_to<Lines_window>(pw).dash_pressed();
}

void Lines_window::cb_dot(Address, Address pw)
{
	reference_to<Lines_window>(pw).dot_pressed();
}

void Lines_window::cb_style(Address, Address pw)
{
	reference_to<Lines_window>(pw).style_pressed();
}

// actions
void Lines_window::next()
{
	// read pair of input coordinates
	int x = next_x.get_int();
	int y = next_y.get_int();

	// create new point out of new coordinates
	lines.add(Point(x, y));

	// update output with current point
	std::stringstream ss;
	ss <<"("<< x <<", "<< y <<")";
	xy_out.put(ss.str());

	// draw new line
	redraw();
}

void Lines_window::quit()
{
	// delete line
	hide();
}