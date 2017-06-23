/*
	TITLE	       Compose an integer from chars  Chapter6Exercise9.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
 		Objective: Read string characters and convert them into integers.
 			Input: 123
 		   Output: 123 is 1 hundred and 2 le ns and 3 ones .
		   Author: Chris B. Kirov
			 Date: 16.02.2015
*/			
#include <iostream>
#include <string>

int composeInteger(const std::string&);

//=========================================================================================
// Execution segment
int main()
{
	// array of strings holding the names of digits' positions
	const size_t arraySize = 4;
	std::string digitPosition[arraySize] = {"one", "ten", "hundred", "thousand"};

	std::cout << "\t\tWelcome to our simple Decimal system synthesizer.\n";
	std::string sentinel = "x";
	std::string input;
	  
	while (true)
	{
		std::cout << "\nPlease type up to "<< arraySize <<" digits; 'x' to exit: \n>>";
		getline(std::cin, input);

		if (input == sentinel) 
		{
			break;
		}

		int digit = composeInteger(input);
			
		// prints the result
		std::cout << ">> ";
		std::cout << digit << " is ";

		// print input as integers
		for (unsigned int j = 0; j < input.size(); j++)
		{
			std::cout << (input[j] - '0') <<" ";

			std::cout<< digitPosition[j];

			if (input[j] > '1') std::cout <<"s ";

			std::cout <<" ";
		}
		std::cout <<".\n";
	}
}

//=========================================================================================
/*
	Function: composeInteger(string inputDigit);
	Use: int number = composeInteger(string inputDigit);

	It takes n numbers in character format and converts them 
	in a digit. Characters are converted to integers and then
	are multiplied by 10 ^ n, where n is their position.
*/
int composeInteger(const std::string& inputDigit)
{
	double powerBase = 10;
	// enumerator formed by multiplying the powerBase by the input string size -1
    double enumerator = pow(powerBase, int (inputDigit.size()-1));
	// denomenator formed by consequtive multiplications of the powerBase by 10
	double denomenator = 0;
	// position weight multiplies each integer starting by 10 to the power of its position
	int positionWeight = 0;
	// sums all the multiplied digits to form the end decimal digit
	int decimalDigit= 0;
	for(unsigned int i = 0 ; i < inputDigit.size();  i++)
	{
		denomenator = pow(powerBase, int (i));
		positionWeight = int (enumerator) / int (denomenator);
	    decimalDigit += (positionWeight) * (inputDigit[i]-'0');	
	}
	return decimalDigit;
}