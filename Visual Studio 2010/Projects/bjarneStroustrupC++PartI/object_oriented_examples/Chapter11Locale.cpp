/*
	TITLE		   System locale check			     Chapter11Locale.cpp
	"Software - Principles and Practice using C++" by Bjarne Stroustrup"
	COMMENT
		Objective: Check system locale
			Input: -
		    Ouput: Displays system locale (English_United Kingdom.1252)
		   Author: Chris B. Kirov
		     Data: 10.05.2015
*/
#include"stdafx.h"

/*
	Function: print_locale_names()
	 
	It provides information about system's
	locales and commands related to them.
*/
void print_locale_names(const locale& my_loc)
{
	cout << "name of current global locale: " << locale().name() << '\n';
	cout << "name of classic C locale: " << locale::classic().name() << '\n';
	cout << "name of user's preferred locale: "<< locale("").name() << '\n';
	cout << "name of my locale: " << my_loc.name() << '\n';
}

int main()
{
	// define locale
	locale loc("");

	// print its name
	cout << "Name of defined locale: " << loc.name()<< '\n';

	print_locale_names(loc);
}