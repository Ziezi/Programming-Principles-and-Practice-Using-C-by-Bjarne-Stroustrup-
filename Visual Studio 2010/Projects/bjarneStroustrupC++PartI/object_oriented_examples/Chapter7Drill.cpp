/*
	TITLE			   Debug and run       		     Chapter7Drill.cpp
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
					   calculator08buggy.cpp
	COMMENT
			Objective: 
					   1.Download : http://www.stroustrup.com/Programming/calculator08buggy.cpp
			             Remove the 3 inserted bugs that the compiler will catch and 3 that it won't.
					   2. Add helpful comments.
					   3. -
					   4. Test for different value and epxressions.
					   5. -
					   6. define k 1000.
					   7. Add sqrt();
					   8. Handle negative square roots with appropriate error message.
					   9. Add pow(x, n), where x^n.
					   10. Declare new variable with: #.
					   11. Exit with 'q'.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 19.02.2015
*/
#include <iostream>
#include <string>
#include <vector>
#include "Chapter7Drill.h"

//============================================================================================

int main()
{
	std::cout << "\t\tWelcome to our calculator!" << std::endl;
	calculate();
}

//============================================================================================

/*
	Function: to_string()
	Use: string s = to_string(Token t)

	Converts the token content to string depending
	on its kind. Used in error handling, to show the
	token that causes the error.
*/

/*
std::string to_string(Token t)
{
	
}
*/

//-------------------------------------------------------------------------------
/* 
	Function: read_test_file();
	Use: Called using keyword: test; branch of statement()

	Redictects cin to read from test file containing a 
	seqence of exressions that check programs input range,
	error handling and stability.
*/

/*
void cinReadsTestFile()
{
	 
}
*/

//-------------------------------------------------------------------------------
/*
	Function: cinReadingDefault();
	Use: Called using keyword: cdef; 

	Called at the end of the test file
	to restore cin to default, i.e. back to
	standard input.
*/

/*
void cinReadingDefault()
{
	  cin.rdbuf(cinbuf);
}
*/



