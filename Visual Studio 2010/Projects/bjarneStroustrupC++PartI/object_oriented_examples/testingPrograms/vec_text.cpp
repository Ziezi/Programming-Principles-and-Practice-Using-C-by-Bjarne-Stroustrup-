/* 
   TITLE	       Reading data into vector object   vect_text.cpp
   COMMENT
		Objective: Introduce vector objects and their
             	   member functions for string manipulation.
				   Compares the last-input-word, discard if same.
			Input: Requests a word. 
		   Output: Prints the alphabetically ordered words; 
		   Author: Chris B. Kirov
		     Date: 01.10.2015
*/
#include "../../std_lib_facilities.h"

int main(){
	// prompt menu
	cout << "\t\tCreate a simple dictionary.\n" << endl;
	cout << "Type a word:" << endl;
	// input vector 
	vector<string> dict;												 
	string temp;														 
	// read loop; no input termination! ONLY keyboard hardware interrupt: (Ctrl + Z)
	while (cin >> temp ) dict.push_back(temp);											
	// vector element manipulation using member functions
	cout << "Number of words: " << dict.size() << endl;					 
	sort(dict.begin(), dict.end());										 
	for (int i = 0; i < dict.size(); ++i){
	    // check if word is the first or not equal to previous
		if (i != 0 || dict[i - 1] != dict[i]) cout << dict[i] << "\n";									 
	}
	return 0;
}