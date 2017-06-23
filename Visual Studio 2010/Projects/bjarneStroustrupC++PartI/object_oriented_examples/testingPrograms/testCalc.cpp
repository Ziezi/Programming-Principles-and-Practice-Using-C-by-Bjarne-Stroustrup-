/* 
   TITLE		       Test calculator		testCalc.cpp
   COMMENT
 			Objective: Test the code of the calculator2.cpp. 
			           Test the link between the (.h;.cpp)files.
 				Input: Type supported algebraic expression in terminal.
 			   Output: Prints the result of the input expression.
			   Author: Chris B. Kirov
			     Date: 01.01.2015
*/

#include "stdafx.h"
//using namespace std;
//#include "calculator2.h"  

int main(){
	try{
		double val;
		while(cin){
			// get token from  custom input stream 'ts'
			TokenStream ts;
			Token t = ts.get();
		
			// quit program
			if (t.kind=='q') break; 
			
			// quit input, evaluate and print
			if (t.kind==';'){  cout << "=" << val << '\n'; 
			}else{ 
				// return the token to the stream (peek analog)
				ts.putback(t);
				val = expression();
			}
		}
	}catch(exception& e){
		cerr<< e.what() << endl;
		keep_window_open();
		return 1;
	}catch(...){
		cerr<< "exception \n";
		keep_window_open();
		return 2;
	}
	return 0;
}