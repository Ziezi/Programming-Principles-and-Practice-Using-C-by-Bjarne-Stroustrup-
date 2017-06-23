/*
	TITLE		    Find & Replace for Document    Chapter20Exercise6.cpp
	"Bjarne Stroustrup "C++ Programming: Principles and Practice.""
	COMMENT
		 Objective: Write find and replace operation for class Document
					based on §20.6.2.
		     Input: -
			Output: -
			Author: Chris B. Kirov
			  Date: 19. 02. 2017
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include "Chapter20Exercise6.h"

int main()
{
	try 
	{
		Document text;
		 
		// operator>> & operator<< & print() 
		std::string s("Lorem Ipsum is simply dummy text\n of the printing and typesetting industry.");
		std::stringstream ss(s);
		ss >> text;

		std::cout << text <<'\n';
		text.print();

		// find() 
		char c = 'I'; // = 'Z';
		Document::iterator p = text.find(text.begin(), c);

		if (p != text.end())
		{
			std::cout <<"\nChar Found!\n";
		}
		else
		{
			std::cout <<"\nNot found!\n";
		}


		//  find_txt()
		std::string t("textof");
		Document::iterator p2 = text.find_txt(t);

		if (p2 != text.end())
		{
			std::cout <<"\nText Found!\n";
		}
		else
		{
			std::cout <<"\nNot found!\n";
		}

		// erase()
		Document::iterator pp = p2;
		pp = text.erase(pp);
		std::cout << text;

		std::cout <<"\n";

		// insert()
		pp = text.insert(text.begin(), 't');
		std::cout << text;

		std::cout <<"\n";

		// replace()
		std::string r("TYPESETTIN"); // ("TYPESETTING"); // ("TYPESETTINGG");
		Document::iterator p3 = text.replace("typesetting", r);

		if (p3 != text.end())
		{
			std::cout <<"Replaced!\n";
			std::cout << text;
		}
		else
		{
			std::cout <<"Not replaced!\n";
		}

	}
	catch (std::exception& e) 
	{
		std::cerr << e.what();
	}
	getchar ();
}