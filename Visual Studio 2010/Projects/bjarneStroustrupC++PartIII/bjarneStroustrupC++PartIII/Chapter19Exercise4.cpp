/*
	TITLE			Templatized Linked List    Chapter19Exercise4.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		Objcective: Modify class Link from Chapter 17.9.3 to be a 
		            template with the type of a value  as the 
					template argument.
					Redo Exercise 13 Chapter 17 with Link<God>.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 21.1.2016
*/
#include <iostream>
#include <string>
#include <functional>
#include "Chapter19Exercise4.h"

int main () 
{
	try
	{
		// God(name(n), mythology(m), vehicle(v), weapon(w)) 
		// Greek mythology list of Gods
		
		Link<God>* greek_gods = new Link<God>(God("Zeus", "Greek", "", "lightning"));
		greek_gods = greek_gods->insert(new Link<God>(God("Hera", "Greek" )));
		greek_gods = greek_gods->insert(new Link<God>(God("Athena", "Greek")));
		greek_gods = greek_gods->insert(new Link<God>(God("Ares", "Greek")));
		greek_gods = greek_gods->insert(new Link<God>(God("Poseidon", "Greek" )));
		
		// Norse mythology list of Gods
		Link<God>* norse_gods = new Link<God>(God("Odin", "Norse", "Eight-legged flying horse called Sleipner"));
		norse_gods = norse_gods->insert(new Link<God>(God("Thor", "Norse")));
		norse_gods = norse_gods->insert(new Link<God>(God("Freia", "Norse")));

		// Bulgarian mythology list of Gods
		Link<God>* bulgarian_gods = new Link<God>(God("Tangra", "Bulgarian", "Horse and Eagle", "Sun"));
		bulgarian_gods = bulgarian_gods->insert(new Link<God>(God("Kubrat", "Bulgarian", "Horse", "Sword & Sons")));
		bulgarian_gods = bulgarian_gods->insert(new Link<God>(God("Batbayan", "Bulgarian", "Horse", "Sword")));
		bulgarian_gods = bulgarian_gods->insert(new Link<God>(God("Kotrag", "Bulgarian", "Horse", "Sword")));
		bulgarian_gods = bulgarian_gods->insert(new Link<God>(God("Asparukh", "Bulgarian", "Horse", "Sword")));
		
		print<God>(greek_gods);
		std::cout <<"\n\n";
		print<God>(norse_gods);
		std::cout <<"\n\n";
		print<God>(bulgarian_gods);

		// lexicographically ordered lists
		std::cout <<"\nOrdered lists\n";

		Link<God>* ordered_greek_gods = nullptr;
		order_list(greek_gods, ordered_greek_gods);
		print(ordered_greek_gods);
		std::cout <<"\n\n";
		
		Link<God>* ordered_norse_gods = nullptr;
		order_list(norse_gods, ordered_norse_gods);
		print(ordered_norse_gods);
		std::cout <<"\n\n";

		Link<God>* ordered_bulgarian_gods = nullptr;
		order_list(bulgarian_gods, ordered_bulgarian_gods);
		print(ordered_bulgarian_gods);
		std::cout <<"\n\n";
		
		std::cout <<"\nDone!\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	catch (...)
	{
		std::cerr << "Unhandled Exception!\n";
	}
	getchar();
}