/*
   TITLE           Currency Conversion  currencyConvert.cpp
   COMMENT
 		Objective: To convert different currencies. 
		           Implemented using: if() else if, statements
 			Input: Prompts the user to select specific 
			       currency conversion and the amount of money.
 		   Output: It prints the respective amount in the wanted currency.
		   Author: Chris B. Kirov
		     Date: 01.01.2014
*/
#include "../../std_lib_facilities.h"

int main(){
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

	// Determine and calculate the conversion
	if (src_currency == 1) { cout << "\t"<<amount << " $ = " << amount*1.43 << " Lev" << endl; }
	else if (src_currency == 2) { cout << "\t" << amount << " $ = " << amount*0.73 << " Euro" << endl; }
	if (src_currency == 3) { cout << "\t" << amount << " $ = " << amount*0.59 << " Pound" << endl; }
	else if (src_currency != 1 || src_currency != 2 || src_currency != 3 ){ cout << "You have entered an invalid operation!" << endl; }

	return 0;
}