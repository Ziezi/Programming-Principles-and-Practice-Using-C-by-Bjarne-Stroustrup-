/*
	TITLE			Accumulate			      Chapter21TryThis3.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define a vector<Record>, initialize it with four
					records of your choice, and compute their total
					price using the function in §21.5.2
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 25. 02. 2017
*/
#include <iostream>
#include <vector>
#include <numeric>

struct Record
{
	Record(double p, int u)
		: unit_price(p), units(u)
	{
	
	}

	double unit_price;
	int units;
};

//--------------------------------------------------------------------

double price (double v, const Record& r)
{
	return v + r.unit_price * r.units;
}

//--------------------------------------------------------------------

double total_price (const std::vector<Record>& r)
{
	double total = 0.0;
	total =  std::accumulate(r.begin(), r.end(), total, price);
	return  total;
}

//--------------------------------------------------------------------

int main()
{
	try
	{
		std::vector<Record> v;
		v.push_back(Record(19.5, 20));
		v.push_back(Record(10.3, 62));
		v.push_back(Record(1.5, 128));

		std::cout <<"Total price: "<< total_price(v);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}