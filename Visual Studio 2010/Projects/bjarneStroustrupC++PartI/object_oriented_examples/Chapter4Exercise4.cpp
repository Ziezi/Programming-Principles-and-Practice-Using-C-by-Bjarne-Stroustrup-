/*
   TITLE		   Guess the number				 Chapter4Exercise4.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
		Objective: Finds a random number within [1,100], 
		           with 7 quesses the most.
			Input: Type a random number to be guessed.  
		   Output: Prints the number one thought of. 
		           (After asking up to 7 qusestions.)
			       (Algorithm based on Binary Search.)
		   Author: Chris B. Kirov
			 Data: 01.04.2015
*/
#include "../../std_lib_facilities.h"

int mid_point(int, int);
 
//==========================================================================

int main()
{
	cout << "Type a random number within [1, 100]; exit with ""|"":\n>>";
	int random = 0;
	cin >> random;
	
	int temp_min = 1;
	int temp_max = 100;

	int round = 0;
	while (temp_min <= temp_max)
	{
		if (random == mid_point(temp_min, temp_max))
		{
			cout <<"Number found!\n";
			break;
		}

		cout <<"Is the number you're thinking of less than "<< mid_point(temp_min, temp_max) <<" (1 / 0)\n>>";
		bool smaller_than;
		cin >> smaller_than;

		if (smaller_than)
		{
			temp_max = mid_point(temp_min, temp_max) - 1;
		}
		else 
		{
			temp_min = mid_point(temp_min, temp_max) + 1;
		}

		if (++round < 7)
		{
			cout <<"Number not found!\n";
			break;
		}
	}	 

	getchar();
}
//==========================================================================

int mid_point(int min, int max)
{
	return min + ((max - min) / 2);
}

