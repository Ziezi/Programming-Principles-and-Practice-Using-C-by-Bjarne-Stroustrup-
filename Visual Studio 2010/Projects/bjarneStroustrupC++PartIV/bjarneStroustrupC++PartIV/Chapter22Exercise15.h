/*
	TITLE		   Programming Language Chronology		Chapter22Exercise15.h
	COMMENT
		Objective: Write a program that given a file with (name, year) pairs, such
				   as (Algol, 1960) and (C, 1974), graphs the names on a timeline
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 06.04.2017

*/
#ifndef Chapter22Exercise15_h
#define Chapter22Exercise15_h

/* Class representing a programming language and its year of invention. */
class LanguageInfo
{
public:
	LanguageInfo() : name(), year() { }

	LanguageInfo(const std::string n, int y) : name(n), year(y) { }

	LanguageInfo(const LanguageInfo& src) : name(src.name), year(src.year) { }

	LanguageInfo& operator= (const LanguageInfo& src)
	{
		LanguageInfo temp(src);
		swap(temp);

		return *this;
	}

	void swap(LanguageInfo& src)
	{
		std::swap(year, src.year);
		std::swap(name, src.name);
	}

	std::string name;
	int year;
};

//----------------------------------------------------------------------------------------

void swap (LanguageInfo& lhs, LanguageInfo& rhs)
{
	lhs.swap(rhs);
}

//----------------------------------------------------------------------------------------

/* Input format: (name , year) */
std::istream& operator>> (std::istream& is, LanguageInfo& dest)
{
	if (!is)
	{
		return is;
	}

	char par1, comma, par2;
	std::string n; // language name
	int y;		   // year of invention

	if (is >> par1 >> n >> comma >> y >> par2)
	{
		if (par1 != '(' || comma != ',' || par2 != ')')
		{
			is.setf(std::ios_base::failbit);
			return is;
		}
		else
		{
			dest = LanguageInfo(n, y);
		}
	}
	else
	{
		is.setf(std::ios_base::failbit);
		return is;
	}
	return is;
}

//----------------------------------------------------------------------------------------

/* Class representing graphically the timeline of programming language inventions. */
class ProgrammingTimeline: Window
{
public:
	ProgrammingTimeline()
		: Window(Point(200, 200), 700, 700, "Language Chronology"),
		quit_button(Point(x_max() - 80, 10), 70, 20, "Quit" , cb_quit),
		timeline(nullptr)
	{
		read_file();
		make_graph();

		attach(*timeline);
		for (auto it = languages.begin(); it != languages.end(); ++it) attach(**it);

		attach(quit_button);
	}

private:
	// controls
	Graph_lib::Button quit_button;

	// callbacks
	static void cb_quit(Address, Address pw) { reference_to<ProgrammingTimeline>(pw).quit_pressed(); }

	// actions
	void quit_pressed() { hide(); }

	// helpers
	void read_file();
	void make_graph();

	int find_min();
	int find_max();
	int find_unique_points();
	
	// data from file
	std::multimap<int, std::string> data;

	// graphical data
	Graph_lib::Axis* timeline;
	std::vector<Graph_lib::Text*> languages;
};

//----------------------------------------------------------------------------------------

void ProgrammingTimeline::read_file()
{
	std::fstream ifs("Chapter22Exercise15.txt");

	if (!ifs) 
	{
		throw std::runtime_error("Can not open input file!");
	}

	LanguageInfo l;
	while (ifs >> l)
	{
		data.insert(std::make_pair(l.year, l.name));
	} 
}

//----------------------------------------------------------------------------------------

void ProgrammingTimeline::make_graph()
{
	const int xoffset = 50;
	const int yoffset = xoffset;
	const int xlength = 600 - 2 * xoffset;

	const int start_year = find_min();
	const int end_year = find_max();
	const int notches = (end_year - start_year) / 5.; // notch every 5 years from 1956 to 2000

	Point origin(xoffset, yoffset);

	// draw horizontal time axis
	timeline = new Graph_lib::Axis(Graph_lib::Axis::Orientation::x, origin, xlength, notches,"Time[years]");
	timeline->label.move(300, 0);

	// draw language_name, year points in order
	int xtranslation = 0;
	const int ytranslation = 20;

	for (auto it = data.begin(); it != data.end(); ++it)
	{
		// message of Text
		std::stringstream ss;
		ss << "(" << it->first <<","<< it->second << ")";

		// current coordinate is either origin or last coordinate + translation
		Point p = (languages.size() == 0) ? origin : languages[languages.size() - 1]->point(0);
		
		xtranslation = (it->first - data.begin()->first);
		p = Point(p.x + xtranslation, p.y + ytranslation);	

		Graph_lib::Text* t = new Graph_lib::Text(p, ss.str());
		t->set_font_size(14);
		t->set_color(rand() % 256 + 1);

		// store a Text
		languages.emplace_back(t);
	}
}

//----------------------------------------------------------------------------------------

int ProgrammingTimeline::find_min()
{
	std::multimap<int, std::string>::iterator it = data.begin();
	return it->first;
}

//----------------------------------------------------------------------------------------

int ProgrammingTimeline::find_max()
{
	std::multimap<int, std::string>::reverse_iterator it = data.rbegin();
	return it->first;
}

//----------------------------------------------------------------------------------------

int ProgrammingTimeline::find_unique_points()
{
	int unique_keys = 0;
	for (auto it = data.begin(); it != data.end(); it = data.upper_bound(it->first))
	{
		++unique_keys;
	}
	return unique_keys ;
}

#endif