/* 
	TITLE		   Test Calculator & I/O redirection			    	Chapter26Exercise6.h
	COMMENT
		Objective: Modify the calculator from Chapter 7 minimally to let it take input from a
				   file and produce output to a file (or use your operating system's facilities
				   for redirecting I/O ). Then devise a reasonably comprehensive test for it.  
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 01.06.2017
*/


#ifndef Chapter26Exercise6_h
#define Chapter26Exercise6_h

template <typename T>
struct Measurement_Conditions
{
	std::string test_label;
	T expected_result;
};

//--------------------------------------------------------------------------------------

/*
	Input format: { Test_Label Expected_Result }
		   Types:   std::string		T
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
	T result;

	is >> label >> result >> cp;

	if (!is || cp != '}')
	{
		is.setf(std::ios_base::failbit);
		return is;
	}

	m.test_label = label;
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

void get_Input_Sequences(std::istream& is, std::vector<std::string>& v)
{
	std::string line;
	while (getline(is, line))
	{
		// consider EOF, /r, /n etc.
	    v.emplace_back(line);
	}
}

//--------------------------------------------------------------------------------------

template <typename T>
bool test_all(std::vector< Measurement_Conditions<T> >& conditions, std::vector<std::string>& sequences)
{
	bool success = true;
	int failed_tests = 0;
	int passed_tests = 0;
	int conducted_tests = 0;

	for (size_t i = 0; i < conditions.size(); ++i)
	{
		for (size_t j = 0; j < sequences.size(); ++j)
		{
			std::stringstream input_stream(sequences[i]);
			std::stringstream output_stream;

			Token_stream tss(input_stream);

			calculate(tss, output_stream, std::cerr);

			T experimental_result;
			output_stream >> experimental_result;

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