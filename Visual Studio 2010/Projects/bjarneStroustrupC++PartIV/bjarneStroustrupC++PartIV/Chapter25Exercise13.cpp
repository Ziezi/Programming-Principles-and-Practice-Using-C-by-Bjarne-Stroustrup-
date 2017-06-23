/*
	TITLE		   Secure communication using TEA			 Chapter25Exercise13.cpp
	COMMENT
		Objective: Use TEA (§25.5.6) to communicate "securely" between two computers.
				   Email is minimally acceptable.
		   Output: -
		   Author: Chris B. Kirov
			 Date: 15.05.2017
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <assert.h>
#include "Chapter25Exercise13.h"

int main ()
{
	try
	{ 
		 assert(sizeof(long) == 4);

		 std::string src("Chapter25Exercise13in.txt");
		 std::string dest("Chapter25Exercise13out.txt");
		 std::string key("ribamech");

		 // receive_msg(src, dest, key);
		 send_msg(src, dest, key);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		exit(1);
	}
	getchar();
}