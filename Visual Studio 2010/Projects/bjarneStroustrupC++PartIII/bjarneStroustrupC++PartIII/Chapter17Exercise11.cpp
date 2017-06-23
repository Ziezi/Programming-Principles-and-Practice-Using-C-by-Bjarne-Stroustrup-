/*
	TITLE		    Linked list             Chapter17Exercise11.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Complete and run the example from 17.10.1.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 07.12.2015
*/
#include <iostream>
#include <string>
#include "Chapter17Exercise11.h"

int main () 
{
	try 
	{
		// creata two lists of deliberately mistaken gods
		Link* norse_gods = new Link("Odin");
		norse_gods = norse_gods->insert(new Link("Zeus"));
		norse_gods = norse_gods->insert(new Link("Freia"));
	
		Link* greek_gods = new Link("Hera");
		greek_gods = greek_gods->insert(new Link("Athena"));
		greek_gods = greek_gods->insert(new Link("Mars"));
		greek_gods = greek_gods->insert(new Link("Poseidon"));

		// correct mistake: replace Mars with Ares and Move Zeus to greek gods
		Link* p = greek_gods->find("Mars");
		if (p)
		{
			p->value = "Ares";
		}

		Link* p2 = norse_gods->find("Zeus");
		if(p2)
		{
			// if p2 is norse_gods, point it to the next element
			if (p2 == norse_gods)
			{
				norse_gods = p2->next();
			}

			p2->erase();

			greek_gods = greek_gods->insert(p2);
		}

		// print both lists
		print_all(norse_gods);
		std::cout <<"\n";

		print_all(greek_gods);
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		getchar();
	}
	getchar();
}