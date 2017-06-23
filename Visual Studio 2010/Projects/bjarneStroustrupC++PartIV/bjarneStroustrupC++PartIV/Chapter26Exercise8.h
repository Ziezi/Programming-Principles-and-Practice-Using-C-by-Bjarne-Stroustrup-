/* 
	TITLE		   Text Input to Graph_lib								  Chapter26Exercise8.h
	COMMENT
		Objective: Add a text-based interface to the graphics interface library from Chapters
				   12 - 15. For example, the string: Cirle(Point(O, 1), 15) should generate a
				   call Circle(Poinl(O, 1), 15). 
				   Use this text interface to make a "kid 's drawing" of a two-dimensional
				   house with a roof, two windows, and a door.  
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 04.06.2017
*/
#ifndef Chapter26Exercise8_h
#define Chapter26Exercise8_h

//--------------------------------------------------------------------------------------------

// Output for Exercise 9 & 10
std::ostream& operator<<(std::ostream& os, Graph_lib::Shape* s)
{
	if (typeid(*s) == typeid(Graph_lib::Line))
	{
		Graph_lib::Line* l = dynamic_cast<Graph_lib::Line*>(s);
		os <<"Line(Point("<< l->point(0).x <<","<< l->point(0).y <<"),Point(" << l->point(1).x
		   <<","<< l->point(1).y <<"))\n"; 
	}
	else if (typeid(*s) == typeid(Graph_lib::Rectangle))
	{
		Graph_lib::Rectangle* r = dynamic_cast<Graph_lib::Rectangle*>(s);
		os <<"Rectangle(Point("<< r->point(0).x <<","<< r->point(0).y <<"),Point(" << r->point(0).x + r->width() 
		   <<","<< r->point(0).y + r->height() <<"))\n"; 
	}
	else if (typeid(*s) == typeid(Graph_lib::Circle))
	{
		Graph_lib::Circle* c = dynamic_cast<Graph_lib::Circle*>(s);
		os <<"Circle(Point("<< c->center().x <<","<< c->center().y <<")," << c->radius() <<")\n";
	}
	else if (typeid(*s) == typeid(Graph_lib::Ellipse))
	{
		Graph_lib::Ellipse* e = dynamic_cast<Graph_lib::Ellipse*>(s);
		os <<"Ellipse(Point("<< e->center().x <<","<< e->center().y <<")," << e->major() <<","<< e->minor() <<")\n";
	}
	else
	{
		throw std::runtime_error("No such object!\n");
	}
	return os;
}

//--------------------------------------------------------------------------------------------

struct Command
{
	std::string object_name;
	Point p1;
	Point p2;
	int w;
	int h;
};

//--------------------------------------------------------------------------------------------

enum Type_ID 
{ 
	LINE = 1, RECTANGLE, CIRCLE, ELLIPSE
};

//--------------------------------------------------------------------------------------------

std::map<std::string, int> Graph_lib_ID; // make it static and insert within get_ID(), followed by init_IDs() ?

//--------------------------------------------------------------------------------------------

static void init_IDs(std::map<std::string, int>& m)
{
	m["Line"] = 1;
	m["Rectangle"] = 2;
	m["Circle"] = 3;
	m["Ellipse"] = 4;
}

//--------------------------------------------------------------------------------------------

int get_ID(const std::string& n)
{
	init_IDs(Graph_lib_ID);
	return Graph_lib_ID.at(n);
}

//--------------------------------------------------------------------------------------------

void print_command(std::ostream& os, Command& c)
{
	int ID = 0;
	ID = get_ID(c.object_name);
	 
	switch(ID)
	{
		case LINE:
		{
			 os << c.object_name <<"(Point("<< c.p1.x <<","<< c.p1.y <<"),Point("<< c.p2.x <<","<< c.p2.y <<"))\n";
			 break;
		}
		case RECTANGLE:
		{
			 os << c.object_name <<"(Point("<< c.p1.x <<","<< c.p1.y <<"),Point("<< c.p2.x <<","<< c.p2.y <<"))\n";
			 break;
		}
		case CIRCLE:
		{
			 os << c.object_name <<"(Point("<< c.p1.x <<","<< c.p1.y <<"),"<< c.w <<")\n";
			 break;
		}
		case ELLIPSE:
		{
			 os << c.object_name <<"(Point("<< c.p1.x <<","<< c.p1.y <<"),"<< c.w <<","<< c.h <<")\n";
			 break;
		}
		default:
		{
			throw std::runtime_error("print_command:No object with such ID!");
		}
	}
}

//--------------------------------------------------------------------------------------------

std::istream& operator>> (std::istream& is, Point& p)
{
	if (!is)
	{
		return is;
	}

	char op, comma, cp;

	is >> op;

	if (op != '(')
	{
		is.setf(std::ios_base::failbit);
		return is;
	}

	int x, y;

	is >> x >> comma >> y >> cp;

	if (comma != ',' || cp != ')' || !is)
	{
		is.setf(std::ios_base::failbit);
		return is;
	}

	p.x = x;
	p.y = y;

	return is;
}

//--------------------------------------------------------------------------------------------

class Command_Parser
{
	std::vector<Command> commands;

	bool get_line_rectangle(std::string& l, Command& c)
	{		
		// Rectangle \ Line(Point(int,int),Point(int,int)) - 8 groups: 3 names, 2 parentheses, comma, 2 Points
		std::string line_rect("(\\bLine\\b|\\bRectangle\\b)(\\()(\\bPoint\\b)(\\(\\d{1,4},\\d{1,4}\\))(,)(\\bPoint\\b)(\\(\\d{1,4},\\d{1,4}\\))(\\))");
		std::regex pattern(line_rect);

		std::smatch match;
		if (std::regex_match(l, match, pattern))
		{
			c.object_name = match[1];
	
			std::stringstream ss1(match[4]);
			ss1 >> c.p1;

			std::stringstream ss2(match[7]);
			ss2 >> c.p2;

			return true;
		}
		return false;
	}

	bool get_circle(std::string& l, Command& c)
	{
		std::string circle("(\\bCircle\\b)(\\()(\\bPoint\\b)(\\(\\d{1,4},\\d{1,4}\\))(,)(\\d{1,4})(\\))");
		std::regex pattern(circle);

		std::smatch match;
		if (std::regex_match(l, match, pattern))
		{
			c.object_name = match[1];

			std::stringstream ss1(match[4]);
			ss1 >> c.p1;

			std::stringstream ss2(match[6]);
			ss2 >> c.w;

			return true;
		}
		return false;
	}

	bool get_ellipse(std::string& l, Command& c)
	{
		std::string ellipse("(\\bEllipse\\b)(\\()(\\bPoint\\b)(\\(\\d{1,4},\\d{1,4}\\))(,)(\\d{1,4})(,)(\\d{1,4})(\\))");
		std::regex pattern(ellipse);

		std::smatch match;
		if (std::regex_match(l, match, pattern))
		{
			c.object_name = match[1];

			std::stringstream ss1(match[4]);
			ss1 >> c.p1;

			std::stringstream ss2(match[6]);
			ss2 >> c.w;

			std::stringstream ss3(match[8]);
			ss3 >> c.h;

			return true;
		}
		return false;
	}

	void parse(std::istream& is)
	{   
		std::string line;
		while (getline(is, line))
		{
			Command c;
			if (get_line_rectangle(line, c))
			{
				 commands.emplace_back(c);
			}
			else if(get_circle(line, c))
			{
				commands.emplace_back(c);
			}
			else if(get_ellipse(line, c))
			{
				commands.emplace_back(c);
			}
			else
			{
				throw std::runtime_error("Command_parser::parse:: No such command!\n");
			}
		}
		std::cout <<"Commands read: " << commands.size() <<'\n';
	}

public:
	Command_Parser(std::istream& is)
	{
		parse(is);
	}

	vector<Command> get_commands() { return commands; }  
};

//--------------------------------------------------------------------------------------------

class Graph_lib_Factory
{
	Graph_lib::Line* create_Line(Point& p1, Point& p2)
	{
		return new Graph_lib::Line(p1, p2);
	}

	Graph_lib::Rectangle* create_Rectangle(Point& p1, Point& p2)
	{
		return new Graph_lib::Rectangle(p1, p2);
	}

	Graph_lib::Circle* create_Circle(Point& p1, int r)
	{
		return new Graph_lib::Circle(p1, r);
	}

	Graph_lib::Ellipse* create_Ellipse(Point& p1, int w, int h)
	{
		return new Graph_lib::Ellipse(p1, w, h);
	}

public:	
	
	Graph_lib::Shape* create(Command& c) 
	{
		int ID = 0;
		ID = get_ID(c.object_name);

		switch(ID)
		{
			case LINE:
			{
				return create_Line(c.p1, c.p2);
			}
			case RECTANGLE:
			{
				return create_Rectangle(c.p1, c.p2);
			}
			case CIRCLE:
			{
				return create_Circle(c.p1, c.w);
			}
			case ELLIPSE:
			{
				return create_Ellipse(c.p1, c.w, c.h);
			}
			default:
			{
				throw std::runtime_error("Graph_lib_Factory::create::No object with such ID!");
			}
		}
	}
};

#endif
