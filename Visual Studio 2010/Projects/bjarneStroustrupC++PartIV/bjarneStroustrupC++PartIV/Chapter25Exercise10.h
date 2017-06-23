/*
	TITLE		   Bitfield manipulation											    Chapter25Exercise10.h
	COMMENT
		Objective: Look at the bitfield example from §25.5.5. Write an example that initializes a PPN, 
				   then reads and prints each field value, then changes each field value (by assigning the field), 
				   and prints the result. 
				   Repeat this exercise, but store the PPN information in a 32-bit unsigned integer and use
				   bit manipulation operators (§25.5.4) to access the bits in the word. 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 15.05.2017
*/

#ifndef Chapter25Exercise10_h
#define Chapter25Exercise10_h

inline void bit_set (unsigned int& src, unsigned int bit_index) { src |= (1 << bit_index); }

//-----------------------------------------------------------------------------------------------------------------

inline void bit_clear (unsigned int& src, unsigned int bit_index) { src &= ~(1 << bit_index); }

//-----------------------------------------------------------------------------------------------------------------

inline void bit_flip (unsigned int& src, unsigned int bit_index) { src ^= (1 << bit_index); }

//-----------------------------------------------------------------------------------------------------------------

inline bool bit_check (unsigned int src, unsigned int bit_index) { return src & (1 << bit_index); }

//-----------------------------------------------------------------------------------------------------------------

struct PPN
{
unsigned int PFN : 22;
int : 3;
unsigned int CCA : 3;
bool nonreachable : 1;
bool dirty : 1;
bool valid : 1;
bool global : 1;
};

//-----------------------------------------------------------------------------------------------------------------

void print_PPN(PPN* p)
{
	std::cout <<"PFN : "<< std::bitset<22>((int)p->PFN)<<'\n'
		      <<"CCA : "<< std::bitset<3>((int)p->CCA) <<'\n'
			  <<"nonreachable : "<< p->nonreachable <<'\n'
			  <<"dirty : "<< p->dirty <<'\n'
			  <<"valid : "<< p->valid <<'\n';
	std::cout <<std::endl;
}

 
#endif