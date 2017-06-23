/* 
	TITLE	       Intrusive Doubly Linked List in C++ vs C	   Chapter27Exercise5.cpp
	COMMENT
		Objective: Compare the results of Exercises 3 and 4.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 13.06.2017
*/
#include <iostream>

/*
	C++ Implementation: 
		- all functions encapsulated: less parameters, context provided (member functions).
		- commonly / frequently used variables defined as member functions: front(); back().
		- memory management easier and less error-prone through RAII - constructor; destructor.
		- inheritance allows new Links containing data to be defined and integrated with ease.

	C Implementation:
		- all functions more general; applicable to more than one object (List).
		- explicit and low level memory management.
		- explicit casts neccessary; type convertion indicated.

     --------------------------------------------- 
	|    DList  |    Time[sec] |    Time [clicks] |
	|-----------|--------------|------------------|
	|    C      |     0.094    |     94           |
	|    C++    |     0.110    |     110          |
	 ---------------------------------------------
	     C++          0.100          100
	   Ex. 6
*/

int main()
{

}
