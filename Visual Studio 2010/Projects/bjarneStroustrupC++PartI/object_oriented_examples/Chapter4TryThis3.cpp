/* 
   TITLE  		   Iterations & casting			 Chapter4TryThis3.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
       Objective: Character iteration table; expicit type casting;
			      ASCII character values.
           Input: - 
          Output: It prints a table with characters 
		          and their corresponding integer values.
		  Author: Chris B, Kirov
            Date: 01. 04. 2015

*/
#include "../std_lib_facilities.h"

int main() 
{	
	char first_character = 'a';
	int num_of_iterations = 26; // size of English alphabet

	int i = 0; 
	while (i < num_of_iterations) 
	{
		std::cout <<"char: "<< char(first_character + i) <<" integer value: "<< int(first_character + i) <<"\n";
		++i;
	}

	getchar();
}