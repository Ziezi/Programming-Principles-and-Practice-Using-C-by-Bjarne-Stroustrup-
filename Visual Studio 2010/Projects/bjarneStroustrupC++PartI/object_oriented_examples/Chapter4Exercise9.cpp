 /*
	TITLE 		   Grains of rice after 64 squares  Chapter4Exercise9.cpp
	 Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Calculate 64 doublings.
			Input: Requests number of doublings.  
		   Output: Prints # rice grains after n number of doublings.
		   Author: Chris B. Kirov
		     Date: 1.05.2015

	 	  long long = 8 bytes => 64 bits => (Overflow on 62nd iteration)
		  unsigned long long (Overflow on 63rd iteration) 9223372036854775808 

		  For 64 the value is negative indicating overflow.
 */
#include "../../std_lib_facilities.h"

unsigned long long find_rice_grains(int);

//============================================================================================
int main()
{
	cout << "\t\tCalculate rice grains after n doublings.\n";

	cout << "Please type number of doublings:\n>>";			 
	int number_of_doublings;	     
	cin >> number_of_doublings;
	
	unsigned long long final_value = find_rice_grains(number_of_doublings);
	 
	cout <<"After: "<< number_of_doublings <<" doublings there are: "<< final_value <<" grains of rice\n";
	getchar();
}
//============================================================================================

unsigned long long find_rice_grains(int doublings)
{
	unsigned long long initial_value = 1;
	int current_doublings = 0;

	while (current_doublings <= doublings)		 
	{			 
		initial_value = initial_value * 2;
		++current_doublings;
	}

	return initial_value;
}