/*	
    TITLE			   Calculator		          Chapter6TryThis1.cpp
    Bjarne Stroustrup "Programming: Principles and Practice Using C++"
 	COMMENT
 			Objective: Make a first attempt to sketch an outline of a 
			           calculator that evaluates compound
					   expressions, considering operator precedence.

					   Left incoplete due to lack of knowledge
					   of Grammar implementation.
 				Input: -
 			   Output: -
			   Author: Chris B. Kirov
		         Date: 1.2.2015
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Token; 
void inputParser(std::stringstream&, std::vector<Token>&);
bool isOperand(const char&);
bool isOperation(const char&);
int operationPrecedence(const char&);
double evaluateExpression(std::vector<Token>&);
double precedence1();
double precedence2();
double precedence3();
double precedence4();

//=========================================================================================

int main()
{
	// holds the interpreted algebraic input epxression
	std::vector<Token> tokenizedExpression;


	std::cout << "\t\t Calculator 1.0\n";
	std::string prompt = "Type an expression:\n>>";
	std::string sentinel = "exit";
	std::string input;

	while(getline(std::cin, input))
	{
		std::cout << prompt;

		// exit ?
		if (input != sentinel)
		{
			return;
		}

		// extract input
		std::stringstream ss(input);

		// tokenize
		inputParser(ss, tokenizedExpression);

		// evaluate tokenized epxression
		evaluateExpression(tokenizedExpression);	 
	}
}
//=========================================================================================

/*
	class: Token

	It converts raw input
	data into tokens: algebraic
	operations and operands.

	operand token: kind == '8', value = dataValue;
	operation token: kind == '+', value = precedenceValue

	The smaller the number, the higher the precedence.  
	operation    precedence  
	 +, -          2
	 *, /          3
	
*/
class Token 
{
public:
	// data members
	char kind;
	double value;

	// constructors
	Token ()
	{
	
	}

	Token(char k)
		: kind(k), value(0)
	{
	
	}

	Token(char k, double v)
		: kind(k), value(v)
	{
	
	}
};

//-----------------------------------------------------------------------------------------


/*
	Function: inputParser();

	It interprets the raw input
	passed via the stringstream parameter
	and it separates it to tokens, 
	i.e. known operations and operands,
	which are then saved in the vector
	passed by reference as second parameter.
*/ 
void inputParser(std::stringstream& input, std::vector<Token>& v)
{
	char operandKind = '8';
	char convertToDigit = '0';

	char rawData;
	while (input.get(rawData))
	{

		 // how to handle (multiply occuring) parenthesses ?
		 if (isOperand(rawData))
		 {
			// return char to stringstream
		    input.unget();

			// read the whole number
			double number;
			input >> number;

			// tokenize and store in vector
			v.emplace_back(Token(operandKind, number));
		 }
		 else if (isOperation(rawData))
		 {
			 int precedence = operationPrecedence(rawData);
			 v.emplace_back(Token(rawData, precedence));
		 }
		 else 
		 {
			std::cerr <<"Wrong input format!\n";
		 }
	}
}

//-----------------------------------------------------------------------------------------
/*
	Function : isOperand();

	Returns true if the contant
	character passed by  reference
	is digit or decimal point.
*/
bool isOperand(const char& c)
{
	if (isdigit(c) || c == '.')
	{
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------------------
/*
	Function: isOperation();

	It returns true if the constant
	character passed by reference is
	a supported algebraic operation.
*/
bool isOperation(const char& c)
{
	const size_t arraySize = 4;
	char supportedOperations[arraySize] = {'+', '-', '*', '/'};

	for (size_t i = 0; i < arraySize; ++i)
	{
		if (c == supportedOperations[i])
		{
			return true;
		}
	}
	return false;
}

//-----------------------------------------------------------------------------------------
/*
	Function: operationPrecedence();

	It returns an integer corresponding
	to the precedence of the operation
	passed by the parameter.

	The smaller the number, the higher the precedence.  
	operation    precedence  
	 +, -          2
	 *, /          3
*/
int operationPrecedence(const char& operation)
{
	switch (operation)
	{
		case '+': case '-':
		{
			return 1;
		}
		case '*': case '/':
		{
			return 2;
		}
		default:
		{
			std::cerr <<"Not supported operation!\n";
			return -1;
		}
	}
}

//-----------------------------------------------------------------------------------------
/*
	Function: evaluateExpression();

	It parses an algebraic expression
	in the contents of the vector
	consisted of tokens (algebraic operations
	and operands) and returns the result of the
	expression.
*/
double evaluateExpression(std::vector<Token>& v)
{
	while (v.size() == 1)
	{
		/* 
			Run through the vector and search for
			the operation with the 
			highest precedence, evaluate it and
			erase its operands and operations,
			replacing them with the result.
			Do this until there is only one 
			element in the vector which is 
			a floating point literal (result).

			Example:
			1+(3*5) => 1+(15) => 1+15 => 16
		*/
	}
}

double precedence1(std::vector<Token>& v)
{
	 
}

double precedence2(std::vector<Token>& v)
{

}

double precedence3(std::vector<Token>& v)
{

}

double precedence4(std::vector<Token>& v)
{

}

 

 