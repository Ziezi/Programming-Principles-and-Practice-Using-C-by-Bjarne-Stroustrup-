/*
	TITLE		    Linked list             Chapter17Exercise13.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Modify Link to include struct God,
				    containing members of type string:
					name, mythology, vehicle, weapon.
					Write: print_all(), add_ordered() functions.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 07.12.2015
*/
#include <iostream>
#include <string>
#include "Chapter17Exercise13.h"

int main () 
{
	try 
	{
		// God(name(n), mythology(m), vehicle(v), weapon(w)) 
		// Greek mythology list of Gods
		
		Link* greek_gods = new Link(God("Zeus", "Greek", "", "lightning"));
		greek_gods = greek_gods->insert(new Link(God("Hera", "Greek" )));
		greek_gods = greek_gods->insert(new Link(God("Athena", "Greek")));
		greek_gods = greek_gods->insert(new Link(God("Ares", "Greek")));
		greek_gods = greek_gods->insert(new Link(God("Poseidon", "Greek" )));

		// Norse mythology list of Gods
		Link* norse_gods = new Link(God("Odin", "Norse", "Eight-legged flying horse called Sleipner"));
		norse_gods = norse_gods->insert(new Link(God("Thor", "Norse")));
		norse_gods = norse_gods->insert(new Link(God("Freia", "Norse")));

		// Bulgarian mythology list of Gods
		Link* bulgarian_gods = new Link(God("Tangra", "Bulgarian", "Horse and Eagle", "Sun"));
		bulgarian_gods = bulgarian_gods->insert(new Link(God("Kubrat", "Bulgarian", "Horse", "Sword & Sons")));
		bulgarian_gods = bulgarian_gods->insert(new Link(God("Batbayan", "Bulgarian", "Horse", "Sword")));
		bulgarian_gods = bulgarian_gods->insert(new Link(God("Kotrag", "Bulgarian", "Horse", "Sword")));
		bulgarian_gods = bulgarian_gods->insert(new Link(God("Asparukh", "Bulgarian", "Horse", "Sword")));

		// print current lists
		print_all_back_to_front(greek_gods);
		std::cout <<"\n\n";

		print_all_back_to_front(norse_gods);
		std::cout <<"\n\n";

		print_all_back_to_front(bulgarian_gods);
		std::cout <<"\n\n"; 

		// lexicographically ordered lists
		std::cout <<"\nOrdered lists\n";

		Link* ordered_greek_gods = nullptr;
		order_list(greek_gods, ordered_greek_gods);
		print_all_back_to_front(ordered_greek_gods);
		std::cout <<"\n\n";
		 
		Link* ordered_norse_gods = nullptr;
		order_list(norse_gods, ordered_norse_gods);
		print_all_back_to_front(ordered_norse_gods);
		std::cout <<"\n\n";

		Link* ordered_bulgarian_gods = nullptr;
		order_list(bulgarian_gods, ordered_bulgarian_gods);
		print_all_back_to_front(ordered_bulgarian_gods);
		std::cout <<"\n\n";

		// !!! leaking all the nodes
		// implement destructor?
	} 
	catch (std::exception &e)
	{
		std::cerr << e.what () << std::endl;
		getchar ();
	}
	getchar ();
}