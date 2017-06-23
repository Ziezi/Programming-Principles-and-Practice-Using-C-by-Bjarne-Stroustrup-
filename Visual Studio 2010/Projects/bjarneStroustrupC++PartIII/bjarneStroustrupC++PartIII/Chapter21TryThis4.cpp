/*
	TITLE			Maps & Dow Jones Index	  Chapter21TryThis4.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Write the example from §21.6.3 and get it to run.  
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 26. 02. 2017
*/
#include <iostream>
#include <string>
#include <map>
#include <numeric>
 
//--------------------------------------------------------------------

double weighted_value(const std::pair<std::string, double>& a, 
					  const std::pair<std::string, double>& b)
{
	return a.second * b.second;
}

//--------------------------------------------------------------------

int main()
{
	try
	{
		std::map<std::string, double> dow_price;
		dow_price["MMM"] = 81.86;
		dow_price["AA"] = 34.69;
		dow_price["MO"] = 54.45;

		std::map<std::string, double> dow_weight;
		dow_weight["MMM"] = 5.8549;
		dow_weight["AA"] = 2.4808;
		dow_weight["MO"] = 3.8940;

		std::map<std::string, std::string> dow_name;
		dow_name["MMM"] = "3M Co.";
		dow_name["AA"] = "Alcoa Inc.";
		dow_name["MO"] = "Altria Group Inc.";

		if (dow_price.find("INTC") != dow_price.end())
		{
			std::cout <<"Intel is in the Dow!\n";
		}
		else
		{
			std::cout <<"Intel is not in the Dow!\n";
		}

		typedef std::map<std::string, double>::const_iterator Dow_iterator;

		for (Dow_iterator p = dow_price.begin(); p != dow_price.end(); ++p)
		{
			const std::string& symbol = p->first;

			std::cout << symbol <<'\t'<< p->second <<'\t'<< dow_name[symbol] <<'\n'; 
		}

		double initial_value = 0.0;
		double dji_index = inner_product(dow_price.begin(), dow_price.end(),
										 dow_weight.begin(), 
										 initial_value, 
										 std::plus<double>(), 
										 weighted_value);

		std::cout <<"Dow Jones index: "<< dji_index;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}