/*
	TITLE		   Bitfield manipulation											    Chapter25Exercise10.cpp
	COMMENT
		Objective: 1. Look at the bitfield example from §25.5.5. Write an example that initializes a PPN, 
				   then reads and prints each field value, then changes each field value (by assigning the field), 
				   and prints the result. 
				   2. Repeat this exercise, but store the PPN information in a 32-bit unsigned integer and use
				   bit manipulation operators (§25.5.4) to access the bits in the word. 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 15.05.2017
*/
#include <iostream>
#include <bitset>

#include "Chapter25Exercise10.h"

int main()
{
	try
	{ 
		 // 1. 
		 // initialize
		 PPN p;
		 p.PFN = 0;
		 p.CCA = 0;
		 p.nonreachable = 0;
		 p.dirty = 0;
		 p.valid = 0;

		 // print
		 print_PPN(&p);

		 // access and modify
		 p.PFN = 4194303;
		 p.CCA = 7;
		 p.nonreachable = 1;
		 p.dirty = 1;
		 p.valid = 1;

		 // print
		 print_PPN(&p);

		 // 2. 
		 // initialize
		 unsigned int PPN = 0;

		 std::cout <<"PPN: "<< std::bitset<32>((int)PPN) <<'\n'; 

		 // access and modify
		 PPN = 4194303 << 10; // set all PFN bits to 1
		 PPN |= 7 << 4;		  // set all CCA bits to 1
		 PPN |= 1 << 3;       // set notreachable to 1
		 PPN |= 1 << 2;		  // set dirty to 1
		 PPN |= 1 << 1;		  // set valid to 1;
		 PPN |= 1;			  // set global to 1;
		 
		 std::cout <<"PPN: "<< std::bitset<32>((int)PPN) <<'\n'; 
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}