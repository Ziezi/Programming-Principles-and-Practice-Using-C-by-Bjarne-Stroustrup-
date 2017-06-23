/*
	TITLE			Redo Jack and Jill       Chapter20Exercise3.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Look the palindrome example from §18.6; redo the 
				    Jack and Jill example from §20.1.2 using that
					variety of techniques.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 18. 02. 2017
*/
#include <iostream>
#include <fstream>
#include <vector>

double* get_from_jack(int* count)
{
	std::string file_name("Chapter20Exercise2.txt");
	std::ifstream ifs(file_name.c_str());

	if (!ifs)
	{
		throw std::runtime_error("get_from_jack: can't open input stream.");
	}

	const int size = *count; 
	double* data = new double [size];
	int index = 0;

	if (!data)
	{
		throw std::bad_alloc("get_from_jack: can't allocate array");
	}

	double value;
	while (index < size && ifs >> value)
	{
		data[index] = value;
		++index;
	}

	return data;
}

//---------------------------------------------------------------------------------------------------------------------------

std::vector<double>* get_from_jill()
{
	std::string file_name("Chapter20Exercise2.txt");
	std::ifstream ifs(file_name.c_str());

	if (!ifs)
	{
		throw std::runtime_error("get_from_jill: can't open input stream.");
	}

	std::vector<double> *data = new std::vector<double>;

	if (!data)
	{
		throw std::bad_alloc("get_from_jill: can't allocate array");
	}

	double value;
	while (ifs >> value)
	{
		data->push_back(value);
	}

	return data;
}

//---------------------------------------------------------------------------------------------------------------------------

/* Initial implementation */
double* high (double* first, double* last)
{
	if (!first || !last)										   
	{
		throw std::invalid_argument("high: null pointer argument!\n");
	}
	
	double* high = first;										 
	for (double* p = first; p != last; ++p)
	{
		if (*high < *p)
		{
			high = p;
		}
	}
	return high;
}

//---------------------------------------------------------------------------------------------------------------------------

/* Iterative implementation */
double* high2 (double* first, double* last)
{
	if (!first || !last)										   
	{
		throw std::invalid_argument("high: null pointer argument!\n");
	}
	
	double* high = first;	
	while (first != last)
	{
		if (*high < *first)
		{
			high = first;
		}

		++first;
	}

	return high;
}

//---------------------------------------------------------------------------------------------------------------------------

/* Rerursive implementation */
double* high3 (double* first, double* last)
{
	if (!first || !last)										   
	{
		throw std::invalid_argument("high: null pointer argument!\n");
	}
	
	double* high = first;		
	if ( first == last)
	{
		return high;
	}
	else
	{
		high = std::max(last, high3(first, --last));
	}
	 
	return high;
}

//---------------------------------------------------------------------------------------------------------------------------

void fct2()
{
	int jack_count = 10;
	double* jack_data =	get_from_jack(&jack_count);

	if(!jack_data)												 
	{
		delete[] jack_data;
		throw std::runtime_error("fct2: null pointer returned!\n");
	}

	std::vector<double>* jill_data = get_from_jill();

	if(!jill_data)												 
	{
		delete[] jack_data;
		delete jill_data;
		throw std::runtime_error("fct2: null pointer returned!\n");
	}

	std::vector<double>& v = *jill_data;		
	 
	double* jack_high = nullptr;
	double* jill_high = nullptr;

	try
	{
		jack_high =	high3(jack_data, jack_data + jack_count);   // <------- high(), high2(), high()3 Function testing
		jill_high = high3(&v[0], &v[0] + v.size());				// <------- high(), high2(), high()3 Function testing
	}		
	catch(std::invalid_argument& i)
	{
		throw std::runtime_error(i.what());
	}
	
	 
	if (jack_high) 
	{
		 std::cout <<"Jack's max: "<< *jack_high <<'\n';
	}
	else
	{
		std::cout <<"Jack data: No max found!\n";
	}

	if (jill_high) 
	{
		std::cout <<"Jill's max: " << *jill_high <<'\n';
	}
	else
	{
		std::cout <<"Jill data: No max found!\n";
	}

	delete[] jack_data;
	delete jill_data;
}

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
	try 
	{
		fct2();
	}
	catch (std::bad_alloc& b) 
	{
		std::cerr << b.what();
	}
	catch (std::runtime_error& r) 
	{
		std::cerr << r.what();
	}
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}