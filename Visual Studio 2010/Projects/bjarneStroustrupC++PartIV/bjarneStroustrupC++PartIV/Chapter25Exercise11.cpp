/*
	TITLE		   Bitset manipulation	Chapter25Exercise11.cpp
	COMMENT
		Objective: Redo previous exercise using bitset.

				   Bitset, Y U no iterators?
		   Output: -
		   Author: Chris B. Kirov
			 Date: 15.05.2017
*/
#include <iostream>
#include <bitset>

template<size_t N>
void set_bits_in_range(size_t s, size_t e, std::bitset<N>& b)
{
	if (s < 0 || e > N)
	{
		throw std::runtime_error("set_bits_in_range::Bits out of range!");
	}

	for (size_t i = s; i < e; ++i)
	{
		b.set(i);
	}
}

//------------------------------------------------------------------------------------------------------------------

template<size_t N>
void set_bits_in_range(size_t s, size_t e, std::bitset<N>& b, std::string src)
{
	if (s < 0 || e > N || (e - s) != src.size())
	{
		throw std::runtime_error("set_bits_in_range::Bits out of range!");
	}

	int index = 0;
	for (size_t i = s; i < e; ++i)
	{
		if (src[index] == '1')
		{
			b.set(i);
		}
		else
		{
			b.reset(i);
		}
		++index;
	}
}

//------------------------------------------------------------------------------------------------------------------

template<size_t N>
void print_bits_in_range(size_t s, size_t e, std::bitset<N>& b, std::string msg)
{
	if (s < 0 || e > N)
	{
		throw std::runtime_error("print_bits_in_range::Bits out of range!");
	}

	std::cout << msg <<" : ";
	for (size_t i = s; i < e; ++i)
	{
		std::cout << b[i];
	}
	std::cout <<"\n";
}

//------------------------------------------------------------------------------------------------------------------

int main()
{
	try
	{ 
		 // 1. 
		 // initialize
		 std::bitset<32> PPN; // PFN : 22, - 3, CCA : 3, nonreach: 1, dirty : 1, valid : 1, global : 1.
		 PPN.reset();

		 // print
		 std::cout <<"PPN : "<< PPN <<'\n';

		 // access and modify
		 set_bits_in_range(10, 32, PPN);  // set all PFN bits to 1
		 std::cout <<"PPN : "<< PPN <<'\n';

		 set_bits_in_range(4, 7, PPN, "111"); // set all CCA bits to 1
		 std::cout <<"PPN : "<< PPN <<'\n';

		 set_bits_in_range(0, 4, PPN);		// set nonreachable, dirty, valid and global to 1

		 // print
		 std::cout <<"PPN : "<< PPN <<'\n';
		 print_bits_in_range(10, 32, PPN, "PFN");
		 print_bits_in_range(4, 7, PPN, "CCA");
		 print_bits_in_range(0, 4, PPN, "nonreachable, dirty, valid and global");
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}