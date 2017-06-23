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
			  Date: 02.12.2017
*/
#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <vector>

#include "Chapter18Exercise11v4.h"

int main () 
{
	try
	{
		 // 1.Initialize an empty Skip_list object
		 Skip_list s;
		 int elements = 500;

		 // 2. insert()
		 for (int i = 0; i < elements ; ++i)
		 {

			 std::stringstream ss;
			 ss << i;

			 s.insert(i, ss.str());
		 }

		 // 2a. print()
		 std::cout <<"Count: "<< s.get_count() <<'\n';
		 std::cout <<"Max height: "<< s.get_height() <<'\n';
		 getchar();	 

		 //s.print();
		 //getchar();	 
	 
		 // 3. find()
		 std::string* f = nullptr;
		 f = s.find(elements / 2);
		 if (f)
		 {
			 std::cout <<"Node found!\nvalue: "<< *f <<'\n';
		 }
		 else
		 {
			std::cout <<"Node NOT found!\n";
		 }
		 getchar();	 
	 
		 // 4. insert() - reassign
		 s.insert(499, "TEST");

		 // 4a. print()
		 s.print();
		 getchar();	 

		 std::cout <<"\nNodes: "<< s.get_count() <<'\n';
		 // 5. erase()
		 s.erase(499);
		 std::cout <<"\nNodes: "<< s.get_count() <<'\n';
		 getchar();	 

		 // 5a. print();
		 s.print();
		 getchar();	
	 
		 std::cout << "\nDone!\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	catch (...)
	{
		std::cerr << "Unhandled exception!\n";
	}
	getchar();	 
}
 
