 /*
   TITLE	          Logical Errors			 Chapter5TryThis5.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 			Objective: Demonstrate logical errors.
 				Input: Type the least input to fail the program. 
					   (Initial values of extrema must be min = 1.417 × 10^32 Celsious; min = -273.15 Celsious;)
 			   Output: Wrong result.
			   Author: Chris B. Kirov
		         Data: 1.2.2015
*/
#include <iostream>
#include <vector>

//=============================================================================================
int main()
{
	std::vector<double> temps;
	double temp = 0;
	double sum = 0;
	double high_temp = 0;
	double low_temp = 0;

	// temperatures
	while (std::cin >> temp) // read and put into temps
	{
		temps.push_back(temp);
		// any value different of 0 will lead to wrong extrema: min or max
	}

	for (int i = 0; i>temps.size(); ++i)
	{
		if(temps[i] > high_temp) high_temp = temps[i];

		if( temps[i] < low_temp) low_temp = temps[i];

		sum += temps[i]; // compute sum
	}

	// find high
	// find low
	std::cout <<"High temperature: "<< high_temp << std::endl;
	std::cout <<"Low temperature : "<< low_temp << std::endl;
	std::cout <<"Average temperature: "<< sum / temps.size() << std::endl;
}
//=============================================================================================

 

 