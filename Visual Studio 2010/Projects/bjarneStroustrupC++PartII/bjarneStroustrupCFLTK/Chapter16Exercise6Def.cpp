/*
	TITLE		   Analog clock     		   Chapter16Exercise6Def.cpp
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

Analog_clock::Analog_clock (Point o, std::string& t)
	: Window(o, 520, 520, t),
	clock_dial(Point(0, 0), "Chapter16Exercise6.gif", Graph_lib::Suffix::Encoding::gif),
	hour_indicator(nullptr),
	minute_indicator(nullptr),
	second_indicator(nullptr)
{
	attach(clock_dial);

	get_time();
	
	set_indicators();

	run_clock();
}

// member methods
void Analog_clock::get_time() 
{
	// get current time
	time_t now = time(0); 
	tm* local_time;
	local_time = localtime(&now); 

	// initialize data members
	sec = local_time->tm_sec;
	min = local_time->tm_min;
	hour = (local_time->tm_hour) % 12;

	std::cout <<"Time: "<< hour <<":"<< min <<":"<< sec <<'\n';
}

// callback
/*
	Funcion: cb_timer()

	A callback function that
	recursively calls: increment_time()
	and then itself, after pause of one 
	second.
*/
void Analog_clock::cb_timer(Address pw)
{
	reference_to<Analog_clock>(pw).increment_time();
	Fl::repeat_timeout(1, cb_timer, pw);
}

// action
/*
	Function: increment_time()

	It successively increments data members
	representing: seconds, minutes and hours.

	Calls: set_indicators() to redraw the
	hands of the analog clock in accordance
	with the incremented values.
*/
void Analog_clock::increment_time()
{
	// increment time
	++sec;
    if (sec == 60)
	{
        ++min;
        sec = 0;
        if (min == 60)
		{
            ++hour;
            min = 0;
            if (hour == 12)
			{
                hour = 0;
            }
        }
    }

	set_indicators();
}

// helper
void Analog_clock::set_time(int h, int m, int s)
{
	if ((h <= 0 || h > 12) || (m <= 0 || m > 60) || (s <= 0 || s > 60))
	{
		throw std::invalid_argument("Analog_clock::set_time: Invalid time values!");
	}

	hour = h;
	min = m;
	sec = s;
}

/*
	Funcion: run_clock()

	Wrapper function containing
	a one - shot timeout callback,
	i.e. it calls the callback function:
	cb_timer, after 1 second pause.
*/
void Analog_clock::run_clock()
{
	Fl::add_timeout(1, cb_timer, this);
}

void Analog_clock::set_indicators()
{
	// included for the constructor initialization
	if (hour_indicator != nullptr && minute_indicator != nullptr && second_indicator != nullptr)
	{
		detach(*hour_indicator);
		detach(*minute_indicator);
		detach(*second_indicator);

		delete hour_indicator;
		delete minute_indicator;
		delete second_indicator;
	}

	Point clock_center (x_max () / 2. - 2, y_max () / 2.);

    // set seconds
    const int second_indicator_length = 150;
    Point twelve_o_clock_s (x_max () / 2. - 2,  y_max () / 2. - second_indicator_length);

	double angle = sec * ((6.) * M_PI) / 180.;
	Point current_s = rotate(twelve_o_clock_s, clock_center, angle);
    second_indicator = new Line (clock_center, current_s); 
    second_indicator->set_style (Line_style (Line_style::solid, 2));
    second_indicator->set_color (Color::red);

    // set minutes
    const int minute_indicator_length = 150;
    Point twelve_o_clock_m (x_max () / 2. - 2,  y_max() / 2. - minute_indicator_length);

	angle = min * ((6.) * M_PI) / 180.;
	Point current_m = rotate(twelve_o_clock_m, clock_center, angle);
    minute_indicator = new Line (clock_center, current_m);
    minute_indicator->set_style (Line_style (Line_style::solid, 8));
	minute_indicator->set_color (Color::black);

    // set hours
    const int hour_indicator_length = 75;
    Point twelve_o_clock (x_max () / 2. - 2,  y_max () / 2. - hour_indicator_length);

	angle = hour * ((30.) * M_PI) / 180.;
	Point current_h = rotate(twelve_o_clock, clock_center, angle);
    hour_indicator = new Line (clock_center, current_h);
    hour_indicator->set_style (Line_style (Line_style::solid, 8));
	hour_indicator->set_color (Color::black);

    // attach in the right order
    attach (*minute_indicator);
    attach (*hour_indicator);
    attach (*second_indicator);

	// plot updated lines
	redraw();
}

Point Analog_clock::rotate(Point initial, Point pivot, double angle)
{
	return Point((cos(angle) * (initial.x - pivot.x)) - (sin(angle) * (initial.y - pivot.y)) + pivot.x,
                 (sin(angle) * (initial.x - pivot.x)) + (cos(angle) * (initial.y - pivot.y)) + pivot.y);
}
