/* 
   TITLE	       Definition, declaration, function call, preprocessor directive: #include,extern		func_call.cpp
   COMMENT 
 		Objective: Introduce functions declaration and preprocessor directives.
			Input: Requests a number. 
   Function Input: Returned result from externally defined function: square, return type int : sqr (in file func_deff.cpp)
		   Output: Square of a number.
		   Author: Chris B. Kirov
		     Date: 01.01.2015
*/
#include "../../std_lib_facilities.h"
// exrernal function declaration; eihter include: source file or extern: function name
//#include "func_def.cpp"
extern int mysquared(int);

// function invocation/calling and used parameter passed (by value), from the user
int main(){
	cout << "\t\tType a number to find its square: ";
	int par = 0;
	cin >> par;
	cout << "\n\t\tThe square of " << par << " is " << mysquared(par) << endl;
	cout << "\n\n\n" << endl;
	return 0;
}