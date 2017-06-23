/*
	TITLE		   Draw a class diagram			  Chapter13Exercise6.cpp
	"Bjarne Stroustrup "Programming Principles and Practices Using C++""
	COMMENT
		Objective: Draw a class diagram. 
		           Define a Box class that is
				   a rectangle with a Text label.
		   Output: 
		   Author: 17.09.2015
		     Date: Chris B. Kirov
*/

#include "GUI.h"
#include "Simple_window.h"
#include <iostream>

//--------------------------------------------------------------------------------------------------
int main(){
	 // window parameters
	 int winWidth = 800;
	 int winHeight = 600;
	 Point centerPoint((x_max() - winWidth) / 2., (y_max() - winHeight) / 2.);
	 Simple_window* siw = new Simple_window(centerPoint, winWidth, winHeight, "Chapter 13 Exercise 4");

	 try{
		  
		 	 siw->wait_for_button();
	 }catch(exception& e){
		cerr << e.what() << endl;
		getchar();
	 }catch(...){
		cerr <<"Defaul exception!"<< endl;
		getchar();
	 }
	 return 0;
}
//--------------------------------------------------------------------------------------------------