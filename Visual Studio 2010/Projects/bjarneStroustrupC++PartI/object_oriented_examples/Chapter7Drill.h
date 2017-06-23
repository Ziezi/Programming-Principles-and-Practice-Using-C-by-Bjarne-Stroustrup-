/*
	TITLE			   Debug and run       		     Chapter7Drill.h
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
#ifndef CHAPTER7DRILL1_H
#define CHAPTER7DRILL1_H

// symbolic constants used in the code
const std::string quit = "exit";     // symbol used for exiting from the program
const char quitKeyword = 'x';
const char print = '=';				 // symbol used to print result
const char number = '8';			 // token kind describing a number
const char name = 'a';				 // token kind describing a name of user defined variable

const std::string declarationKeyword = "#";
const char declKey = 'L';			 // token kind describing user defined variable command

const std::string StdInReadsTestFile = "test";	
const char test = 'T';				 // token kind describing opetation involving: cin redirection to read test file 

const std::string squareRootKeyword = "sqrt";
const char mysqrt = 's';			 // token kind describing square root of a number

const std::string powerKeyword = "pow";
const char mypow = 'p';				 // token kind describing power of a number

#define k 1000;

const std::string prompt = "> ";	 // sybmol used to prompt the user for input
const std::string result = "= ";	 // symbol after which the result is printed
//------------------------------------------------------------------------------
/*
	class: Token

	Used for the conversion
	of raw input to interprted
	data used for algebraic
	calculations.
*/
class Token {
public:
	// data members for the three types of tokens:
	char kind;
	double value;
	std::string name;

	// constructors for each of the three tokens
	Token(char ch)
		:kind(ch), value(0)
	{
	
	}

	Token(char ch, double val)
		:kind(ch), value(val)
	{
	
	}

	Token(char ch, std::string n)
		:kind(ch), name(n) 
	{
	
	}
};

//------------------------------------------------------------------------------
/*
	class Token_stream

	Used as a buffer for
	tokenized input.
*/ 
class Token_stream
{
public:
	// constructor
	Token_stream() 
		:full(false), buffer(0) 
	{

	}

	// member functions 
	Token get();
	void unget(Token t); 
	void ignore(char s);

private:
	// data members 
	bool full;
	Token buffer;
} ts; // object instantiated to be used in the following functions

//------------------------------------------------------------------------------
/*
	class Variable

	Used as for user
	defined variables
	within the calculator.
*/ 
class Variable 
{
public:
	// data members
	std::string name;
	double value;

	// constuctor
	Variable(std::string n, double v)
		: name(n), value(v) 
	{
	
	}
};

// container holding the user defined variables; 
// pairs up together with the functions: get_value(); set_value(); is_declared();
std::vector<Variable> names;	

//------------------------------------------------------------------------------
// forward declaration due to circular dependacy between the functions implementing the grammar
double expression();
double statement();


 
#include "Chapter7DrillDef.cpp"
#endif