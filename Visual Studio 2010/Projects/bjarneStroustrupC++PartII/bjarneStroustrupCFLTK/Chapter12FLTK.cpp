/*
	TITLE			   First example in FLTK   Chapter12FLTK.cpp
	"Bjarne Stroustrup - Programming - Principles and Practice."
	COMMENT
			Objective: Install FLTK. Make a simple graph.
			    Input: - 
			   Output: Window with graph in it.
			   Author: Chris B. Kirov
			     Date: 26. 08. 2015
*/
#include "fltk.h"


int main(){
	Fl_Window window(200, 200, "Window title");
	Fl_Box box(0, 0 , 200, 200, "Hello, World!");
	window.show();
	return Fl::run();
}