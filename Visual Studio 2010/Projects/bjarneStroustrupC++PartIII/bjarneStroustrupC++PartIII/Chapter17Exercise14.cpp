/*
	TITLE		    Singly Linked list      Chapter17Exercise14.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Reimplement the example from Chapter 17.10.1
		            and modify it to a sinlgly-linked list.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 21.12.2015
*/
#include <iostream>
#include <string>
#include "Chapter17Exercise14.h"

int main () 
{
	try 
	{
	    // 1. Create a list from back to front
		Singly_linked_list* cars = new Singly_linked_list("BMW");

		// keep a pointer to the first element
		Singly_linked_list* head = cars;

		// list grows back to front
		cars = cars->add(new Singly_linked_list("Tesla"));
		cars = cars->add(new Singly_linked_list("LADA"));
		cars = cars->add(new Singly_linked_list("Toyota"));

		print_all(head);

		std::cout <<"\n\n\n";

		// 2. Create a list from front to back
		Singly_linked_list* motorcycles = new Singly_linked_list("Ducati");
		motorcycles = motorcycles->insert(new Singly_linked_list("BMW"));
		motorcycles = motorcycles->insert(new Singly_linked_list("Harley"));
		motorcycles = motorcycles->insert(new Singly_linked_list("MZ"));
		motorcycles = motorcycles->insert(new Singly_linked_list("Honda"));

		print_all(motorcycles);
	}
	catch (std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	getchar();
}