/* 
    TITLE          Calculate a sum             Chapter3Exercise_11.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
    COMMENT
		Objective: Convert the currencies to a single unit and
				   accumulate their total sum. 
					
			Input: Requests coins as number of pennies, 
			       nickels, dimes, quarters and dollars.
		   Output: Prints them ordered and calculates 
		           the total sum in pounds.
		   Author: Chris B. Kirov
			 Date: 10.02.2014
*/
#include "../../std_lib_facilities.h"

int main()
{
	cout << "Calculate how much money do you have\n" << endl;
	cout << "\nHow many pennies (1 cent coins) do you have: ";
	int pennies = 0;
	cin >> pennies;

	cout << "\nHow many nickels (5 cent coins) do you have: ";
	int nickels = 0;
	cin >> nickels;

	cout << "\nHow many dimes (10 cent coins) do you have: ";
	int dimes = 0;
	cin >> dimes;

	cout << "\nHow many quarters (25 cent coins) do you have: ";
	int quarters = 0;
	cin >> quarters;

	cout << "\nHow many half dollars do you have: ";
	int h_dollars = 0;
	cin >> h_dollars;

	cout << "\nHow many half dollars do you have: ";
	int dollars = 0;
	cin >> dollars;

	// input confirmation; singular/plural differentiation
	cout << "\n\n\nYou have: " << endl;

	if (pennies == 1)
	{
		cout << "\t" << pennies << " pennie" << endl;
	}
	else 
	{
		cout << "\t" << pennies << " pennies" << endl;
	}
	if (nickels == 1)
	{
		cout << "\t" << nickels << " nickel" << endl;
	}
	else
	{
		cout << "\t" << nickels << " nickels" << endl;
	}
	if (dimes == 1)
	{
		cout << "\t" << dimes << " dime" << endl;
	}
	else
	{
		cout << "\t" << dimes << " dimes" << endl;
	}
	if (quarters == 1)
	{
		cout << "\t" << quarters << " quarter" << endl;
	}
	else
	{
		cout << "\t" << quarters << " quarters" << endl;
	}
	if (h_dollars == 1)
	{
		cout << "\t" << h_dollars << " half dollar" << endl;
	}
	else
	{
		cout << "\t" << h_dollars << " half dollars" << endl;
	}
	if (dollars == 1)
	{
		cout << "\t" << dollars << " dollar" << endl;
	}
	else
	{
		cout << "\t" << dollars << " dollars" << endl;
	}
 
	// total in cents 
	const int pennies_to_cents = 1; 
	const int nickels_to_cents = 5;
	const int dimes_to_cents = 10;
	const int quarters_to_cents = 25;
	const int half_a_dollar_to_cents = 50;
	const int dollars_to_cents = 100;

	double total_in_cents = 0;
	total_in_cents = (pennies_to_cents * pennies) + (nickels_to_cents * nickels) +
				     (dimes_to_cents * dimes) + (quarters_to_cents * quarters) + 
					 (half_a_dollar_to_cents * h_dollars) + (dollars_to_cents * dollars);

	cout <<"\n\n\nYour total amount of money is: "<< total_in_cents << " cents" << endl;

	// total in dollars
	double total_in_dollars = total_in_cents / dollars_to_cents;

	cout << "\nEquivalent to: " << total_in_dollars<< " $" << endl;

	getchar();
	return 0;
}
