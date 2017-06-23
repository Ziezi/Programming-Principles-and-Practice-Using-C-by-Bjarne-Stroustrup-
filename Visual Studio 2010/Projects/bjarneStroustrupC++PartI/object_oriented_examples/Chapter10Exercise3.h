/*
	TITLE			   Read file & calculate statistics     Chapter10Exercise3.h
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Write a function that reads a file containing
					   data in the format (hour, temp) and calculates
					   mean and median temperatures.
				Input: - 
			   Output: -
			   Author: Chris B. Kirov
			     Date: 08.04.2015
*/

bool is_valid_input(int h ,double t);

struct Reading
{
	Reading()
		: hour(0), temperature(0)
	{
	
	}

	Reading(int h, double t)
		: hour(h), temperature(t)
	{
		if (!is_valid_input(h, t))
		{
			throw std::invalid_argument("Reading::Invalid initialization value!\n");
		}
	}

	int hour;
	double temperature;
};
//-----------------------------------------------------------------------------------------------------------

// Overloaded operators
/*
	operator>>

	Populates an objec Reading.
	Input format (hour, temperature),
	where hour: [0, 23] and
	temperature: [-273.15, 1.4e32].
*/
std::istream& operator >> (std::istream& is, Reading& r)
{
	char par1, comma, par2;
	int h;
	double t;

	// extract data
	is >> par1 >> h >> comma >> t >> par2;

	// check stream state
	if (!is)
	{
		return is;
	}

	// check input validity
	if (par1 != '(' || comma != ',' || par2 != ')')
	{
		is.clear(std::ios_base::failbit);
		return is;
	}

	r = Reading(h, t);
	
	return is;
}
//-----------------------------------------------------------------------------------------------------------

/*
	operator<<

	Prints the data mebers
	of an object Reading.
	Output format: (hour, date).
*/
std::ostream& operator<< (std::ostream& os, Reading& r)
{
	return os <<'('<< r.hour <<','<< r.temperature <<')';
}
//-----------------------------------------------------------------------------------------------------------
// Helper functions
/*
	Function: is_valid_input(h, t);

	It checks whether the constructor
	is initialized with valid value.
*/
bool is_valid_input(int h, double t)
{
	// 24 - hour format
	const int lower_bound = 0;
	const int upper_bound = 23;
	if (h < lower_bound || h > upper_bound)
	{
		return false;
	}

	// theoretical range in Ceslius
	const double absolute_zero = -273.15;
	const double planck_temperature = 1.4e32;
	if (t < absolute_zero || t > planck_temperature)
	{
		return false;
	}

	return true;
}
//-----------------------------------------------------------------------------------------------------------

/*
	Function: void fill_vector(std::istream& is, std::vector<Reading>& v)


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
			v.emplace_back(r);
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
