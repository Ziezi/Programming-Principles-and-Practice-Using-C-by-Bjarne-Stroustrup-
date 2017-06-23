/*
	TITLE		   Drawing GUI					  Chapter16Exercise5Def.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Make a program that draws a shape of you choice and moves
				   it to a new point each time you click "Next". The new point
				   should be determined by a coordinate pair read from an input
				   stream.
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/

Shape_window::Shape_window(Point o, int w, int h, std::string& t)
	:Window(o, w, h, t),
	shape(nullptr),
	circle(false), square(false), ellipse(false),
	center(x_max()/2, y_max()/2),

	next_button(Point(x_max() - 80, 0), 70, 20, "Next", cb_next),
	menu_button(Point(x_max() - 80, 40), 80, 30, "Shape", cb_menu_button),
	shape_menu(Point(x_max() - 80, 40), 70, 20, Graph_lib::Menu::Kind::vertical, "shape"),

	xy_current(Point(100, 0), 70, 20, "Current (x, y): ")
{
	attach(next_button);
	attach(menu_button);

	shape_menu.attach(new Button(Point(0, 0), 0, 0, "Circle", cb_circle));
	shape_menu.attach(new Button(Point(0, 0), 0, 0, "Square", cb_square));
	shape_menu.attach(new Button(Point(0, 0), 0, 0, "Ellipse", cb_ellipse));
	attach(shape_menu);
	hide_menu();

	attach(xy_current);
	xy_current.put("at center");
}

// action
void Shape_window::next_pressed()
{
	// populate center
	read_console_input();

	// relocate or create a new shape
	if (circle)
	{
		circle_make();
	}
	else if (square)
	{
		square_make();
	}
	else if (ellipse)
	{
		ellipse_make();
	}

	// re-attach new shape and coordinates
	attach(*shape);

	redraw();
}

// helper
void Shape_window::read_console_input()
{
	// read input
	std::cout << "Type coordinates:\n x y : ";

	std::string input;
	getline(std::cin, input);
		
	int x, y;
	std::stringstream ss(input);

	if (ss >> x >> y)
	{
		// display current coordinates 
		xy_current.put(ss.str());

		// update coordinates
		center.x = x;
		center.y = y;		
	}
	else
	{
		std::cerr <<"Wrong input format!\n";
	}
}

void Shape_window::circle_make()
{
	// erase from window and delete current shape
	if (shape != nullptr)
	{
		detach(*shape);
		delete shape;
	}

	// create new shape and draw on window
	const int radius = 25;
	shape = new Graph_lib::Circle(center, radius);
}

void Shape_window::square_make()
{
	if (shape != nullptr)
	{
		detach(*shape);
		delete shape;
	}

	const int side = 25;
	shape = new Graph_lib::Rectangle(center, side, side);
}

void Shape_window::ellipse_make()
{
	if (shape != nullptr)
	{
		detach(*shape);
		delete shape;
	}

	int a = 25, b = 50;
	shape = new Graph_lib::Ellipse(center, a, b);
}