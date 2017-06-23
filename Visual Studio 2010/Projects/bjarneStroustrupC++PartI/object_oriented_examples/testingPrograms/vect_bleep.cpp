/* 
   TITLE	       Reading data into vector object   vect_bleep.cpp
   COMMENT
 		Objective: Introduce vector objects and their member functions.
 			Input: Requests a string. 
 		   Output: Prints the input-word if it's not 
                   among the forbidden ones; 
				   Otherwise prints BLEEP.
		   Author: Chris B. Kirov
		     Date: 01.10.2015
 			  Bug: It prints the BLEEP if word in list of Forbidden words (i.e. element of vector: noword), 
 				   BUT prints it together with the "allowed case".
*/
#include "../../std_lib_facilities.h"

int main(){
	// vector object creation; containing the list of forbidden words 	 
	vector<string>noword(5);											
	noword[0] = "Evolution";
	noword[1] = "Science";
	noword[2] = "Fact";
	noword[3] = "Logic";
	noword[4] = "Mind";
	// prompt menu
	cout << "\t\tCheck if a word is proper to say.\n" << endl;
	cout << "Please enter a word: ";
	string temp;
	cin >> temp;
	// check if input word forbidden, if not print 
	int i = 0; // declared outside so that can be visible in inside loops/conditions
	for (i = 0; i <= noword.size(); ++i){
		if (noword[i] == temp){
     		cout << "\n\n\n\t\tBLEEP " << endl;
			return 0;
		}
	}
	cout << temp << '\n';
	cout << "\n\t\tEnd.";
	
	getchar();
	return 0;
}