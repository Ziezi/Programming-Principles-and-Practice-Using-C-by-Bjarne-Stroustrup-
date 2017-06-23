 /*
	TITLE 		   Grains of rice  		          Chapter4Exercise8.cpp
	 Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
		Objective: Show how many iterations (squares)
            	   are needed to grow from initial value to final value.
				   (8 iterations:10e+3; 14 iterations: 10e+6; 20 iterations: 10e+9)
			Input: Requests initial and final values.  
		   Output: Prints # of doublings.
		   Author: Chris B. Kirov
		     Date: 1.05.2015

	      int = 4Bytes = 32bit => 2e+32 = 2,147,483,647 (Overflow on 21 iteration)
	 	  long long = 8 bytes => 64 bits =>  9,223,372,036,854,775,807(Overflow on 41 iteration)
 */
#include "../../std_lib_facilities.h"

int find_doublings(int, int);

//============================================================================================
int main()
{
	cout << "\t\tCalculate number of doublings such that initial value becomes final value.\n";

	cout << "Please type initial value, followed by final value of rice grains:\n>>";			 
	int initial_value = 0;	  // initial quantity of rice grains
	long int final_value = 0; // final quantity of rice grains
	cin >> initial_value >> final_value;
	
	// find number of squares needed to give the inventor "final_value" grains of rice 
	int number_of_doublings = find_doublings(initial_value, final_value);
	 
	cout << final_value <<" grains of rice reached after: " << number_of_doublings << " squares." << endl;
	getchar();
}
//============================================================================================

int find_doublings(int initial_value, int final_value)
{
	if (initial_value >=  final_value)
	{
		cout << "Initial value must be smaller than final value!" << endl;
		return 0;
	}

	int doublings = 0;

	while (initial_value <= final_value)		 
	{			 
		initial_value = initial_value * 2;
		++doublings;
	}

	return doublings;
}