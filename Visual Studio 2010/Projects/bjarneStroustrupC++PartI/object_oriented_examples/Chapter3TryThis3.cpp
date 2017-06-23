 /*
   TITLE           Program flow  				 Chapter3TryThis3.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
		Objective: Describe program execution sequence.
		           The program deletes repeated words entered consequtively.
			Input: -
		   Output: -      
		   Author: Chris B. Kirov
		     Date: 02.02.2014
		   
*/
#include "../../std_lib_facilities.h"

int main()
{ 
	string previous =" "; // previous word; initialized to "not a word"
	string current;		  // current word

	// read a stream of words
	while (cin >> current) 
	{
		// check if the word is the same as last
		if (previous == current) 
		{
			cout << "repeated word : "<< current <<'\n';
		}

		// first iteration initializes previous;
		// next reassigns to keep memory of the last input value
		previous = current;
	}
}

/*
	Program flow:

	line 15: program trasfered from OS to program main()
	
	line 17: variable of type string defined to empty value " "

	line 18: variable of type string declared

	line 21: loop extracting from standard input stream and initialialing (reassigning) values to current

	line 24: conditional statement containig a comparison between the two strings: if true (equal strings): prints message

	line 31: string initilized (reassigned)

	line 32: go to line 21 


	Example:
	
	Input: "The cat cat jumped"
	Ouput: repeated word: cat

*/
