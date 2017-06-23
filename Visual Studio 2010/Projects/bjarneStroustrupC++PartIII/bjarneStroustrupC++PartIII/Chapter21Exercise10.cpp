/*
	TITLE		    Order Total Value       Chapter21Exercise10.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Compute the total value of the orders in 
					the two files from the previous exercise.
					The value of an individual Purchase is 
					(of course) its unit_price * count.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 28. 02. 2017
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>		// inner_product
#include "Chapter21Exercise9.h"

//--------------------------------------------------------------------
// T - Purchase, U - double
template <class T, class U>
struct multiply_purhase 
{
  U operator() (const T& x, const T& y) const 
  {
	  return x.count * y.unit_price;
  }
};

//--------------------------------------------------------------------

int main()
{
	try
	{
		std::vector<Order> v;
		
		std::string file("Chapter21Exercise9m.txt");
		std::ifstream ifs(file.c_str());
		if (!ifs)
		{
			throw std::runtime_error("Can't open input file!\n");
		}

		Order sale;
		while (ifs >> sale)  
		{
			v.push_back(sale);
			sale = Order();
		}

		double total = 0.0;
		for (auto it = v.begin(); it != v.end(); ++it)
		{
			total = std::inner_product(it->sales.begin(),  it->sales.end(), 
									   it->sales.begin(),  
									   total, 
									   std::plus<double>(), multiply_purhase<Purchase, double>());
			std::cout << total <<'\n';
			getchar();
		}
		
		std::cout <<"Total: "<< total <<'\n';
		 
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}