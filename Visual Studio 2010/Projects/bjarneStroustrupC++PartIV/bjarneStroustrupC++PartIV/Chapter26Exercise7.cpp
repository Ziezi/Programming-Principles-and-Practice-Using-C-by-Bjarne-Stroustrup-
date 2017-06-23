/* 
	TITLE		   Test Text Editor   Chapter26Exercise7.cpp
	COMMENT
		Objective: Test the "simple text editor" from §20.6. 
			Input: -
		   Output: -
		   Author: Chris B. Kirov
			 Date: 01.06.2017
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>

#include "D:\C++ Projects\Visual Studio 2010\Projects\bjarneStroustrupC++PartIII\bjarneStroustrupC++PartIII\Chapter20Exercise6.h"
#include "Chapter26Exercise7.h"

int main()
{
	try 
	{
		std::string input_text("Chapter26Exercise7InputText.txt");
		std::string tests("Chapter26Exercise7Tests.txt");

		std::ifstream text_ifs(input_text.c_str());
		std::ifstream measure_ifs(tests.c_str());

		if (!text_ifs|| !measure_ifs)
		{
			throw std::runtime_error("Can't open file!\n");
		}

		Test_Document t(measure_ifs, text_ifs);
	}
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}