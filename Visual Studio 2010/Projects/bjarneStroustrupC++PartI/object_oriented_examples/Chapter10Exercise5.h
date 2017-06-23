/*
	TITLE			   Function print_year            Chapter10Exercise5.h
		Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Implement function print_year() from §1O.11.2. 
				Input: - 
			   Output: -
			   Author: Chris B. Kirov
			     Date: 08.04.2015
*/

// values signifying uninitialized variables
const int not_a_reading = -7777;
const int not_a_day = -1;
const int not_a_month = -1;

//====================================================================================================

/*
	Struct Day

	Data structure repsresenting 
	an 24 - hour astronomical day
	with its temperature. 
*/ 
struct Day
{
	Day()
		: day(not_a_day), hour(24) 
	{
		for(size_t i = 0; i < hour.size(); ++i) 
		{
			hour[i] = not_a_reading;
		}
	}

	int day;

	// each index is an hour and each value a temperature
	std::vector<double> hour;
};
//====================================================================================================

/*
	Struct Month

	Data structure repsresenting
	an 32 - day astronomical month.
*/ 
struct Month
{
	Month()
		: month(not_a_month), day(32) 
	{

	}

	int month;

	// index is a day
	std::vector<Day> day;
};
//====================================================================================================

/*
	Struct Year

	Data structure repsresenting
	an 12 - month astronomical year.
*/ 
struct Year
{
	Year()
		: month(12) 
	{
	
	}

	int year;

	// index is a month
	std::vector<Month> month;
};
//====================================================================================================

/*
	Struct Reading

	Data structure repsresenting
	temperature reading at specific
	day and hour.
*/
struct Reading
{
	int day;		    // acts like index in struct Month: day, std::vector data member.
	int hour;			// acts like index in struct Day: hour, std::vector data member.
	double temperature; // holds the temperature value saved in Year -> Month -> Day -> Hour : temp.
};
//====================================================================================================

// Helper functions
/*
	Function: init_input_tbl();
	 
*/
void init_input_tbl(std::vector<std::string>& tbl)
{
	tbl.push_back("jan");
	tbl.push_back("feb");
	tbl.push_back("mar");
	tbl.push_back("apr");
	tbl.push_back("may");
	tbl.push_back("jun");
	tbl.push_back("jul");
	tbl.push_back("aug");
	tbl.push_back("sep");
	tbl.push_back("oct");
	tbl.push_back("nov");
	tbl.push_back("dec");
}

std::vector<std::string> month_input_tb;  
//----------------------------------------------------------------------------------------------------

/*
	Function: month_to_int()
	 
    It converts a Month from
	string to integer representation.
*/
int month_to_int (const std::string& s)
{
	for(size_t i = 0; i < 12; ++i)
	{
		if(month_input_tb[i] == s)
		{
			return i;
		}
	}
	return -1;
}
//----------------------------------------------------------------------------------------------------

/*
	Function: init_print_tbl();
	 
*/
void init_print_tbl(std::vector<std::string>& tbl)
{
	tbl.push_back("jan");
	tbl.push_back("feb");
	tbl.push_back("mar");
	tbl.push_back("apr");
	tbl.push_back("may");
	tbl.push_back("jun");
	tbl.push_back("jul");
	tbl.push_back("aug");
	tbl.push_back("sep");
	tbl.push_back("oct");
	tbl.push_back("nov");
	tbl.push_back("dec");
}

std::vector<std::string> month_print_table;
//----------------------------------------------------------------------------------------------------

/*
	Function: int_to_month(int it)
	 
    It converts a Month from
	integer to string representation.
*/
std::string int_to_month(int i)
{
	 if (i < 0 && i > 11)
	 {
		std::cerr <<"Bad month index!\n";
	 }
	 return month_print_table[i];
}
//----------------------------------------------------------------------------------------------------

/*
	Function: is_valid();
	 
	It checks the input validity 
	of data members
	of object Reading.
*/
bool is_valid(const Reading& r)
{
	const int implausible_min = -200;
	const int implausible_max =  200;

	if (r.day < 1 || r.day > 31) 
	{
		return false;
	}

	if (r.hour < 0 || r.hour > 23) 
	{
		return false;
	}

	if(r.temperature < implausible_min || r.temperature > implausible_max) 
	{
		return false;
	}

	return true;
}
//----------------------------------------------------------------------------------------------------

/*
	Function: end_of_loop();
	 
	It detects end of input loop 
	and / or checks whether the input is a 
	valid sentinel.
*/
void end_of_loop(std::istream& is, char term, const std::string& message)
{
	if(is.fail())
	{
		is.clear();
		char ch;

		if(is >> ch || ch == term)
		{
			return;
		}
		std::cerr << message <<'\n';
	}
}
//====================================================================================================

// Overloaded operators
/*
	operator>>
	 
    It populates the data members 
	of an object Reading, i.e:
	day, hour, temperature.

	Input format: ( dd hh tt )
*/
std::istream& operator>> (std::istream& is, Reading& r)
{
	char ch1;

	if(is >> ch1 && ch1 != '(')
	{
		is.unget();
		is.clear(std::ios_base::failbit);
		return is;
	}

	char ch2;
	int d;
	int h;
	double t;

	is >> d >> h >> t >> ch2;

	end_of_loop(is, ')', "bad reading!\n");

	r.day = d;
	r.hour = h;
	r.temperature = t;

	return is;
}
//----------------------------------------------------------------------------------------------------

/*
	operator>>
	
	It populates the data members of
	an object Month, i.e month marker,
	month name and a Reading object.

	Input format: { month mmm ( dd hh tt ) }
*/
std::istream& operator>> (std::istream& is, Month& m)
{
	char ch = 0;
	is >> ch;

	if(ch != '{')
	{
		is.unget();
		is.clear(std::ios_base::failbit);
		return is;
	}

	std::string month_marker;
	std::string mm;

	is >> month_marker >> mm;

	if(!is || month_marker != "month") 
	{
		std::cerr <<"bad reading!\n";
	}

	// indicate this month contains at least one day with reading
	m.month = month_to_int(mm);

	int duplicates = 0;
	int invalids = 0;

	// extract temperature reading
	Reading r;
	while(is >> r)
	{
		// check reading value validity
		if(is_valid(r))
		{
			// check if there is an already existent reading at that date
			if(m.day[r.day].hour[r.hour] != not_a_reading)
			{
				++duplicates;
			}

			// indicate this day contains at least one hour with reading
			m.day[r.day].day = r.day;

			// Store the reading at specific day and hour, where the first two Reading 
			// data members are used as indexes to access the date and time of measurement. 
			m.day[r.day].hour[r.hour] = r.temperature;
		}
		else
		{
			++invalids;
		}
	}

	if(invalids)
	{
		std::cerr <<"invalid readings in month: "<< invalids <<"\n";
	}

	if(duplicates) 
	{
		std::cerr <<"duplicate readings in month: "<< duplicates <<"\n";
	}

	end_of_loop(is, '}', "bad end of month");

	return is;
}
//----------------------------------------------------------------------------------------------------

/*
	operator>>
	 
	It populates class Year object. 
	Input format: {year YYYY, month mmm}.
*/
std::istream& operator>> (std::istream& is, Year& y)
{
	char ch;
	is >> ch;

	if(ch != '{')
	{
		is.unget();
		is.clear(std::ios_base::failbit);
		return is;
	}

	std::string year_marker;
	int year;

	is >> year_marker >> year;

	if(!is || year_marker != "year")
	{
		std::cerr <<"bad start of year!\n";
	}

	// assign a value to the year
	y.year = year;

	Month m;
	while(is >> m)
	{
		// Shallow copy ???!!!
		y.month[m.month] = m;

		// reinitialize to default to avoid accumulating readings from previous months
		m = Month(); 
	}

	end_of_loop(is, '}', "bad year ending.");

	return is;
}
//----------------------------------------------------------------------------------------------------
/*
	operator<<

	It prints the data members
	of object Day, i.e. hour and 
	temperature.
	Output format: ( HH TT )
*/
std::ostream& operator<< (std::ostream& os, const Day& d)
{
	for (size_t i = 0; i < d.hour.size(); ++i)
	{
		// print only the elements with initialized value
		if (d.hour[i] != not_a_reading)
		{
			//   hour " " temperature
			os << i <<" "<< d.hour[i];

			// put a space between consecutive hour-temperature values in one days
			if (i < d.hour.size() - 1)
			{
				os <<" "; 
			}
		}
	}
	return os;
}
//----------------------------------------------------------------------------------------------------
/*
	operator<<

	It prints the data members
	of object Month, i.e. the name
	of the month, all its days, 
	all hours with initialized temperatures

	Output format: { month MMM ( HH1 TT1 HH2 TT2 ...) ( HH TT ... ) ( HH TT ... )... }
*/
std::ostream& operator<< (std::ostream& os, const Month& m)
{
	for (size_t i = 0; i < m.day.size(); ++i)
	{
		// print only days that have readings
		if (m.day[i].day != not_a_day)
		{
			//         day  " " all hours and temperatures
			os <<" ("<< i <<" "<< m.day[i] <<") ";
		}
	}
	return os;
}
//----------------------------------------------------------------------------------------------------
/*
	operator<<

	It prints the data members
	of object Year, i.e. year,
	all its months, all days in the months that
	have hours with initialized temperatures.

	Output format: { year YYYY { month MMM1 ( HH1 TT1 HH2 TT2 ...) ( HH TT ... ) ( HH TT ... )... }...
	                        ...{ month MMMN ( HH1 TT1 HH2 TT2 ...) ( HH TT ... ) ( HH TT ... )... } }
*/
std::ostream& operator<< (std::ostream& os, const Year& y)
{
	os <<"{ year "<< y.year;
	for	(size_t i = 0; i < y.month.size(); ++i)
	{
		// print only months that contain days with readings
		if (y.month[i].month != not_a_month)
		{
			os <<" { month "<< int_to_month(y.month[i].month);
			os << y.month[i];
			os <<" } ";
		}
	}
	os <<" }";
	return os;
}
//----------------------------------------------------------------------------------------------------


/*
	Function: print_year();
	 
	It prints all the elements 
	of the vector elements.

	Output format:

	Output format: { year YYYY1 { month MMM1 ( HH1 TT1 HH2 TT2 ...) ( HH TT ... ) ( HH TT ... )... }...
	                         ...{ month MMMN ( HH1 TT1 HH2 TT2 ...) ( HH TT ... ) ( HH TT ... )... } }

				   { year YYYY2 { month MMM1 ( HH1 TT1 HH2 TT2 ...) ( HH TT ... ) ( HH TT ... )... }...
	                         ...{ month MMMN ( HH1 TT1 HH2 TT2 ...) ( HH TT ... ) ( HH TT ... )... } }
*/
void print_year(std::ostream& os, std::vector<Year>& y)
{
	 for (size_t i = 0; i < y.size(); ++i)
	 {
		os << y[i] <<"\n";
	 }
}