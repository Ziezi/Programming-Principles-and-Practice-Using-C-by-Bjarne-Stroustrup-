/* 
	TITLE		   Input formatting				Chapter5Exercise14.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Read pairs of <Day of week> <int value>,
				   and store the valid values.
			Input: Name of day of the week, 
			       followed by single space and integer value.
		   Output: Print all input values and their sum.
		   Author: Chris B. Kirov
		     Date: 5. 1 . 2015
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void populate_2Dvector(std::vector< std::vector<int> >&);
void print_2Dvector(const std::vector< std::vector<int> >&);
void sum_2Dvector_elements(const std::vector< std::vector<int> >&);
bool isValidDay(const std::string&);
int dayToInt(const std::string&);

//=====================================================================
int main()
{	
	// a 2D structure representing Day of the Week and values corresponding to it
	std::vector< std::vector<int> > values(7);

	populate_2Dvector(values);

	print_2Dvector(values);

	sum_2Dvector_elements(values); 

	getchar();
	getchar();
}
//=====================================================================

/*
	Function: populate_vector()
	Use: populate_vector(int_vect);

	It prompts the used to input
	string - int pairs, where if
	the string is a day of the week
	its integer value is stored in 
	the vector passed as parameter.

	Handles wrong types and wrong
	days by dispalaying an error
	message and ignoring the value,
	while continuing the input loop.
*/
void populate_2Dvector(std::vector< std::vector<int> >& values)
{
	int number_of_rejected_input = 0;

	// input loop
	std::string prompt = "Please enter day followed by integer number; \"end\" to exit:\n>>";
	std::string sentinel = "end";
	while (true)
	{
		// read input
		std::cout << prompt;
		std::string input;	
		getline(std::cin, input);

		// quit ?
		if (input == sentinel)
		{
			break;
		}

		// extract input
		std::stringstream ss(input);
		std::string day;
		int value;
		if (ss >> day >> value)
		{
			if (isValidDay(day))
			{
				// add value to the right day of the week
				int index = dayToInt(day); 
				values[index].push_back(value);
			}
			else // check day value validity
			{
				++number_of_rejected_input;
				std::cerr <<"There is no such day: "<< day <<" !\n";
			}
		}
		else // check type validity
		{
			std::cerr <<"Wrong input type!\n";
		}
	}
	std::cout <<"Number of rejected input: "<< number_of_rejected_input <<"\n";
}

//---------------------------------------------------------------------
/*
	Function: print_vector()
	Use: print_vector(vect_of_vect_of_int);

	It prints a 2D int vector, where
	each vector contents are on a new
	line.
*/
void print_2Dvector(const std::vector< std::vector<int> >& v)
{
	std::string week_days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		std::cout <<"The "<< week_days[i] <<" values are:\n";
		for (unsigned int j = 0; j < v[i].size(); ++j)
		{
			std::cout << v[i][j] <<", ";
		} 
		std::cout <<"\n";
	}
	std::cout <<'\n';
}

//---------------------------------------------------------------------
/*
	Function: sum_vector_elements()
	Use: sum_vector_elements(vect_int, first_n);
	It sums and prints the first_n elemenents
	of the vector passed by reference.
*/
void sum_2Dvector_elements(const std::vector< std::vector<int> >& v)
{
	 // calculate sums
	 std::vector<int> sums;
	 for (size_t i = 0; i < v.size(); ++i)
	 {
		int sum = 0;
		for (size_t j = 0; j < v[i].size(); ++j)
		{
			sum += v[i][j];
		}
		sums.push_back(sum);
	 }

	// print sums
	std::string week_days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	std::cout <<"The sums of values of each day are:\n";
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << week_days[i] <<" : "<< sums[i] <<"\n";
	}
}

//---------------------------------------------------------------------
/*
	Function: isValidDay()
	Use: bool valid = isValidDay(day_val);

	Check whether the input string parameter's
	value mathces any of the days of the week,
	if so returns true.
*/
bool isValidDay(const std::string& v)
{
	std::vector<std::string> valid_days(14);

		valid_days[0] = "Monday";
		valid_days[1] = "monday";

		valid_days[2] = "Tuesday";
		valid_days[3] = "tuesday";

		valid_days[4] = "Wednesday";
		valid_days[5] = "wednesday";

		valid_days[6] = "Thursday";
		valid_days[7] = "thursday";

		valid_days[8] = "Friday";
		valid_days[9] = "friday";

		valid_days[10] = "Saturday";
		valid_days[11] = "saturday";

		valid_days[12] = "Sunday";
		valid_days[13] = "sunday";

	for (unsigned int i = 0; i < valid_days.size(); ++i)
	{
		if (v == valid_days[i])
		{
			return true;
		}
	}
	std::cout <<"Not found: "<< v <<"\n";
	return false;
}

//---------------------------------------------------------------------
/*
	Function: dayToInt()
	Use: int val = dayToInt(const std::string&);

	It returns an integer corresponding to the
	number of the day passed as parameter, 
	starting from 0 - Monday to 6 - Sunday.

*/
int dayToInt(const std::string& v)
{
	std::vector<std::string> valid_days_lower(7);
	valid_days_lower[0] = "monday";
	valid_days_lower[1] = "tuesday";
	valid_days_lower[2] = "wednesday";
	valid_days_lower[3] = "thursday";
	valid_days_lower[4] = "friday";
	valid_days_lower[5] = "saturday";
	valid_days_lower[6] = "sunday";

	std::vector<std::string> valid_days_upper(7);
	valid_days_upper[0] = "Monday";
	valid_days_upper[1] = "Tuesday";
	valid_days_upper[2] = "Wednesday";
	valid_days_upper[3] = "Thursday";
	valid_days_upper[4] = "Friday";
	valid_days_upper[5] = "Saturday";
	valid_days_upper[6] = "Sunday";

	for (size_t i = 0; i < valid_days_lower.size(); ++i)
	{
		if (v == valid_days_lower[i])
		{
			return i;
		}
	}

	for (size_t i = 0; i < valid_days_upper.size(); ++i)
	{
		if (v == valid_days_upper[i])
		{
			return i;
		}
	}

	std::cerr <<"Can't convert day to integer!\n";
	return -1;
}