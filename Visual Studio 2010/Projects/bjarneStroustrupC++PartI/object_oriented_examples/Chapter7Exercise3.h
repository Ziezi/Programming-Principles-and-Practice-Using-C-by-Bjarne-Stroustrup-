/*
	TITLE			   Constant variables          Chapter7Exercise3.h
	Bjarne Stroustrup "Programming: Principles and Practice Using C++"
	COMMENT
			Objective: Provide constant variables declarations/ definitions
					   using specific identifier; they can't be reassigned.
				Input: -
			   Output: -
			   Author: Chris B. Kirov
			     Date: 24.02.2015
*/

#ifndef CHAPTER7EXERCISE3_H
#define CHAPTER7EXERCISE3_H

// "keyword" input 
// "identifier" internal semaphore used for function communication

const char printKeyword = '=';					 
const char printIdentifier = '=';

const char assignmentIdentifier = '=';			 

const char numberIdentifier = '8';			 

const char nameIdentifier = 'a';			 

const std::string quitKeyword = "exit";		
const char quitIdentifier = 'Q';				 

const std::string declarationKeyword = "#";
const char declarationIdentifier = 'L';			 

const std::string squareRootKeyword = "sqrt";
const char mysqrtIdentifier = 's';				 

const std::string powerKeyword = "pow";
const char mypowIdentifier = 'p';			 

// New code
const std::string constantVariableKeyword = "const";
const char constantVariableIdentifier = 'c';

const char variableIdentifier = 'v';

#define k 1000;

const std::string prompt = "> ";				// sybmol used to prompt the user for input
const std::string result = "= ";				// symbol after which the result is printed

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
	 
	char kind;
	double value;
	std::string name;

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
	Token_stream() 
		:full(false), buffer(0)
	{
	
	}

	Token get();
	void unget(Token t); 
	void ignore(char s);

private:
	bool full;
	Token buffer;
} ts; // Object of type Token_stream used in the program  

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
	char identifier;
	std::string name;
	double value;

	Variable(char i, std::string n, double v)
		: identifier(i), name(n), value(v) { }
};

// container holding the user defined variables; 
std::vector<Variable> names;	

double expression();


#include "Chapter7Exercise3Def.cpp" 
#endif