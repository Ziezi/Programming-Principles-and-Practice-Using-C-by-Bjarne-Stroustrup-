/*
	TITLE		    Skip List	            Chapter18Exercise11v2.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Research and implement the data structure:
					Skip List. 
		           
					References to the papers by W. Pugh:
					http://epaperpress.com/sortsearch/download/skiplist.pdf

					http://cglab.ca/~morin/teaching/5408/refs/p90b.pdf
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 11.1.2016
*/
#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <vector>

#include "Chapter18Exercise11v3.h"

//==================================================
int main () {
	 // 1.Initialize an empty Skip_list object
	 Skip_list s;

	 // 2. insert()
	 for (int i = 0; i < 500; ++i){

		 std::stringstream ss;
		 ss << i;

		 s.insert(i, ss.str());
	 }
	 
	 // 2a. print()
	 s.print();
	 getchar();	 
	 
	 // 3. find()
	 std::string* f = nullptr;
	 f = s.find(250);
	 if (f) std::cout <<"Node found!\nvalue: "<< *f <<'\n';
	 else std::cout <<"Node NOT found!\n";
	 getchar();	 
	 
	 // 4. insert() - reassign
	 s.insert(499, "TEST");

	 // 4a. print()
	 s.print();
	 getchar();	 

	 // 5. erase()
	 s.erase(499);

	 // 5a. print();
	 s.print();
	 getchar();	
	 
	 std::cout << "\nDone!\n";
	 getchar();	 
}
//==================================================
 
