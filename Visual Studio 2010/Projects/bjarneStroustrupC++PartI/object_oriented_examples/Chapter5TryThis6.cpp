 /*
   TITLE	          Logical Errors			 Chapter5TryThis6.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 			Objective: Demonstrate logical values.
 				Input: Type the least input to fail the program. 
					   (Initial values of extrema must be min = 1.417 × 10^32 Celsious; min = -273.15 Celsious;)
 			   Output: Wrong result.
			   Author: Chris B. Kirov
		         Data: 1.2.2015
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

//=============================================================================================
int main()
{
	std::vector<double> temps;
	double temp = 0;
	double sum = 0;

	// the lowest temperature possible in Celsius; absolute zero
	double high_temp = -273.15;		
	// highest possible temperature: Planck temperature
	double low_temp = 1.47 * pow((double) 10, 32);      

	// temperatures
	std::string sentinel = "|";
	std::string input;
	while (getline(std::cin, input) && input != sentinel) // read and put into temps
	{
		std::stringstream ss(input);

		while (ss >> temp)
		{
			temps.push_back(temp);
			// any value different of 0 will lead to wrong extrema
		}
	}

	for (size_t i = 0; i < temps.size(); ++i)
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

	getchar();
	getchar();
}
//=============================================================================================

 

 