/* 
   TITLE  		  Selection Blocks			      Chapter4TryThis.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
       Objective: Implement a currency converter using 
				  if - else (if) block.
           Input: - 
          Output: -
		  Author: Chris B, Kirov
            Date: 01.04.2015

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
	if (src_currency == lev) 
	{ 
		cout << "\t"<<amount << " $ = " << amount *  dollars_to_lev << " Lev" << endl; 
	}
	else if (src_currency == euro) 
	{ 
		cout << "\t" << amount << " $ = " << amount * dollars_to_euro << " Euro" << endl; 
	}
	else if (src_currency == pound)
	{ 
		cout << "\t" << amount << " $ = " << amount * dollars_to_pound << " Pound" << endl; 
	}
	else 
	{ 
		cout << "You have entered an invalid operation!" << endl; 
	}

	return 0;
}