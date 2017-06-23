 /*
   TITLE	          Result Estimation			 Chapter5TryThis8.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 			Objective: Calculate an approximate value for the result.
 				Input: -
 			   Output: -
			   Author: Chris B. Kirov
		         Date: 1.2.2015
*/
#include <iostream>
 
int main()
{
	// Estimate an the driving time between NY city and Denver 
	// Estimate an the driving time between from London to Nice

	// 1. Find distance (Google Maps)
	// NY -> Denver d1 = 2861 km
	// London -> d2 = 1382 km

	// 2. Find mean velocity (not accounting for pauses, traffic, etc.)
    // by car  v1 = 120 km/h
	// by plane v2 = 1000 km/h

	// 3. Find time
	// by car
	// for d1: t1 = d1 / v1 = 2861 / 120 = 23.84 h
	// for d2: t2 = d2 / v1 = 1382 / 120 = 11.51 h

	// by plane
	// for d1: t1 = d1 / v1 = 2861 / 1000 = 2.8 h
	// for d2: t2 = d2 / v2 = 1382 / 1000 = 1.3 h
}

 