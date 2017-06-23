/* 
	TITLE		   Test data format  			    Chapter26Exercise4.h
	COMMENT
		Objective: Devise a format for test data so that you can 
				   define a sequence once and run several tests against.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 31.05.2017
*/

/*
	Test data format allowing multiple test on a single sequence.

	This could be done by separating the Input Sequence from the Measurement Conditions:
		- { Test_Label Target_Value Expected_Result } - Measurement Conditions
		- { Sequence } - Input Sequence 

	File Layot could look like this: two separate files containing the tests:
		TestSequences.txt
			Input Sequence1
			Input Sequence2
			Input Sequence3

		MeasurementConditions.txt
			Measurement Conditions1a
			Measurement Conditions1b
			Measurement Conditions1c
			Measurement Conditions1d
			Measurement Conditions1e

	Then testing is consisted of applying every Measurement Condition on each Input Sequence.
*/

#ifndef Chapter26Exercise4_h
#define Chapter26Exercise4_h

template <typename T>
struct Measurement_Conditions
{
	std::string test_label;
	T target_value;
	bool expected_result;
};

//--------------------------------------------------------------------------------------

/*
	Input format: { Test_Label Target_Value Expected_Result }
		   Types:   std::string		T			bool
*/
template <typename T>
std::istream& operator>> (std::istream& is, Measurement_Conditions<T>& m)
{
	if (!is)
	{
		return is;
	}

	char op, cp;

	is >> op;

	if (op != '{')
	{
		is.setf(std::ios_base::failbit);
		return is;
	}

	if (is.peek() == '}') // empty 
	{
		return is;
	}

	std::string label;
	T value;
	bool result;

	is >> label >> value >> result >> cp;

	if (!is || cp != '}')
	{
		is.setf(std::ios_base::failbit);
		return is;
	}

	m.test_label = label;
	m.target_value = value;
	m.expected_result = result;

	return is;
}

//--------------------------------------------------------------------------------------

template <typename T>
void get_Measurement_Conditions(std::istream& is, std::vector<Measurement_Conditions<T>>& v)
{
	Measurement_Conditions<T> m;
	while (is >> m)
	{
		v.emplace_back(m);
	}
}

//--------------------------------------------------------------------------------------

/*
	Removes the characters defining the input format with whitespace to allow
	tokenization. Stores tokens sequences of type T in container v.

	Parameters:
		- std::istream: file containing lines of sequences.
		- Input format: defines string to be used in regex.
		- container to hold the lines of sequences.

    Current input format: { T , T , T, T , T }
*/
template <typename T>
void get_Input_Sequences(std::istream& is, std::vector< std::vector<T> >& v)
{
	std::string line;
	while (getline(is, line))
	{
		std::replace_if(line.begin(), line.end(),
					 [ ](const char& c) { return ((c == ',') || (c == '{') || (c == '}')); }, 
					 ' ');

		std::stringstream ss(line);  
		std::vector<T> sequence((std::istream_iterator<T>(ss)), std::istream_iterator<T>());

	    v.emplace_back(sequence);
	}
}

//--------------------------------------------------------------------------------------

template <typename T>
bool test_all(std::vector< Measurement_Conditions<T> >& conditions, std::vector< std::vector<T> >& sequences)
{
	bool success = true;
	int failed_tests = 0;
	int passed_tests = 0;
	int conducted_tests = 0;

	for (size_t i = 0; i < conditions.size(); ++i)
	{
		for (size_t j = 0; j < sequences.size(); ++j)
		{
			bool experimental_result = std::binary_search(sequences[j].begin(), sequences[j].end(), conditions[i].target_value);

			if (experimental_result != conditions[i].expected_result)
			{
				++failed_tests;
				std::cout <<"Test: "<< conditions[i].test_label <<" Expected: " << conditions[i].expected_result
						  <<" Experimental: " << experimental_result <<'\n'; 

				success = false;
			}
			else
			{
				++passed_tests;
			}

			++conducted_tests;
		}
	}

	std::cout <<"Conducted: " << conducted_tests <<" Passed: " << passed_tests <<" Failed: "<< failed_tests <<'\n';

	return success;
}

#endif