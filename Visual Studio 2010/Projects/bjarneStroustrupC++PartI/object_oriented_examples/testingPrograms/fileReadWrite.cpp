/* 
	TITLE		Read and write from file		fileReadWrite.cpp
	COMMENT
			Objective: Define streams for file read and write.
				Input: Reads from file testCalculator.cpp
			   Output: To file testCalculator and to stdout.
			   Author: Chris B. Kirov
			     Date: 20.02.2015
*/
#include "stdafx.h"

int main()
	try{
		char inp[100];
		string fileName("testCalculator.dat");
		ifstream istr(fileName.c_str());
		if(!isrt) error("Can't open input file: ", fileName);
		
		istr >> inp;
		cout << "File content: " << inp << endl;
		keep_window_open();
		
	}catch(runtime_error& e){
		cerr << e.what() << endl;
		keep_window_open("~");
	}