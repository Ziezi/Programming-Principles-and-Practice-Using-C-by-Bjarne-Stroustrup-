/*
    TITLE          Directing the computer        Chapter2Exercise2.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
    COMMENT
 		Objective: Pseudo code; 
		           Initial algorithmic approach to task. 
 				   Give directions to the computer to reach
 				   the bathroom within a building.
 			Input: -
 		   Output: - 
		   Author: Chris B. Kirov
		     Date: 02.06.2014
*/
#include "../../std_lib_facilities.h"

int main(){
#def wall, floor, coridor, staircase, room, bathroom;
#def point, line, direction, distance, vector, coordinates, left, right, up, down, straight, back;
#def movement, start, stop, end;
#def time, now, later

	int	movement(current position(now,room), end position(later,bathroom)){
		start(point(coordinates), vector(direction, distance)){
			straight "down" the corridor(till wall);
			then left(till staircase);
			then up(till floor);
			then left;
			straight(till room);
			if (time(later - now) != = usual) | (distance(bathroom - room) != = usual) = > stop, return to start position;
			stop;
		}
	end;
	}	

return 0;
}