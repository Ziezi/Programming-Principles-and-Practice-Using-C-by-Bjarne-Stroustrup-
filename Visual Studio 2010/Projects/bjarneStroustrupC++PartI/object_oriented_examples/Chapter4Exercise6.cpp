/*
   TITLE		   Word-number conversion		Chapter4Exercise6.cpp
   Bjarne Stroustrup "Programming: Principles and Practice Using C++"
   COMMENT
 		Objective: To establish a connection between an input number
				   and its name.
 			Input: Requests a number either as digit or spelled out
			       and converts it to corresponding representation.  
		   Output: Prints the respective input number
		           to its "opposite" representation.
		   Author: Chris B. Kirov
			 Data: 01.04.2015
*/
#include "../../std_lib_facilities.h"

int word_to_digit(const string&);
string digit_to_word(int);

//=========================================================================================

int main()
{	 			
	cout << "Type a number as digit/spelled-out form and get its spelled-out/digit representation.\n>>";

	string sentinel = "|";
	string input;

	while (getline(cin, input) && input != sentinel)
	{
		stringstream ss(input);
		int type_test = ss.peek();

		if (isdigit(type_test))
		{
			int digit;
			ss >> digit;
			cout <<"You've typed: "<< digit_to_word(digit) <<"\n"; 
		}
		else  
		{
			string name;
			ss >> name;
			cout <<"You've typed: "<< word_to_digit(name) <<"\n"; 
		}
		cout << "Type a number as digit/spelled-out form and get its spelled-out/digit representation.\n>>";
	}
}

//=========================================================================================

int word_to_digit(const string& number)
{
	vector<string> numword(10);
	numword[0] = "zero";
	numword[1] = "one";
	numword[2] = "two";
	numword[3] = "three";
	numword[4] = "four";
	numword[5] = "five";
	numword[6] = "six";
	numword[7] = "seven";
	numword[8] = "eight";
	numword[9] = "nine";

	for (unsigned int i = 0; i < numword.size(); ++i)
	{
		if (number == numword[i])
		{
			return i;
		}
	}

	// not found
	return -1;
}

string digit_to_word(int index)
{
	vector<string> numword(10);

	if (index < 0 || index > numword.size())
	{
		// not found
		return "none";
	}

	numword[0] = "zero";
	numword[1] = "one";
	numword[2] = "two";
	numword[3] = "three";
	numword[4] = "four";
	numword[5] = "five";
	numword[6] = "six";
	numword[7] = "seven";
	numword[8] = "eight";
	numword[9] = "nine";

	return numword[index];
}