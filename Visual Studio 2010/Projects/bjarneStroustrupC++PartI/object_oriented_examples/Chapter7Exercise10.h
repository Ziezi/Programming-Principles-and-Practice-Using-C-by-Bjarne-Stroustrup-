 /*
	TITLE			   Propose 3 & Implement 1 feature  Chapter7Exercise10.h
	"Software - Principles and Practice using C++" by Bjarne Stroustrup"
	COMMENT
			Objective: Propose three possible improvements and implement
					   one.
				Input: - 
			   Output: -
			   Author: Chris B. Kirov
			     Date: 25.02.2015
*/
#ifndef CHAPTER7EXERCISE10_H
#define CHAPTER7EXERCISE10_H

// symbolic constants used in the code
// "keyword" is a read via input
// "identifier" is an internal semaphore for function communication

// New code
const char sinFunctionIdentifier = 't';
const std::string sinFunctionKeyword = "sin";
#define PI 3.14159

const char factorialIdentifier = '!';

const std::string helpKeyword = "H";
const char helpIdentifier = 'h';

const char printKeyword = '=';			
const char printIdentifier = 'r'; 

const char numberIdentifier = '8';	 

const char nameIdentifier = 'a';	 

const std::string quitKeyword = "Q";		
const char quitIdentifier = 'q';	 

const std::string declarationKeyword = "let";
const char declarationIdentifier = 'L';	 

const std::string squareRootKeyword = "sqrt";
const char mysqrtIdentifier = 's';	 

const std::string powerKeyword = "pow";
const char mypowIdentifier = 'p';	 

const char assignmentIdentifier = '=';

#define k 1000;				

const std::string constantVariableKeyword = "const";
const char constantVariableIdentifier = 'c';

const char variableIdentifier = 'v';

const std::string prompt = "> ";	// symbol used to prompt the user for input
const std::string result = "= ";	// symbol after which the result is printed
//------------------------------------------------------------------------------
/*
	class: Token

	Used for the conversion
	of raw input to interpreted
	data used for algebraic
	calculations.
*/
class Token 
{
public:

	char kind;
	double value;
	std::string name;

	Token(char ch)
		: kind(ch), value(0)
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
} ts; // object of type Token_stream used in the program  
//------------------------------------------------------------------------------------------
/*
	class Table
	
	Used to store/recover user-defined variables.
*/
class Table // New code
{
public:
	inline double get(std::string n)
	{
		return get_value(n);
	}

	inline double set(std::string n)
	{
		return reAssign(n);
	}

	inline void declare(char i, std::string n)
	{
		set_value(i,n,0);
	}

	inline bool is_declared(std::string name)
	{
		return is_Declared(name);
	}

	inline bool is_constvar(std::string name)
	{
		return is_constantVar(name);
	}

	inline void add(char i, std::string n, double v)
	{
		symbol_table.push_back(Variable(i, n, v));
	}
	
private:
	/*
		class Variable

		Defining data structure used 
		for user defined variables.
	*/
	class Variable
	{
	public:
		char identifier;
		std::string name;
		double value;	

		Variable(char i, std::string n, double v)
			: identifier(i), name(n), value(v) 
		{
		
		}
	};

	// container holding the user defined variables; 
	std::vector<Variable> symbol_table;	// New code

	double get_value(std::string s);
	void set_value(char i ,std::string s, double d);
	bool is_Declared(std::string s);
	double reAssign(std::string n);
	bool is_constantVar(std::string name);
} st; // object of type Symbol_table used in the program  

// forward declaration so that primary() can call expression()(defined after primary)
double expression();

#include "Chapter7Exercise10Def.cpp"

#endif
