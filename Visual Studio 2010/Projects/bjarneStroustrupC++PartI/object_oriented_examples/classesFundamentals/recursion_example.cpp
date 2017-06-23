/*

   TITLE	       Alphabet Permutations		recursion_example.cpp
   COMMENT
 		Objective: Implement alpabet string permutations (without repetiotion) using recursion
 			Input: 
 		   Output: All possible letter permutations of the English alphabet 
		   Author: Chris B. Kirov
		     Date: 01.01.2015
*/
#include "../../std_lib_facilities.h"

void recPermute(string soFar, string rest);

int main(){
    
	recPermute(string soFar, string rest)
	return 0;
}

void recPermute(string soFar, string rest){
	if (rest == ""){
		cout << soFar << endl;
	}else{
		for (int i = 0; i < rest.length(); i++){
			string next = soFar + rest[i];
			string remaining = rest.substr(0, i) + rest.substr(i + 1);
			recPermute(next, remaining);
		}
	}
}
