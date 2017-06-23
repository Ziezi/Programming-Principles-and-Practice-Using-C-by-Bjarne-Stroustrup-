/* 
   TITLE	       Delete Repeated Words     strng_rpr_dlt.cpp
   COMMENT
 		Objective: Deletes repeatedly occurring strings . 
 			Input: Requests input strings.
 		   Output: Prints repeated strings, if occur.
		   Author: Chris B. Kirov
		     Date: 01.01.2015
*/
#include "../../std_lib_facilities.h"

int main(){
    // previous word; initialized to "not a word" (it works from the second cycle)
	string previous = "";						
	string current;								 
	int number_of_words;
	// all the statements following to be repeated while cin>>current is successful
	while (cin >> current)						{
		++number_of_words;
		// checks if the current word is the same as the previous
		if (previous == current)				
			cout << "word number"<< number_of_words << "repeated:" << current << "\n";
		// before starting again we pass the current word as previous 
		previous = current;						
	}
	return 0;
}