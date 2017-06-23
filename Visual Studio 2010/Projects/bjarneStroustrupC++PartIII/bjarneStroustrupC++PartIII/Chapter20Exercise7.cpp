/*
	TITLE		     Max in vector<string>    Chapter20Exercise7.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Find the lexicographically last string in an unsorted 
					vector<string>
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 19. 02. 2017
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	try 
	{ 
		 std::vector<std::string> v;
		 v.push_back("aaa");
		 v.push_back("ccc");
		 v.push_back("bbb");
		 v.push_back("ddd");

		 auto p = std::max_element(v.begin(), v.end());

		 if (p != v.end())
		 {
			std::cout <<" lexicographically last string: "<< *p;
		 }
	}
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}