/*
	TITLE		    Correct the error   	  Chapter20TryThis4.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Find and remove the error in the code. 
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 17. 02. 2017
*/
#include <iostream>
#include <vector>

double* get_from_jack(int* count)
{
	return new double;
}

//-----------------------------------------------------------------------

std::vector<double>* get_from_jill()
{
	return new std::vector<double>();
}

//-----------------------------------------------------------------------

template <class Iterator>
Iterator high (Iterator first, Iterator last)
{
	if (!first || !last)
	{
		throw std::invalid_argument("high: null pointer argument!\n");
	}

	Iterator high = first;
	for (Iterator p = first; first != last; ++p)
	{
		if (*high < *p) 
		{
			high = p;
		}
	}
	return high;
}

//-----------------------------------------------------------------------

void fct2()
{
	int jack_count = 0;
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
	double* jill_high = nullptr;

	try
	{
		jack_high =	high(jack_data, jack_data + jack_count);
		jill_high = high(&v[0], &v[0] + v.size());
	}
	catch(std::invalid_argument& i)
	{
		throw std::runtime_error(i.what());
	}
	
	 
	if (jack_high) 
	{
		 std::cout <<" Jack's max: "<< *jack_high <<'\n';
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

//-----------------------------------------------------------------------

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