/*
	TITLE		    Improving "ugly" code	  Chapter20TryThis1.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: If you were able how would you change Jill's code
				    to get rid of the ugliness?
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 17. 02. 2017
*/
#include <iostream>
#include <vector>

double* get_from_jack(int* count);								// read from array
std::vector<double>* get_from_jill();							// read from vector

// First attempt
void fct()
{
	int jack_count = 0;
	double* jack_data =	get_from_jack(&jack_count);
	std::vector<double>* jill_data = get_from_jill();
	std::vector<double>& v = *jill_data;						// introduce a reference to eliminate ptr dereference in the code

	// process
	double h = -1;
	double* jack_high;
	double* jill_high;

	for (int i = 0; i < jack_count; ++i)
	{
		if (h < jack_data[i])
		{
			jack_high = &jack_data[i];
		}
	}

	h = -1;
	for (int i = 0; i < v.size(); ++i)
	{
		if (h < v[i])
		{
			jill_high = &v[i];
		}
	}

	std::cout <<"Jill's max: " << *jill_high <<" Jack's max: "<< *jack_high;

	delete[] jack_data;
	delete jill_data;
}

//---------------------------------------------------------------------------------------------------------------------------

// Second attempt
double* high (double* first, double* last)
{
	double h = -1;
	double* high;

	for (double* p = first; p != last; ++p)
	{
		if (h < *p)
		{
			high = p;
		}
	}
	return high;
}

//---------------------------------------------------------------------------------------------------------------------------

void fct2()
{
	int jack_count = 0;
	double* jack_data =	get_from_jack(&jack_count);
	std::vector<double>* jill_data = get_from_jill();
	std::vector<double>& v = *jill_data;		

	double* jack_high = high(jack_data, jack_data + jack_count);
	double* jill_high = high(&v[0], &v[0] + v.size());

	std::cout <<"Jill's max: " << *jill_high <<" Jack's max: "<< *jack_high;

	delete[] jack_data;
	delete jill_data;
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
	try 
	{
		 
	} 
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}