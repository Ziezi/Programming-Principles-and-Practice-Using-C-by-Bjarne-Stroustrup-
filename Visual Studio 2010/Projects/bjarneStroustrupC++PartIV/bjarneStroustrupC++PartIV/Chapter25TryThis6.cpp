/*
	TITLE		   Simple Encryption - Bit Twiddling 		Chapter25TryThis6.cpp
	COMMENT
		Objective: Write "the Tiny Encryption Algorithm" by D. Wheeler,
				   presented in §25.5.6, copy the encrypted text in a file
				   and decrypt it. The key is: bs.
				   https://en.wikipedia.org/wiki/Tiny_Encryption_Algorithm
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
			 Date: 11.05.2017
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <assert.h>
#include "Chapter25TryThis6.h"
 
int main()
{
	try
	{
		 assert(sizeof(long) == 4);

		 std::string src("Chapter25TryThis6in.txt");
		 std::string dest("Chapter25TryThis6out.txt");

		 std::string dest2("Chapter25TryThis6out2.txt");
		 std::string key("bs");

		 receive_msg(src, dest, key);
		 // send_msg(dest, dest2, key);
		 // receive_msg(dest2, dest, key);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	std::cout <<"Decryption done!\n";
	getchar();
}