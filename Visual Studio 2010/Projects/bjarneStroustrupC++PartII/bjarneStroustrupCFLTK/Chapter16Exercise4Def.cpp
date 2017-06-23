/*
	TITLE		   Drawing GUI					  Chapter16Exercise4Def.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Make a menu with items that make a circle, a square,
				   an equilateral triangle, and a hexagon respectively.
				   Make an input box for giving coordinate pair, and
				   place the shape made by pressing a menu item at 
				   that coordinate.
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/

Shapes_window::Shapes_window(Point o, int w, int h, std::string& t)
	: Window(o, w, h, t),
	x_coordinate(Point(25, 0), 70, 20, "x : "),
	y_coordinate(Point(125, 0), 70, 20, "y : "),
	xy_current(Point(250, 0), 70, 20, "(x,y) :"),
	menu_button(Point(x_max() - 80, 0), 80, 30, "Shapes", cb_menu_button),
	shape_menu(Point(x_max() - 80, 0), 70, 20, Graph_lib::Menu::Kind::vertical, "drawings")
{
	attach(x_coordinate);
	attach(y_coordinate);
	attach(xy_current);
	xy_current.put("no point");

	attach(menu_button);

	shape_menu.attach(new Button(Point(0, 0), 0, 0, "Circle", cb_circle));
	shape_menu.attach(new Button(Point(0, 0), 0, 0, "Square", cb_square));
	shape_menu.attach(new Button(Point(0, 0), 0, 0, "Triangle", cb_triangle));
	shape_menu.attach(new Button(Point(0, 0), 0, 0, "Hexagon", cb_hexagon));
	attach(shape_menu);
	shape_menu.hide();
}

void Shapes_window::circle_pressed()
{
	// get coodrinates
	int x = x_coordinate.get_int();
	int y = y_coordinate.get_int();

	// create shape
	int r = 50;
	add_drawing(new Graph_lib::Circle(Point(x, y), r));

	// update output box
	std::stringstream ss;
	ss <<"("<< x <<", "<< y << ")";
	xy_current.put(ss.str());

	// draw & update window widgets
	plot_drawings();
	hide_menu();
}

void Shapes_window::square_pressed()
{
	int x = x_coordinate.get_int();
	int y = y_coordinate.get_int();

	int s = 50;
	add_drawing(new Graph_lib::Rectangle(Point(x, y), s, s));

	std::stringstream ss;
	ss <<"("<< x <<", "<< y << ")";
	xy_current.put(ss.str());

	plot_drawings();
	hide_menu();
}

void Shapes_window::triangle_pressed()
{
	std::cout <<"Not implemented!\n";
}

void Shapes_window::hexagon_pressed()
{
	std::cout <<"Not implemented!\n";
}