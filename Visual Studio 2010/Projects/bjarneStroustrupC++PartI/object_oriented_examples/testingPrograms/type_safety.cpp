/* 
   TITLE	       Type safety		 					type_safety.cpp
   COMMENT
 		Objective: To present type-safety errors that should be avoided. 
 			Input: - 
 		   Output: It causes compilation errors due to conversion errors. 
		   Author: Chris B. Kirov
		     Date: 01.01.2015
*/
#include "../../std_lib_facilities.h"
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmd, int nCmd);
#include <stdio.h>
#include <iostream>

int main(){
	double d = 10000;
	// repeat the statements within while loop till the condition is true/succeeds
	while (std::cin >> d){
		int i = d;						// sqeeze double into int (danger of losing data if the value needs more than 32-bits(int size))
		char c = i;						// convert int to char (danger of losing data if the value needs more than 8-bits(char size))
		int i2 = c;						// convert char to int (it gets the ASCII representation of the character)
		std::cout << "d==" << d				// print the original value of d
			<< "i==" << i				// print d, after conversion type double (d) to type int (i) 
			<< "i2==" << i2				// print i, after conversion type char (c) to type int (i2)
			<< "char(" << c << ")\n";	// print c, after conversion type int (d) to type char (c)
	}
	return 0;
}