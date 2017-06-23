/* 
   TITLE		   Median   				     Chapter4Exercise2.cpp
    Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
		Objective: Correct Chapter 4.6.2 code to include mode 
				   for both odd and even data sets
			Input:  
		   Output:  
		   Author: Chris B. Kirov
			 Data: 01.04.2015
*/
#include "../../std_lib_facilities.h"

int main()
{
	// temperatures
	vector<double> temps; 
	double temp;

	// read
	while (cin >> temp) 
	{
		// put into vector
		temps.push_back(temp);  	
	}
	// compute mean temperature:
	double sum = 0;
	for (int i = 0; i < temps.size(); ++i)
	{
		sum += temps[i];
	}
	cout << "Average tempe rature: " << sum / temps.size() << endl;

	// compute median temperature:

	// sort temps from the beginning to the end
	sort(temps. begin(),temps.end()); 

	cout <<"Median temperature: ";
	// if the number of values is odd: median is the middle number
	if (temps.size() % 2 != 0)
	{
		cout << temps[temps.size() / 2] << endl;
	}
	else 
	{
		double middle_numbers  = (temps[temps.size() / 2] + temps[(temps.size() / 2) + 1]) / 2.;
		cout << middle_numbers;
	}
}