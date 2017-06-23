/*
	TITLE		    ownership_vector		Chapter20Exercise17.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Define an `ownership_vector` that holds 
					pointers to objects like `pvector`, 
					but provides a mechanism for the user to 
					decide which objects are owned by the vector
					(i.e., which objects are `delete`d by the destructor).

					Vector_ref.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 22. 02. 2017
*/
#include <iostream>
#include <vector>
#include "Chapter20Exercise17.h"

int main()
{
	try
	{
		 Ownership_vector<int> v;

		 v.push_back(new int(1));
		 v.push_back(new int(2));

		 int n = 4;
		 v.push_back(n);
		 v.push_back(n);
		 v.push_back(n);

		 std::cout <<"Stored: "<< v.number_of_stored() <<'\n';
		 std::cout <<"Owned: "<< v.number_of_owned() <<'\n';
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	getchar();
}