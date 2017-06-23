/*
	TITLE		   Function GUI			          Chapter16Exercise10.h
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Provide a program where one can choose among
				   a set of functions (e.g. sin(x), log(x)), 
				   provide parameters for those functions,
				   and then graph them. 
			Input: - 
		   Output: -
		   Author: 18.10.2015
		     Date: Chris B. Kirov
*/

#ifndef _Chapter16Exercise10_h_
#define _Chapter16Exercise10_h_


double x_func(double n) { return n; }
double x2_func(double n) { return n * n; }


class Function_GUI: Window
{
public:
	Function_GUI();

private:
	// data members
	std::vector<Graph_lib::Function*> functions;

	int min, max, sample, xscale, yscale;
	Point origin;
	Graph_lib::Fct* func;

	// controls
	Button fmenu_button, plot_button;
	Menu function_menu;

	In_box range_f, origin_f, points_f, xscale_f, yscale_f;

	// callback
	static void cb_fmenu_button(Address, Address pw) { reference_to<Function_GUI>(pw).fmenu_button_pressed(); }
	static void cb_fmenu(Address, Address pw);

	static void cb_x(Address, Address pw) { reference_to<Function_GUI>(pw).x_pressed(); }
	static void cb_x2(Address, Address pw) { reference_to<Function_GUI>(pw).x2_pressed(); }
	static void cb_sin(Address, Address pw) { reference_to<Function_GUI>(pw).sin_pressed(); }
	static void cb_cos(Address, Address pw) { reference_to<Function_GUI>(pw).cos_pressed(); }

	static void cb_plot(Address, Address pw) { reference_to<Function_GUI>(pw).plot(); }

	// action
	void fmenu_button_pressed() { fmenu_button.hide(); function_menu.show(); }

	void x_pressed() { func = &x_func; hide_fmenu(); }
	void x2_pressed() { func = &x2_func; hide_fmenu(); }
	void sin_pressed() { func = &sin; hide_fmenu(); }
	void cos_pressed() { func = &cos; hide_fmenu(); }

	void plot();

	// helper
	void hide_fmenu() { function_menu.hide(); fmenu_button.show(); }
};

//----------------------------------------------------------------------------------------------------------------------

Function_GUI::Function_GUI()
	:Window(Point(300, 300), 700, 700, "Chapter 16 Exercise 10"),
	fmenu_button(Point(x_max() - 100, 130), 80, 30, "Functions", cb_fmenu_button),
	function_menu(Point(x_max() - 100, 130), 80, 30, Graph_lib::Menu::Kind::vertical, "Functions"),
	range_f(Point(x_max() - 100, 0), 80, 20, "Range: [x1, x2] : "), 
	origin_f(Point(x_max() - 100, 25), 80, 20, "Origin: (x, y) : "), 
	points_f(Point(x_max() - 100, 50), 80, 20, "Sample: n : "),
	xscale_f(Point(x_max() - 100, 75), 80, 20, "Scale X: a : "),
	yscale_f(Point(x_max() - 100, 100), 80, 20, "Scale Y: b : "),
	plot_button(Point(x_max() - 100, 260), 80, 30, "Plot", cb_plot)
{
	min = -10;
	max = 10;
	origin = Point(x_max() / 2, y_max() / 2);
	sample = 200;
	xscale = 10;
	yscale = 10;
	func = nullptr;

	attach(fmenu_button);

	function_menu.attach(new Button(Point(0, 0), 0, 0, "x", cb_x));
	function_menu.attach(new Button(Point(0, 0), 0, 0, "x^2", cb_x2));
	function_menu.attach(new Button(Point(0, 0), 0, 0, "sinx", cb_sin));
	function_menu.attach(new Button(Point(0, 0), 0, 0, "cosx", cb_cos));

	attach(function_menu);
	function_menu.hide();

	attach(range_f);
	attach(origin_f);
	attach(points_f);
	attach(xscale_f);
	attach(yscale_f);
	attach(plot_button);
}

//----------------------------------------------------------------------------------------------------------------------
 
void Function_GUI::plot()
{
	// get range
	std::stringstream ss(range_f.get_string());

	int b, e;
	char p1, c, p2;
	if (ss >> p1 >> b >> c >> e >> p2)
	{
		min  = b;
		max = e;
	}

	ss.str(std::string());
	ss.clear();

	// get origin
	ss << origin_f.get_string();
	int x, y;
	if (ss >> p1 >> x >> c >> y >> p2)
	{
		origin = Point(x, y);
	}

	ss.str(std::string());
	ss.clear();

	// get points
	ss << points_f.get_string();
	int n;
	if (ss >> n)
	{
		sample = n;
	}

	ss.str(std::string());
	ss.clear();

	// get scale
	int scx, scy;
	ss << xscale_f.get_string() <<" , " << yscale_f.get_string();
	if (ss >> scx >> c >> scy)
	{
		xscale = scx;
		yscale = scy;
	}

	// add functions
	functions.emplace_back(new Graph_lib::Function(func, min, max, origin, sample, xscale, yscale));
	attach(*functions[functions.size() - 1]);

	// update window 
	redraw();
}

#endif