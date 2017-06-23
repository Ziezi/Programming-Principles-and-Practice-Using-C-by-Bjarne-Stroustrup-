/* 
   TITLE  		  Selection Blocks			      Chapter4TryThis2.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
       Objective: Implement a currency converter using 
				  switch - case: break; selection construct.
           Input: - 
          Output: -
		  Author: Chris B, Kirov
            Date: 01.04. 2015

*/
#include "../std_lib_facilities.h"

int main() 
{	
	const int lev = 1;
	const int euro = 2;
	const int pound = 3;

	const double dollars_to_lev = 1.43;
	const double dollars_to_euro = 0.73;
	const double dollars_to_pound = 0.59;

	// Prompt message: Select currency
	cout << "Convert US dollars to:\n" << endl;
	cout << "\t1. Lev.\n" << endl;
	cout << "\t2. Euro.\n" << endl;
	cout << "\t3. British Pound.\n" << endl;
	cout << "Please type a number followed by Enter: ";
	int src_currency;
	cin >> src_currency;
	
	// Select amount 
	cout << "\nPlease type the amount you want to convert followed by Enter: ";
	double amount;
	cin >> amount;

	// Determine and calculate the convetion
	switch (src_currency){
	case lev: 
		cout << "\t"<<amount << " $ = " << amount *  dollars_to_lev << " Lev" << endl; 
		break;
	case euro: 
		cout << "\t" << amount << " $ = " << amount * dollars_to_euro << " Euro" << endl; 
		break;
	case pound:
		cout << "\t" << amount << " $ = " << amount * dollars_to_pound << " Pound" << endl; 
		break;
	default:
		cout << "You have entered an invalid operation!" << endl; 
		break;
	}

	return 0;
}