/*
	TITLE			   File I/O & Statistics    Chapter10Exercise4.h
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: 1. Populate a file with temperature readings in
					      the format (hour, temperature, unit), where
						  hour: [0, 23], temperature: [min, max],
						  unit: C - Celcius,    min = -273.15, max = 1.4e32,
						        F - Fahrenheit, min = −459.67, max = 2.5e32.
					   2. Read the file containing the temperatures, convert
					      them all into Fahrenheit and calcualte their mean
						  and median.
				Input: - 
			   Output: -
			   Author: Chris B. Kirov
			     Date: 08.04.2015
*/

// forward declarations
bool is_valid_input(int h ,double t, char u);

//-----------------------------------------------------------------------------------------------------------
/*
	Struct Reading

	A data structure 
	representing a tempereture
	measurement.
*/
struct Reading
{
	Reading()
		: hour(0), temperature(0), unit('0')
	{
	
	}

	Reading(int h, double t, char u)
		: hour(h), temperature(t), unit(u)
	{
		if (!is_valid_input(h, t, u))
		{
			throw std::invalid_argument("Reading::Invalid initialization value!\n");
		}
	}

	int hour;
	double temperature;
	char unit;
};
//-----------------------------------------------------------------------------------------------------------

// Helper functions
/*
	Function: is_valid_input(h, t, u);

	It checks whether the constructor
	is initialized with valid value.
*/
bool is_valid_input(int h, double t, char u)
{
	// 24 - hour format
	const int lower_bound = 0;
	const int upper_bound = 23;
	if (h < lower_bound || h > upper_bound)
	{
		return false;
	}

	// supported temperature units
	if (u != 'c' && u != 'f')
	{
		return false;
	}

	// temperatare value range
	if (u == 'c')
	{
		// theoretical range in Ceslius
		const double absolute_zero_celsius = -273.15;
		const double planck_temperature_celsius  = 1.4e32;
		if (t < absolute_zero_celsius || t > planck_temperature_celsius )
		{
			return false;
		}
	}
	else
	{
		// theoretical range in Fahrenheit
		const double absolute_zero_fahrenheit = -459.67;
		const double planck_temperature_fahrenheit  = 2.5e32;
		if (t < absolute_zero_fahrenheit  || t > planck_temperature_fahrenheit)
		{
			return false;
		}
	}

	return true;
}
//-----------------------------------------------------------------------------------------------------------

// Overloaded operators
/*
	operator>>

	Populates an objec Reading.
	Input format (hour, temperature, unit),
	where hour: [0, 23] and
	temperature: [-273.15, 1.4e32],
	unit 'c' or 'f'.
*/
std::istream& operator >> (std::istream& is, Reading& r)
{
	char par1, comma1, comma2, par2, unit;
	int h;
	double t;

	// extract data
	is >> par1 >> h >> comma1 >> t >> comma2 >> unit >> par2;

	// check stream state
	if (!is)
	{
		return is;
	}

	// check input validity
	if (par1 != '(' || comma1 != ',' || comma2 != ',' || par2 != ')')
	{
		is.clear(std::ios_base::failbit);
		return is;
	}

	r = Reading(h, t, unit);
	
	return is;
}
//-----------------------------------------------------------------------------------------------------------

/*
	operator<<

	Prints the data mebers
	of an object Reading.
	Output format: (hour, date, unit).
*/
std::ostream& operator<< (std::ostream& os, Reading& r)
{
	return os <<'('<< r.hour <<','<< r.temperature <<','<< r.unit <<')';
}
//-----------------------------------------------------------------------------------------------------------

// Non - member functions
/*
	Function: convert_to_fahrenheit()

	It converts the temperature of 
	object Reading from Celsius to
	Fahrenheit.
*/
void convert_to_fahrenheit(Reading& r)
{
	if (r.unit == 'c')
	{
		double fahrenheit = (r.temperature * 9./ 5.) + 32.;
		r.temperature = fahrenheit;
	}
}
//-----------------------------------------------------------------------------------------------------------

/*
	Function: void fill_vector(std::istream& is, std::vector<Reading>& v)

	It populates the vector with the file data, converting
	all the temperatures in Fahrenheit
*/
void fill_vector(std::istream& is, std::vector<Reading>& v)
{
	// read line by line
	std::string input;
	while (getline(is, input))
	{
		std::stringstream ss(input);
		Reading r;

		if (ss >> r)
		{
			if (r.unit == 'f')
			{
				v.emplace_back(r);
			}
			else
			{
				convert_to_fahrenheit(r);
				v.emplace_back(r);
			}
		}
		else
		{
			std::cerr <<"Wrong input format!\n";
		}
	}
}
//-----------------------------------------------------------------------------------------------------------

/*
	Function: vector_mean(std::vector<Reading>& r)

	It returns the mean of the temperatures  
	stored in the vector.
*/
double vector_mean(std::vector<Reading>& v)
{
	double sum = 0;
	for (size_t i = 0; i < v.size(); ++i)
	{
		sum += v[i].temperature;
	}
	return sum / v.size();
}
//-----------------------------------------------------------------------------------------------------------

/*
	Function: vector_median(std::vector<Reading>& v)

	It returns the median of the temperatures 
	stored in the vector.
*/
double vector_median(std::vector<Reading>& v)
{
	std::vector<double> temperatures;

	for (size_t i = 0; i < v.size(); ++i)
	{
		temperatures.push_back(v[i].temperature);
	}

	sort(temperatures.begin(), temperatures.end());

	if (temperatures.size() % 2 == 0)
	{
		return (temperatures[temperatures.size() / 2 - 1] + temperatures[temperatures.size() / 2]) / 2;
	}
	else
	{
		return temperatures[temperatures.size() / 2];
	}
}

//-----------------------------------------------------------------------------------------------------------

/*
	Funtion: random();
	 
	It generates a random
	number in the range [min, max).
*/
int random(int min, int max)
{
	static bool first = true;
	if (first)
	{
		srand((unsigned int) time(NULL));   
		first = false;
	}
	return min + rand() % (max - min);
}
//-----------------------------------------------------------------------------------------------------------

/*
	Function: populate_file(file_name);
	 
	It creates a file: 
	and populates it with 50 random 
	temperature values in the interval 
	[-230,200), in Celsius or Fahrenheit.
	Output format: (hours, temperatures, unit).
*/
void populate_file(std::string& file_name)
{
	std::ofstream ofs(file_name.c_str());

	if(!ofs)
	{
		std::cerr <<"Can't open output file: " << file_name <<"\n";
	}

	for (int i = 0; i < 50; ++i)
	{
		char unit = (i % 2 == 0) ? 'f' : 'c';

		ofs <<'('<< random(0, 24) <<','<< random(-230, 200) <<','<< unit <<')'<<'\n';   
	}
}