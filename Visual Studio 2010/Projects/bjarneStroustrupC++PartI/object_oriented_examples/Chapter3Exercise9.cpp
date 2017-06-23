/* 
	TITLE          String Comparison			 Chapter3Exercise9.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
    COMMENT
	    Objective:  
	        Input: Requests an integer. (entered as string)
	       Output: Prints it as an int.
		   Author: Chris B. Kirov
		     Date: 10.02.2014
*/
#include "../../std_lib_facilities.h"

int main()
{
	const unsigned int array_size = 5;
	string number_names[array_size] = {"zero", "one", "two", "three", "four"};

	cout << "Please type a spelled-out(as string) number: ";
	string input_var;
	cin >> input_var; 

	for (unsigned int i = 0; i < array_size; ++i) 
	{
		if (input_var == number_names[i])
		{
			cout <<"Number as int: "<< i <<"\n";

			getchar();

			return 0;
		}
	}
	cout <<"You have types an unknown number name!\n";
	
	getchar();

	return 0;
}