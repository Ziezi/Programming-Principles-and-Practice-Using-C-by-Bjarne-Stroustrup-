/*
	TITLE			   Redirect standard I/O	 Chapter10Exercise10.cpp
	"Software - Principles and Practice using C++" by Bjarne Stroustrup"
	COMMENT
			Objective: Implement class that redirects standard I/O; Using C library.
				Input:   
			   Output:  
			   Author: Chris B. Kirov
			     Date: 06.05.2015
*/ 
#include"stdafx.h"


/*
	Function: redirectStdInToFile();
	Use: void redirectStdIntoFile(void);
	This file redirects standard input
	to read from file.
*/
FILE* redirectStdIntoFile(void){
	cout << "fromfile\n";
	Token t2= ts.get();
	cout << "name token kind:  " << t2.kind << " name: " << t2.name << '\n';
	FILE* fin;
	if(t2.kind == fileNameToken) {
		cout <<"stdin Stream redirected!\n"; 
		
		fin = freopen(t2.name.c_str(), "r", stdin);
		if(fin != NULL) error("This file cannot be openned: ", t2.name.c_str());

		while(fin != NULL){
			cout << "Reading attempt!\n"; 
			cout << result << statement() << endl;
		}
	}
	return fin;
}  

/*
	Function: redirectStdOutToFile();
	Use: void redirectStdOuttoFile(void);
	This file redirects standard output
	to write to file.
*/
void redirectStdOuttoFile(void){
	Token t2 = ts.get();
	if(t2.kind == fileNameToken) freopen(t2.name.c_str(), "w", stdout);
} 



// In calculate()
// command for redirecting cin to read from file 
			FILE* fin(NULL);
			if(t.kind == fromfile)fin = redirectStdIntoFile();
			 
			// command for redirecting cout to write to file
			if(t.kind == tofile) redirectStdOuttoFile();

			if(t.kind == endOfFileReached) fclose(fin);