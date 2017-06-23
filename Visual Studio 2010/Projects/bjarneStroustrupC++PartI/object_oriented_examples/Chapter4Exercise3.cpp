/* 
   TITLE		   City Distances				 Chapter4Exercise3.cpp
    Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
		Objective: Calculates total distance, min, max, mean distance.
			Input: Prompts for input. 
		   Output: Prints: Total sum of input distances. 
		           Smallesr and greatest diastance. Mean distance.
		   Author: Chris B. Kirov
			 Data: 01.04.2015
*/
#include "../../std_lib_facilities.h"

int main()
{
	 vector<double> city_distances;

	 // read input
	 cout <<"Type a set of distances; terminate with ""|"":\n>>";
	 string input;

	 while (cin >> input && input != "|")
	 {
		cout <<">>";
		stringstream ss(input);

		double distance;
		if (ss >> distance && distance > 0)
		{
			city_distances.push_back(distance);
		}
		else 
		{
			cout <<"Value type not supported!\n";
			ss.ignore();
		}
	 }

	 // calculate total length
	 double total_sum = 0;

	 // calculate min, max
	 double min = 1000000, max = -1000000;

	 // calculate mean
	 for (unsigned int i = 0; i < city_distances.size(); ++i)
	 {
		total_sum += city_distances[i];

		if (city_distances[i] < min)
		{
			min = city_distances[i];
		}
		if (city_distances[i] > max)
		{
			max = city_distances[i];
		}
	 }

	 cout <<"Total sum: "<< total_sum <<"\n";
	 cout <<"Min: "<< min <<" Max: "<< max <<"\n";
	 cout <<"Mean: "<< total_sum / city_distances.size() <<"\n";
	
	 getchar();
}


