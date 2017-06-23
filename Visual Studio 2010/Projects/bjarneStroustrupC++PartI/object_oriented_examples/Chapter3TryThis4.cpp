 /*
   TITLE           Program flow  				 Chapter3TryThis4.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
		Objective: The program deletes repeated words entered consequtively.
		           observe upper case - lower case sensitivity.
 			Input: -
		   Output: -      
		   Author: Chris B. Kirov
		     Date: 02.02.2014
		   
*/
#include "../../std_lib_facilities.h"

int main()
{ 
	string previous =" ";   
	string current;		   

	while (cin >> current) 
	{
		if (previous == current) 
		{
			cout << "repeated word : "<< current <<'\n';
		}
		previous = current;
	}
}

/*
	Example:
	
	Input: "She she jumps He He He sits what he did did"
	Ouput: repeated word: He
	       repeated word: He
		   repeated word: did
*/
