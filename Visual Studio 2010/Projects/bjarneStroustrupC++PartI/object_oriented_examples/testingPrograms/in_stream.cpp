/* 
   TITLE	       User input type conversion	 	vect_temp.cpp
   COMMENT
 		Objective: Introduce stringstream for separating
            	   data input and data interpretation.
 				   Type conversion using stringstream property 
				   of indirect data input.
 			Input: Requests different types of variables. 
 		   Output: Prints the type of the input variables.
		   Author: Chris B. Kirov
             Date: 01.01.2015		   
*/
#include "../../std_lib_facilities.h"
#define end "end"
		
int main(){
	// Input/Output buffer from stringstream, which allows i_o_buffer content to be treated as a stream
	// stream in: i_o_buffer insertion from variable: num of type: int, if input is integer
	// stream in: i_o_buffer insertion from variable: wor of type: string, if input is string
	string i_o_buffer = "";								
	int num = 0;										
	string wor = "";									
	
	cout << "Please enter a string: ";
	getline(cin, i_o_buffer);
	stringstream(i_o_buffer) >> num;
	
	cout << "\nThe input number is: " << num << endl;
	cout << "Number manipulation (+5): " << num + 5 << endl;

	stringstream(i_o_buffer) >> wor;
	cout << "\nThe input number converted to string is: " << wor << endl;
	cout << "String manipulation: " << wor + " + letters" << endl;
	cout << "\n" << endl;
	 
	// char to int, type covnersion is unique (i.e.every char has one and the same number representation) 
	// string to int, type conversion is not unique, using this method.
	char inchar = ' ';										
	cout << "Please enter a char: ";						
	cin >> inchar;
	cout << "\nChar conversion using: int(""char""): " << int(inchar) << endl;
	return 0; 
}