/*
	TITLE		    Jack and Jill using STL  Chapter20Exercise4.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Find and fix errors in Jack and Jill in §20.3.1
					by using STL techniques throughout.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 19. 02. 2017
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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

//-----------------------------------------------------------------------

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
		throw std::bad_alloc("get_from_jill: can't allocate vector");
	}

	double value;
	while (ifs >> value)
	{
		data->push_back(value);
	}

	return data;
}

//-----------------------------------------------------------------------

template <class Iterator>
Iterator high (Iterator first, Iterator last)
{
	return std::max_element(first, last);
}

//-----------------------------------------------------------------------

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

	if (!jill_data)												 
	{
		delete[] jack_data;
		delete jill_data;
		throw std::runtime_error("fct2: null pointer returned!\n");
	}

	std::vector<double>& v = *jill_data;		
	 
	double* jack_high = nullptr;
	std::vector<double>::iterator jill_high;

	try
	{
		jack_high =	high(jack_data, jack_data + jack_count);
		jill_high = high(v.begin(), v.end());
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

	
	if (jill_high != v.end()) 
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

//-----------------------------------------------------------------------

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