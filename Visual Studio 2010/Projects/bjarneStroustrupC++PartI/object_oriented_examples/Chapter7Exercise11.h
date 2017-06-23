/*
	TITLE			    Operate only on int                 Chapter7Exercise11.h
	"Software - Principles and Practice using C++" by Bjarne Stroustrup"
	COMMENT
			Objective: Modify the calculator to work only on integer
			           values. 
					   
					   Handle overflow and underflow.
					   addition
					   subtractiom
					   multiplication
					   division
				Input: - 
			   Output: -
			   Author: Chris B. Kirov
			     Date: 25.02.2015
*/  
#ifndef CHAPTER7EXERCISE11_H
#define CHAPTER7EXERCISE11_H

// symbolic constants used in the code
// "keyword" is a read via input
// "identifier" is an internal semaphore for function communication

// New code
int MAXIMUM_INT_VALUE = std::numeric_limits<int>::max();
int MINIMUM_INT_VALUE = std::numeric_limits<int>::min();

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

const std::string prompt = "> ";	// sybmol used to prompt the user for input
const std::string result = "= ";	// symbol after which the result is printed
//------------------------------------------------------------------------------
/*
	class: Token

	Used for the conversion
	of raw input to interprted
	data used for algebraic
	calculations.
*/
class Token 
{
public:

	char kind;
	int value;
	std::string name;

	Token(char ch)
		: kind(ch), value(0)
	{
	
	}

	Token(char ch, int val)
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
	inline int get(std::string n)
	{
		return get_value(n);
	}

	inline int set(std::string n)
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

	inline void add(char i, std::string n, int v)
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
		int value;	

		Variable(char i, std::string n, int v)
			: identifier(i), name(n), value(v) 
		{
		
		}
	};

	// container holding the user defined variables; 
	std::vector<Variable> symbol_table;	// New code

	int get_value(std::string s);
	void set_value(char i ,std::string s, int d);
	bool is_Declared(std::string s);
	int reAssign(std::string n);
	bool is_constantVar(std::string name);
} st; // object of type Symbol_table used in the program  

// forward declaration so that primary() can call expression()(defined after primary)
int expression();

#include "Chapter7Exercise11Def.cpp"

#endif
